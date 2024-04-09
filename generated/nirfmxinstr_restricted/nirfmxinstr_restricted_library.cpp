//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-RFMXINSTR-RESTRICTED Metadata
//---------------------------------------------------------------------
#include "nirfmxinstr_restricted_library.h"
#include <server/shared_library.h>

#include <memory>

#if defined(_MSC_VER)
static const char* kLibraryName = "niRFmxInstr.dll";
#else
static const char* kLibraryName = "libnirfmxinstr.so.1";
#endif

namespace nirfmxinstr_restricted_grpc {

NiRFmxInstrRestrictedLibrary::NiRFmxInstrRestrictedLibrary() : NiRFmxInstrRestrictedLibrary(std::make_shared<nidevice_grpc::SharedLibrary>()) {}

NiRFmxInstrRestrictedLibrary::NiRFmxInstrRestrictedLibrary(std::shared_ptr<nidevice_grpc::SharedLibraryInterface> shared_library) : shared_library_(shared_library)
{
  shared_library_->set_library_name(kLibraryName);
  shared_library_->load();
  bool loaded = shared_library_->is_loaded();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!loaded) {
    return;
  }
  function_pointers_.ConvertForPowerUnitsUtility = reinterpret_cast<ConvertForPowerUnitsUtilityPtr>(shared_library_->get_function_pointer("RFmxInstr_ConvertForPowerUnitsUtility"));
  function_pointers_.DeleteSnapshot = reinterpret_cast<DeleteSnapshotPtr>(shared_library_->get_function_pointer("RFmxInstr_DeleteSnapshot"));
  function_pointers_.GetActiveResultName = reinterpret_cast<GetActiveResultNamePtr>(shared_library_->get_function_pointer("RFmxInstr_GetActiveResultName"));
  function_pointers_.GetActiveTableName = reinterpret_cast<GetActiveTableNamePtr>(shared_library_->get_function_pointer("RFmxInstr_GetActiveTableName"));
  function_pointers_.GetAttributeAuthor = reinterpret_cast<GetAttributeAuthorPtr>(shared_library_->get_function_pointer("RFmxInstr_GetAttributeAuthor"));
  function_pointers_.GetAttributeDesiredF32 = reinterpret_cast<GetAttributeDesiredF32Ptr>(shared_library_->get_function_pointer("RFmxInstr_GetAttributeDesiredF32"));
  function_pointers_.GetAttributeDesiredF32Array = reinterpret_cast<GetAttributeDesiredF32ArrayPtr>(shared_library_->get_function_pointer("RFmxInstr_GetAttributeDesiredF32Array"));
  function_pointers_.GetAttributeDesiredF64 = reinterpret_cast<GetAttributeDesiredF64Ptr>(shared_library_->get_function_pointer("RFmxInstr_GetAttributeDesiredF64"));
  function_pointers_.GetAttributeDesiredF64Array = reinterpret_cast<GetAttributeDesiredF64ArrayPtr>(shared_library_->get_function_pointer("RFmxInstr_GetAttributeDesiredF64Array"));
  function_pointers_.GetAttributeDesiredI32 = reinterpret_cast<GetAttributeDesiredI32Ptr>(shared_library_->get_function_pointer("RFmxInstr_GetAttributeDesiredI32"));
  function_pointers_.GetAttributeDesiredI64 = reinterpret_cast<GetAttributeDesiredI64Ptr>(shared_library_->get_function_pointer("RFmxInstr_GetAttributeDesiredI64"));
  function_pointers_.GetAttributeDesiredString = reinterpret_cast<GetAttributeDesiredStringPtr>(shared_library_->get_function_pointer("RFmxInstr_GetAttributeDesiredString"));
  function_pointers_.GetCalibrationPlaneEnabled = reinterpret_cast<GetCalibrationPlaneEnabledPtr>(shared_library_->get_function_pointer("RFmxInstr_GetCalibrationPlaneEnabled"));
  function_pointers_.GetCalibrationPlaneNames = reinterpret_cast<GetCalibrationPlaneNamesPtr>(shared_library_->get_function_pointer("RFmxInstr_GetCalibrationPlaneNames"));
  function_pointers_.GetError = reinterpret_cast<GetErrorPtr>(shared_library_->get_function_pointer("RFmxInstr_GetError"));
  function_pointers_.GetErrorString = reinterpret_cast<GetErrorStringPtr>(shared_library_->get_function_pointer("RFmxInstr_GetErrorString"));
  function_pointers_.GetExternalAttenuationTableNames = reinterpret_cast<GetExternalAttenuationTableNamesPtr>(shared_library_->get_function_pointer("RFmxInstr_GetExternalAttenuationTableNames"));
  function_pointers_.GetForceAllTracesEnabled = reinterpret_cast<GetForceAllTracesEnabledPtr>(shared_library_->get_function_pointer("RFmxInstr_GetForceAllTracesEnabled"));
  function_pointers_.GetInitiaitedSnapshotStrings = reinterpret_cast<GetInitiaitedSnapshotStringsPtr>(shared_library_->get_function_pointer("RFmxInstr_GetInitiaitedSnapshotStrings"));
  function_pointers_.GetLatestConfigurationSnapshot = reinterpret_cast<GetLatestConfigurationSnapshotPtr>(shared_library_->get_function_pointer("RFmxInstr_GetLatestConfigurationSnapshot"));
  function_pointers_.GetOpenSessionsInformation = reinterpret_cast<GetOpenSessionsInformationPtr>(shared_library_->get_function_pointer("RFmxInstr_GetOpenSessionsInformation"));
  function_pointers_.GetPrivilegeLevel = reinterpret_cast<GetPrivilegeLevelPtr>(shared_library_->get_function_pointer("RFmxInstr_GetPrivilegeLevel"));
  function_pointers_.GetRFmxVersion = reinterpret_cast<GetRFmxVersionPtr>(shared_library_->get_function_pointer("RFmxInstr_GetRFmxVersion"));
  function_pointers_.GetSessionUniqueIdentifier = reinterpret_cast<GetSessionUniqueIdentifierPtr>(shared_library_->get_function_pointer("RFmxInstr_GetSessionUniqueIdentifier"));
  function_pointers_.GetSignalConfigurationState64 = reinterpret_cast<GetSignalConfigurationState64Ptr>(shared_library_->get_function_pointer("RFmxInstr_GetSignalConfigurationState64"));
  function_pointers_.GetSnapshotInfoFromCache = reinterpret_cast<GetSnapshotInfoFromCachePtr>(shared_library_->get_function_pointer("RFmxInstr_GetSnapshotInfoFromCache"));
  function_pointers_.GetSnapshotState = reinterpret_cast<GetSnapshotStatePtr>(shared_library_->get_function_pointer("RFmxInstr_GetSnapshotState"));
  function_pointers_.GetTracesInfoForMonitorSnapshot = reinterpret_cast<GetTracesInfoForMonitorSnapshotPtr>(shared_library_->get_function_pointer("RFmxInstr_GetTracesInfoForMonitorSnapshot"));
  function_pointers_.LoadAllForRevert = reinterpret_cast<LoadAllForRevertPtr>(shared_library_->get_function_pointer("RFmxInstr_LoadAllForRevert"));
  function_pointers_.LoadConfigurationsFromJSON = reinterpret_cast<LoadConfigurationsFromJSONPtr>(shared_library_->get_function_pointer("RFmxInstr_LoadConfigurationsFromJSON"));
  function_pointers_.RegisterSpecialClientSnapshotInterest = reinterpret_cast<RegisterSpecialClientSnapshotInterestPtr>(shared_library_->get_function_pointer("RFmxInstr_RegisterSpecialClientSnapshotInterest"));
  function_pointers_.RequestPrivilege = reinterpret_cast<RequestPrivilegePtr>(shared_library_->get_function_pointer("RFmxInstr_RequestPrivilege"));
  function_pointers_.SaveAllForRevert = reinterpret_cast<SaveAllForRevertPtr>(shared_library_->get_function_pointer("RFmxInstr_SaveAllForRevert"));
  function_pointers_.SaveConfigurationsToJSON = reinterpret_cast<SaveConfigurationsToJSONPtr>(shared_library_->get_function_pointer("RFmxInstr_SaveConfigurationsToJSON"));
  function_pointers_.SetForceAllTracesEnabled = reinterpret_cast<SetForceAllTracesEnabledPtr>(shared_library_->get_function_pointer("RFmxInstr_SetForceAllTracesEnabled"));
  function_pointers_.SetIOTraceStatus = reinterpret_cast<SetIOTraceStatusPtr>(shared_library_->get_function_pointer("RFmxInstr_SetIOTraceStatus"));
  function_pointers_.UnregisterSpecialClientSnapshotInterest = reinterpret_cast<UnregisterSpecialClientSnapshotInterestPtr>(shared_library_->get_function_pointer("RFmxInstr_UnregisterSpecialClientSnapshotInterest"));
  function_pointers_.GetSFPSessionAccessEnabled = reinterpret_cast<GetSFPSessionAccessEnabledPtr>(shared_library_->get_function_pointer("RFmxInstr_GetSFPSessionAccessEnabled"));
  function_pointers_.CreateDefaultSignalConfiguration = reinterpret_cast<CreateDefaultSignalConfigurationPtr>(shared_library_->get_function_pointer("RFmxInstr_CreateDefaultSignalConfiguration"));
  function_pointers_.LoadExternalAttenuationTable = reinterpret_cast<LoadExternalAttenuationTablePtr>(shared_library_->get_function_pointer("RFmxInstr_LoadExternalAttenuationTable"));
  function_pointers_.DefineExternalAttenuationTable = reinterpret_cast<DefineExternalAttenuationTablePtr>(shared_library_->get_function_pointer("RFmxInstr_DefineExternalAttenuationTable"));
  function_pointers_.CfgSParameterExternalAttenuationTableFrequencies = reinterpret_cast<CfgSParameterExternalAttenuationTableFrequenciesPtr>(shared_library_->get_function_pointer("RFmxInstr_CfgSParameterExternalAttenuationTableFrequencies"));
  function_pointers_.CfgSParameterExternalAttenuationTableSParameter = reinterpret_cast<CfgSParameterExternalAttenuationTableSParameterPtr>(shared_library_->get_function_pointer("RFmxInstr_CfgSParameterExternalAttenuationTableSParameter"));
  function_pointers_.DefineSParameterExternalAttenuationTable = reinterpret_cast<DefineSParameterExternalAttenuationTablePtr>(shared_library_->get_function_pointer("RFmxInstr_DefineSParameterExternalAttenuationTable"));
}

