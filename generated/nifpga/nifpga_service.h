
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service header for the NI-FPGA Metadata
//---------------------------------------------------------------------
#ifndef NIFPGA_GRPC_SERVICE_H
#define NIFPGA_GRPC_SERVICE_H

#include <nifpga.grpc.pb.h>
#include <condition_variable>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <map>
#include <server/converters.h>
#include <server/feature_toggles.h>
#include <server/session_resource_repository.h>
#include <server/shared_library.h>
#include <server/exceptions.h>

#include "nifpga_library_interface.h"

namespace nifpga_grpc {

struct NiFpgaFeatureToggles
{
  using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;
  NiFpgaFeatureToggles(const nidevice_grpc::FeatureToggles& feature_toggles = {});

  bool is_enabled;
};

class NiFpgaService final : public NiFpga::Service {
public:
  using ResourceRepositorySharedPtr = std::shared_ptr<nidevice_grpc::SessionResourceRepository<NiFpga_Session>>;

  NiFpgaService(
    NiFpgaLibraryInterface* library,
    ResourceRepositorySharedPtr session_repository,
    const NiFpgaFeatureToggles& feature_toggles = {});
  virtual ~NiFpgaService();
  
  ::grpc::Status Open(::grpc::ServerContext* context, const OpenRequest* request, OpenResponse* response) override;
  ::grpc::Status Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response) override;
  ::grpc::Status Run(::grpc::ServerContext* context, const RunRequest* request, RunResponse* response) override;
  ::grpc::Status Reset(::grpc::ServerContext* context, const ResetRequest* request, ResetResponse* response) override;
  ::grpc::Status Download(::grpc::ServerContext* context, const DownloadRequest* request, DownloadResponse* response) override;
  ::grpc::Status ReadBool(::grpc::ServerContext* context, const ReadBoolRequest* request, ReadBoolResponse* response) override;
  ::grpc::Status ReadI8(::grpc::ServerContext* context, const ReadI8Request* request, ReadI8Response* response) override;
  ::grpc::Status ReadU8(::grpc::ServerContext* context, const ReadU8Request* request, ReadU8Response* response) override;
  ::grpc::Status ReadI16(::grpc::ServerContext* context, const ReadI16Request* request, ReadI16Response* response) override;
  ::grpc::Status ReadU16(::grpc::ServerContext* context, const ReadU16Request* request, ReadU16Response* response) override;
  ::grpc::Status ReadI32(::grpc::ServerContext* context, const ReadI32Request* request, ReadI32Response* response) override;
  ::grpc::Status ReadU32(::grpc::ServerContext* context, const ReadU32Request* request, ReadU32Response* response) override;
  ::grpc::Status ReadI64(::grpc::ServerContext* context, const ReadI64Request* request, ReadI64Response* response) override;
  ::grpc::Status ReadU64(::grpc::ServerContext* context, const ReadU64Request* request, ReadU64Response* response) override;
  ::grpc::Status WriteBool(::grpc::ServerContext* context, const WriteBoolRequest* request, WriteBoolResponse* response) override;
  ::grpc::Status WriteI8(::grpc::ServerContext* context, const WriteI8Request* request, WriteI8Response* response) override;
  ::grpc::Status WriteU8(::grpc::ServerContext* context, const WriteU8Request* request, WriteU8Response* response) override;
  ::grpc::Status WriteI16(::grpc::ServerContext* context, const WriteI16Request* request, WriteI16Response* response) override;
  ::grpc::Status WriteU16(::grpc::ServerContext* context, const WriteU16Request* request, WriteU16Response* response) override;
  ::grpc::Status WriteI32(::grpc::ServerContext* context, const WriteI32Request* request, WriteI32Response* response) override;
  ::grpc::Status WriteU32(::grpc::ServerContext* context, const WriteU32Request* request, WriteU32Response* response) override;
  ::grpc::Status WriteI64(::grpc::ServerContext* context, const WriteI64Request* request, WriteI64Response* response) override;
  ::grpc::Status WriteU64(::grpc::ServerContext* context, const WriteU64Request* request, WriteU64Response* response) override;
  ::grpc::Status ReadArrayI16(::grpc::ServerContext* context, const ReadArrayI16Request* request, ReadArrayI16Response* response) override;
  ::grpc::Status ReadArrayU16(::grpc::ServerContext* context, const ReadArrayU16Request* request, ReadArrayU16Response* response) override;
  ::grpc::Status ReadArrayI64(::grpc::ServerContext* context, const ReadArrayI64Request* request, ReadArrayI64Response* response) override;
  ::grpc::Status ReadArrayU64(::grpc::ServerContext* context, const ReadArrayU64Request* request, ReadArrayU64Response* response) override;
  ::grpc::Status WriteArrayI16(::grpc::ServerContext* context, const WriteArrayI16Request* request, WriteArrayI16Response* response) override;
  ::grpc::Status WriteArrayU16(::grpc::ServerContext* context, const WriteArrayU16Request* request, WriteArrayU16Response* response) override;
  ::grpc::Status WriteArrayI64(::grpc::ServerContext* context, const WriteArrayI64Request* request, WriteArrayI64Response* response) override;
  ::grpc::Status WriteArrayU64(::grpc::ServerContext* context, const WriteArrayU64Request* request, WriteArrayU64Response* response) override;
private:
  NiFpgaLibraryInterface* library_;
  ResourceRepositorySharedPtr session_repository_;
  std::map<std::int32_t, std::int32_t> openattribute_input_map_ { {0, 0},{1, 1},{2, 2},{3, 1073741824},{4, 2147483648}, };
  std::map<std::int32_t, std::int32_t> openattribute_output_map_ { {0, 0},{1, 1},{2, 2},{1073741824, 3},{2147483648, 4}, };

  NiFpgaFeatureToggles feature_toggles_;
};

} // namespace nifpga_grpc

#endif  // NIFPGA_GRPC_SERVICE_H
