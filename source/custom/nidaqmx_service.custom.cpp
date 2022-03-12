#include <nidaqmx/nidaqmx_library.h>
#include <nidaqmx/nidaqmx_service.h>
#include <server/moniker_service.h>
#include <sideband_data.h>
#include <sideband_internal.h>
#include <sideband_grpc.h>

using std::cout;
using std::endl;
using grpc::Status;
namespace nidaqmx_grpc {

//---------------------------------------------------------------------
//---------------------------------------------------------------------
struct MonikerWriteDAQmxData {
 public:
  TaskHandle task;
  int32 numsamples;  // ?
  int32 num_samps_per_chan;
  bool auto_start;
  double timeout;
  int32 data_layout;
  NiDAQmxLibraryInterface* library;
};

//---------------------------------------------------------------------
//---------------------------------------------------------------------
grpc::Status MonikerWriteAnalogF64Stream(void* data, google::protobuf::Any& packedData)
{
  MonikerWriteDAQmxData* writeData = (MonikerWriteDAQmxData*)data;

  int32 samps_per_chan_written;  

  ChannelData channelData;
  packedData.UnpackTo(&channelData);

  const double* values = channelData.data().data();

  // ?
  auto status = writeData->library->WriteAnalogF64(writeData->task, writeData->num_samps_per_chan, writeData->auto_start, writeData->timeout, writeData->data_layout, values, &samps_per_chan_written, nullptr);
  if (status < 0) {
    std ::cout << "DAQmxWriteAnalogF64 error: " << status << endl;
  }
  return grpc::Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// Custom code for BeginWriteAnalogF64Stream
::grpc::Status NiDAQmxService::BeginWriteAnalogF64Stream(::grpc::ServerContext* context, const BeginWriteAnalogF64StreamRequest* request, BeginWriteAnalogF64StreamResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    MonikerWriteDAQmxData* writeData = new MonikerWriteDAQmxData(); 
    auto task_grpc_session = request->task();
    writeData->task = session_repository_->access_session(task_grpc_session.id(), task_grpc_session.name());
    // Retrieved from WriteAnalogF64()
    writeData->num_samps_per_chan = request->num_samps_per_chan();
    writeData->auto_start = request->auto_start();
    writeData->timeout = request->timeout();
   // int32 data_layout;
    switch (request->data_layout_enum_case()) {
      case nidaqmx_grpc::BeginWriteAnalogF64StreamRequest::DataLayoutEnumCase::kDataLayout: {
        writeData->data_layout = static_cast<int32>(request->data_layout());
        break;
      }
      case nidaqmx_grpc::BeginWriteAnalogF64StreamRequest::DataLayoutEnumCase::kDataLayoutRaw: {
        writeData->data_layout = static_cast<int32>(request->data_layout_raw());
        break;
      }
      case nidaqmx_grpc::BeginWriteAnalogF64StreamRequest::DataLayoutEnumCase::DATA_LAYOUT_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for data_layout was not specified or out of range");
        break;
      }
    }

    // Register stream 

    writeData->library = library_;
    ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
    ni::MonikerServiceImpl::RegisterMonikerInstance("MonikerWriteAnalogF64Stream", writeData, *writeMoniker);
    response->set_allocated_moniker(writeMoniker);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

void NiDAQmxService::initialize()
{
  ni::MonikerServiceImpl::RegisterMonikerEndpoint("MonikerWriteAnalogF64Stream", MonikerWriteAnalogF64Stream);
  // ni::MonikerServiceImpl::RegisterMonikerEndpoint("MonikerReadAnalogF64Stream", MonikerReadAnalogF64Stream);
}

}