NiRFmxInstrRestrictedLibrary::~NiRFmxInstrRestrictedLibrary()
{
}

::grpc::Status NiRFmxInstrRestrictedLibrary::check_function_exists(std::string functionName)
{
  return shared_library_->function_exists(functionName.c_str())
    ? ::grpc::Status::OK
    : ::grpc::Status(::grpc::NOT_FOUND, "Could not find the function " + functionName);
}

int32 NiRFmxInstrRestrictedLibrary::ConvertForPowerUnitsUtility(niRFmxInstrHandle instrumentHandle, float64 referenceOrTriggerLevelIn, int32 inputPowerUnits, int32 outputPowerUnits, int32 terminalConfiguration, float64 bandwidth, float64* referenceOrTriggerLevelOut)
{
  if (!function_pointers_.ConvertForPowerUnitsUtility) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_ConvertForPowerUnitsUtility.");
  }
  return function_pointers_.ConvertForPowerUnitsUtility(instrumentHandle, referenceOrTriggerLevelIn, inputPowerUnits, outputPowerUnits, terminalConfiguration, bandwidth, referenceOrTriggerLevelOut);
}

int32 NiRFmxInstrRestrictedLibrary::DeleteSnapshot(niRFmxInstrHandle instrumentHandle, int32 personality, char selectorString[])
{
  if (!function_pointers_.DeleteSnapshot) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_DeleteSnapshot.");
  }
  return function_pointers_.DeleteSnapshot(instrumentHandle, personality, selectorString);
}

