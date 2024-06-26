//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Compilation test for the NI-Digital Pattern Driver Metadata
//---------------------------------------------------------------------
#include "nidigitalpattern_library.h"

namespace nidigitalpattern_grpc {

ViStatus Abort(ViSession vi)
{
  return niDigital_Abort(vi);
}

ViStatus AbortKeepAlive(ViSession vi)
{
  return niDigital_AbortKeepAlive(vi);
}

ViStatus ApplyLevelsAndTiming(ViSession vi, ViConstString siteList, ViConstString levelsSheet, ViConstString timingSheet, ViConstString initialStateHighPins, ViConstString initialStateLowPins, ViConstString initialStateTristatePins)
{
  return niDigital_ApplyLevelsAndTiming(vi, siteList, levelsSheet, timingSheet, initialStateHighPins, initialStateLowPins, initialStateTristatePins);
}

ViStatus ApplyTDROffsets(ViSession vi, ViConstString channelList, ViInt32 numOffsets, ViReal64 offsets[])
{
  return niDigital_ApplyTDROffsets(vi, channelList, numOffsets, offsets);
}

ViStatus BurstPattern(ViSession vi, ViConstString siteList, ViConstString startLabel, ViBoolean selectDigitalFunction, ViBoolean waitUntilDone, ViReal64 timeout)
{
  return niDigital_BurstPattern(vi, siteList, startLabel, selectDigitalFunction, waitUntilDone, timeout);
}

ViStatus BurstPatternSynchronized(ViUInt32 sessionCount, ViSession sessions[], ViConstString siteList, ViConstString startLabel, ViBoolean selectDigitalFunction, ViBoolean waitUntilDone, ViReal64 timeout)
{
  return niDigital_BurstPatternSynchronized(sessionCount, sessions, siteList, startLabel, selectDigitalFunction, waitUntilDone, timeout);
}

ViStatus ClearError(ViSession vi)
{
  return niDigital_ClearError(vi);
}

ViStatus ClockGeneratorAbort(ViSession vi, ViConstString channelList)
{
  return niDigital_ClockGenerator_Abort(vi, channelList);
}

ViStatus ClockGeneratorGenerateClock(ViSession vi, ViConstString channelList, ViReal64 frequency, ViBoolean selectDigitalFunction)
{
  return niDigital_ClockGenerator_GenerateClock(vi, channelList, frequency, selectDigitalFunction);
}

ViStatus ClockGeneratorInitiate(ViSession vi, ViConstString channelList)
{
  return niDigital_ClockGenerator_Initiate(vi, channelList);
}

ViStatus Close(ViSession vi)
{
  return niDigital_close(vi);
}

ViStatus Commit(ViSession vi)
{
  return niDigital_Commit(vi);
}

ViStatus ConfigureActiveLoadLevels(ViSession vi, ViConstString channelList, ViReal64 iol, ViReal64 ioh, ViReal64 vcom)
{
  return niDigital_ConfigureActiveLoadLevels(vi, channelList, iol, ioh, vcom);
}

ViStatus ConfigureCycleNumberHistoryRAMTrigger(ViSession vi, ViInt64 cycleNumber, ViInt32 pretriggerSamples)
{
  return niDigital_ConfigureCycleNumberHistoryRAMTrigger(vi, cycleNumber, pretriggerSamples);
}

ViStatus ConfigureDigitalEdgeConditionalJumpTrigger(ViSession vi, ViConstString triggerIdentifier, ViConstString source, ViInt32 edge)
{
  return niDigital_ConfigureDigitalEdgeConditionalJumpTrigger(vi, triggerIdentifier, source, edge);
}

ViStatus ConfigureDigitalEdgeStartTrigger(ViSession vi, ViConstString source, ViInt32 edge)
{
  return niDigital_ConfigureDigitalEdgeStartTrigger(vi, source, edge);
}

ViStatus ConfigureFirstFailureHistoryRAMTrigger(ViSession vi, ViInt32 pretriggerSamples)
{
  return niDigital_ConfigureFirstFailureHistoryRAMTrigger(vi, pretriggerSamples);
}

ViStatus ConfigureHistoryRAMCyclesToAcquire(ViSession vi, ViInt32 cyclesToAcquire)
{
  return niDigital_ConfigureHistoryRAMCyclesToAcquire(vi, cyclesToAcquire);
}

ViStatus ConfigurePatternBurstSites(ViSession vi, ViConstString siteList)
{
  return niDigital_ConfigurePatternBurstSites(vi, siteList);
}

ViStatus ConfigurePatternLabelHistoryRAMTrigger(ViSession vi, ViConstString label, ViInt64 vectorOffset, ViInt64 cycleOffset, ViInt32 pretriggerSamples)
{
  return niDigital_ConfigurePatternLabelHistoryRAMTrigger(vi, label, vectorOffset, cycleOffset, pretriggerSamples);
}

ViStatus ConfigureSoftwareEdgeConditionalJumpTrigger(ViSession vi, ViConstString triggerIdentifier)
{
  return niDigital_ConfigureSoftwareEdgeConditionalJumpTrigger(vi, triggerIdentifier);
}

ViStatus ConfigureSoftwareEdgeStartTrigger(ViSession vi)
{
  return niDigital_ConfigureSoftwareEdgeStartTrigger(vi);
}

ViStatus ConfigureStartLabel(ViSession vi, ViConstString label)
{
  return niDigital_ConfigureStartLabel(vi, label);
}

ViStatus ConfigureTerminationMode(ViSession vi, ViConstString channelList, ViInt32 mode)
{
  return niDigital_ConfigureTerminationMode(vi, channelList, mode);
}

ViStatus ConfigureTimeSetCompareEdgesStrobe(ViSession vi, ViConstString pinList, ViConstString timeSet, ViReal64 strobeEdge)
{
  return niDigital_ConfigureTimeSetCompareEdgesStrobe(vi, pinList, timeSet, strobeEdge);
}

ViStatus ConfigureTimeSetCompareEdgesStrobe2x(ViSession vi, ViConstString pinList, ViConstString timeSet, ViReal64 strobeEdge, ViReal64 strobe2Edge)
{
  return niDigital_ConfigureTimeSetCompareEdgesStrobe2x(vi, pinList, timeSet, strobeEdge, strobe2Edge);
}

ViStatus ConfigureTimeSetDriveEdges(ViSession vi, ViConstString pinList, ViConstString timeSet, ViInt32 format, ViReal64 driveOnEdge, ViReal64 driveDataEdge, ViReal64 driveReturnEdge, ViReal64 driveOffEdge)
{
  return niDigital_ConfigureTimeSetDriveEdges(vi, pinList, timeSet, format, driveOnEdge, driveDataEdge, driveReturnEdge, driveOffEdge);
}

ViStatus ConfigureTimeSetDriveEdges2x(ViSession vi, ViConstString pinList, ViConstString timeSet, ViInt32 format, ViReal64 driveOnEdge, ViReal64 driveDataEdge, ViReal64 driveReturnEdge, ViReal64 driveOffEdge, ViReal64 driveData2Edge, ViReal64 driveReturn2Edge)
{
  return niDigital_ConfigureTimeSetDriveEdges2x(vi, pinList, timeSet, format, driveOnEdge, driveDataEdge, driveReturnEdge, driveOffEdge, driveData2Edge, driveReturn2Edge);
}

ViStatus ConfigureTimeSetDriveFormat(ViSession vi, ViConstString pinList, ViConstString timeSet, ViInt32 driveFormat)
{
  return niDigital_ConfigureTimeSetDriveFormat(vi, pinList, timeSet, driveFormat);
}

ViStatus ConfigureTimeSetEdge(ViSession vi, ViConstString pinList, ViConstString timeSet, ViInt32 edge, ViReal64 time)
{
  return niDigital_ConfigureTimeSetEdge(vi, pinList, timeSet, edge, time);
}

ViStatus ConfigureTimeSetEdgeMultiplier(ViSession vi, ViConstString pinList, ViConstString timeSet, ViInt32 edgeMultiplier)
{
  return niDigital_ConfigureTimeSetEdgeMultiplier(vi, pinList, timeSet, edgeMultiplier);
}

ViStatus ConfigureTimeSetPeriod(ViSession vi, ViConstString timeSet, ViReal64 period)
{
  return niDigital_ConfigureTimeSetPeriod(vi, timeSet, period);
}

ViStatus ConfigureVoltageLevels(ViSession vi, ViConstString channelList, ViReal64 vil, ViReal64 vih, ViReal64 vol, ViReal64 voh, ViReal64 vterm)
{
  return niDigital_ConfigureVoltageLevels(vi, channelList, vil, vih, vol, voh, vterm);
}

ViStatus CreateCaptureWaveformFromFileDigicapture(ViSession vi, ViConstString waveformName, ViConstString waveformFilePath)
{
  return niDigital_CreateCaptureWaveformFromFileDigicapture(vi, waveformName, waveformFilePath);
}

ViStatus CreateCaptureWaveformParallel(ViSession vi, ViConstString pinList, ViConstString waveformName)
{
  return niDigital_CreateCaptureWaveformParallel(vi, pinList, waveformName);
}

ViStatus CreateCaptureWaveformSerial(ViSession vi, ViConstString pinList, ViConstString waveformName, ViUInt32 sampleWidth, ViInt32 bitOrder)
{
  return niDigital_CreateCaptureWaveformSerial(vi, pinList, waveformName, sampleWidth, bitOrder);
}

ViStatus CreateChannelMap(ViSession vi, ViInt32 numSites)
{
  return niDigital_CreateChannelMap(vi, numSites);
}

ViStatus CreatePinGroup(ViSession vi, ViConstString pinGroupName, ViConstString pinList)
{
  return niDigital_CreatePinGroup(vi, pinGroupName, pinList);
}

ViStatus CreatePinMap(ViSession vi, ViConstString dutPinList, ViConstString systemPinList)
{
  return niDigital_CreatePinMap(vi, dutPinList, systemPinList);
}

ViStatus CreateSourceWaveformFromFileTDMS(ViSession vi, ViConstString waveformName, ViConstString waveformFilePath, ViBoolean writeWaveformData)
{
  return niDigital_CreateSourceWaveformFromFileTDMS(vi, waveformName, waveformFilePath, writeWaveformData);
}

ViStatus CreateSourceWaveformParallel(ViSession vi, ViConstString pinList, ViConstString waveformName, ViInt32 dataMapping)
{
  return niDigital_CreateSourceWaveformParallel(vi, pinList, waveformName, dataMapping);
}

ViStatus CreateSourceWaveformSerial(ViSession vi, ViConstString pinList, ViConstString waveformName, ViInt32 dataMapping, ViUInt32 sampleWidth, ViInt32 bitOrder)
{
  return niDigital_CreateSourceWaveformSerial(vi, pinList, waveformName, dataMapping, sampleWidth, bitOrder);
}

ViStatus CreateTimeSet(ViSession vi, ViConstString name)
{
  return niDigital_CreateTimeSet(vi, name);
}

ViStatus DeleteAllTimeSets(ViSession vi)
{
  return niDigital_DeleteAllTimeSets(vi);
}

ViStatus DisableConditionalJumpTrigger(ViSession vi, ViConstString triggerIdentifier)
{
  return niDigital_DisableConditionalJumpTrigger(vi, triggerIdentifier);
}

ViStatus DisableSites(ViSession vi, ViConstString siteList)
{
  return niDigital_DisableSites(vi, siteList);
}

ViStatus DisableStartTrigger(ViSession vi)
{
  return niDigital_DisableStartTrigger(vi);
}

ViStatus EnableMatchFailCombination(ViUInt32 sessionCount, ViSession sessions[], ViSession syncSession)
{
  return niDigital_EnableMatchFailCombination(sessionCount, sessions, syncSession);
}

ViStatus EnableSites(ViSession vi, ViConstString siteList)
{
  return niDigital_EnableSites(vi, siteList);
}

ViStatus EndChannelMap(ViSession vi)
{
  return niDigital_EndChannelMap(vi);
}

ViStatus ErrorMessage(ViSession vi, ViStatus errorCode, ViChar errorMessage[256])
{
  return niDigital_error_message(vi, errorCode, errorMessage);
}

ViStatus ExportSignal(ViSession vi, ViInt32 signal, ViConstString signalIdentifier, ViConstString outputTerminal)
{
  return niDigital_ExportSignal(vi, signal, signalIdentifier, outputTerminal);
}

ViStatus FetchCaptureWaveformU32(ViSession vi, ViConstString siteList, ViConstString waveformName, ViInt32 samplesToRead, ViReal64 timeout, ViInt32 dataBufferSize, ViUInt32 data[], ViInt32* actualNumWaveforms, ViInt32* actualSamplesPerWaveform)
{
  return niDigital_FetchCaptureWaveformU32(vi, siteList, waveformName, samplesToRead, timeout, dataBufferSize, data, actualNumWaveforms, actualSamplesPerWaveform);
}

ViStatus FetchHistoryRAMCycleInformation(ViSession vi, ViConstString site, ViInt64 sampleIndex, ViInt32* patternIndex, ViInt32* timeSetIndex, ViInt64* vectorNumber, ViInt64* cycleNumber, ViInt32* numDutCycles)
{
  return niDigital_FetchHistoryRAMCycleInformation(vi, site, sampleIndex, patternIndex, timeSetIndex, vectorNumber, cycleNumber, numDutCycles);
}

ViStatus FetchHistoryRAMCyclePinData(ViSession vi, ViConstString site, ViConstString pinList, ViInt64 sampleIndex, ViInt32 dutCycleIndex, ViInt32 pinDataBufferSize, ViUInt8 expectedPinStates[], ViUInt8 actualPinStates[], ViBoolean perPinPassFail[], ViInt32* actualNumPinData)
{
  return niDigital_FetchHistoryRAMCyclePinData(vi, site, pinList, sampleIndex, dutCycleIndex, pinDataBufferSize, expectedPinStates, actualPinStates, perPinPassFail, actualNumPinData);
}

ViStatus FetchHistoryRAMScanCycleNumber(ViSession vi, ViConstString site, ViInt64 sampleIndex, ViInt64* scanCycleNumber)
{
  return niDigital_FetchHistoryRAMScanCycleNumber(vi, site, sampleIndex, scanCycleNumber);
}

ViStatus FrequencyCounterConfigureMeasurementMode(ViSession vi, ViInt32 measurementmode)
{
  return niDigital_FrequencyCounter_ConfigureMeasurementMode(vi, measurementmode);
}

ViStatus FrequencyCounterConfigureMeasurementTime(ViSession vi, ViConstString channelList, ViReal64 measurementTime)
{
  return niDigital_FrequencyCounter_ConfigureMeasurementTime(vi, channelList, measurementTime);
}

ViStatus FrequencyCounterMeasureFrequency(ViSession vi, ViConstString channelList, ViInt32 frequenciesBufferSize, ViReal64 frequencies[], ViInt32* actualNumFrequencies)
{
  return niDigital_FrequencyCounter_MeasureFrequency(vi, channelList, frequenciesBufferSize, frequencies, actualNumFrequencies);
}

ViStatus GetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean* value)
{
  return niDigital_GetAttributeViBoolean(vi, channelName, attribute, value);
}

