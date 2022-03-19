#include <NiFpga.h>
#include <nifpga.grpc.pb.h>
#include <nifpga/nifpga_service.h>
#include <nifpga/nifpga_library_interface.h>
#include <server/data_moniker_service.h>

namespace nifpga_grpc {

void RegisterMonikers()
{
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI32Stream", MonikerReadI32Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI64Stream", MonikerReadI64Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU64Stream", MonikerReadU64Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI32Stream", MonikerWriteI32Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI64Stream", MonikerWriteI64Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU64Stream", MonikerWriteU64Stream);

    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayI64Stream", MonikerReadArrayI64Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayI64Stream", MonikerWriteArrayI64Stream);
}

struct MonikerReadI32Data
{
    NiFpga_Session session;
    uint32_t indicator;
    nifpga_grpc::I32Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

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
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, -1);
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

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
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->indicator;
    int32_t* value_ptr = readData->data.mutable_value()->mutable_data();

    auto status = library->ReadI32(session, indicator, value_ptr);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadI32Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

struct MonikerWriteI32Data
{
    NiFpga_Session session;
    uint32_t control;
    nifpga_grpc::I32Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::WriteI32Stream(::grpc::ServerContext* context, const WriteI32StreamRequest* request, WriteI32StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerWriteI32Data* writeData = new MonikerWriteI32Data();
        writeData->session = session;
        writeData->control = request->control();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteI32Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteI32Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerWriteI32Data* writeData = (MonikerWriteI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->control;

    I32Data i32_data;
    packedData.UnpackTo(&i32_data);
    int32_t value = *(i32_data.value().data());

    auto status = library->WriteI32(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteI32Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct MonikerReadI64Data
{
    NiFpga_Session session;
    uint32_t indicator;
    nifpga_grpc::I64Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::ReadI64Stream(::grpc::ServerContext* context, const ReadI64StreamRequest* request, ReadI64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerReadI64Data* readData = new MonikerReadI64Data();
        readData->session = session;
        readData->indicator = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, -1);
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadI64Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadI64Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerReadI64Data* readData = (MonikerReadI64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->indicator;
    int64_t* value_ptr = readData->data.mutable_value()->mutable_data();

    auto status = library->ReadI64(session, indicator, value_ptr);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadI64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

struct MonikerWriteI64Data
{
    NiFpga_Session session;
    uint32_t control;
    nifpga_grpc::I64Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::WriteI64Stream(::grpc::ServerContext* context, const WriteI64StreamRequest* request, WriteI64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerWriteI64Data* writeData = new MonikerWriteI64Data();
        writeData->session = session;
        writeData->control = request->control();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteI64Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteI64Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerWriteI64Data* writeData = (MonikerWriteI64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->control;

    I64Data i64_data;
    packedData.UnpackTo(&i64_data);
    int64_t value = *(i64_data.value().data());

    auto status = library->WriteI64(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteI64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct MonikerReadU64Data
{
    NiFpga_Session session;
    uint32_t indicator;
    nifpga_grpc::U64Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::ReadU64Stream(::grpc::ServerContext* context, const ReadU64StreamRequest* request, ReadU64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerReadU64Data* readData = new MonikerReadU64Data();
        readData->session = session;
        readData->indicator = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, -1);
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadU64Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadU64Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerReadU64Data* readData = (MonikerReadU64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->indicator;
    uint64_t* value_ptr = readData->data.mutable_value()->mutable_data();

    auto status = library->ReadU64(session, indicator, value_ptr);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadU64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

struct MonikerWriteU64Data
{
    NiFpga_Session session;
    uint32_t control;
    nifpga_grpc::U64Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::WriteU64Stream(::grpc::ServerContext* context, const WriteU64StreamRequest* request, WriteU64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerWriteU64Data* writeData = new MonikerWriteU64Data();
        writeData->session = session;
        writeData->control = request->control();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteU64Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteU64Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerWriteU64Data* writeData = (MonikerWriteU64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->control;

    U64Data u64_data;
    packedData.UnpackTo(&u64_data);
    uint64_t value = *(u64_data.value().data());

    auto status = library->WriteU64(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteU64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct MonikerReadArrayI64Data
{
    NiFpga_Session session;
    uint32_t indicator;
    nifpga_grpc::I64Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::ReadArrayI64Stream(::grpc::ServerContext* context, const ReadArrayI64StreamRequest* request, ReadArrayI64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerReadArrayI64Data* readData = new MonikerReadArrayI64Data();
        readData->session = session;
        readData->indicator = request->indicator();
        readData->data.mutable_value()->Reserve(request->size());
	    readData->data.mutable_value()->Resize(request->size(), 0);
        readData->size = request->size();
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadArrayI64Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadArrayI64Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerReadArrayI64Data* readData = (MonikerReadArrayI64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->indicator;
    auto size = readData->size;
    std::vector<int64_t> array(size);    

    //int64_t* value_ptr = readData->data.mutable_value()->mutable_data();

    auto status = library->ReadArrayI64(session, indicator, array.data(), size);
    if (status >= 0) {
        std::transform(
            array.begin(),
            array.begin() + size,
            ::google::protobuf::RepeatedFieldBackInserter(readData->data.mutable_value()),
            [&](auto x) {
                return x;
            });
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadArrayI64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

struct MonikerWriteArrayI64Data
{
    NiFpga_Session session;
    uint32_t control;
    nifpga_grpc::I64Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::WriteArrayI64Stream(::grpc::ServerContext* context, const WriteArrayI64StreamRequest* request, WriteArrayI64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerWriteArrayI64Data* writeData = new MonikerWriteArrayI64Data();
        writeData->session = session;
        writeData->control = request->control();
        writeData->size = request->size();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteArrayI64Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteArrayI64Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerWriteArrayI64Data* writeData = (MonikerWriteArrayI64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->control;
    auto size = writeData->size;

    I64Data i64_data;
    packedData.UnpackTo(&i64_data);
    auto array = const_cast<const int64_t*>(i64_data.value().data());
    auto status = library->WriteArrayI64(session, control, array, size);
    if (status < 0) {
        std::cout << "MonikerWriteArrayI64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

}  // namespace nifpga_grpc

