/*
 * ctrl_custom.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.75
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Tue Jan 29 11:21:24 2019
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_custom_h_
#define RTW_HEADER_ctrl_custom_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_custom_COMMON_INCLUDES_
# define ctrl_custom_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_custom_COMMON_INCLUDES_ */

#include "ctrl_custom_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ctrl_custom_rtModel            RT_MODEL_ctrl_custom_T

/* Block signals for system '<S17>/Ned-Body' */
typedef struct {
  real_T y[3];                         /* '<S17>/Ned-Body' */
} B_NedBody_ctrl_custom_T;

/* Block signals (auto storage) */
typedef struct {
  real_T SIXAIS_INN;                   /* '<Root>/SIXAIS_INN' */
  real_T Ki;                           /* '<Root>/Ki' */
  real_T Kp;                           /* '<Root>/Kp' */
  real_T EtaSetX;                      /* '<Root>/EtaSetX' */
  real_T EtaSetY;                      /* '<Root>/EtaSetY' */
  real_T EtaSetPsi;                    /* '<Root>/EtaSetPsi' */
  real_T MomentDes;                    /* '<Root>/MomentDes' */
  real_T x_m;                          /* '<S5>/x_m' */
  real_T FXDes;                        /* '<Root>/FXDes' */
  real_T y_m;                          /* '<S5>/y_m' */
  real_T FyDes;                        /* '<Root>/FyDes' */
  real_T psi_m;                        /* '<S5>/psi_m' */
  real_T ThrustAlocMethod;             /* '<Root>/ThrustAlocMethod' */
  real_T etahat[3];                    /* '<S17>/Integrator' */
  real_T Useobserver4Eta;              /* '<S4>/Useobserver4Eta' */
  real_T DirectControl_or_Dp;          /* '<Root>/DirectControl_or_Dp' */
  real_T Uk1;                          /* '<S9>/Delay Input1' */
  real_T Integrator2[3];               /* '<S15>/Integrator2' */
  real_T Sum[3];                       /* '<S11>/Sum' */
  real_T Switch1;                      /* '<S7>/Switch1' */
  real_T Switch[7];                    /* '<S7>/Switch' */
  real_T IC[3];                        /* '<S13>/IC' */
  real_T Integrator[3];                /* '<S15>/Integrator' */
  real_T Saturation4[3];               /* '<S15>/Saturation4' */
  real_T Sum3[3];                      /* '<S15>/Sum3' */
  real_T w_n[3];                       /* '<S15>/w_n' */
  real_T Add;                          /* '<S16>/Add' */
  real_T d_etahat[3];                  /* '<S17>/Add' */
  real_T Multiply2[3];                 /* '<S17>/Multiply2' */
  real_T invM[3];                      /* '<S17>/invM' */
  real_T Acc_z;                        /* '<S2>/Acc_z' */
  real_T Acc_x;                        /* '<S2>/Acc_x' */
  real_T Acc_y;                        /* '<S2>/Acc_y' */
  real_T Gyro_x;                       /* '<S2>/Gyro_x' */
  real_T Gyro_y;                       /* '<S2>/Gyro_y' */
  real_T Gyro_z;                       /* '<S2>/Gyro_z' */
  real_T y[3];                         /* '<S11>/NED->Body' */
  boolean_T FixPtRelationalOperator;   /* '<S9>/FixPt Relational Operator' */
  B_NedBody_ctrl_custom_T sf_NedBody1; /* '<S17>/Ned-Body1' */
  B_NedBody_ctrl_custom_T sf_NedBody;  /* '<S17>/Ned-Body' */
} B_ctrl_custom_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S9>/Delay Input1' */
  real_T SIXAIS_INN_DWORK1;            /* '<Root>/SIXAIS_INN' */
  real_T Ki_DWORK1;                    /* '<Root>/Ki' */
  real_T Kp_DWORK1;                    /* '<Root>/Kp' */
  real_T SIXAIS_OUT_DWORK1;            /* '<Root>/SIXAIS_OUT' */
  real_T EtaSetX_DWORK1;               /* '<Root>/EtaSetX' */
  real_T EtaSetY_DWORK1;               /* '<Root>/EtaSetY' */
  real_T EtaSetPsi_DWORK1;             /* '<Root>/EtaSetPsi' */
  real_T MomentDes_DWORK1;             /* '<Root>/MomentDes' */
  real_T x_m_DWORK1;                   /* '<S5>/x_m' */
  real_T QTM_SCOPEX_DWORK1;            /* '<Root>/QTM_SCOPEX' */
  real_T FXDes_DWORK1;                 /* '<Root>/FXDes' */
  real_T y_m_DWORK1;                   /* '<S5>/y_m' */
  real_T QTM_SCOPEY_DWORK1;            /* '<Root>/QTM_SCOPEY' */
  real_T FyDes_DWORK1;                 /* '<Root>/FyDes' */
  real_T psi_m_DWORK1;                 /* '<S5>/psi_m' */
  real_T QTM_SCOPEPSI_DWORK1;          /* '<Root>/QTM_SCOPEPSI' */
  real_T ThrustAlocMethod_DWORK1;      /* '<Root>/ThrustAlocMethod' */
  real_T Useobserver4Eta_DWORK1;       /* '<S4>/Useobserver4Eta' */
  real_T DirectControl_or_Dp_DWORK1;   /* '<Root>/DirectControl_or_Dp' */
  real_T SaturationFlag_DWORK1;        /* '<Root>/SaturationFlag' */
  real_T alpha_VSP2_DWORK1;            /* '<S8>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1;            /* '<S8>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<S8>/omega_VSP2' */
  real_T alpha_VSP1_DWORK1;            /* '<S8>/alpha_VSP1' */
  real_T u_BT_DWORK1;                  /* '<S8>/u_BT' */
  real_T u_VSP1_DWORK1;                /* '<S8>/u_VSP1' */
  real_T u_VSP2_DWORK1;                /* '<S8>/u_VSP2' */
  real_T IC_FirstOutputTime;           /* '<S13>/IC' */
  real_T Acc_z_DWORK1;                 /* '<S2>/Acc_z' */
  real_T IMU_SCOPEZ_DWORK1;            /* '<S2>/IMU_SCOPEZ' */
  real_T Acc_x_DWORK1;                 /* '<S2>/Acc_x' */
  real_T Acc_y_DWORK1;                 /* '<S2>/Acc_y' */
  real_T Gyro_x_DWORK1;                /* '<S2>/Gyro_x' */
  real_T Gyro_y_DWORK1;                /* '<S2>/Gyro_y' */
  real_T Gyro_z_DWORK1;                /* '<S2>/Gyro_z' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S11>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_f;                     /* '<S13>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S13>/Scope1' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S15>/Scope5' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_g;                     /* '<S17>/Scope' */

  uint8_T SIXAIS_INN_DWORK2[12];       /* '<Root>/SIXAIS_INN' */
  uint8_T Ki_DWORK2[12];               /* '<Root>/Ki' */
  uint8_T Kp_DWORK2[12];               /* '<Root>/Kp' */
  uint8_T SIXAIS_OUT_DWORK2[12];       /* '<Root>/SIXAIS_OUT' */
  uint8_T EtaSetX_DWORK2[12];          /* '<Root>/EtaSetX' */
  uint8_T EtaSetY_DWORK2[12];          /* '<Root>/EtaSetY' */
  uint8_T EtaSetPsi_DWORK2[12];        /* '<Root>/EtaSetPsi' */
  uint8_T MomentDes_DWORK2[12];        /* '<Root>/MomentDes' */
  uint8_T x_m_DWORK2[12];              /* '<S5>/x_m' */
  uint8_T QTM_SCOPEX_DWORK2[12];       /* '<Root>/QTM_SCOPEX' */
  uint8_T FXDes_DWORK2[12];            /* '<Root>/FXDes' */
  uint8_T y_m_DWORK2[12];              /* '<S5>/y_m' */
  uint8_T QTM_SCOPEY_DWORK2[12];       /* '<Root>/QTM_SCOPEY' */
  uint8_T FyDes_DWORK2[12];            /* '<Root>/FyDes' */
  uint8_T psi_m_DWORK2[12];            /* '<S5>/psi_m' */
  uint8_T QTM_SCOPEPSI_DWORK2[12];     /* '<Root>/QTM_SCOPEPSI' */
  uint8_T ThrustAlocMethod_DWORK2[12]; /* '<Root>/ThrustAlocMethod' */
  uint8_T Useobserver4Eta_DWORK2[12];  /* '<S4>/Useobserver4Eta' */
  uint8_T DirectControl_or_Dp_DWORK2[12];/* '<Root>/DirectControl_or_Dp' */
  uint8_T SaturationFlag_DWORK2[12];   /* '<Root>/SaturationFlag' */
  uint8_T alpha_VSP2_DWORK2[12];       /* '<S8>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2[12];       /* '<S8>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[12];       /* '<S8>/omega_VSP2' */
  uint8_T alpha_VSP1_DWORK2[12];       /* '<S8>/alpha_VSP1' */
  uint8_T u_BT_DWORK2[12];             /* '<S8>/u_BT' */
  uint8_T u_VSP1_DWORK2[12];           /* '<S8>/u_VSP1' */
  uint8_T u_VSP2_DWORK2[12];           /* '<S8>/u_VSP2' */
  uint8_T Acc_z_DWORK2[12];            /* '<S2>/Acc_z' */
  uint8_T IMU_SCOPEZ_DWORK2[12];       /* '<S2>/IMU_SCOPEZ' */
  uint8_T Acc_x_DWORK2[12];            /* '<S2>/Acc_x' */
  uint8_T Acc_y_DWORK2[12];            /* '<S2>/Acc_y' */
  uint8_T Gyro_x_DWORK2[12];           /* '<S2>/Gyro_x' */
  uint8_T Gyro_y_DWORK2[12];           /* '<S2>/Gyro_y' */
  uint8_T Gyro_z_DWORK2[12];           /* '<S2>/Gyro_z' */
} DW_ctrl_custom_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S17>/Integrator' */
  real_T Integrator_CSTATE_f[3];       /* '<S11>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S15>/Integrator2' */
  real_T Integrator_CSTATE_i[3];       /* '<S15>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S15>/Integrator1' */
  real_T Integrator1_CSTATE_j[3];      /* '<S17>/Integrator1' */
  real_T B_CSTATE[3];                  /* '<S17>/B' */
} X_ctrl_custom_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S17>/Integrator' */
  real_T Integrator_CSTATE_f[3];       /* '<S11>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S15>/Integrator2' */
  real_T Integrator_CSTATE_i[3];       /* '<S15>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S15>/Integrator1' */
  real_T Integrator1_CSTATE_j[3];      /* '<S17>/Integrator1' */
  real_T B_CSTATE[3];                  /* '<S17>/B' */
} XDot_ctrl_custom_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S17>/Integrator' */
  boolean_T Integrator_CSTATE_f[3];    /* '<S11>/Integrator' */
  boolean_T Integrator2_CSTATE[3];     /* '<S15>/Integrator2' */
  boolean_T Integrator_CSTATE_i[3];    /* '<S15>/Integrator' */
  boolean_T Integrator1_CSTATE[3];     /* '<S15>/Integrator1' */
  boolean_T Integrator1_CSTATE_j[3];   /* '<S17>/Integrator1' */
  boolean_T B_CSTATE[3];               /* '<S17>/B' */
} XDis_ctrl_custom_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S11>/Integrator' */
} PrevZCX_ctrl_custom_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_custom_B
#define BlockIO                        B_ctrl_custom_T
#define rtX                            ctrl_custom_X
#define ContinuousStates               X_ctrl_custom_T
#define rtXdot                         ctrl_custom_XDot
#define StateDerivatives               XDot_ctrl_custom_T
#define tXdis                          ctrl_custom_XDis
#define StateDisabled                  XDis_ctrl_custom_T
#define rtP                            ctrl_custom_P
#define Parameters                     P_ctrl_custom_T
#define rtDWork                        ctrl_custom_DW
#define D_Work                         DW_ctrl_custom_T
#define rtPrevZCSigState               ctrl_custom_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_custom_T

