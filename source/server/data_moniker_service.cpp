//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <thread>
#include <tuple>
//#include <sideband_data.h>
//#include <sideband_internal.h>
//#include <sideband_grpc.h>
#include "data_moniker_service.h"

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using grpc::ServerReaderWriter;
using std::string;
using ni::data_monikers::DataMoniker;
using ni::data_monikers::MonikerList;
using ni::data_monikers::MonikerWriteRequest;
using ni::data_monikers::MonikerReadResult;
using ni::data_monikers::StreamWriteResponse;
//using ni::data_monikers::SidebandWriteRequest;
//using ni::data_monikers::SidebandReadResponse;
//using ni::data_monikers::BeginMonikerSidebandStreamRequest;
//using ni::data_monikers::BeginMonikerSidebandStreamResponse;

namespace ni::data_monikers
{
    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    DataMonikerService* DataMonikerService::s_Server;

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    DataMonikerService::DataMonikerService()
    {
        s_Server = this;
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    void DataMonikerService::RegisterMonikerEndpoint(string endpointName, MonikerEndpointPtr endpoint)
    {
        s_Server->_endpoints.emplace(endpointName, endpoint);
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    void DataMonikerService::RegisterMonikerInstance(string endpointName, void* instanceData, Moniker& moniker)
    {
        moniker.set_data_instance(reinterpret_cast<int64_t>(instanceData));
        moniker.set_service_location("local");
        moniker.set_data_source(endpointName);
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    void DataMonikerService::InitiateMonikerList(const MonikerList& monikers, EndpointList& readers, EndpointList& writers)
    {
        for (auto readMoniker: monikers.read_monikers())
        {
            auto instance = readMoniker.data_instance();
            auto source = readMoniker.data_source();
            auto it = _endpoints.find(source);
            MonikerEndpointPtr ptr = nullptr;
            if (it != _endpoints.end())
            {
                ptr = (*it).second;
            }
            readers.push_back(EndpointInstance(ptr, reinterpret_cast<void*>(instance)));
        }
        for (auto writeMoniker: monikers.write_monikers())
        {
            auto instance = writeMoniker.data_instance();
            auto source = writeMoniker.data_source();
            auto it = _endpoints.find(source);
            MonikerEndpointPtr ptr = nullptr;
            if (it != _endpoints.end())
            {
                ptr = (*it).second;
            }
            writers.push_back(EndpointInstance(ptr, reinterpret_cast<void*>(instance)));
        }
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    Status DataMonikerService::StreamReadWrite(ServerContext* context, ServerReaderWriter<MonikerReadResult, MonikerWriteRequest>* stream)
    {
        EndpointList writers;
        EndpointList readers;
        MonikerWriteRequest writeRequest;
        stream->Read(&writeRequest);
        InitiateMonikerList(writeRequest.monikers(), readers, writers);

        int x = 0;
        if (writeRequest.monikers().is_initial_write())
        {
            while (stream->Read(&writeRequest) && !context->IsCancelled())
            {
                x = 0;
                for (auto writer: writers)
                {
                    std::get<0>(writer)(std::get<1>(writer), const_cast<google::protobuf::Any&>(writeRequest.data().values(x++)));
                }

                x = 0;
                MonikerReadResult readResult;
                for (auto reader: readers)
                {
                    auto readValue = readResult.mutable_data()->add_values();
                    std::get<0>(reader)(std::get<1>(reader), *readValue);
                }
                stream->Write(readResult);
            }
        }
        else
        {
            while (!context->IsCancelled())
            {
                x = 0;
                MonikerReadResult readResult;
                for (auto reader: readers)
                {
                    auto readValue = readResult.mutable_data()->mutable_values(x++);
                    std::get<0>(reader)(std::get<1>(reader), *readValue);
                }
                stream->Write(readResult);

                int x = 0;
                for (auto writer: writers)
                {
                    std::get<0>(writer)(std::get<1>(writer), const_cast<google::protobuf::Any&>(writeRequest.data().values(x++)));
                }
            }
        }
        return Status::OK;
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    Status DataMonikerService::StreamRead(ServerContext* context, const MonikerList* request, ServerWriter<MonikerReadResult>* writer)
    {
        EndpointList writers;
        EndpointList readers;
        InitiateMonikerList(*request, readers, writers);

        int x = 0;
        while (!context->IsCancelled())
        {
            x = 0;
            MonikerReadResult readResult;
            for (auto reader: readers)
            {
                auto readValue = readResult.mutable_data()->add_values();
                std::get<0>(reader)(std::get<1>(reader), *readValue);
            }
            writer->Write(readResult);
        }
        return Status::OK;
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    Status DataMonikerService::StreamWrite(ServerContext* context, ServerReaderWriter<StreamWriteResponse, MonikerWriteRequest>* stream)
    {
    #ifndef _WIN32
        cpu_set_t cpuSet;
        CPU_ZERO(&cpuSet);
        CPU_SET(3, &cpuSet);
        sched_setaffinity(0, sizeof(cpu_set_t), &cpuSet);
    #endif

        EndpointList writers;
        EndpointList readers;
        MonikerWriteRequest writeRequest;
        stream->Read(&writeRequest);
        InitiateMonikerList(writeRequest.monikers(), readers, writers);

        int x = 0;
        while (stream->Read(&writeRequest) && !context->IsCancelled())
        {
            x = 0;
            for (auto writer: writers)
            {
                std::get<0>(writer)(std::get<1>(writer), const_cast<google::protobuf::Any&>(writeRequest.data().values(x++)));
            }
        }
        return Status::OK;
    }
}
