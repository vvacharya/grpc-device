#include <NiFpga.h>
#include <nifpga.grpc.pb.h>
#include <nifpga/nifpga_service.h>
#include <nifpga/nifpga_library_interface.h>
#include <server/data_moniker_service.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <chrono>




namespace nifpga_grpc {
	
using namespace std;

void RegisterMonikers()
{
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadBool", MonikerReadBool);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI8", MonikerReadI8);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU8", MonikerReadU8);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI16", MonikerReadI16);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU16", MonikerReadU16);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI32", MonikerReadI32);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU32", MonikerReadU32);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadI64", MonikerReadI64);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadU64", MonikerReadU64);

    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteBool", MonikerWriteBool);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI8", MonikerWriteI8);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU8", MonikerWriteU8);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI16", MonikerWriteI16);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU16", MonikerWriteU16);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI32", MonikerWriteI32);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU32", MonikerWriteU32);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteI64", MonikerWriteI64);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteU64", MonikerWriteU64);

    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayI16", MonikerReadArrayI16);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayU16", MonikerReadArrayU16);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayI64", MonikerReadArrayI64);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadArrayU64", MonikerReadArrayU64);

    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayI16", MonikerWriteArrayI16);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayU16", MonikerWriteArrayU16);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayI64", MonikerWriteArrayI64);
    ::ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteArrayU64", MonikerWriteArrayU64);
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

struct MonikerBoolData
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::BoolData data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