/* Parameters (auto storage) */
struct P_ctrl_custom_T_ {
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S9>/Delay Input1'
                                        */
  real_T DeadReckoning_Value;          /* Expression: 0
                                        * Referenced by: '<S16>/Dead Reckoning'
                                        */
  real_T DRon_Value;                   /* Expression: 1
                                        * Referenced by: '<S16>/DR on '
                                        */
  real_T SIXAIS_INN_P1;                /* Expression: width
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  real_T SIXAIS_INN_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  real_T SIXAIS_INN_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  real_T SIXAIS_INN_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  real_T SIXAIS_INN_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  real_T SIXAIS_INN_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  real_T Ki_P1;                        /* Expression: width
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T Ki_P2;                        /* Expression: dtype
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T Ki_P3;                        /* Expression: portnum
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T Ki_P4;                        /* Expression: stime
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T Ki_P5;                        /* Expression: stype
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T Ki_P6;                        /* Expression: btype
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T Kp_P1;                        /* Expression: width
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T Kp_P2;                        /* Expression: dtype
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T Kp_P3;                        /* Expression: portnum
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T Kp_P4;                        /* Expression: stime
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T Kp_P5;                        /* Expression: stype
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T Kp_P6;                        /* Expression: btype
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T SIXAIS_OUT_P1;                /* Expression: width
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  real_T SIXAIS_OUT_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  real_T SIXAIS_OUT_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  real_T SIXAIS_OUT_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  real_T SIXAIS_OUT_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  real_T SIXAIS_OUT_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  real_T EtaSetX_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  real_T EtaSetX_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  real_T EtaSetX_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  real_T EtaSetX_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  real_T EtaSetX_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  real_T EtaSetX_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  real_T EtaSetY_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  real_T EtaSetY_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  real_T EtaSetY_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  real_T EtaSetY_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  real_T EtaSetY_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  real_T EtaSetY_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  real_T EtaSetPsi_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  real_T EtaSetPsi_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  real_T EtaSetPsi_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  real_T EtaSetPsi_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  real_T EtaSetPsi_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  real_T EtaSetPsi_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  real_T MomentDes_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  real_T MomentDes_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  real_T MomentDes_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  real_T MomentDes_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  real_T MomentDes_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  real_T MomentDes_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  real_T x_m_P1;                       /* Expression: width
                                        * Referenced by: '<S5>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S5>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S5>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S5>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S5>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S5>/x_m'
                                        */
  real_T QTM_SCOPEX_P1;                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  real_T QTM_SCOPEX_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  real_T QTM_SCOPEX_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  real_T QTM_SCOPEX_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  real_T QTM_SCOPEX_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  real_T QTM_SCOPEX_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  real_T FXDes_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/FXDes'
                                        */
  real_T FXDes_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/FXDes'
                                        */
  real_T FXDes_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/FXDes'
                                        */
  real_T FXDes_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/FXDes'
                                        */
  real_T FXDes_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/FXDes'
                                        */
  real_T FXDes_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/FXDes'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S5>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S5>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S5>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S5>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S5>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S5>/y_m'
                                        */
  real_T QTM_SCOPEY_P1;                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  real_T QTM_SCOPEY_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  real_T QTM_SCOPEY_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  real_T QTM_SCOPEY_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  real_T QTM_SCOPEY_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  real_T QTM_SCOPEY_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  real_T FyDes_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/FyDes'
                                        */
  real_T FyDes_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/FyDes'
                                        */
  real_T FyDes_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/FyDes'
                                        */
  real_T FyDes_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/FyDes'
                                        */
  real_T FyDes_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/FyDes'
                                        */
  real_T FyDes_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/FyDes'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/psi_m'
                                        */
  real_T QTM_SCOPEPSI_P1;              /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  real_T QTM_SCOPEPSI_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  real_T QTM_SCOPEPSI_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  real_T QTM_SCOPEPSI_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  real_T QTM_SCOPEPSI_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  real_T QTM_SCOPEPSI_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  real_T ThrustAlocMethod_P1;          /* Expression: width
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  real_T ThrustAlocMethod_P2;          /* Expression: dtype
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  real_T ThrustAlocMethod_P3;          /* Expression: portnum
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  real_T ThrustAlocMethod_P4;          /* Expression: stime
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  real_T ThrustAlocMethod_P5;          /* Expression: stype
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  real_T ThrustAlocMethod_P6;          /* Expression: btype
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S17>/Integrator'
                                        */
  real_T Useobserver4Eta_P1;           /* Expression: width
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  real_T Useobserver4Eta_P2;           /* Expression: dtype
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  real_T Useobserver4Eta_P3;           /* Expression: portnum
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  real_T Useobserver4Eta_P4;           /* Expression: stime
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  real_T Useobserver4Eta_P5;           /* Expression: stype
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  real_T Useobserver4Eta_P6;           /* Expression: btype
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T DirectControl_or_Dp_P1;       /* Expression: width
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  real_T DirectControl_or_Dp_P2;       /* Expression: dtype
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  real_T DirectControl_or_Dp_P3;       /* Expression: portnum
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  real_T DirectControl_or_Dp_P4;       /* Expression: stime
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  real_T DirectControl_or_Dp_P5;       /* Expression: stype
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  real_T DirectControl_or_Dp_P6;       /* Expression: btype
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  real_T Integrator_IC_h;              /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T Integrator2_IC[3];            /* Expression: [0;0;0]
                                        * Referenced by: '<S15>/Integrator2'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S7>/Switch1'
                                        */
  real_T SaturationFlag_P1;            /* Expression: width
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  real_T SaturationFlag_P2;            /* Expression: dtype
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  real_T SaturationFlag_P3;            /* Expression: portnum
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  real_T SaturationFlag_P4;            /* Expression: stime
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  real_T SaturationFlag_P5;            /* Expression: stype
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  real_T SaturationFlag_P6;            /* Expression: btype
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S8>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S8>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S8>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  real_T IC_Value[3];                  /* Expression: [0;0;0]
                                        * Referenced by: '<S13>/IC'
                                        */
  real_T Integrator_IC_g[3];           /* Expression: [0;0;0]
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 ;0; 0]
                                        * Referenced by: '<S15>/Integrator1'
                                        */
  real_T Saturation4_UpperSat[3];      /* Expression: [
                                          0.5600    0.5600    0.2120]
                                        * Referenced by: '<S15>/Saturation4'
                                        */
  real_T Saturation4_LowerSat[3];      /* Expression: -[
                                          0.5600    0.5600    0.2120]
                                        * Referenced by: '<S15>/Saturation4'
                                        */
  real_T w_n2_Gain[3];                 /* Expression: [   0.8000    0.8000    2.8000]
                                        * Referenced by: '<S15>/w_n2'
                                        */
  real_T w_n1_Gain[3];                 /* Expression: [ 0.8000    0.8000    2.8000]
                                        * Referenced by: '<S15>/w_n1'
                                        */
  real_T ciwni_Gain[3];                /* Expression: [
                                          0.7155    0.7155    1.3387
                                          ]
                                        * Referenced by: '<S15>/ciwni'
                                        */
  real_T w_n_Gain[3];                  /* Expression: [0.8944    0.8944    1.6733
                                          ]
                                        * Referenced by: '<S15>/w_n'
                                        */
  real_T Dummy_Value;                  /* Expression: 1
                                        * Referenced by: '<S16>/Dummy'
                                        */
  real_T L1_Gain[9];                   /* Expression: diag([1 1 1]*5)
                                        * Referenced by: '<S17>/L1'
                                        */
  real_T Integrator1_IC_p;             /* Expression: 0
                                        * Referenced by: '<S17>/Integrator1'
                                        */
  real_T L2_Gain[9];                   /* Expression: diag([1 1 1]*5)
                                        * Referenced by: '<S17>/L2 '
                                        */
  real_T Dsomewhatweirdwith725_Gain[9];/* Expression: [0.6555 0 0 ; 0 1.33  7.2500 ;0 0 1.9];
                                        * Referenced by: '<S17>/D (somewhat weird with 7.25) '
                                        */
  real_T B_IC;                         /* Expression: 0
                                        * Referenced by: '<S17>/B'
                                        */
  real_T L3_Gain[9];                   /* Expression: diag([1 1 1]*1)
                                        * Referenced by: '<S17>/L3'
                                        */
  real_T invM_Gain[9];                 /* Expression: [16.11 0 0;0 24.11 0.5291; 0 0.5291 2.76]^-1
                                        * Referenced by: '<S17>/invM'
                                        */
  real_T Acc_z_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  real_T Acc_z_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  real_T Acc_z_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  real_T Acc_z_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  real_T Acc_z_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  real_T Acc_z_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  real_T IMU_SCOPEZ_P1;                /* Expression: width
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  real_T IMU_SCOPEZ_P2;                /* Expression: dtype
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  real_T IMU_SCOPEZ_P3;                /* Expression: portnum
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  real_T IMU_SCOPEZ_P4;                /* Expression: stime
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  real_T IMU_SCOPEZ_P5;                /* Expression: stype
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  real_T IMU_SCOPEZ_P6;                /* Expression: btype
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  real_T Acc_x_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  real_T Acc_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  real_T Acc_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  real_T Acc_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  real_T Acc_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  real_T Acc_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  real_T Acc_y_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  real_T Acc_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  real_T Acc_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  real_T Acc_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  real_T Acc_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  real_T Acc_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  real_T Gyro_x_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  real_T Gyro_x_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  real_T Gyro_x_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  real_T Gyro_x_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  real_T Gyro_x_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  real_T Gyro_x_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  real_T Gyro_y_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  real_T Gyro_y_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  real_T Gyro_y_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  real_T Gyro_y_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  real_T Gyro_y_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  real_T Gyro_y_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  real_T Gyro_z_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  real_T Gyro_z_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  real_T Gyro_z_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  real_T Gyro_z_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  real_T Gyro_z_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  real_T Gyro_z_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S16>/Manual Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_custom_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[21];
  real_T odeF[4][21];
  ODE4_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ctrl_custom_T ctrl_custom_P;

/* Block signals (auto storage) */
extern B_ctrl_custom_T ctrl_custom_B;

/* Continuous states (auto storage) */
extern X_ctrl_custom_T ctrl_custom_X;

/* Block states (auto storage) */
extern DW_ctrl_custom_T ctrl_custom_DW;

/* Model entry point functions */
extern void ctrl_custom_initialize(void);
extern void ctrl_custom_output(void);
extern void ctrl_custom_update(void);
extern void ctrl_custom_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_custom_rtModel *ctrl_custom(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_custom_T *const ctrl_custom_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ctrl_custom'
 * '<S1>'   : 'ctrl_custom/Find tau_body'
 * '<S2>'   : 'ctrl_custom/IMU'
 * '<S3>'   : 'ctrl_custom/Model Info'
 * '<S4>'   : 'ctrl_custom/OBserver'
 * '<S5>'   : 'ctrl_custom/Pose'
 * '<S6>'   : 'ctrl_custom/Pose1'
 * '<S7>'   : 'ctrl_custom/Thrust Allocation'
 * '<S8>'   : 'ctrl_custom/u'
 * '<S9>'   : 'ctrl_custom/Find tau_body/Detect Change'
 * '<S10>'  : 'ctrl_custom/Find tau_body/Direct Control'
 * '<S11>'  : 'ctrl_custom/Find tau_body/Simple DP controller'
 * '<S12>'  : 'ctrl_custom/Find tau_body/Direct Control/NED->Body'
 * '<S13>'  : 'ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)'
 * '<S14>'  : 'ctrl_custom/Find tau_body/Simple DP controller/NED->Body'
 * '<S15>'  : 'ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model'
 * '<S16>'  : 'ctrl_custom/OBserver/Dead Reckoning ON//OFF  '
 * '<S17>'  : 'ctrl_custom/OBserver/SimpleObserver'
 * '<S18>'  : 'ctrl_custom/OBserver/SimpleObserver/Body->Ned'
 * '<S19>'  : 'ctrl_custom/OBserver/SimpleObserver/Ned-Body'
 * '<S20>'  : 'ctrl_custom/OBserver/SimpleObserver/Ned-Body1'
 * '<S21>'  : 'ctrl_custom/Thrust Allocation/Adjustable Alpha'
 * '<S22>'  : 'ctrl_custom/Thrust Allocation/Fixed Alhpa'
 */
#endif                                 /* RTW_HEADER_ctrl_custom_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.75
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Tue Jan 29 11:21:24 2019
 *========================================================================*/
#if !defined(NI_HEADER_ctrl_custom_h_)
#define NI_HEADER_ctrl_custom_h_
#ifdef NI_ROOTMODEL_ctrl_custom

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* ctrl_custom.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_ctrl_custom_T rtParameter[NUMST+!TID01EQ];
P_ctrl_custom_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_ctrl_custom_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_ctrl_custom_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_ctrl_custom_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
#endif                                 /* NI_HEADER_ctrl_custom_h_ */