ViStatus GetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32* value)
{
  return niDigital_GetAttributeViInt32(vi, channelName, attribute, value);
}

ViStatus GetAttributeViInt64(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt64* value)
{
  return niDigital_GetAttributeViInt64(vi, channelName, attribute, value);
}

ViStatus GetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64* value)
{
  return niDigital_GetAttributeViReal64(vi, channelName, attribute, value);
}

ViStatus GetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attribute, ViSession* value)
{
  return niDigital_GetAttributeViSession(vi, channelName, attribute, value);
}

ViStatus GetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 bufferSize, ViChar value[])
{
  return niDigital_GetAttributeViString(vi, channelName, attribute, bufferSize, value);
}

ViStatus GetChannelName(ViSession vi, ViInt32 index, ViInt32 nameBufferSize, ViChar name[])
{
  return niDigital_GetChannelName(vi, index, nameBufferSize, name);
}

ViStatus GetChannelNameFromString(ViSession vi, ViConstString index, ViInt32 nameBufferSize, ViChar name[])
{
  return niDigital_GetChannelNameFromString(vi, index, nameBufferSize, name);
}

ViStatus GetError(ViSession vi, ViStatus* errorCode, ViInt32 errorDescriptionBufferSize, ViChar errorDescription[])
{
  return niDigital_GetError(vi, errorCode, errorDescriptionBufferSize, errorDescription);
}

