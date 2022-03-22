#include <NiFpga.h>
#include <nifpga.grpc.pb.h>
#include <nifpga/nifpga_service.h>
#include <nifpga/nifpga_library_interface.h>
#include <server/data_moniker_service.h>

namespace nifpga_grpc {

void RegisterMonikers()
{
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadBoolStream", MonikerReadBoolStream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI8Stream", MonikerReadI8Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU8Stream", MonikerReadU8Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI16Stream", MonikerReadI16Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU16Stream", MonikerReadU16Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI32Stream", MonikerReadI32Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU32Stream", MonikerReadU32Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI64Stream", MonikerReadI64Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU64Stream", MonikerReadU64Stream);

    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteBoolStream", MonikerWriteBoolStream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI8Stream", MonikerWriteI8Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU8Stream", MonikerWriteU8Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI16Stream", MonikerWriteI16Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU16Stream", MonikerWriteU16Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI32Stream", MonikerWriteI32Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU32Stream", MonikerWriteU32Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI64Stream", MonikerWriteI64Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU64Stream", MonikerWriteU64Stream);

    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayI16Stream", MonikerReadArrayI16Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayU16Stream", MonikerReadArrayU16Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayI64Stream", MonikerReadArrayI64Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayU64Stream", MonikerReadArrayU64Stream);

    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayI16Stream", MonikerWriteArrayI16Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayU16Stream", MonikerWriteArrayU16Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayI64Stream", MonikerWriteArrayI64Stream);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayU64Stream", MonikerWriteArrayU64Stream);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct MonikerI32Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::I32Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerU32Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::U32Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerI64Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::I64Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerU64Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::U64Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

