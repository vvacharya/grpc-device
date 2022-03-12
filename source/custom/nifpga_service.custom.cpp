#include <NiFpga.h>
#include <nifpga.grpc.pb.h>
#include <nifpga/nifpga_service.h>

namespace nifpga_grpc {

struct MonikerReadI32Data
{
    NiFpga_Session session;
    uint32_t indicator;
    nifpga_grpc::I32Data data;
};

::grpc::Status NiFpgaService::BeginReadI32Stream(::grpc::ServerContext* context, const BeginReadI32StreamRequest* request, BeginReadI32StreamResponse* response)
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
        // ni::data_monikers::MonikerServiceImpl::RegisterMonikerInstance("MonikerReadI32Stream", writeData, *writeMoniker);
        
        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status NiFpgaService::MonikerReadI32Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerReadI32Data* readData = (MonikerReadI32Data*)data;

    int32_t value = 0;
    auto status = library_->ReadI32(readData->session, readData->indicator, &value);
    if (status >= 0) {
        readData->data.set_value(value);
        packedData.PackFrom(readData->data);
    }
    return ::grpc::Status::OK;
}

}  // namespace nifpga_grpc