int32 NiRFmxInstrRestrictedLibrary::GetActiveResultName(niRFmxInstrHandle instrumentHandle, char signalName[], uInt32 signalType, int32 resultSize, char resultName[], int32* actualResultSize, int32* resultState)
{
  if (!function_pointers_.GetActiveResultName) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetActiveResultName.");
  }
  return function_pointers_.GetActiveResultName(instrumentHandle, signalName, signalType, resultSize, resultName, actualResultSize, resultState);
}

int32 NiRFmxInstrRestrictedLibrary::GetActiveTableName(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char activeTableName[])
{
  if (!function_pointers_.GetActiveTableName) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetActiveTableName.");
  }
  return function_pointers_.GetActiveTableName(instrumentHandle, selectorString, arraySize, activeTableName);
}

int32 NiRFmxInstrRestrictedLibrary::GetAttributeAuthor(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32* attrVal)
{
  if (!function_pointers_.GetAttributeAuthor) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetAttributeAuthor.");
  }
  return function_pointers_.GetAttributeAuthor(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 NiRFmxInstrRestrictedLibrary::GetAttributeDesiredF32(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32* attrVal)
{
  if (!function_pointers_.GetAttributeDesiredF32) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetAttributeDesiredF32.");
  }
  return function_pointers_.GetAttributeDesiredF32(instrumentHandle, channelName, attributeID, attrVal);
}

