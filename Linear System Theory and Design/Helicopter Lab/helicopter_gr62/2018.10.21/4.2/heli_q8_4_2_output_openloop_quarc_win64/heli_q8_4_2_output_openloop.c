/*
 * heli_q8_4_2_output_openloop.c
 *
 * Code generation for model "heli_q8_4_2_output_openloop".
 *
 * Model version              : 1.75
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sat Oct 20 09:39:32 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "heli_q8_4_2_output_openloop.h"
#include "heli_q8_4_2_output_openloop_private.h"
#include "heli_q8_4_2_output_openloop_dt.h"

/* Block signals (auto storage) */
B_heli_q8_4_2_output_openloop_T heli_q8_4_2_output_openloop_B;

/* Continuous states */
X_heli_q8_4_2_output_openloop_T heli_q8_4_2_output_openloop_X;

/* Block states (auto storage) */
DW_heli_q8_4_2_output_openloo_T heli_q8_4_2_output_openloop_DW;

/* Real-time model */
RT_MODEL_heli_q8_4_2_output_o_T heli_q8_4_2_output_openloop_M_;
RT_MODEL_heli_q8_4_2_output_o_T *const heli_q8_4_2_output_openloop_M =
  &heli_q8_4_2_output_openloop_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_4_2_output_openloop_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_4_2_output_openloop_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_q8_4_2_output_openloop_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_4_2_output_openloop_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_4_2_output_openloop_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_4_2_output_openloop_M->Timing.perTaskSampleHits[5] =
      heli_q8_4_2_output_openloop_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_4_2_output_openloop_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_4_2_output_openloop_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_4_2_output_openloop_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 11;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_4_2_output_openloop_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_4_2_output_openloop_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_DeadZoney;
  real_T rtb_Frontgain;
  real_T rtb_Sum2[2];
  int32_T i;
  real_T rtb_Gain7_0[5];
  real_T tmp[3];
  real_T tmp_0[6];
  real_T tmp_1[6];
  int32_T i_0;
  real_T rtb_Gain7_idx_2;
  real_T rtb_Gain7_idx_5;
  real_T unnamed_idx_2;
  real_T u0;
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    /* set solver stop time */
    if (!(heli_q8_4_2_output_openloop_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_4_2_output_openloop_M->solverInfo,
                            ((heli_q8_4_2_output_openloop_M->Timing.clockTickH0
        + 1) * heli_q8_4_2_output_openloop_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_4_2_output_openloop_M->solverInfo,
                            ((heli_q8_4_2_output_openloop_M->Timing.clockTick0 +
        1) * heli_q8_4_2_output_openloop_M->Timing.stepSize0 +
        heli_q8_4_2_output_openloop_M->Timing.clockTickH0 *
        heli_q8_4_2_output_openloop_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_4_2_output_openloop_M)) {
    heli_q8_4_2_output_openloop_M->Timing.t[0] = rtsiGetT
      (&heli_q8_4_2_output_openloop_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_4_2_output_openloop/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (heli_q8_4_2_output_openloop_DW.HILReadEncoderTimebase_Task, 1,
         &heli_q8_4_2_output_openloop_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_4_2_output_openloop_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_4_2_output_openloop_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney =
          heli_q8_4_2_output_openloop_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* Integrator: '<S3>/Integrator' */
  for (i = 0; i < 6; i++) {
    heli_q8_4_2_output_openloop_B.Integrator[i] =
      heli_q8_4_2_output_openloop_X.Integrator_CSTATE[i];
  }

  /* End of Integrator: '<S3>/Integrator' */
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    /* Gain: '<S2>/Pitch: Count to rad' */
    heli_q8_4_2_output_openloop_B.PitchCounttorad =
      heli_q8_4_2_output_openloop_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Gain: '<S7>/Gain'
     */
    heli_q8_4_2_output_openloop_B.Sum1 = heli_q8_4_2_output_openloop_P.Gain_Gain
      * heli_q8_4_2_output_openloop_B.PitchCounttorad +
      heli_q8_4_2_output_openloop_P.Constant1_Value;

    /* Gain: '<Root>/Gain' */
    heli_q8_4_2_output_openloop_B.Gain =
      heli_q8_4_2_output_openloop_P.Gain_Gain_n *
      heli_q8_4_2_output_openloop_B.Sum1;
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  TransferFcn: '<S2>/Pitch: Transfer Fcn'
   */
  heli_q8_4_2_output_openloop_B.Gain_o =
    (heli_q8_4_2_output_openloop_P.PitchTransferFcn_C *
     heli_q8_4_2_output_openloop_X.PitchTransferFcn_CSTATE +
     heli_q8_4_2_output_openloop_P.PitchTransferFcn_D *
     heli_q8_4_2_output_openloop_B.PitchCounttorad) *
    heli_q8_4_2_output_openloop_P.Gain_Gain_f;

  /* Gain: '<Root>/Gain4' */
  heli_q8_4_2_output_openloop_B.Gain4 = heli_q8_4_2_output_openloop_P.Gain4_Gain
    * heli_q8_4_2_output_openloop_B.Gain_o;
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    /* Gain: '<S2>/Elevation: Count to rad' */
    heli_q8_4_2_output_openloop_B.ElevationCounttorad =
      heli_q8_4_2_output_openloop_P.ElevationCounttorad_Gain * rtb_DeadZoney;
  }

  /* Gain: '<S6>/Gain' incorporates:
   *  TransferFcn: '<S2>/Elevation: Transfer Fcn'
   */
  heli_q8_4_2_output_openloop_B.Gain_p =
    (heli_q8_4_2_output_openloop_P.ElevationTransferFcn_C *
     heli_q8_4_2_output_openloop_X.ElevationTransferFcn_CSTATE +
     heli_q8_4_2_output_openloop_P.ElevationTransferFcn_D *
     heli_q8_4_2_output_openloop_B.ElevationCounttorad) *
    heli_q8_4_2_output_openloop_P.Gain_Gain_j;

  /* Gain: '<Root>/Gain6' */
  heli_q8_4_2_output_openloop_B.Gain6 = heli_q8_4_2_output_openloop_P.Gain6_Gain
    * heli_q8_4_2_output_openloop_B.Gain_p;
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    /* Constant: '<Root>/Constant1' */
    heli_q8_4_2_output_openloop_B.Constant1 =
      heli_q8_4_2_output_openloop_P.Constant1_Value_a;

    /* Gain: '<S2>/Travel: Count to rad' */
    heli_q8_4_2_output_openloop_B.TravelCounttorad =
      heli_q8_4_2_output_openloop_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S9>/Gain' */
    heli_q8_4_2_output_openloop_B.Gain_b =
      heli_q8_4_2_output_openloop_P.Gain_Gain_b *
      heli_q8_4_2_output_openloop_B.TravelCounttorad;
  }

  /* Gain: '<S10>/Gain' incorporates:
   *  TransferFcn: '<S2>/Travel: Transfer Fcn'
   */
  heli_q8_4_2_output_openloop_B.Gain_i =
    (heli_q8_4_2_output_openloop_P.TravelTransferFcn_C *
     heli_q8_4_2_output_openloop_X.TravelTransferFcn_CSTATE +
     heli_q8_4_2_output_openloop_P.TravelTransferFcn_D *
     heli_q8_4_2_output_openloop_B.TravelCounttorad) *
    heli_q8_4_2_output_openloop_P.Gain_Gain_d;
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S5>/Gain'
     */
    heli_q8_4_2_output_openloop_B.Sum =
      heli_q8_4_2_output_openloop_P.Gain_Gain_l *
      heli_q8_4_2_output_openloop_B.ElevationCounttorad +
      heli_q8_4_2_output_openloop_P.Constant_Value;
  }

  /* Gain: '<Root>/Gain7' */
  rtb_Gain7_idx_2 = heli_q8_4_2_output_openloop_P.Gain7_Gain *
    heli_q8_4_2_output_openloop_B.Sum1;
  rtb_Gain7_idx_5 = heli_q8_4_2_output_openloop_P.Gain7_Gain *
    heli_q8_4_2_output_openloop_B.Gain_p;

  /* RateTransition: '<S11>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    if (heli_q8_4_2_output_openloop_M->Timing.RateInteraction.TID1_2) {
      heli_q8_4_2_output_openloop_B.RateTransitionx =
        heli_q8_4_2_output_openloop_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S11>/Dead Zone: x' */
    if (heli_q8_4_2_output_openloop_B.RateTransitionx >
        heli_q8_4_2_output_openloop_P.DeadZonex_End) {
      rtb_DeadZoney = heli_q8_4_2_output_openloop_B.RateTransitionx -
        heli_q8_4_2_output_openloop_P.DeadZonex_End;
    } else if (heli_q8_4_2_output_openloop_B.RateTransitionx >=
               heli_q8_4_2_output_openloop_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = heli_q8_4_2_output_openloop_B.RateTransitionx -
        heli_q8_4_2_output_openloop_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S11>/Dead Zone: x' */

    /* Gain: '<S11>/Joystick_gain_x' incorporates:
     *  Gain: '<S11>/Gain: x'
     */
    heli_q8_4_2_output_openloop_B.Joystick_gain_x =
      heli_q8_4_2_output_openloop_P.Gainx_Gain * rtb_DeadZoney *
      heli_q8_4_2_output_openloop_P.Joystick_gain_x;

    /* Gain: '<S4>/Gain2' */
    heli_q8_4_2_output_openloop_B.Gain2 =
      heli_q8_4_2_output_openloop_P.Gain2_Gain *
      heli_q8_4_2_output_openloop_B.Joystick_gain_x;

    /* RateTransition: '<S11>/Rate Transition: y' */
    if (heli_q8_4_2_output_openloop_M->Timing.RateInteraction.TID1_2) {
      heli_q8_4_2_output_openloop_B.RateTransitiony =
        heli_q8_4_2_output_openloop_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S11>/Rate Transition: y' */

    /* DeadZone: '<S11>/Dead Zone: y' */
    if (heli_q8_4_2_output_openloop_B.RateTransitiony >
        heli_q8_4_2_output_openloop_P.DeadZoney_End) {
      rtb_DeadZoney = heli_q8_4_2_output_openloop_B.RateTransitiony -
        heli_q8_4_2_output_openloop_P.DeadZoney_End;
    } else if (heli_q8_4_2_output_openloop_B.RateTransitiony >=
               heli_q8_4_2_output_openloop_P.DeadZoney_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = heli_q8_4_2_output_openloop_B.RateTransitiony -
        heli_q8_4_2_output_openloop_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S11>/Dead Zone: y' */

    /* Gain: '<S11>/Joystick_gain_y' incorporates:
     *  Gain: '<S11>/Gain: y'
     */
    heli_q8_4_2_output_openloop_B.Joystick_gain_y =
      heli_q8_4_2_output_openloop_P.Gainy_Gain * rtb_DeadZoney *
      heli_q8_4_2_output_openloop_P.Joystick_gain_y;

    /* Gain: '<S4>/Gain5' */
    heli_q8_4_2_output_openloop_B.Gain5 =
      heli_q8_4_2_output_openloop_P.Gain5_Gain *
      heli_q8_4_2_output_openloop_B.Joystick_gain_y;

    /* Gain: '<S4>/P' incorporates:
     *  SignalConversion: '<S4>/TmpSignal ConversionAtPInport1'
     */
    heli_q8_4_2_output_openloop_B.P[0] = 0.0;
    heli_q8_4_2_output_openloop_B.P[0] += heli_q8_4_2_output_openloop_P.P[0] *
      heli_q8_4_2_output_openloop_B.Gain2;
    heli_q8_4_2_output_openloop_B.P[0] += heli_q8_4_2_output_openloop_P.P[2] *
      heli_q8_4_2_output_openloop_B.Gain5;
    heli_q8_4_2_output_openloop_B.P[1] = 0.0;
    heli_q8_4_2_output_openloop_B.P[1] += heli_q8_4_2_output_openloop_P.P[1] *
      heli_q8_4_2_output_openloop_B.Gain2;
    heli_q8_4_2_output_openloop_B.P[1] += heli_q8_4_2_output_openloop_P.P[3] *
      heli_q8_4_2_output_openloop_B.Gain5;
  }

  /* End of RateTransition: '<S11>/Rate Transition: x' */

  /* SignalConversion: '<S4>/TmpSignal ConversionAtK1Inport1' incorporates:
   *  Gain: '<Root>/Gain7'
   *  Gain: '<S4>/K1'
   *  Integrator: '<S4>/Integrator'
   *  Integrator: '<S4>/Integrator1'
   */
  rtb_Gain7_0[0] = rtb_Gain7_idx_2;
  rtb_Gain7_0[1] = heli_q8_4_2_output_openloop_P.Gain7_Gain *
    heli_q8_4_2_output_openloop_B.Gain_o;
  rtb_Gain7_0[2] = rtb_Gain7_idx_5;
  rtb_Gain7_0[3] = heli_q8_4_2_output_openloop_X.Integrator_CSTATE_j;
  rtb_Gain7_0[4] = heli_q8_4_2_output_openloop_X.Integrator1_CSTATE;

  /* Sum: '<S4>/Sum2' incorporates:
   *  Gain: '<S4>/K1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Frontgain = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Frontgain += heli_q8_4_2_output_openloop_P.K[(i_0 << 1) + i] *
        rtb_Gain7_0[i_0];
    }

    rtb_Sum2[i] = heli_q8_4_2_output_openloop_B.P[i] - rtb_Frontgain;
  }

  /* End of Sum: '<S4>/Sum2' */

  /* Sum: '<Root>/Sum1' */
  rtb_Frontgain = rtb_Sum2[0] + heli_q8_4_2_output_openloop_B.Constant1;
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    /* Gain: '<Root>/Gain1' */
    heli_q8_4_2_output_openloop_B.Gain1 =
      heli_q8_4_2_output_openloop_P.Gain1_Gain *
      heli_q8_4_2_output_openloop_B.Sum;

    /* Gain: '<Root>/Gain3' */
    heli_q8_4_2_output_openloop_B.Gain3 =
      heli_q8_4_2_output_openloop_P.Gain3_Gain *
      heli_q8_4_2_output_openloop_B.Gain_b;
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (rtb_Sum2[1] + rtb_Frontgain) *
    heli_q8_4_2_output_openloop_P.Frontgain_Gain;

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (u0 > heli_q8_4_2_output_openloop_P.FrontmotorSaturation_UpperSat) {
    heli_q8_4_2_output_openloop_B.FrontmotorSaturation =
      heli_q8_4_2_output_openloop_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < heli_q8_4_2_output_openloop_P.FrontmotorSaturation_LowerSat) {
    heli_q8_4_2_output_openloop_B.FrontmotorSaturation =
      heli_q8_4_2_output_openloop_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_q8_4_2_output_openloop_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (rtb_Frontgain - rtb_Sum2[1]) *
    heli_q8_4_2_output_openloop_P.Backgain_Gain;

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (u0 > heli_q8_4_2_output_openloop_P.BackmotorSaturation_UpperSat) {
    heli_q8_4_2_output_openloop_B.BackmotorSaturation =
      heli_q8_4_2_output_openloop_P.BackmotorSaturation_UpperSat;
  } else if (u0 < heli_q8_4_2_output_openloop_P.BackmotorSaturation_LowerSat) {
    heli_q8_4_2_output_openloop_B.BackmotorSaturation =
      heli_q8_4_2_output_openloop_P.BackmotorSaturation_LowerSat;
  } else {
    heli_q8_4_2_output_openloop_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: heli_q8_4_2_output_openloop/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_4_2_output_openloop_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_4_2_output_openloop_B.FrontmotorSaturation;
      heli_q8_4_2_output_openloop_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_4_2_output_openloop_B.BackmotorSaturation;
      result = hil_write_analog
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILWriteAnalog_channels, 2,
         &heli_q8_4_2_output_openloop_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S3>/C_0' incorporates:
   *  Sum: '<S3>/Sum2'
   */
  for (i = 0; i < 3; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp[i] += heli_q8_4_2_output_openloop_P.C_0[3 * i_0 + i] *
        heli_q8_4_2_output_openloop_B.Integrator[i_0];
    }
  }

  /* End of Gain: '<S3>/C_0' */

  /* Sum: '<S3>/Sum2' incorporates:
   *  Gain: '<S3>/L'
   */
  rtb_Frontgain = heli_q8_4_2_output_openloop_B.Gain - tmp[0];
  u0 = heli_q8_4_2_output_openloop_B.Gain1 - tmp[1];
  unnamed_idx_2 = heli_q8_4_2_output_openloop_B.Gain3 - tmp[2];
  for (i = 0; i < 6; i++) {
    /* Gain: '<S3>/B_0' incorporates:
     *  Sum: '<S3>/Sum'
     */
    tmp_0[i] = heli_q8_4_2_output_openloop_P.B_0[i + 6] * rtb_Sum2[1] +
      heli_q8_4_2_output_openloop_P.B_0[i] * rtb_Sum2[0];

    /* Gain: '<S3>/L' incorporates:
     *  Sum: '<S3>/Sum'
     */
    tmp_1[i] = heli_q8_4_2_output_openloop_P.L[i + 12] * unnamed_idx_2 +
      (heli_q8_4_2_output_openloop_P.L[i + 6] * u0 +
       heli_q8_4_2_output_openloop_P.L[i] * rtb_Frontgain);
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/A_0'
   */
  for (i = 0; i < 6; i++) {
    rtb_Frontgain = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Frontgain += heli_q8_4_2_output_openloop_P.A_0[6 * i_0 + i] *
        heli_q8_4_2_output_openloop_B.Integrator[i_0];
    }

    heli_q8_4_2_output_openloop_B.Sum_n[i] = (tmp_0[i] + tmp_1[i]) +
      rtb_Frontgain;
  }

  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
  }

  /* Sum: '<S4>/Sum' */
  heli_q8_4_2_output_openloop_B.Sum_i = rtb_Gain7_idx_2 -
    heli_q8_4_2_output_openloop_B.Gain2;

  /* Sum: '<S4>/Sum1' */
  heli_q8_4_2_output_openloop_B.Sum1_j = rtb_Gain7_idx_5 -
    heli_q8_4_2_output_openloop_B.Gain5;
}

/* Model update function for TID0 */
void heli_q8_4_2_output_openloop_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_4_2_output_openloop_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_4_2_output_openloop_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_4_2_output_openloop_M->Timing.clockTick0)) {
    ++heli_q8_4_2_output_openloop_M->Timing.clockTickH0;
  }

  heli_q8_4_2_output_openloop_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_4_2_output_openloop_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_4_2_output_openloop_M->Timing.clockTick1)) {
    ++heli_q8_4_2_output_openloop_M->Timing.clockTickH1;
  }

  heli_q8_4_2_output_openloop_M->Timing.t[1] =
    heli_q8_4_2_output_openloop_M->Timing.clockTick1 *
    heli_q8_4_2_output_openloop_M->Timing.stepSize1 +
    heli_q8_4_2_output_openloop_M->Timing.clockTickH1 *
    heli_q8_4_2_output_openloop_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_4_2_output_openloop_derivatives(void)
{
  int32_T i;
  XDot_heli_q8_4_2_output_openl_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_4_2_output_openl_T *)
             heli_q8_4_2_output_openloop_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S3>/Integrator' */
  for (i = 0; i < 6; i++) {
    _rtXdot->Integrator_CSTATE[i] = heli_q8_4_2_output_openloop_B.Sum_n[i];
  }

  /* End of Derivatives for Integrator: '<S3>/Integrator' */

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE +=
    heli_q8_4_2_output_openloop_P.PitchTransferFcn_A *
    heli_q8_4_2_output_openloop_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE +=
    heli_q8_4_2_output_openloop_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    heli_q8_4_2_output_openloop_P.ElevationTransferFcn_A *
    heli_q8_4_2_output_openloop_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    heli_q8_4_2_output_openloop_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE +=
    heli_q8_4_2_output_openloop_P.TravelTransferFcn_A *
    heli_q8_4_2_output_openloop_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE +=
    heli_q8_4_2_output_openloop_B.TravelCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = heli_q8_4_2_output_openloop_B.Sum_i;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_4_2_output_openloop_B.Sum1_j;
}