//-----------------------------------------------------------------------------
// Read Scalar Methods
//-----------------------------------------------------------------------------
::grpc::Status NiFpgaService::ReadBoolStream(::grpc::ServerContext* context, const ReadBoolStreamRequest* request, ReadBoolStreamResponse* response)
{
    return ::grpc::Status::OK;
}
::grpc::Status MonikerReadBoolStream(void* data, google::protobuf::Any& packedData)
{
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::ReadI8Stream(::grpc::ServerContext* context, const ReadI8StreamRequest* request, ReadI8StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU32Data* readData = new MonikerU32Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, 0);
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadI8Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadI8Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerI32Data* readData = (MonikerI32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    auto value_ptr = reinterpret_cast<int16_t*>(readData->data.mutable_value()->mutable_data());

    auto status = library->ReadI16(session, indicator, value_ptr);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadI16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::ReadU8Stream(::grpc::ServerContext* context, const ReadU8StreamRequest* request, ReadU8StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU32Data* readData = new MonikerU32Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, 0);
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadU8Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadU8Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerU32Data* readData = (MonikerU32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    auto value_ptr = reinterpret_cast<uint8_t*>(readData->data.mutable_value()->mutable_data());

    auto status = library->ReadU8(session, indicator, value_ptr);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadU8Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::ReadI16Stream(::grpc::ServerContext* context, const ReadI16StreamRequest* request, ReadI16StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU32Data* readData = new MonikerU32Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, 0);
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadI16Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadI16Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerI32Data* readData = (MonikerI32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    auto value_ptr = reinterpret_cast<int16_t*>(readData->data.mutable_value()->mutable_data());

    auto status = library->ReadI16(session, indicator, value_ptr);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadI16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::ReadU16Stream(::grpc::ServerContext* context, const ReadU16StreamRequest* request, ReadU16StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU32Data* readData = new MonikerU32Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, 0);
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadU16Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadU16Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerU32Data* readData = (MonikerU32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    auto value_ptr = reinterpret_cast<uint16_t*>(readData->data.mutable_value()->mutable_data());

    auto status = library->ReadU16(session, indicator, value_ptr);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadU16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::ReadI32Stream(::grpc::ServerContext* context, const ReadI32StreamRequest* request, ReadI32StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerI32Data* readData = new MonikerI32Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, 0);
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
    MonikerI32Data* readData = (MonikerI32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
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

::grpc::Status NiFpgaService::ReadU32Stream(::grpc::ServerContext* context, const ReadU32StreamRequest* request, ReadU32StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU32Data* readData = new MonikerU32Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, 0);
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadU32Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadU32Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerU32Data* readData = (MonikerU32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    uint32_t* value_ptr = readData->data.mutable_value()->mutable_data();

    auto status = library->ReadU32(session, indicator, value_ptr);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadU32Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::ReadI64Stream(::grpc::ServerContext* context, const ReadI64StreamRequest* request, ReadI64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerI64Data* readData = new MonikerI64Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, 0);
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
    MonikerI64Data* readData = (MonikerI64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
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

::grpc::Status NiFpgaService::ReadU64Stream(::grpc::ServerContext* context, const ReadU64StreamRequest* request, ReadU64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU64Data* readData = new MonikerU64Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(1);
	    readData->data.mutable_value()->Resize(1, 0);
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
    MonikerU64Data* readData = (MonikerU64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
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

//-----------------------------------------------------------------------------
// Write Scalar Methods
//-----------------------------------------------------------------------------
::grpc::Status NiFpgaService::WriteBoolStream(::grpc::ServerContext* context, const WriteBoolStreamRequest* request, WriteBoolStreamResponse* response)
{
    return ::grpc::Status::OK;
}
::grpc::Status MonikerWriteBoolStream(void* data, google::protobuf::Any& packedData)
{
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteI8Stream(::grpc::ServerContext* context, const WriteI8StreamRequest* request, WriteI8StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerI32Data* writeData = new MonikerI32Data();
        writeData->session = session;
        writeData->item = request->control();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteI8Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteI8Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerI32Data* writeData = (MonikerI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    I32Data i32_data;
    packedData.UnpackTo(&i32_data);
    int32_t value = *(i32_data.value().data());
    if (value < std::numeric_limits<int8_t>::min() || value > std::numeric_limits<int8_t>::max()) {
        std::string message("value " + std::to_string(value) + " doesn't fit in datatype int8_t");
        throw nidevice_grpc::ValueOutOfRangeException(message);
    }

    auto status = library->WriteI8(session, control, static_cast<int8_t>(value));
    if (status < 0) {
        std::cout << "MonikerWriteI8Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteU8Stream(::grpc::ServerContext* context, const WriteU8StreamRequest* request, WriteU8StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU32Data* writeData = new MonikerU32Data();
        writeData->session = session;
        writeData->item = request->control();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteU8Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteU8Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerI32Data* writeData = (MonikerI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    U32Data u32_data;
    packedData.UnpackTo(&u32_data);
    uint32_t value = *(u32_data.value().data());
    if (value < std::numeric_limits<uint8_t>::min() || value > std::numeric_limits<uint8_t>::max()) {
        std::string message("value " + std::to_string(value) + " doesn't fit in datatype uint8_t");
        throw nidevice_grpc::ValueOutOfRangeException(message);
    }

    auto status = library->WriteU8(session, control, static_cast<uint8_t>(value));
    if (status < 0) {
        std::cout << "MonikerWriteU8Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteI16Stream(::grpc::ServerContext* context, const WriteI16StreamRequest* request, WriteI16StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerI32Data* writeData = new MonikerI32Data();
        writeData->session = session;
        writeData->item = request->control();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteI16Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteI16Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerI32Data* writeData = (MonikerI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    I32Data i32_data;
    packedData.UnpackTo(&i32_data);
    int32_t value = *(i32_data.value().data());
    if (value < std::numeric_limits<int16_t>::min() || value > std::numeric_limits<int16_t>::max()) {
        std::string message("value " + std::to_string(value) + " doesn't fit in datatype int16_t");
        throw nidevice_grpc::ValueOutOfRangeException(message);
    }

    auto status = library->WriteI16(session, control, static_cast<int16_t>(value));
    if (status < 0) {
        std::cout << "MonikerWriteI16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteU16Stream(::grpc::ServerContext* context, const WriteU16StreamRequest* request, WriteU16StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU32Data* writeData = new MonikerU32Data();
        writeData->session = session;
        writeData->item = request->control();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteU16Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteU16Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerU32Data* writeData = (MonikerU32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    U32Data u32_data;
    packedData.UnpackTo(&u32_data);
    uint32_t value = *(u32_data.value().data());
    if (value < std::numeric_limits<uint16_t>::min() || value > std::numeric_limits<uint16_t>::max()) {
        std::string message("value " + std::to_string(value) + " doesn't fit in datatype uint16_t");
        throw nidevice_grpc::ValueOutOfRangeException(message);
    }

    auto status = library->WriteU16(session, control, static_cast<uint16_t>(value));
    if (status < 0) {
        std::cout << "MonikerWriteU16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteI32Stream(::grpc::ServerContext* context, const WriteI32StreamRequest* request, WriteI32StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerI32Data* writeData = new MonikerI32Data();
        writeData->session = session;
        writeData->item = request->control();
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
    MonikerI32Data* writeData = (MonikerI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    I32Data i32_data;
    packedData.UnpackTo(&i32_data);
    int32_t value = *(i32_data.value().data());

    auto status = library->WriteI32(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteI32Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteU32Stream(::grpc::ServerContext* context, const WriteU32StreamRequest* request, WriteU32StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU32Data* writeData = new MonikerU32Data();
        writeData->session = session;
        writeData->item = request->control();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteU32Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteU32Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerU32Data* writeData = (MonikerU32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    U32Data u32_data;
    packedData.UnpackTo(&u32_data);
    uint32_t value = *(u32_data.value().data());

    auto status = library->WriteU32(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteU32Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteI64Stream(::grpc::ServerContext* context, const WriteI64StreamRequest* request, WriteI64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerI64Data* writeData = new MonikerI64Data();
        writeData->session = session;
        writeData->item = request->control();
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
    MonikerI64Data* writeData = (MonikerI64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    I64Data i64_data;
    packedData.UnpackTo(&i64_data);
    int64_t value = *(i64_data.value().data());

    auto status = library->WriteI64(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteI64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteU64Stream(::grpc::ServerContext* context, const WriteU64StreamRequest* request, WriteU64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerU64Data* writeData = new MonikerU64Data();
        writeData->session = session;
        writeData->item = request->control();
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
    MonikerU64Data* writeData = (MonikerU64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

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
// Read Array Methods
//-----------------------------------------------------------------------------

struct MonikerArrayI32Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::I32Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerArrayU32Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::U32Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerArrayI64Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::I64Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerArrayU64Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::U64Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::ReadArrayI16Stream(::grpc::ServerContext* context, const ReadArrayI16StreamRequest* request, ReadArrayI16StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerArrayI32Data* readData = new MonikerArrayI32Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(request->size());
	    readData->data.mutable_value()->Resize(request->size(), 0);
        readData->size = request->size();
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadArrayI16Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadArrayI16Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerArrayI32Data* readData = (MonikerArrayI32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    auto size = readData->size;
    std::vector<int16_t> array(size);

    auto status = library->ReadArrayI16(session, indicator, array.data(), size);
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
        std::cout << "MonikerReadArrayI16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::ReadArrayU16Stream(::grpc::ServerContext* context, const ReadArrayU16StreamRequest* request, ReadArrayU16StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerArrayU32Data* readData = new MonikerArrayU32Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(request->size());
	    readData->data.mutable_value()->Resize(request->size(), 0);
        readData->size = request->size();
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadArrayU16Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadArrayU16Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerArrayU32Data* readData = (MonikerArrayU32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    auto size = readData->size;
    std::vector<uint16_t> array(size);

    auto status = library->ReadArrayU16(session, indicator, array.data(), size);
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
        std::cout << "MonikerReadArrayU16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::ReadArrayI64Stream(::grpc::ServerContext* context, const ReadArrayI64StreamRequest* request, ReadArrayI64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerArrayI64Data* readData = new MonikerArrayI64Data();
        readData->session = session;
        readData->item = request->indicator();
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
    MonikerArrayI64Data* readData = (MonikerArrayI64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    auto size = readData->size;
    std::vector<int64_t> array(size);

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

::grpc::Status NiFpgaService::ReadArrayU64Stream(::grpc::ServerContext* context, const ReadArrayU64StreamRequest* request, ReadArrayU64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerArrayU64Data* readData = new MonikerArrayU64Data();
        readData->session = session;
        readData->item = request->indicator();
        readData->data.mutable_value()->Reserve(request->size());
	    readData->data.mutable_value()->Resize(request->size(), 0);
        readData->size = request->size();
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadArrayU64Stream", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadArrayU64Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerArrayU64Data* readData = (MonikerArrayU64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    auto size = readData->size;
    std::vector<uint64_t> array(size);

    auto status = library->ReadArrayU64(session, indicator, array.data(), size);
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
        std::cout << "MonikerReadArrayU64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

//---------------------------------------------------------------------
// Write Array Methods
//---------------------------------------------------------------------
::grpc::Status NiFpgaService::WriteArrayI16Stream(::grpc::ServerContext* context, const WriteArrayI16StreamRequest* request, WriteArrayI16StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerArrayI32Data* writeData = new MonikerArrayI32Data();
        writeData->session = session;
        writeData->item = request->control();
        writeData->size = request->size();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteArrayI16Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteArrayI16Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerArrayI32Data* writeData = (MonikerArrayI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;
    auto size = writeData->size;

    I32Data i32_data;
    packedData.UnpackTo(&i32_data);
    auto i32_array = i32_data.value();
    auto array = std::vector<int16_t>();
    array.reserve(i32_array.size());
    std::transform(
        i32_array.begin(),
        i32_array.end(),
        std::back_inserter(array),
        [](auto x) {
              if (x < std::numeric_limits<int16_t>::min() || x > std::numeric_limits<int16_t>::max()) {
                  std::string message("value " + std::to_string(x) + " doesn't fit in datatype int16_t");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<int16_t>(x);
        });
    auto status = library->WriteArrayI16(session, control, array.data(), size);
    if (status < 0) {
        std::cout << "MonikerWriteArrayI16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteArrayU16Stream(::grpc::ServerContext* context, const WriteArrayU16StreamRequest* request, WriteArrayU16StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerArrayU32Data* writeData = new MonikerArrayU32Data();
        writeData->session = session;
        writeData->item = request->control();
        writeData->size = request->size();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteArrayU16Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteArrayU16Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerArrayU32Data* writeData = (MonikerArrayU32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;
    auto size = writeData->size;

    U32Data u32_data;
    packedData.UnpackTo(&u32_data);
    auto u32_array = u32_data.value();
    auto array = std::vector<uint16_t>();
    array.reserve(u32_array.size());
    std::transform(
        u32_array.begin(),
        u32_array.end(),
        std::back_inserter(array),
        [](auto x) {
              if (x < std::numeric_limits<uint16_t>::min() || x > std::numeric_limits<uint16_t>::max()) {
                  std::string message("value " + std::to_string(x) + " doesn't fit in datatype uint16_t");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<uint16_t>(x);
        });
    auto status = library->WriteArrayU16(session, control, array.data(), size);
    if (status < 0) {
        std::cout << "MonikerWriteArrayU16Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::WriteArrayI64Stream(::grpc::ServerContext* context, const WriteArrayI64StreamRequest* request, WriteArrayI64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerArrayI64Data* writeData = new MonikerArrayI64Data();
        writeData->session = session;
        writeData->item = request->control();
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
    MonikerArrayI64Data* writeData = (MonikerArrayI64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;
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

::grpc::Status NiFpgaService::WriteArrayU64Stream(::grpc::ServerContext* context, const WriteArrayU64StreamRequest* request, WriteArrayU64StreamResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerArrayU64Data* writeData = new MonikerArrayU64Data();
        writeData->session = session;
        writeData->item = request->control();
        writeData->size = request->size();
        writeData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteArrayU64Stream", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteArrayU64Stream(void* data, google::protobuf::Any& packedData)
{
    MonikerArrayU64Data* writeData = (MonikerArrayU64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;
    auto size = writeData->size;

    U64Data u64_data;
    packedData.UnpackTo(&u64_data);
    auto array = const_cast<const uint64_t*>(u64_data.value().data());
    auto status = library->WriteArrayU64(session, control, array, size);
    if (status < 0) {
        std::cout << "MonikerWriteArrayU64Stream error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

}  // namespace nifpga_grpc