ViStatus GetFailCount(ViSession vi, ViConstString channelList, ViInt32 bufferSize, ViInt64 failureCount[], ViInt32* actualNumRead)
{
  return niDigital_GetFailCount(vi, channelList, bufferSize, failureCount, actualNumRead);
}

ViStatus GetHistoryRAMSampleCount(ViSession vi, ViConstString site, ViInt64* sampleCount)
{
  return niDigital_GetHistoryRAMSampleCount(vi, site, sampleCount);
}

ViStatus GetPatternName(ViSession vi, ViInt32 patternIndex, ViInt32 nameBufferSize, ViChar name[])
{
  return niDigital_GetPatternName(vi, patternIndex, nameBufferSize, name);
}

ViStatus GetPatternPinIndexes(ViSession vi, ViConstString startLabel, ViInt32 pinIndexesBufferSize, ViInt32 pinIndexes[], ViInt32* actualNumPins)
{
  return niDigital_GetPatternPinIndexes(vi, startLabel, pinIndexesBufferSize, pinIndexes, actualNumPins);
}

ViStatus GetPatternPinList(ViSession vi, ViConstString startLabel, ViInt32 pinListBufferSize, ViChar pinList[])
{
  return niDigital_GetPatternPinList(vi, startLabel, pinListBufferSize, pinList);
}

