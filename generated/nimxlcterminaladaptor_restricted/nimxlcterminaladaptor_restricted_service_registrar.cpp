
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-MXLCTERMINALADAPTOR-RESTRICTED Metadata
//---------------------------------------------------------------------
#include "nimxlcterminaladaptor_restricted_library.h"

#include <grpcpp/server_builder.h>

#include "nimxlcterminaladaptor_restricted_service.h"
#include "nimxlcterminaladaptor_restricted_service_registrar.h"

namespace nimxlcterminaladaptor_restricted_grpc {

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder,
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<nimxlc_Session>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NimxlcTerminalAdaptorRestrictedFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library = std::make_shared<NimxlcTerminalAdaptorRestrictedLibrary>();
    auto service = std::make_shared<NimxlcTerminalAdaptorRestrictedService>(
      library,
      resource_repository,
      toggles);
    builder.RegisterService(service.get());
    return service;
  }

  return {};
}

} // nimxlcterminaladaptor_restricted_grpc