/* Model output function for TID2 */
void heli_q8_4_2_output_openloop_output2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S11>/Game Controller' */

  /* S-Function Block: heli_q8_4_2_output_openloop/PI Controller/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_4_2_output_openloop_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (heli_q8_4_2_output_openloop_DW.GameController_Controller, &state,
         &new_data);
      if (result == 0) {
        heli_q8_4_2_output_openloop_B.GameController_o4 = state.x;
        heli_q8_4_2_output_openloop_B.GameController_o5 = state.y;
      }
    } else {
      heli_q8_4_2_output_openloop_B.GameController_o4 = 0;
      heli_q8_4_2_output_openloop_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_q8_4_2_output_openloop_update2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S11>/Rate Transition: x' */
  heli_q8_4_2_output_openloop_DW.RateTransitionx_Buffer0 =
    heli_q8_4_2_output_openloop_B.GameController_o4;

  /* Update for RateTransition: '<S11>/Rate Transition: y' */
  heli_q8_4_2_output_openloop_DW.RateTransitiony_Buffer0 =
    heli_q8_4_2_output_openloop_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_4_2_output_openloop_M->Timing.clockTick2)) {
    ++heli_q8_4_2_output_openloop_M->Timing.clockTickH2;
  }

  heli_q8_4_2_output_openloop_M->Timing.t[2] =
    heli_q8_4_2_output_openloop_M->Timing.clockTick2 *
    heli_q8_4_2_output_openloop_M->Timing.stepSize2 +
    heli_q8_4_2_output_openloop_M->Timing.clockTickH2 *
    heli_q8_4_2_output_openloop_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_4_2_output_openloop_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_4_2_output_openloop_output0();
    break;

   case 2 :
    heli_q8_4_2_output_openloop_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_4_2_output_openloop_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_4_2_output_openloop_update0();
    break;

   case 2 :
    heli_q8_4_2_output_openloop_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_4_2_output_openloop_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_4_2_output_openloop/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0",
                      &heli_q8_4_2_output_openloop_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (heli_q8_4_2_output_openloop_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
      return;
    }

    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_input_ &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_inpu_m &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_analog_input_chan, 8U,
         &heli_q8_4_2_output_openloop_DW.HILInitialize_AIMinimums[0],
         &heli_q8_4_2_output_openloop_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_output &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_outp_b &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_4_2_output_openloop_DW.HILInitialize_AOMinimums[0],
         &heli_q8_4_2_output_openloop_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_outp_e &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_outp_j &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_4_2_output_openloop_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_4_2_output_openloop_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_encoder_param &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_encoder_par_m &&
         is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_4_2_output_openloop_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_encoder_count &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_encoder_cou_k &&
         is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_encoder_channels, 8U,
         &heli_q8_4_2_output_openloop_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_pwm_params_at &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_pwm_params__f &&
         is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_pwm_channels, 8U,
         (t_pwm_mode *)
         &heli_q8_4_2_output_openloop_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_q8_4_2_output_openloop_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = heli_q8_4_2_output_openloop_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              heli_q8_4_2_output_openloop_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
           &heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
           &heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_pwm_channels, 8U,
         (t_pwm_configuration *)
         &heli_q8_4_2_output_openloop_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &heli_q8_4_2_output_openloop_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &heli_q8_4_2_output_openloop_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedFreqs[0],
         &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_pwm_outputs_a &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_pwm_outputs_g &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
        heli_q8_4_2_output_openloop_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_4_2_output_openloop_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
         heli_q8_4_2_output_openloop_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_4_2_output_openloop/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
       heli_q8_4_2_output_openloop_P.HILReadEncoderTimebase_samples_,
       heli_q8_4_2_output_openloop_P.HILReadEncoderTimebase_channels, 3,
       &heli_q8_4_2_output_openloop_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S11>/Rate Transition: x' */
  heli_q8_4_2_output_openloop_B.RateTransitionx =
    heli_q8_4_2_output_openloop_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S11>/Rate Transition: y' */
  heli_q8_4_2_output_openloop_B.RateTransitiony =
    heli_q8_4_2_output_openloop_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S11>/Game Controller' */

  /* S-Function Block: heli_q8_4_2_output_openloop/PI Controller/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_4_2_output_openloop_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (heli_q8_4_2_output_openloop_P.GameController_ControllerNumber,
         heli_q8_4_2_output_openloop_P.GameController_BufferSize, deadzone,
         saturation, heli_q8_4_2_output_openloop_P.GameController_AutoCenter, 0,
         1.0, &heli_q8_4_2_output_openloop_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    for (i = 0; i < 6; i++) {
      heli_q8_4_2_output_openloop_X.Integrator_CSTATE[i] =
        heli_q8_4_2_output_openloop_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<S3>/Integrator' */

    /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
    heli_q8_4_2_output_openloop_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
    heli_q8_4_2_output_openloop_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
    heli_q8_4_2_output_openloop_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    heli_q8_4_2_output_openloop_X.Integrator_CSTATE_j =
      heli_q8_4_2_output_openloop_P.Integrator_IC_b;

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    heli_q8_4_2_output_openloop_X.Integrator1_CSTATE =
      heli_q8_4_2_output_openloop_P.Integrator1_IC;

    /* InitializeConditions for RateTransition: '<S11>/Rate Transition: x' */
    heli_q8_4_2_output_openloop_DW.RateTransitionx_Buffer0 =
      heli_q8_4_2_output_openloop_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S11>/Rate Transition: y' */
    heli_q8_4_2_output_openloop_DW.RateTransitiony_Buffer0 =
      heli_q8_4_2_output_openloop_P.RateTransitiony_X0;
  }
}