ViStatus GetPinName(ViSession vi, ViInt32 pinIndex, ViInt32 nameBufferSize, ViChar name[])
{
  return niDigital_GetPinName(vi, pinIndex, nameBufferSize, name);
}

ViStatus GetPinResultsPinInformation(ViSession vi, ViConstString channelList, ViInt32 bufferSize, ViInt32 pinIndexes[], ViInt32 siteNumbers[], ViInt32 channelIndexes[], ViInt32* actualNumValues)
{
  return niDigital_GetPinResultsPinInformation(vi, channelList, bufferSize, pinIndexes, siteNumbers, channelIndexes, actualNumValues);
}

ViStatus GetSitePassFail(ViSession vi, ViConstString siteList, ViInt32 passFailBufferSize, ViBoolean passFail[], ViInt32* actualNumSites)
{
  return niDigital_GetSitePassFail(vi, siteList, passFailBufferSize, passFail, actualNumSites);
}

ViStatus GetSiteResultsSiteNumbers(ViSession vi, ViConstString siteList, ViInt32 siteResultType, ViInt32 siteNumbersBufferSize, ViInt32 siteNumbers[], ViInt32* actualNumSiteNumbers)
{
  return niDigital_GetSiteResultsSiteNumbers(vi, siteList, siteResultType, siteNumbersBufferSize, siteNumbers, actualNumSiteNumbers);
}

