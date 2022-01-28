
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-RFMXLTE.
//---------------------------------------------------------------------
#ifndef NIRFMXLTE_GRPC_CLIENT_H
#define NIRFMXLTE_GRPC_CLIENT_H

#include <grpcpp/grpcpp.h>

#include <nirfmxlte.grpc.pb.h>
#include <tests/utilities/client_helpers.h>

#include <memory>
#include <vector>

namespace nirfmxlte_grpc::experimental::client {

namespace pb = ::google::protobuf;
using StubPtr = std::unique_ptr<NiRFmxLTE::Stub>;
using namespace nidevice_grpc::experimental::client;


CloseResponse close(const StubPtr& stub, const nidevice_grpc::Session& instrument, const simple_variant<Boolean, pb::int32>& force_destroy);
InitializeResponse initialize(const StubPtr& stub, const pb::string& resource_name, const pb::string& option_string);

} // namespace nirfmxlte_grpc::experimental::client

#endif /* NIRFMXLTE_GRPC_CLIENT_H */