int32 NiRFmxInstrRestrictedLibrary::GetAttributeDesiredF32Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32 attrVal[], int32 arraySize, int32* actualArraySize)
{
  if (!function_pointers_.GetAttributeDesiredF32Array) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetAttributeDesiredF32Array.");
  }
  return function_pointers_.GetAttributeDesiredF32Array(instrumentHandle, channelName, attributeID, attrVal, arraySize, actualArraySize);
}

int32 NiRFmxInstrRestrictedLibrary::GetAttributeDesiredF64(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64* attrVal)
{
  if (!function_pointers_.GetAttributeDesiredF64) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetAttributeDesiredF64.");
  }
  return function_pointers_.GetAttributeDesiredF64(instrumentHandle, channelName, attributeID, attrVal);
}

int32 NiRFmxInstrRestrictedLibrary::GetAttributeDesiredF64Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64 attrVal[], int32 arraySize, int32* actualArraySize)
{
  if (!function_pointers_.GetAttributeDesiredF64Array) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetAttributeDesiredF64Array.");
  }
  return function_pointers_.GetAttributeDesiredF64Array(instrumentHandle, channelName, attributeID, attrVal, arraySize, actualArraySize);
}

int32 NiRFmxInstrRestrictedLibrary::GetAttributeDesiredI32(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32* attrVal)
{
  if (!function_pointers_.GetAttributeDesiredI32) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetAttributeDesiredI32.");
  }
  return function_pointers_.GetAttributeDesiredI32(instrumentHandle, channelName, attributeID, attrVal);
}

int32 NiRFmxInstrRestrictedLibrary::GetAttributeDesiredI64(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64* attrVal)
{
  if (!function_pointers_.GetAttributeDesiredI64) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetAttributeDesiredI64.");
  }
  return function_pointers_.GetAttributeDesiredI64(instrumentHandle, channelName, attributeID, attrVal);
}

int32 NiRFmxInstrRestrictedLibrary::GetAttributeDesiredString(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 arraySize, char attrVal[])
{
  if (!function_pointers_.GetAttributeDesiredString) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetAttributeDesiredString.");
  }
  return function_pointers_.GetAttributeDesiredString(instrumentHandle, channelName, attributeID, arraySize, attrVal);
}