ViStatus GetTimeSetDriveFormat(ViSession vi, ViConstString pin, ViConstString timeSet, ViInt32* format)
{
  return niDigital_GetTimeSetDriveFormat(vi, pin, timeSet, format);
}

ViStatus GetTimeSetEdge(ViSession vi, ViConstString pin, ViConstString timeSet, ViInt32 edge, ViReal64* time)
{
  return niDigital_GetTimeSetEdge(vi, pin, timeSet, edge, time);
}

ViStatus GetTimeSetEdgeMultiplier(ViSession vi, ViConstString pin, ViConstString timeSet, ViInt32* edgeMultiplier)
{
  return niDigital_GetTimeSetEdgeMultiplier(vi, pin, timeSet, edgeMultiplier);
}

ViStatus GetTimeSetName(ViSession vi, ViInt32 timeSetIndex, ViInt32 nameBufferSize, ViChar name[])
{
  return niDigital_GetTimeSetName(vi, timeSetIndex, nameBufferSize, name);
}

ViStatus GetTimeSetPeriod(ViSession vi, ViConstString timeSet, ViReal64* period)
{
  return niDigital_GetTimeSetPeriod(vi, timeSet, period);
}

ViStatus Init(ViString resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViSession* newVi)
{
  return niDigital_init(resourceName, idQuery, resetDevice, newVi);
}

ViStatus InitWithOptions(ViString resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* newVi)
{
  return niDigital_InitWithOptions(resourceName, idQuery, resetDevice, optionString, newVi);
}

ViStatus Initiate(ViSession vi)
{
  return niDigital_Initiate(vi);
}

ViStatus IsDone(ViSession vi, ViBoolean* done)
{
  return niDigital_IsDone(vi, done);
}

ViStatus IsSiteEnabled(ViSession vi, ViConstString site, ViBoolean* enable)
{
  return niDigital_IsSiteEnabled(vi, site, enable);
}