/* Model terminate function */
void heli_q8_4_2_output_openloop_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_4_2_output_openloop/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_4_2_output_openloop_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_4_2_output_openloop_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_out_ex &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_analog_outp_c &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_4_2_output_openloop_P.HILInitialize_set_pwm_output_ap &&
         !is_switching) ||
        (heli_q8_4_2_output_openloop_P.HILInitialize_set_pwm_outputs_p &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            heli_q8_4_2_output_openloop_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_4_2_output_openloop_DW.HILInitialize_Card
                         ,
                         heli_q8_4_2_output_openloop_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         ,
                         heli_q8_4_2_output_openloop_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         ,
                         &heli_q8_4_2_output_openloop_DW.HILInitialize_AOVoltages
                         [0]
                         ,
                         &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues
                         [0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
             heli_q8_4_2_output_openloop_P.HILInitialize_analog_output_cha,
             num_final_analog_outputs,
             &heli_q8_4_2_output_openloop_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (heli_q8_4_2_output_openloop_DW.HILInitialize_Card,
             heli_q8_4_2_output_openloop_P.HILInitialize_pwm_channels,
             num_final_pwm_outputs,
             &heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_4_2_output_openloop_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_4_2_output_openloop_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_4_2_output_openloop_DW.HILInitialize_Card);
    hil_close(heli_q8_4_2_output_openloop_DW.HILInitialize_Card);
    heli_q8_4_2_output_openloop_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S11>/Game Controller' */

  /* S-Function Block: heli_q8_4_2_output_openloop/PI Controller/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_4_2_output_openloop_P.GameController_Enabled) {
      game_controller_close
        (heli_q8_4_2_output_openloop_DW.GameController_Controller);
      heli_q8_4_2_output_openloop_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_4_2_output_openloop_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_4_2_output_openloop_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_q8_4_2_output_openloop_initialize();
}

void MdlTerminate(void)
{
  heli_q8_4_2_output_openloop_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_4_2_output_o_T *heli_q8_4_2_output_openloop(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_4_2_output_openloop_M, 0,
                sizeof(RT_MODEL_heli_q8_4_2_output_o_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_4_2_output_openloop_M->solverInfo,
                          &heli_q8_4_2_output_openloop_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_4_2_output_openloop_M->solverInfo, &rtmGetTPtr
                (heli_q8_4_2_output_openloop_M));
    rtsiSetStepSizePtr(&heli_q8_4_2_output_openloop_M->solverInfo,
                       &heli_q8_4_2_output_openloop_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_4_2_output_openloop_M->solverInfo,
                 &heli_q8_4_2_output_openloop_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_q8_4_2_output_openloop_M->solverInfo, (real_T **)
                         &heli_q8_4_2_output_openloop_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_q8_4_2_output_openloop_M->solverInfo,
      &heli_q8_4_2_output_openloop_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&heli_q8_4_2_output_openloop_M->solverInfo,
                          (&rtmGetErrorStatus(heli_q8_4_2_output_openloop_M)));
    rtsiSetRTModelPtr(&heli_q8_4_2_output_openloop_M->solverInfo,
                      heli_q8_4_2_output_openloop_M);
  }

  rtsiSetSimTimeStep(&heli_q8_4_2_output_openloop_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_4_2_output_openloop_M->ModelData.intgData.f[0] =
    heli_q8_4_2_output_openloop_M->ModelData.odeF[0];
  heli_q8_4_2_output_openloop_M->ModelData.contStates = ((real_T *)
    &heli_q8_4_2_output_openloop_X);
  rtsiSetSolverData(&heli_q8_4_2_output_openloop_M->solverInfo, (void *)
                    &heli_q8_4_2_output_openloop_M->ModelData.intgData);
  rtsiSetSolverName(&heli_q8_4_2_output_openloop_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      heli_q8_4_2_output_openloop_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_4_2_output_openloop_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_4_2_output_openloop_M->Timing.sampleTimes =
      (&heli_q8_4_2_output_openloop_M->Timing.sampleTimesArray[0]);
    heli_q8_4_2_output_openloop_M->Timing.offsetTimes =
      (&heli_q8_4_2_output_openloop_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_4_2_output_openloop_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_4_2_output_openloop_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_4_2_output_openloop_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_4_2_output_openloop_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_4_2_output_openloop_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_4_2_output_openloop_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_4_2_output_openloop_M,
             &heli_q8_4_2_output_openloop_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_4_2_output_openloop_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      heli_q8_4_2_output_openloop_M->Timing.perTaskSampleHitsArray;
    heli_q8_4_2_output_openloop_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_4_2_output_openloop_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_4_2_output_openloop_M, -1);
  heli_q8_4_2_output_openloop_M->Timing.stepSize0 = 0.002;
  heli_q8_4_2_output_openloop_M->Timing.stepSize1 = 0.002;
  heli_q8_4_2_output_openloop_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_4_2_output_openloop_M->Sizes.checksums[0] = (36095233U);
  heli_q8_4_2_output_openloop_M->Sizes.checksums[1] = (2257210748U);
  heli_q8_4_2_output_openloop_M->Sizes.checksums[2] = (603967416U);
  heli_q8_4_2_output_openloop_M->Sizes.checksums[3] = (157487746U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    heli_q8_4_2_output_openloop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_4_2_output_openloop_M->extModeInfo,
      &heli_q8_4_2_output_openloop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_4_2_output_openloop_M->extModeInfo,
                        heli_q8_4_2_output_openloop_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_4_2_output_openloop_M->extModeInfo, rtmGetTPtr
                (heli_q8_4_2_output_openloop_M));
  }

  heli_q8_4_2_output_openloop_M->solverInfoPtr =
    (&heli_q8_4_2_output_openloop_M->solverInfo);
  heli_q8_4_2_output_openloop_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_4_2_output_openloop_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_4_2_output_openloop_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_4_2_output_openloop_M->ModelData.blockIO = ((void *)
    &heli_q8_4_2_output_openloop_B);

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_4_2_output_openloop_B.Integrator[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_4_2_output_openloop_B.Sum_n[i] = 0.0;
    }

    heli_q8_4_2_output_openloop_B.PitchCounttorad = 0.0;
    heli_q8_4_2_output_openloop_B.Sum1 = 0.0;
    heli_q8_4_2_output_openloop_B.Gain = 0.0;
    heli_q8_4_2_output_openloop_B.Gain_o = 0.0;
    heli_q8_4_2_output_openloop_B.Gain4 = 0.0;
    heli_q8_4_2_output_openloop_B.ElevationCounttorad = 0.0;
    heli_q8_4_2_output_openloop_B.Gain_p = 0.0;
    heli_q8_4_2_output_openloop_B.Gain6 = 0.0;
    heli_q8_4_2_output_openloop_B.Constant1 = 0.0;
    heli_q8_4_2_output_openloop_B.TravelCounttorad = 0.0;
    heli_q8_4_2_output_openloop_B.Gain_b = 0.0;
    heli_q8_4_2_output_openloop_B.Gain_i = 0.0;
    heli_q8_4_2_output_openloop_B.Sum = 0.0;
    heli_q8_4_2_output_openloop_B.RateTransitionx = 0.0;
    heli_q8_4_2_output_openloop_B.Joystick_gain_x = 0.0;
    heli_q8_4_2_output_openloop_B.Gain2 = 0.0;
    heli_q8_4_2_output_openloop_B.RateTransitiony = 0.0;
    heli_q8_4_2_output_openloop_B.Joystick_gain_y = 0.0;
    heli_q8_4_2_output_openloop_B.Gain5 = 0.0;
    heli_q8_4_2_output_openloop_B.P[0] = 0.0;
    heli_q8_4_2_output_openloop_B.P[1] = 0.0;
    heli_q8_4_2_output_openloop_B.Gain1 = 0.0;
    heli_q8_4_2_output_openloop_B.Gain3 = 0.0;
    heli_q8_4_2_output_openloop_B.FrontmotorSaturation = 0.0;
    heli_q8_4_2_output_openloop_B.BackmotorSaturation = 0.0;
    heli_q8_4_2_output_openloop_B.GameController_o4 = 0.0;
    heli_q8_4_2_output_openloop_B.GameController_o5 = 0.0;
    heli_q8_4_2_output_openloop_B.Sum_i = 0.0;
    heli_q8_4_2_output_openloop_B.Sum1_j = 0.0;
  }

  /* parameters */
  heli_q8_4_2_output_openloop_M->ModelData.defaultParam = ((real_T *)
    &heli_q8_4_2_output_openloop_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_4_2_output_openloop_X;
    heli_q8_4_2_output_openloop_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_q8_4_2_output_openloop_X, 0,
                  sizeof(X_heli_q8_4_2_output_openloop_T));
  }

  /* states (dwork) */
  heli_q8_4_2_output_openloop_M->ModelData.dwork = ((void *)
    &heli_q8_4_2_output_openloop_DW);
  (void) memset((void *)&heli_q8_4_2_output_openloop_DW, 0,
                sizeof(DW_heli_q8_4_2_output_openloo_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_4_2_output_openloop_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_4_2_output_openloop_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_4_2_output_openloop_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_4_2_output_openloop_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_4_2_output_openloop_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_4_2_output_openloop_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_4_2_output_openloop_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_4_2_output_openloop_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_4_2_output_openloop_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_4_2_output_openloop_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_4_2_output_openloop_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_4_2_output_openloop_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_4_2_output_openloop_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_4_2_output_openloop_M->Sizes.numContStates = (11);/* Number of continuous states */
  heli_q8_4_2_output_openloop_M->Sizes.numY = (0);/* Number of model outputs */
  heli_q8_4_2_output_openloop_M->Sizes.numU = (0);/* Number of model inputs */
  heli_q8_4_2_output_openloop_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_4_2_output_openloop_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_4_2_output_openloop_M->Sizes.numBlocks = (76);/* Number of blocks */
  heli_q8_4_2_output_openloop_M->Sizes.numBlockIO = (30);/* Number of block outputs */
  heli_q8_4_2_output_openloop_M->Sizes.numBlockPrms = (253);/* Sum of parameter "widths" */
  return heli_q8_4_2_output_openloop_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