int32 NiRFmxInstrRestrictedLibrary::GetCalibrationPlaneEnabled(niRFmxInstrHandle instrumentHandle, char selectorString[], int32* calibrationPlaneEnabled)
{
  if (!function_pointers_.GetCalibrationPlaneEnabled) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetCalibrationPlaneEnabled.");
  }
  return function_pointers_.GetCalibrationPlaneEnabled(instrumentHandle, selectorString, calibrationPlaneEnabled);
}

int32 NiRFmxInstrRestrictedLibrary::GetCalibrationPlaneNames(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char calibrationPlaneNames[])
{
  if (!function_pointers_.GetCalibrationPlaneNames) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetCalibrationPlaneNames.");
  }
  return function_pointers_.GetCalibrationPlaneNames(instrumentHandle, selectorString, arraySize, calibrationPlaneNames);
}

int32 NiRFmxInstrRestrictedLibrary::GetError(niRFmxInstrHandle instrumentHandle, int32* errorCode, int32 errorDescriptionBufferSize, char errorDescription[])
{
  if (!function_pointers_.GetError) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetError.");
  }
  return function_pointers_.GetError(instrumentHandle, errorCode, errorDescriptionBufferSize, errorDescription);
}

int32 NiRFmxInstrRestrictedLibrary::GetErrorString(niRFmxInstrHandle instrumentHandle, int32 errorCode, int32 errorDescriptionBufferSize, char errorDescription[])
{
  if (!function_pointers_.GetErrorString) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetErrorString.");
  }
  return function_pointers_.GetErrorString(instrumentHandle, errorCode, errorDescriptionBufferSize, errorDescription);
}

int32 NiRFmxInstrRestrictedLibrary::GetExternalAttenuationTableNames(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char externalAttenuationTableNames[])
{
  if (!function_pointers_.GetExternalAttenuationTableNames) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetExternalAttenuationTableNames.");
  }
  return function_pointers_.GetExternalAttenuationTableNames(instrumentHandle, selectorString, arraySize, externalAttenuationTableNames);
}

int32 NiRFmxInstrRestrictedLibrary::GetForceAllTracesEnabled(niRFmxInstrHandle instrumentHandle, char channelName[], int32* attrVal)
{
  if (!function_pointers_.GetForceAllTracesEnabled) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetForceAllTracesEnabled.");
  }
  return function_pointers_.GetForceAllTracesEnabled(instrumentHandle, channelName, attrVal);
}

int32 NiRFmxInstrRestrictedLibrary::GetInitiaitedSnapshotStrings(niRFmxInstrHandle instrumentHandle, uInt64* snapshotInfoCacheIndex, int32 personalityIDArray[], int32 personalityIDArraySize, int32* personalityIDArrayActualSize, char signalNames[], int32 signalNamesSize, int32* signalNamesActualSize, char resultNames[], int32 resultNamesSize, int32* resultNamesActualSize, char snapshotIdentifiers[], int32 snapshotIdentifiersSize, int32* snapshotIdentifiersActualSize, uInt64 snapshotTimestampArray[], int32 snapshotTimestampArraySize, int32* snapshotTimestampArrayActualSize)
{
  if (!function_pointers_.GetInitiaitedSnapshotStrings) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetInitiaitedSnapshotStrings.");
  }
  return function_pointers_.GetInitiaitedSnapshotStrings(instrumentHandle, snapshotInfoCacheIndex, personalityIDArray, personalityIDArraySize, personalityIDArrayActualSize, signalNames, signalNamesSize, signalNamesActualSize, resultNames, resultNamesSize, resultNamesActualSize, snapshotIdentifiers, snapshotIdentifiersSize, snapshotIdentifiersActualSize, snapshotTimestampArray, snapshotTimestampArraySize, snapshotTimestampArrayActualSize);
}