//-----------------------------------------------------------------------------
// Read Scalar Methods
//-----------------------------------------------------------------------------
::grpc::Status NiFpgaService::BeginReadBool(::grpc::ServerContext* context, const BeginReadBoolRequest* request, BeginReadBoolResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto session_grpc_session = request->session();
        NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());

        MonikerBoolData* readData = new MonikerBoolData();
        readData->session = session;
        readData->item = request->indicator();
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadBool", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}
::grpc::Status MonikerReadBool(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerBoolData* readData = (MonikerBoolData*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    NiFpga_Bool value = NiFpga_False;

    auto status = library->ReadBool(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadBool error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadI8(::grpc::ServerContext* context, const BeginReadI8Request* request, BeginReadI8Response* response)
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
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadI8", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadI8(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI32Data* readData = (MonikerI32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    int8_t value = 0;

    auto status = library->ReadI8(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadI16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadU8(::grpc::ServerContext* context, const BeginReadU8Request* request, BeginReadU8Response* response)
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
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadU8", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadU8(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerU32Data* readData = (MonikerU32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    uint8_t value = 0;

    auto status = library->ReadU8(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadU8 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadI16(::grpc::ServerContext* context, const BeginReadI16Request* request, BeginReadI16Response* response)
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
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadI16", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadI16(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI32Data* readData = (MonikerI32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    int16_t value = 0;

    auto status = library->ReadI16(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadI16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadU16(::grpc::ServerContext* context, const BeginReadU16Request* request, BeginReadU16Response* response)
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
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadU16", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadU16(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerU32Data* readData = (MonikerU32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    uint16_t value = 0;

    auto status = library->ReadU16(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadU16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadI32(::grpc::ServerContext* context, const BeginReadI32Request* request, BeginReadI32Response* response)
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
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadI32", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadI32(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI32Data* readData = (MonikerI32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    int32_t value = 0;

    auto status = library->ReadI32(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadI32 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadU32(::grpc::ServerContext* context, const BeginReadU32Request* request, BeginReadU32Response* response)
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
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadU32", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadU32(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerU32Data* readData = (MonikerU32Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    uint32_t value = 0;

    auto status = library->ReadU32(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadU32 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadI64(::grpc::ServerContext* context, const BeginReadI64Request* request, BeginReadI64Response* response)
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
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadI64", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadI64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI64Data* readData = (MonikerI64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    int64_t value = 0;

	auto status = library->ReadI64(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadI64 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadU64(::grpc::ServerContext* context, const BeginReadU64Request* request, BeginReadU64Response* response)
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
        readData->library = std::shared_ptr<NiFpgaLibraryInterface>(library_);

        ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadU64", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadU64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerU64Data* readData = (MonikerU64Data*)data;
    auto library = readData->library;
    auto session = readData->session;
    auto indicator = readData->item;
    uint64_t value = 0;

    auto status = library->ReadU64(session, indicator, &value);
    readData->data.set_value(value);
    if (status >= 0) {
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadU64 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

//-----------------------------------------------------------------------------
// Write Scalar Methods
//-----------------------------------------------------------------------------
::grpc::Status NiFpgaService::BeginWriteBool(::grpc::ServerContext* context, const BeginWriteBoolRequest* request, BeginWriteBoolResponse* response)
{
    return ::grpc::Status::OK;
}
::grpc::Status MonikerWriteBool(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteI8(::grpc::ServerContext* context, const BeginWriteI8Request* request, BeginWriteI8Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteI8", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteI8(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI32Data* writeData = (MonikerI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    I32Data i32_data;
    packedData.UnpackTo(&i32_data);
    int32_t value = i32_data.value();
    if (value < std::numeric_limits<int8_t>::min() || value > std::numeric_limits<int8_t>::max()) {
        std::string message("value " + std::to_string(value) + " doesn't fit in datatype int8_t");
        throw nidevice_grpc::ValueOutOfRangeException(message);
    }

    auto status = library->WriteI8(session, control, static_cast<int8_t>(value));
    if (status < 0) {
        std::cout << "MonikerWriteI8 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteU8(::grpc::ServerContext* context, const BeginWriteU8Request* request, BeginWriteU8Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteU8", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteU8(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI32Data* writeData = (MonikerI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    U32Data u32_data;
    packedData.UnpackTo(&u32_data);
    uint32_t value = u32_data.value();
    if (value < std::numeric_limits<uint8_t>::min() || value > std::numeric_limits<uint8_t>::max()) {
        std::string message("value " + std::to_string(value) + " doesn't fit in datatype uint8_t");
        throw nidevice_grpc::ValueOutOfRangeException(message);
    }

    auto status = library->WriteU8(session, control, static_cast<uint8_t>(value));
    if (status < 0) {
        std::cout << "MonikerWriteU8 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteI16(::grpc::ServerContext* context, const BeginWriteI16Request* request, BeginWriteI16Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteI16", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteI16(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI32Data* writeData = (MonikerI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    I32Data i32_data;
    packedData.UnpackTo(&i32_data);
    int32_t value = i32_data.value();
    if (value < std::numeric_limits<int16_t>::min() || value > std::numeric_limits<int16_t>::max()) {
        std::string message("value " + std::to_string(value) + " doesn't fit in datatype int16_t");
        throw nidevice_grpc::ValueOutOfRangeException(message);
    }

    auto status = library->WriteI16(session, control, static_cast<int16_t>(value));
    if (status < 0) {
        std::cout << "MonikerWriteI16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteU16(::grpc::ServerContext* context, const BeginWriteU16Request* request, BeginWriteU16Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteU16", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteU16(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerU32Data* writeData = (MonikerU32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    U32Data u32_data;
    packedData.UnpackTo(&u32_data);
    uint32_t value = u32_data.value();
    if (value < std::numeric_limits<uint16_t>::min() || value > std::numeric_limits<uint16_t>::max()) {
        std::string message("value " + std::to_string(value) + " doesn't fit in datatype uint16_t");
        throw nidevice_grpc::ValueOutOfRangeException(message);
    }

    auto status = library->WriteU16(session, control, static_cast<uint16_t>(value));
    if (status < 0) {
        std::cout << "MonikerWriteU16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteI32(::grpc::ServerContext* context, const BeginWriteI32Request* request, BeginWriteI32Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteI32", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteI32(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI32Data* writeData = (MonikerI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    I32Data i32_data;
    packedData.UnpackTo(&i32_data);
    int32_t value = i32_data.value();

    auto status = library->WriteI32(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteI32 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteU32(::grpc::ServerContext* context, const BeginWriteU32Request* request, BeginWriteU32Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteU32", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteU32(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerU32Data* writeData = (MonikerU32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    U32Data u32_data;
    packedData.UnpackTo(&u32_data);
    uint32_t value = u32_data.value();

    auto status = library->WriteU32(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteU32 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteI64(::grpc::ServerContext* context, const BeginWriteI64Request* request, BeginWriteI64Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteI64", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteI64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerI64Data* writeData = (MonikerI64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    I64Data i64_data;
    packedData.UnpackTo(&i64_data);
    int64_t value = i64_data.value();

    auto status = library->WriteI64(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteI64 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteU64(::grpc::ServerContext* context, const BeginWriteU64Request* request, BeginWriteU64Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteU64", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteU64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerU64Data* writeData = (MonikerU64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;

    U64Data u64_data;
    packedData.UnpackTo(&u64_data);
    uint64_t value = u64_data.value();

    auto status = library->WriteU64(session, control, value);
    if (status < 0) {
        std::cout << "MonikerWriteU64 error: " << status << std::endl;
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
    nifpga_grpc::ArrayI32Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerArrayU32Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::ArrayU32Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerArrayI64Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::ArrayI64Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerArrayU64Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::ArrayU64Data data;
    size_t size;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

::grpc::Status NiFpgaService::BeginReadArrayI16(::grpc::ServerContext* context, const BeginReadArrayI16Request* request, BeginReadArrayI16Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadArrayI16", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadArrayI16(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
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
            readData->data.mutable_value()->begin(),
            [&](auto x) {
                return x;
            });
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadArrayI16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadArrayU16(::grpc::ServerContext* context, const BeginReadArrayU16Request* request, BeginReadArrayU16Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadArrayU16", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadArrayU16(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
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
            readData->data.mutable_value()->begin(),
            [&](auto x) {
                return x;
            });
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadArrayU16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadArrayI64(::grpc::ServerContext* context, const BeginReadArrayI64Request* request, BeginReadArrayI64Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadArrayI64", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadArrayI64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
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
            readData->data.mutable_value()->begin(),
            [&](auto x) {
                return x;
            });
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadArrayI64 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginReadArrayU64(::grpc::ServerContext* context, const BeginReadArrayU64Request* request, BeginReadArrayU64Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadArrayU64", readData, *writeMoniker);

        response->set_allocated_moniker(writeMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerReadArrayU64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
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
            readData->data.mutable_value()->begin(),
            [&](auto x) {
                return x;
            });
        packedData.PackFrom(readData->data);
    }
    else
    {
        std::cout << "MonikerReadArrayU64 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

//---------------------------------------------------------------------
// Write Array Methods
//---------------------------------------------------------------------
::grpc::Status NiFpgaService::BeginWriteArrayI16(::grpc::ServerContext* context, const BeginWriteArrayI16Request* request, BeginWriteArrayI16Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteArrayI16", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteArrayI16(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerArrayI32Data* writeData = (MonikerArrayI32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;
    auto size = writeData->size;

    ArrayI32Data i32_data;
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
        std::cout << "MonikerWriteArrayI16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteArrayU16(::grpc::ServerContext* context, const BeginWriteArrayU16Request* request, BeginWriteArrayU16Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteArrayU16", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteArrayU16(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerArrayU32Data* writeData = (MonikerArrayU32Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;
    auto size = writeData->size;

    ArrayU32Data u32_data;
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
        std::cout << "MonikerWriteArrayU16 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteArrayI64(::grpc::ServerContext* context, const BeginWriteArrayI64Request* request, BeginWriteArrayI64Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteArrayI64", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteArrayI64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
	MonikerArrayI64Data* writeData = (MonikerArrayI64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;
    auto size = writeData->size;
	
    ArrayI64Data i64_data;
    packedData.UnpackTo(&i64_data);
    auto array = const_cast<const int64_t*>(i64_data.value().data());
    auto status = library->WriteArrayI64(session, control, array, size);
    if (status < 0) {
        std::cout << "MonikerWriteArrayI64 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

::grpc::Status NiFpgaService::BeginWriteArrayU64(::grpc::ServerContext* context, const BeginWriteArrayU64Request* request, BeginWriteArrayU64Response* response)
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
        ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteArrayU64", writeData, *readMoniker);

        response->set_allocated_moniker(readMoniker);
        return ::grpc::Status::OK;
    }
    catch (std::exception& ex) {
        return ::grpc::Status(::grpc::UNKNOWN, ex.what());
    }
}

::grpc::Status MonikerWriteArrayU64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
    MonikerArrayU64Data* writeData = (MonikerArrayU64Data*)data;

    auto library = writeData->library;
    auto session = writeData->session;
    auto control = writeData->item;
    auto size = writeData->size;

    ArrayU64Data u64_data;
    packedData.UnpackTo(&u64_data);
    auto array = const_cast<const uint64_t*>(u64_data.value().data());
    auto status = library->WriteArrayU64(session, control, array, size);
    if (status < 0) {
        std::cout << "MonikerWriteArrayU64 error: " << status << std::endl;
    }
    return ::grpc::Status::OK;
}

}  // namespace nifpga_grpc
