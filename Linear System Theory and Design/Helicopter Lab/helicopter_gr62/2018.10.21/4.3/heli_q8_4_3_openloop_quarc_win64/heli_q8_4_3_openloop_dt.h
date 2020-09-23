/*
 * heli_q8_4_3_openloop_dt.h
 *
 * Code generation for model "heli_q8_4_3_openloop".
 *
 * Model version              : 1.74
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sat Oct 20 11:39:46 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_game_controller),
  sizeof(t_card),
  sizeof(t_task)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_game_controller",
  "t_card",
  "t_task"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&heli_q8_4_3_openloop_B.Integrator[0]), 0, 0, 41 }
  ,

  { (char_T *)(&heli_q8_4_3_openloop_DW.HILInitialize_AIMinimums[0]), 0, 0, 68 },

  { (char_T *)(&heli_q8_4_3_openloop_DW.GameController_Controller), 14, 0, 1 },

  { (char_T *)(&heli_q8_4_3_openloop_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&heli_q8_4_3_openloop_DW.HILReadEncoderTimebase_Task), 16, 0, 1 },

  { (char_T *)(&heli_q8_4_3_openloop_DW.Scope_PWORK.LoggedData), 11, 0, 14 },

  { (char_T *)(&heli_q8_4_3_openloop_DW.HILInitialize_ClockModes[0]), 6, 0, 46 },

  { (char_T *)(&heli_q8_4_3_openloop_DW.HILInitialize_POSortedChans[0]), 7, 0, 8
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&heli_q8_4_3_openloop_P.A_0[0]), 0, 0, 105 },

  { (char_T *)(&heli_q8_4_3_openloop_P.HILReadEncoderTimebase_clock), 6, 0, 10 },

  { (char_T *)(&heli_q8_4_3_openloop_P.HILInitialize_analog_input_chan[0]), 7, 0,
    39 },

  { (char_T *)(&heli_q8_4_3_openloop_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&heli_q8_4_3_openloop_P.Integrator_IC), 0, 0, 46 },

  { (char_T *)(&heli_q8_4_3_openloop_P.GameController_BufferSize), 5, 0, 1 },

  { (char_T *)(&heli_q8_4_3_openloop_P.GameController_ControllerNumber), 3, 0, 1
  },

  { (char_T *)(&heli_q8_4_3_openloop_P.HILReadEncoderTimebase_Active), 8, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  8U,
  rtPTransitions
};

/* [EOF] heli_q8_4_3_openloop_dt.h */