int32 NiRFmxInstrRestrictedLibrary::GetLatestConfigurationSnapshot(niRFmxInstrHandle instrumentHandle, uInt64* snapshotInfoCacheIndex, int32* personalityID, char signalName[], int32 signalNameSize, int32* signalNameActualSize, char snapshotIdentifier[], int32 snapshotIdentifierSize, int32* snapshotIdentifierActualSize, int32* signalConfigurationState, uInt64* signalTimestamp)
{
  if (!function_pointers_.GetLatestConfigurationSnapshot) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetLatestConfigurationSnapshot.");
  }
  return function_pointers_.GetLatestConfigurationSnapshot(instrumentHandle, snapshotInfoCacheIndex, personalityID, signalName, signalNameSize, signalNameActualSize, snapshotIdentifier, snapshotIdentifierSize, snapshotIdentifierActualSize, signalConfigurationState, signalTimestamp);
}

int32 NiRFmxInstrRestrictedLibrary::GetOpenSessionsInformation(char resourceName[], int32 infoJsonSize, char infoJson[])
{
  if (!function_pointers_.GetOpenSessionsInformation) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetOpenSessionsInformation.");
  }
  return function_pointers_.GetOpenSessionsInformation(resourceName, infoJsonSize, infoJson);
}

int32 NiRFmxInstrRestrictedLibrary::GetPrivilegeLevel(niRFmxInstrHandle instrumentHandle, int32* isConnectionAlive, int32* privilegeLevel)
{
  if (!function_pointers_.GetPrivilegeLevel) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetPrivilegeLevel.");
  }
  return function_pointers_.GetPrivilegeLevel(instrumentHandle, isConnectionAlive, privilegeLevel);
}

int32 NiRFmxInstrRestrictedLibrary::GetRFmxVersion(niRFmxInstrHandle instrumentHandle, int32 arraySize, char RFmxVersion[])
{
  if (!function_pointers_.GetRFmxVersion) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetRFmxVersion.");
  }
  return function_pointers_.GetRFmxVersion(instrumentHandle, arraySize, RFmxVersion);
}

int32 NiRFmxInstrRestrictedLibrary::GetSessionUniqueIdentifier(char resourceNames[], char optionString[], int32 sessionUniqueIdentifierSize, char sessionUniqueIdentifier[])
{
  if (!function_pointers_.GetSessionUniqueIdentifier) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetSessionUniqueIdentifier.");
  }
  return function_pointers_.GetSessionUniqueIdentifier(resourceNames, optionString, sessionUniqueIdentifierSize, sessionUniqueIdentifier);
}

int32 NiRFmxInstrRestrictedLibrary::GetSignalConfigurationState64(niRFmxInstrHandle instrumentHandle, char signalName[], uInt32 signalType, int32* signalState, uInt64* timeStamp)
{
  if (!function_pointers_.GetSignalConfigurationState64) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetSignalConfigurationState64.");
  }
  return function_pointers_.GetSignalConfigurationState64(instrumentHandle, signalName, signalType, signalState, timeStamp);
}

int32 NiRFmxInstrRestrictedLibrary::GetSnapshotInfoFromCache(niRFmxInstrHandle instrumentHandle, uInt64 snapshotInfoCacheIndex, int32 personalityIDArray[], int32 personalityIDArraySize, int32* personalityIDArrayActualSize, char signalNames[], int32 signalNamesSize, int32* signalNamesActualSize, char resultNames[], int32 resultNamesSize, int32* resultNamesActualSize, char snapshotIdentifiers[], int32 snapshotIdentifiersSize, int32* snapshotIdentifiersActualSize, uInt64 snapshotTimestampArray[], int32 snapshotTimestampArraySize, int32* snapshotTimestampArrayActualSize)
{
  if (!function_pointers_.GetSnapshotInfoFromCache) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetSnapshotInfoFromCache.");
  }
  return function_pointers_.GetSnapshotInfoFromCache(instrumentHandle, snapshotInfoCacheIndex, personalityIDArray, personalityIDArraySize, personalityIDArrayActualSize, signalNames, signalNamesSize, signalNamesActualSize, resultNames, resultNamesSize, resultNamesActualSize, snapshotIdentifiers, snapshotIdentifiersSize, snapshotIdentifiersActualSize, snapshotTimestampArray, snapshotTimestampArraySize, snapshotTimestampArrayActualSize);
}

