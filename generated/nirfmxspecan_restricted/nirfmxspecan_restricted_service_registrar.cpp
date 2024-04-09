
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-RFMXSPECAN-RESTRICTED Metadata
//---------------------------------------------------------------------
#include "nirfmxspecan_restricted_library.h"

#include <grpcpp/server_builder.h>

#include "nirfmxspecan_restricted_service.h"
#include "nirfmxspecan_restricted_service_registrar.h"

namespace nirfmxspecan_restricted_grpc {

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder,
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<niRFmxInstrHandle>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiRFmxSpecAnRestrictedFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library = std::make_shared<NiRFmxSpecAnRestrictedLibrary>();
    auto service = std::make_shared<NiRFmxSpecAnRestrictedService>(
      library,
      resource_repository,
      toggles);
    builder.RegisterService(service.get());
    return service;
  }

  return {};
}

} // nirfmxspecan_restricted_grpc