ViStatus LoadLevels(ViSession vi, ViConstString levelsFilePath)
{
  return niDigital_LoadLevels(vi, levelsFilePath);
}

ViStatus LoadPattern(ViSession vi, ViConstString filePath)
{
  return niDigital_LoadPattern(vi, filePath);
}

ViStatus LoadPinMap(ViSession vi, ViConstString pinMapFilePath)
{
  return niDigital_LoadPinMap(vi, pinMapFilePath);
}

ViStatus LoadSpecifications(ViSession vi, ViConstString specificationsFilePath)
{
  return niDigital_LoadSpecifications(vi, specificationsFilePath);
}

ViStatus LoadTiming(ViSession vi, ViConstString timingFilePath)
{
  return niDigital_LoadTiming(vi, timingFilePath);
}

ViStatus MapPinToChannel(ViSession vi, ViConstString pin, ViInt32 site, ViConstString channel)
{
  return niDigital_MapPinToChannel(vi, pin, site, channel);
}

ViStatus PPMUConfigureApertureTime(ViSession vi, ViConstString channelList, ViReal64 apertureTime, ViInt32 units)
{
  return niDigital_PPMU_ConfigureApertureTime(vi, channelList, apertureTime, units);
}

ViStatus PPMUConfigureCurrentLevel(ViSession vi, ViConstString channelList, ViReal64 currentLevel)
{
  return niDigital_PPMU_ConfigureCurrentLevel(vi, channelList, currentLevel);
}

ViStatus PPMUConfigureCurrentLevelRange(ViSession vi, ViConstString channelList, ViReal64 range)
{
  return niDigital_PPMU_ConfigureCurrentLevelRange(vi, channelList, range);
}

ViStatus PPMUConfigureCurrentLimit(ViSession vi, ViConstString channelList, ViInt32 behavior, ViReal64 limit)
{
  return niDigital_PPMU_ConfigureCurrentLimit(vi, channelList, behavior, limit);
}

ViStatus PPMUConfigureCurrentLimitRange(ViSession vi, ViConstString channelList, ViReal64 range)
{
  return niDigital_PPMU_ConfigureCurrentLimitRange(vi, channelList, range);
}

ViStatus PPMUConfigureOutputFunction(ViSession vi, ViConstString channelList, ViInt32 outputFunction)
{
  return niDigital_PPMU_ConfigureOutputFunction(vi, channelList, outputFunction);
}

ViStatus PPMUConfigureVoltageLevel(ViSession vi, ViConstString channelList, ViReal64 voltageLevel)
{
  return niDigital_PPMU_ConfigureVoltageLevel(vi, channelList, voltageLevel);
}

ViStatus PPMUConfigureVoltageLimits(ViSession vi, ViConstString channelList, ViReal64 lowerVoltageLimit, ViReal64 upperVoltageLimit)
{
  return niDigital_PPMU_ConfigureVoltageLimits(vi, channelList, lowerVoltageLimit, upperVoltageLimit);
}

ViStatus PPMUMeasure(ViSession vi, ViConstString channelList, ViInt32 measurementType, ViInt32 bufferSize, ViReal64 measurements[], ViInt32* actualNumRead)
{
  return niDigital_PPMU_Measure(vi, channelList, measurementType, bufferSize, measurements, actualNumRead);
}

ViStatus PPMUSource(ViSession vi, ViConstString channelList)
{
  return niDigital_PPMU_Source(vi, channelList);
}

ViStatus ReadSequencerFlag(ViSession vi, ViConstString flag, ViBoolean* value)
{
  return niDigital_ReadSequencerFlag(vi, flag, value);
}

ViStatus ReadSequencerRegister(ViSession vi, ViConstString reg, ViInt32* value)
{
  return niDigital_ReadSequencerRegister(vi, reg, value);
}

ViStatus ReadStatic(ViSession vi, ViConstString channelList, ViInt32 bufferSize, ViUInt8 data[], ViInt32* actualNumRead)
{
  return niDigital_ReadStatic(vi, channelList, bufferSize, data, actualNumRead);
}

ViStatus Reset(ViSession vi)
{
  return niDigital_reset(vi);
}