int32 NiRFmxInstrRestrictedLibrary::GetSnapshotState(niRFmxInstrHandle instrumentHandle, int32 personality, char selectorString[], int32* snapshotState)
{
  if (!function_pointers_.GetSnapshotState) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetSnapshotState.");
  }
  return function_pointers_.GetSnapshotState(instrumentHandle, personality, selectorString, snapshotState);
}

int32 NiRFmxInstrRestrictedLibrary::GetTracesInfoForMonitorSnapshot(niRFmxInstrHandle instrumentHandle, char selectorString[], int32* allTracesEnabled)
{
  if (!function_pointers_.GetTracesInfoForMonitorSnapshot) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetTracesInfoForMonitorSnapshot.");
  }
  return function_pointers_.GetTracesInfoForMonitorSnapshot(instrumentHandle, selectorString, allTracesEnabled);
}

int32 NiRFmxInstrRestrictedLibrary::LoadAllForRevert(niRFmxInstrHandle instrumentHandle, char filePath[])
{
  if (!function_pointers_.LoadAllForRevert) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_LoadAllForRevert.");
  }
  return function_pointers_.LoadAllForRevert(instrumentHandle, filePath);
}

int32 NiRFmxInstrRestrictedLibrary::LoadConfigurationsFromJSON(niRFmxInstrHandle instrumentHandle, char jsonString[], int32 arraySize)
{
  if (!function_pointers_.LoadConfigurationsFromJSON) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_LoadConfigurationsFromJSON.");
  }
  return function_pointers_.LoadConfigurationsFromJSON(instrumentHandle, jsonString, arraySize);
}

int32 NiRFmxInstrRestrictedLibrary::RegisterSpecialClientSnapshotInterest(char resourceName[])
{
  if (!function_pointers_.RegisterSpecialClientSnapshotInterest) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_RegisterSpecialClientSnapshotInterest.");
  }
  return function_pointers_.RegisterSpecialClientSnapshotInterest(resourceName);
}

int32 NiRFmxInstrRestrictedLibrary::RequestPrivilege(niRFmxInstrHandle instrumentHandle, int32 privilegeLevel)
{
  if (!function_pointers_.RequestPrivilege) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_RequestPrivilege.");
  }
  return function_pointers_.RequestPrivilege(instrumentHandle, privilegeLevel);
}

int32 NiRFmxInstrRestrictedLibrary::SaveAllForRevert(niRFmxInstrHandle instrumentHandle, char filePath[])
{
  if (!function_pointers_.SaveAllForRevert) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_SaveAllForRevert.");
  }
  return function_pointers_.SaveAllForRevert(instrumentHandle, filePath);
}

int32 NiRFmxInstrRestrictedLibrary::SaveConfigurationsToJSON(niRFmxInstrHandle instrumentHandle, char signalNames[], char jsonStringOut[], int32 arraySize, int32* actualArraySize)
{
  if (!function_pointers_.SaveConfigurationsToJSON) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_SaveConfigurationsToJSON.");
  }
  return function_pointers_.SaveConfigurationsToJSON(instrumentHandle, signalNames, jsonStringOut, arraySize, actualArraySize);
}

int32 NiRFmxInstrRestrictedLibrary::SetForceAllTracesEnabled(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attrVal)
{
  if (!function_pointers_.SetForceAllTracesEnabled) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_SetForceAllTracesEnabled.");
  }
  return function_pointers_.SetForceAllTracesEnabled(instrumentHandle, channelName, attrVal);
}

