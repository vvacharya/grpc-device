#include <NiFpga.h>
#include <nifpga.grpc.pb.h>
#include <nifpga/nifpga_service.h>
#include <nifpga/nifpga_library_interface.h>
#include <server/data_moniker_service.h>

namespace nifpga_grpc {

struct MonikerReadI32Data
{
    NiFpga_Session session;
    uint32_t indicator;
    nifpga_grpc::I32Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

void RegisterMonikers()
{
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI32Stream", MonikerReadI32Stream);
}

::grpc::Status NiFpgaService::ReadI32Stream(::grpc::ServerContext* context, const ReadI32StreamRequest* request, ReadI32StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
        
        MonikerReadI32Data* readData = new MonikerReadI32Data();
        readData->session = session;
        readData->indicator = request->indicator();
        
        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadI32Stream", readData, *writeMoniker);
        
        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadI32Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerReadI32Data* readData = (MonikerReadI32Data*)data;

    int32_t value = 0;
    auto status = (readData->library)->ReadI32(readData->session, readData->indicator, &value);
    if (status >= 0) {
        readData->data.set_value(value);
        packedData.PackFrom(readData->data);
    }
    return ::grpc::Status::OK;
}

}  // namespace nifpga_grpc
