
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the niFake Metadata
//---------------------------------------------------------------------
#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <nifake_service.h>
#include <atomic>

namespace ni
{
namespace fake
{
namespace grpc
{
  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  using internal = ni::hardware::grpc::internal;
  using niFake_AbortPtr = int (*)(std::uint64_t);
  using niFake_EnumInputFunctionWithDefaultsPtr = int (*)(std::uint64_t, std::uint32_t);
  using niFake_GetABooleanPtr = int (*)(std::uint64_t, bool*);
  using niFake_GetANumberPtr = int (*)(std::uint64_t, std::uint32_t*);
  using niFake_GetArraySizeForPythonCodePtr = int (*)(std::uint64_t, std::int32_t*);
  using niFake_GetAttributeViBooleanPtr = int (*)(std::uint64_t, std::string, NiFakeAttributes, bool*);
  using niFake_GetAttributeViInt32Ptr = int (*)(std::uint64_t, std::string, NiFakeAttributes, std::int32_t*);
  using niFake_GetAttributeViInt64Ptr = int (*)(std::uint64_t, std::string, NiFakeAttributes, std::int64_t*);
  using niFake_GetAttributeViReal64Ptr = int (*)(std::uint64_t, std::string, NiFakeAttributes, double*);
  using niFake_GetCalDateAndTimePtr = int (*)(std::uint64_t, std::int32_t, std::int32_t*, std::int32_t*, std::int32_t*, std::int32_t*, std::int32_t*);
  using niFake_GetCalIntervalPtr = int (*)(std::uint64_t, std::int32_t*);
  using niFake_GetCustomTypePtr = int (*)(std::uint64_t, std::uint64_t*);
  using niFake_GetEnumValuePtr = int (*)(std::uint64_t, std::int32_t*, std::uint32_t*);
  using niFake_GetLastCalDateAndTimePtr = int (*)(std::uint64_t, std::int32_t, google.protobuf.Timestamp*);
  using niFake_InitWithOptionsPtr = int (*)(std::string, bool, bool, std::string, std::uint64_t*);
  using niFake_InitiatePtr = int (*)(std::uint64_t);
  using niFake_LockSessionPtr = int (*)(std::uint64_t, bool*);
  using niFake_OneInputFunctionPtr = int (*)(std::uint64_t, std::int32_t);
  using niFake_ParametersAreMultipleTypesPtr = int (*)(std::uint64_t, bool, std::int32_t, std::int64_t, std::uint32_t, double, double, std::int32_t, std::string);
  using niFake_PoorlyNamedSimpleFunctionPtr = int (*)(std::uint64_t);
  using niFake_ReadPtr = int (*)(std::uint64_t, double, double*);
  using niFake_ReadFromChannelPtr = int (*)(std::uint64_t, std::string, std::int32_t, double*);
  using niFake_ReturnDurationInSecondsPtr = int (*)(std::uint64_t, double*);
  using niFake_SetAttributeViBooleanPtr = int (*)(std::uint64_t, std::string, NiFakeAttributes, bool);
  using niFake_SetAttributeViInt32Ptr = int (*)(std::uint64_t, std::string, NiFakeAttributes, std::int32_t);
  using niFake_SetAttributeViInt64Ptr = int (*)(std::uint64_t, std::string, NiFakeAttributes, std::int64_t);
  using niFake_SetAttributeViReal64Ptr = int (*)(std::uint64_t, std::string, NiFakeAttributes, double);
  using niFake_SetAttributeViStringPtr = int (*)(std::uint64_t, std::string, NiFakeAttributes, std::string);
  using niFake_SetCustomTypePtr = int (*)(std::uint64_t, std::uint64_t);
  using niFake_StringValuedEnumInputFunctionWithDefaultsPtr = int (*)(std::uint64_t, std::string);
  using niFake_TwoInputFunctionPtr = int (*)(std::uint64_t, double, std::string);
  using niFake_UnlockSessionPtr = int (*)(std::uint64_t, bool*);
  using niFake_Use64BitNumberPtr = int (*)(std::uint64_t, std::int64_t, std::int64_t*);
  using niFake_closePtr = int (*)(std::uint64_t);
  using niFake_fancy_self_testPtr = int (*)(std::uint64_t);