int32 NiRFmxInstrRestrictedLibrary::SetIOTraceStatus(niRFmxInstrHandle instrumentHandle, int32 IOTraceStatus)
{
  if (!function_pointers_.SetIOTraceStatus) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_SetIOTraceStatus.");
  }
  return function_pointers_.SetIOTraceStatus(instrumentHandle, IOTraceStatus);
}

int32 NiRFmxInstrRestrictedLibrary::UnregisterSpecialClientSnapshotInterest(char resourceName[])
{
  if (!function_pointers_.UnregisterSpecialClientSnapshotInterest) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_UnregisterSpecialClientSnapshotInterest.");
  }
  return function_pointers_.UnregisterSpecialClientSnapshotInterest(resourceName);
}

int32 NiRFmxInstrRestrictedLibrary::GetSFPSessionAccessEnabled(char optionString[], int32* isSFPSessionAccessEnabled)
{
  if (!function_pointers_.GetSFPSessionAccessEnabled) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_GetSFPSessionAccessEnabled.");
  }
  return function_pointers_.GetSFPSessionAccessEnabled(optionString, isSFPSessionAccessEnabled);
}

int32 NiRFmxInstrRestrictedLibrary::CreateDefaultSignalConfiguration(niRFmxInstrHandle instrumentHandle, char signalName[], int32 personalityID)
{
  if (!function_pointers_.CreateDefaultSignalConfiguration) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_CreateDefaultSignalConfiguration.");
  }
  return function_pointers_.CreateDefaultSignalConfiguration(instrumentHandle, signalName, personalityID);
}

int32 NiRFmxInstrRestrictedLibrary::LoadExternalAttenuationTable(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], char filePath[])
{
  if (!function_pointers_.LoadExternalAttenuationTable) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_LoadExternalAttenuationTable.");
  }
  return function_pointers_.LoadExternalAttenuationTable(instrumentHandle, selectorString, tableName, filePath);
}

int32 NiRFmxInstrRestrictedLibrary::DefineExternalAttenuationTable(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], int32 numberOfPoints)
{
  if (!function_pointers_.DefineExternalAttenuationTable) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_DefineExternalAttenuationTable.");
  }
  return function_pointers_.DefineExternalAttenuationTable(instrumentHandle, selectorString, tableName, numberOfPoints);
}

int32 NiRFmxInstrRestrictedLibrary::CfgSParameterExternalAttenuationTableFrequencies(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], float64 sParameterFrequencies[], int32 sParameterFrequenciesArraySize)
{
  if (!function_pointers_.CfgSParameterExternalAttenuationTableFrequencies) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_CfgSParameterExternalAttenuationTableFrequencies.");
  }
  return function_pointers_.CfgSParameterExternalAttenuationTableFrequencies(instrumentHandle, selectorString, tableName, sParameterFrequencies, sParameterFrequenciesArraySize);
}

int32 NiRFmxInstrRestrictedLibrary::CfgSParameterExternalAttenuationTableSParameter(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], NIComplexDouble sParameters[], int32 sParameterTableSize, int32 sParameterOrientation)
{
  if (!function_pointers_.CfgSParameterExternalAttenuationTableSParameter) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_CfgSParameterExternalAttenuationTableSParameter.");
  }
  return function_pointers_.CfgSParameterExternalAttenuationTableSParameter(instrumentHandle, selectorString, tableName, sParameters, sParameterTableSize, sParameterOrientation);
}

int32 NiRFmxInstrRestrictedLibrary::DefineSParameterExternalAttenuationTable(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], int32 numberOfFrequencyPoints, int32 numberOfPorts)
{
  if (!function_pointers_.DefineSParameterExternalAttenuationTable) {
    throw nidevice_grpc::LibraryLoadException("Could not find RFmxInstr_DefineSParameterExternalAttenuationTable.");
  }
  return function_pointers_.DefineSParameterExternalAttenuationTable(instrumentHandle, selectorString, tableName, numberOfFrequencyPoints, numberOfPorts);
}

}  // namespace nirfmxinstr_restricted_grpc