ViStatus ResetAttribute(ViSession vi, ViConstString channelName, ViAttr attributeId)
{
  return niDigital_ResetAttribute(vi, channelName, attributeId);
}

ViStatus ResetDevice(ViSession vi)
{
  return niDigital_ResetDevice(vi);
}

ViStatus SelectFunction(ViSession vi, ViConstString channelList, ViInt32 function)
{
  return niDigital_SelectFunction(vi, channelList, function);
}

ViStatus SelfCalibrate(ViSession vi)
{
  return niDigital_SelfCalibrate(vi);
}

ViStatus SelfTest(ViSession vi, ViInt16* testResult, ViChar testMessage[2048])
{
  return niDigital_self_test(vi, testResult, testMessage);
}

ViStatus SendSoftwareEdgeTrigger(ViSession vi, ViInt32 trigger, ViConstString triggerIdentifier)
{
  return niDigital_SendSoftwareEdgeTrigger(vi, trigger, triggerIdentifier);
}

ViStatus SetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value)
{
  return niDigital_SetAttributeViBoolean(vi, channelName, attribute, value);
}

ViStatus SetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value)
{
  return niDigital_SetAttributeViInt32(vi, channelName, attribute, value);
}

ViStatus SetAttributeViInt64(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt64 value)
{
  return niDigital_SetAttributeViInt64(vi, channelName, attribute, value);
}

ViStatus SetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value)
{
  return niDigital_SetAttributeViReal64(vi, channelName, attribute, value);
}

ViStatus SetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value)
{
  return niDigital_SetAttributeViSession(vi, channelName, attribute, value);
}

ViStatus SetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value)
{
  return niDigital_SetAttributeViString(vi, channelName, attribute, value);
}

ViStatus TDR(ViSession vi, ViConstString channelList, ViBoolean applyOffsets, ViInt32 offsetsBufferSize, ViReal64 offsets[], ViInt32* actualNumOffsets)
{
  return niDigital_TDR(vi, channelList, applyOffsets, offsetsBufferSize, offsets, actualNumOffsets);
}

ViStatus UnloadAllPatterns(ViSession vi, ViBoolean unloadKeepAlivePattern)
{
  return niDigital_UnloadAllPatterns(vi, unloadKeepAlivePattern);
}

ViStatus UnloadSpecifications(ViSession vi, ViConstString specificationsFilePath)
{
  return niDigital_UnloadSpecifications(vi, specificationsFilePath);
}

ViStatus WaitUntilDone(ViSession vi, ViReal64 timeout)
{
  return niDigital_WaitUntilDone(vi, timeout);
}

ViStatus WriteSequencerFlag(ViSession vi, ViConstString flag, ViBoolean value)
{
  return niDigital_WriteSequencerFlag(vi, flag, value);
}

ViStatus WriteSequencerFlagSynchronized(ViUInt32 sessionCount, ViSession sessions[], ViConstString flag, ViBoolean value)
{
  return niDigital_WriteSequencerFlagSynchronized(sessionCount, sessions, flag, value);
}

ViStatus WriteSequencerRegister(ViSession vi, ViConstString reg, ViInt32 value)
{
  return niDigital_WriteSequencerRegister(vi, reg, value);
}

ViStatus WriteSourceWaveformBroadcastU32(ViSession vi, ViConstString waveformName, ViInt32 waveformSize, ViUInt32 waveformData[])
{
  return niDigital_WriteSourceWaveformBroadcastU32(vi, waveformName, waveformSize, waveformData);
}

ViStatus WriteSourceWaveformDataFromFileTDMS(ViSession vi, ViConstString waveformName, ViConstString waveformFilePath)
{
  return niDigital_WriteSourceWaveformDataFromFileTDMS(vi, waveformName, waveformFilePath);
}

ViStatus WriteSourceWaveformSiteUniqueU32(ViSession vi, ViConstString siteList, ViConstString waveformName, ViInt32 numWaveforms, ViInt32 samplesPerWaveform, ViUInt32 waveformData[1])
{
  return niDigital_WriteSourceWaveformSiteUniqueU32(vi, siteList, waveformName, numWaveforms, samplesPerWaveform, waveformData);
}

ViStatus WriteStatic(ViSession vi, ViConstString channelList, ViUInt8 state)
{
  return niDigital_WriteStatic(vi, channelList, state);
}

}  // namespace nidigitalpattern_grpc