  #if defined(_MSC_VER)
    static const char* driver_api_library_name = "nifake_64.dll";
  #else
    static const char* driver_api_library_name = "./nifake.so";
  #endif

  NiFakeService::NiFakeService(internal::SharedLibrary* shared_library, internal::SessionRepository* session_repository)
      : shared_library_(shared_library), session_repository_(session_repository) 
  {
    shared_library_->set_library_name(driver_api_library_name);
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::Abort(grpc::ServerContext* context, const AbortRequest* request, AbortResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto abort_function = reinterpret_cast<niFake_AbortPtr>(shared_library_->get_function_pointer("niFake_Abort"));
    if (abort_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_Abort");
    }

    std::uint64_t vi = request->vi());
    auto status = abort_function(vi);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::AcceptListOfDurationsInSeconds(grpc::ServerContext* context, const AcceptListOfDurationsInSecondsRequest* request, AcceptListOfDurationsInSecondsResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::BoolArrayOutputFunction(grpc::ServerContext* context, const BoolArrayOutputFunctionRequest* request, BoolArrayOutputFunctionResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::DoubleAllTheNums(grpc::ServerContext* context, const DoubleAllTheNumsRequest* request, DoubleAllTheNumsResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::EnumArrayOutputFunction(grpc::ServerContext* context, const EnumArrayOutputFunctionRequest* request, EnumArrayOutputFunctionResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::EnumInputFunctionWithDefaults(grpc::ServerContext* context, const EnumInputFunctionWithDefaultsRequest* request, EnumInputFunctionWithDefaultsResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto enum_input_function_with_defaults_function = reinterpret_cast<niFake_EnumInputFunctionWithDefaultsPtr>(shared_library_->get_function_pointer("niFake_EnumInputFunctionWithDefaults"));
    if (enum_input_function_with_defaults_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_EnumInputFunctionWithDefaults");
    }

    std::uint64_t vi = request->vi());
    std::uint32_t a_turtle = request->a_turtle();
    auto status = enum_input_function_with_defaults_function(vi, a_turtle);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ExportAttributeConfigurationBuffer(grpc::ServerContext* context, const ExportAttributeConfigurationBufferRequest* request, ExportAttributeConfigurationBufferResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::FetchWaveform(grpc::ServerContext* context, const FetchWaveformRequest* request, FetchWaveformResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetABoolean(grpc::ServerContext* context, const GetABooleanRequest* request, GetABooleanResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto get_a_boolean_function = reinterpret_cast<niFake_GetABooleanPtr>(shared_library_->get_function_pointer("niFake_GetABoolean"));
    if (get_a_boolean_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetABoolean");
    }

    std::uint64_t vi = request->vi());
    bool a_boolean;
    auto status = get_a_boolean_function(vi, &a_boolean);
    response->set_status(status);
    if (status == 0) {
      response->set_a_boolean(a_boolean);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetANumber(grpc::ServerContext* context, const GetANumberRequest* request, GetANumberResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto get_a_number_function = reinterpret_cast<niFake_GetANumberPtr>(shared_library_->get_function_pointer("niFake_GetANumber"));
    if (get_a_number_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetANumber");
    }

    std::uint64_t vi = request->vi());
    std::uint32_t a_number;
    auto status = get_a_number_function(vi, &a_number);
    response->set_status(status);
    if (status == 0) {
      response->set_a_number(a_number);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetAStringOfFixedMaximumSize(grpc::ServerContext* context, const GetAStringOfFixedMaximumSizeRequest* request, GetAStringOfFixedMaximumSizeResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetAStringUsingPythonCode(grpc::ServerContext* context, const GetAStringUsingPythonCodeRequest* request, GetAStringUsingPythonCodeResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetAnIviDanceString(grpc::ServerContext* context, const GetAnIviDanceStringRequest* request, GetAnIviDanceStringResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetAnIviDanceWithATwistString(grpc::ServerContext* context, const GetAnIviDanceWithATwistStringRequest* request, GetAnIviDanceWithATwistStringResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetArrayForPythonCodeCustomType(grpc::ServerContext* context, const GetArrayForPythonCodeCustomTypeRequest* request, GetArrayForPythonCodeCustomTypeResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetArrayForPythonCodeDouble(grpc::ServerContext* context, const GetArrayForPythonCodeDoubleRequest* request, GetArrayForPythonCodeDoubleResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetArraySizeForPythonCode(grpc::ServerContext* context, const GetArraySizeForPythonCodeRequest* request, GetArraySizeForPythonCodeResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto get_array_size_for_python_code_function = reinterpret_cast<niFake_GetArraySizeForPythonCodePtr>(shared_library_->get_function_pointer("niFake_GetArraySizeForPythonCode"));
    if (get_array_size_for_python_code_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetArraySizeForPythonCode");
    }

    std::uint64_t vi = request->vi());
    std::int32_t size_out;
    auto status = get_array_size_for_python_code_function(vi, &size_out);
    response->set_status(status);
    if (status == 0) {
      response->set_size_out(size_out);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetArrayUsingIviDance(grpc::ServerContext* context, const GetArrayUsingIviDanceRequest* request, GetArrayUsingIviDanceResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetCalInterval(grpc::ServerContext* context, const GetCalIntervalRequest* request, GetCalIntervalResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto get_cal_interval_function = reinterpret_cast<niFake_GetCalIntervalPtr>(shared_library_->get_function_pointer("niFake_GetCalInterval"));
    if (get_cal_interval_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetCalInterval");
    }

    std::uint64_t vi = request->vi());
    std::int32_t months;
    auto status = get_cal_interval_function(vi, &months);
    response->set_status(status);
    if (status == 0) {
      response->set_months(months);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetCustomType(grpc::ServerContext* context, const GetCustomTypeRequest* request, GetCustomTypeResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto get_custom_type_function = reinterpret_cast<niFake_GetCustomTypePtr>(shared_library_->get_function_pointer("niFake_GetCustomType"));
    if (get_custom_type_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetCustomType");
    }

    std::uint64_t vi = request->vi());
    std::uint64_t cs;
    auto status = get_custom_type_function(vi, &cs);
    response->set_status(status);
    if (status == 0) {
      response->set_cs(cs);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetCustomTypeArray(grpc::ServerContext* context, const GetCustomTypeArrayRequest* request, GetCustomTypeArrayResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetEnumValue(grpc::ServerContext* context, const GetEnumValueRequest* request, GetEnumValueResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto get_enum_value_function = reinterpret_cast<niFake_GetEnumValuePtr>(shared_library_->get_function_pointer("niFake_GetEnumValue"));
    if (get_enum_value_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetEnumValue");
    }

    std::uint64_t vi = request->vi());
    std::int32_t a_quantity;
    std::uint32_t a_turtle;
    auto status = get_enum_value_function(vi, &a_quantity, &a_turtle);
    response->set_status(status);
    if (status == 0) {
      response->set_a_quantity(a_quantity);
      response->set_a_turtle(a_turtle);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ImportAttributeConfigurationBuffer(grpc::ServerContext* context, const ImportAttributeConfigurationBufferRequest* request, ImportAttributeConfigurationBufferResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::LockSession(grpc::ServerContext* context, const LockSessionRequest* request, LockSessionResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto lock_session_function = reinterpret_cast<niFake_LockSessionPtr>(shared_library_->get_function_pointer("niFake_LockSession"));
    if (lock_session_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_LockSession");
    }

    std::uint64_t vi = request->vi());
    bool caller_has_lock;
    auto status = lock_session_function(vi, &caller_has_lock);
    response->set_status(status);
    if (status == 0) {
      response->set_caller_has_lock(caller_has_lock);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::MultipleArrayTypes(grpc::ServerContext* context, const MultipleArrayTypesRequest* request, MultipleArrayTypesResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::MultipleArraysSameSize(grpc::ServerContext* context, const MultipleArraysSameSizeRequest* request, MultipleArraysSameSizeResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::OneInputFunction(grpc::ServerContext* context, const OneInputFunctionRequest* request, OneInputFunctionResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto one_input_function_function = reinterpret_cast<niFake_OneInputFunctionPtr>(shared_library_->get_function_pointer("niFake_OneInputFunction"));
    if (one_input_function_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_OneInputFunction");
    }

    std::uint64_t vi = request->vi());
    std::int32_t a_number = request->a_number();
    auto status = one_input_function_function(vi, a_number);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ParametersAreMultipleTypes(grpc::ServerContext* context, const ParametersAreMultipleTypesRequest* request, ParametersAreMultipleTypesResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto parameters_are_multiple_types_function = reinterpret_cast<niFake_ParametersAreMultipleTypesPtr>(shared_library_->get_function_pointer("niFake_ParametersAreMultipleTypes"));
    if (parameters_are_multiple_types_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_ParametersAreMultipleTypes");
    }

    std::uint64_t vi = request->vi());
    bool a_boolean = request->a_boolean();
    std::int32_t an_int32 = request->an_int32();
    std::int64_t an_int64 = request->an_int64();
    std::uint32_t an_int_enum = request->an_int_enum();
    double a_float = request->a_float();
    double a_float_enum = request->a_float_enum();
    std::int32_t string_size = request->string_size();
    std::string a_string = request->a_string().c_str();
    auto status = parameters_are_multiple_types_function(vi, a_boolean, an_int32, an_int64, an_int_enum, a_float, a_float_enum, string_size, a_string);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::PoorlyNamedSimpleFunction(grpc::ServerContext* context, const PoorlyNamedSimpleFunctionRequest* request, PoorlyNamedSimpleFunctionResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto poorly_named_simple_function_function = reinterpret_cast<niFake_PoorlyNamedSimpleFunctionPtr>(shared_library_->get_function_pointer("niFake_PoorlyNamedSimpleFunction"));
    if (poorly_named_simple_function_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_PoorlyNamedSimpleFunction");
    }

    std::uint64_t vi = request->vi());
    auto status = poorly_named_simple_function_function(vi);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::Read(grpc::ServerContext* context, const ReadRequest* request, ReadResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto read_function = reinterpret_cast<niFake_ReadPtr>(shared_library_->get_function_pointer("niFake_Read"));
    if (read_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_Read");
    }

    std::uint64_t vi = request->vi());
    double maximum_time = request->maximum_time();
    double reading;
    auto status = read_function(vi, maximum_time, &reading);
    response->set_status(status);
    if (status == 0) {
      response->set_reading(reading);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReadFromChannel(grpc::ServerContext* context, const ReadFromChannelRequest* request, ReadFromChannelResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto read_from_channel_function = reinterpret_cast<niFake_ReadFromChannelPtr>(shared_library_->get_function_pointer("niFake_ReadFromChannel"));
    if (read_from_channel_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_ReadFromChannel");
    }

    std::uint64_t vi = request->vi());
    std::string channel_name = request->channel_name().c_str();
    std::int32_t maximum_time = request->maximum_time();
    double reading;
    auto status = read_from_channel_function(vi, channel_name, maximum_time, &reading);
    response->set_status(status);
    if (status == 0) {
      response->set_reading(reading);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReturnANumberAndAString(grpc::ServerContext* context, const ReturnANumberAndAStringRequest* request, ReturnANumberAndAStringResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReturnDurationInSeconds(grpc::ServerContext* context, const ReturnDurationInSecondsRequest* request, ReturnDurationInSecondsResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto return_duration_in_seconds_function = reinterpret_cast<niFake_ReturnDurationInSecondsPtr>(shared_library_->get_function_pointer("niFake_ReturnDurationInSeconds"));
    if (return_duration_in_seconds_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_ReturnDurationInSeconds");
    }

    std::uint64_t vi = request->vi());
    double timedelta;
    auto status = return_duration_in_seconds_function(vi, &timedelta);
    response->set_status(status);
    if (status == 0) {
      response->set_timedelta(timedelta);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReturnListOfDurationsInSeconds(grpc::ServerContext* context, const ReturnListOfDurationsInSecondsRequest* request, ReturnListOfDurationsInSecondsResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReturnMultipleTypes(grpc::ServerContext* context, const ReturnMultipleTypesRequest* request, ReturnMultipleTypesResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::SetCustomType(grpc::ServerContext* context, const SetCustomTypeRequest* request, SetCustomTypeResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto set_custom_type_function = reinterpret_cast<niFake_SetCustomTypePtr>(shared_library_->get_function_pointer("niFake_SetCustomType"));
    if (set_custom_type_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_SetCustomType");
    }

    std::uint64_t vi = request->vi());
    std::uint64_t cs = request->cs();
    auto status = set_custom_type_function(vi, cs);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::SetCustomTypeArray(grpc::ServerContext* context, const SetCustomTypeArrayRequest* request, SetCustomTypeArrayResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::StringValuedEnumInputFunctionWithDefaults(grpc::ServerContext* context, const StringValuedEnumInputFunctionWithDefaultsRequest* request, StringValuedEnumInputFunctionWithDefaultsResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto string_valued_enum_input_function_with_defaults_function = reinterpret_cast<niFake_StringValuedEnumInputFunctionWithDefaultsPtr>(shared_library_->get_function_pointer("niFake_StringValuedEnumInputFunctionWithDefaults"));
    if (string_valued_enum_input_function_with_defaults_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_StringValuedEnumInputFunctionWithDefaults");
    }

    std::uint64_t vi = request->vi());
    std::string a_mobile_o_s_name = request->a_mobile_o_s_name().c_str();
    auto status = string_valued_enum_input_function_with_defaults_function(vi, a_mobile_o_s_name);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::TwoInputFunction(grpc::ServerContext* context, const TwoInputFunctionRequest* request, TwoInputFunctionResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto two_input_function_function = reinterpret_cast<niFake_TwoInputFunctionPtr>(shared_library_->get_function_pointer("niFake_TwoInputFunction"));
    if (two_input_function_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_TwoInputFunction");
    }

    std::uint64_t vi = request->vi());
    double a_number = request->a_number();
    std::string a_string = request->a_string();
    auto status = two_input_function_function(vi, a_number, a_string);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::UnlockSession(grpc::ServerContext* context, const UnlockSessionRequest* request, UnlockSessionResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto unlock_session_function = reinterpret_cast<niFake_UnlockSessionPtr>(shared_library_->get_function_pointer("niFake_UnlockSession"));
    if (unlock_session_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_UnlockSession");
    }

    std::uint64_t vi = request->vi());
    bool caller_has_lock;
    auto status = unlock_session_function(vi, &caller_has_lock);
    response->set_status(status);
    if (status == 0) {
      response->set_caller_has_lock(caller_has_lock);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::Use64BitNumber(grpc::ServerContext* context, const Use64BitNumberRequest* request, Use64BitNumberResponse* response)
  {
    shared_library_->load();
    if (!shared_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto use64_bit_number_function = reinterpret_cast<niFake_Use64BitNumberPtr>(shared_library_->get_function_pointer("niFake_Use64BitNumber"));
    if (use64_bit_number_function == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_Use64BitNumber");
    }

    std::uint64_t vi = request->vi());
    std::int64_t input = request->input();
    std::int64_t output;
    auto status = use64_bit_number_function(vi, input, &output);
    response->set_status(status);
    if (status == 0) {
      response->set_output(output);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::WriteWaveform(grpc::ServerContext* context, const WriteWaveformRequest* request, WriteWaveformResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

} // namespace grpc
} // namespace fake
} // namespace ni