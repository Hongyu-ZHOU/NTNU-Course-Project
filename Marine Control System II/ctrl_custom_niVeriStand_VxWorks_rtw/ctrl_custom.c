/*
 * ctrl_custom.c
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

#include "ctrl_custom.h"
#include "ctrl_custom_private.h"

/* Block signals (auto storage) */
B_ctrl_custom_T ctrl_custom_B;

/* Continuous states */
X_ctrl_custom_T ctrl_custom_X;

/* Block states (auto storage) */
DW_ctrl_custom_T ctrl_custom_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_custom_T ctrl_custom_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_custom_T ctrl_custom_M_;
RT_MODEL_ctrl_custom_T *const ctrl_custom_M = &ctrl_custom_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_custom_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S17>/Ned-Body'
 *    '<S17>/Ned-Body1'
 */
void ctrl_custom_NedBody(real_T rtu_psi, const real_T rtu_Bodyvector[3],
  B_NedBody_ctrl_custom_T *localB)
{
  real_T tmp[9];
  int32_T i;

  /* MATLAB Function 'OBserver/SimpleObserver/Ned-Body': '<S19>:1' */
  /* '<S19>:1:4' */
  /* Bodyvector = u; - skrevet av studass */
  /* '<S19>:1:4' */
  /* R = Rzyx(phi, theta, psi); */
  /*  y = 3x1 matrix containing bodyfixed coordinates */
  /* '<S19>:1:7' */
  tmp[0] = cos(rtu_psi);
  tmp[3] = sin(rtu_psi);
  tmp[6] = 0.0;
  tmp[1] = -sin(rtu_psi);
  tmp[4] = cos(rtu_psi);
  tmp[7] = 0.0;
  tmp[2] = 0.0;
  tmp[5] = 0.0;
  tmp[8] = 1.0;
  for (i = 0; i < 3; i++) {
    localB->y[i] = 0.0;
    localB->y[i] += tmp[i] * rtu_Bodyvector[0];
    localB->y[i] += tmp[i + 3] * rtu_Bodyvector[1];
    localB->y[i] += tmp[i + 6] * rtu_Bodyvector[2];
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void ctrl_custom_output(void)
{
  /* local block i/o variables */
  real_T rtb_Multiply1_d[3];
  real_T rtb_B[3];
  boolean_T didZcEventOccur;
  static const int8_T b[3] = { 0, 0, 1 };

  static const real_T a[15] = { 0.0, 0.4854368932038835, 0.0, 0.4854368932038835,
    0.0, 0.20638959606761165, 0.00919028938546725, 0.222039685406917,
    -0.0091902893854672058, 0.222039685406917, 0.44771890179934032,
    -0.048613648345452933, -0.57138494797595418, 0.048613648345453085,
    -0.57138494797595418 };

  int32_T Flag;
  real_T alpha_2;
  static const int8_T b_0[3] = { 0, 0, 1 };

  real_T rtb_Switch_f[3];
  int32_T rtb_Flag_f;
  real_T rtb_U[5];
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[3];
  real_T rtb_Switch;
  real_T u_m;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_idx_2;
  real_T u_m_idx_0;
  real_T u_m_idx_1;
  real_T u_m_idx_2;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* set solver stop time */
    if (!(ctrl_custom_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_custom_M->solverInfo,
                            ((ctrl_custom_M->Timing.clockTickH0 + 1) *
        ctrl_custom_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_custom_M->solverInfo,
                            ((ctrl_custom_M->Timing.clockTick0 + 1) *
        ctrl_custom_M->Timing.stepSize0 + ctrl_custom_M->Timing.clockTickH0 *
        ctrl_custom_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_custom_M)) {
    ctrl_custom_M->Timing.t[0] = rtsiGetT(&ctrl_custom_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  /* Integrator: '<S17>/Integrator' */
  ctrl_custom_B.etahat[0] = ctrl_custom_X.Integrator_CSTATE[0];
  ctrl_custom_B.etahat[1] = ctrl_custom_X.Integrator_CSTATE[1];
  ctrl_custom_B.etahat[2] = ctrl_custom_X.Integrator_CSTATE[2];

  /* Switch: '<S4>/Switch' */
  if (ctrl_custom_B.Useobserver4Eta > ctrl_custom_P.Switch_Threshold) {
    rtb_Switch_idx_0 = ctrl_custom_B.etahat[0];
    rtb_Switch_idx_1 = ctrl_custom_B.etahat[1];
    rtb_Switch_idx_2 = ctrl_custom_B.etahat[2];
  } else {
    rtb_Switch_idx_0 = ctrl_custom_B.x_m;
    rtb_Switch_idx_1 = ctrl_custom_B.y_m;
    rtb_Switch_idx_2 = ctrl_custom_B.psi_m;
  }

  /* End of Switch: '<S4>/Switch' */
  /* MATLAB Function 'Find tau_body/Direct Control/NED->Body': '<S12>:1' */
  /* '<S12>:1:4' */
  /* Bodyvector = u; - skrevet av studass */
  /* '<S12>:1:4' */
  /* R = Rzyx(phi, theta, psi); */
  /*  y = 3x1 matrix containing bodyfixed coordinates */
  /* '<S12>:1:7' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* UnitDelay: '<S9>/Delay Input1' */
    ctrl_custom_B.Uk1 = ctrl_custom_DW.DelayInput1_DSTATE;
  }

  /* RelationalOperator: '<S9>/FixPt Relational Operator' */
  ctrl_custom_B.FixPtRelationalOperator = (ctrl_custom_B.DirectControl_or_Dp !=
    ctrl_custom_B.Uk1);

  /* Integrator: '<S11>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    didZcEventOccur = (ctrl_custom_B.FixPtRelationalOperator &&
                       (ctrl_custom_PrevZCX.Integrator_Reset_ZCE != POS_ZCSIG));
    ctrl_custom_PrevZCX.Integrator_Reset_ZCE =
      ctrl_custom_B.FixPtRelationalOperator;

    /* evaluate zero-crossings */
    if (didZcEventOccur) {
      ctrl_custom_X.Integrator_CSTATE_f[0] = ctrl_custom_P.Integrator_IC_h;
      ctrl_custom_X.Integrator_CSTATE_f[1] = ctrl_custom_P.Integrator_IC_h;
      ctrl_custom_X.Integrator_CSTATE_f[2] = ctrl_custom_P.Integrator_IC_h;
    }
  }

  /* MATLAB Function: '<S11>/NED->Body' */
  /* MATLAB Function 'Find tau_body/Simple DP controller/NED->Body': '<S14>:1' */
  /* '<S14>:1:4' */
  /* Bodyvector = u; - skrevet av studass */
  /* '<S14>:1:4' */
  /* R = Rzyx(phi, theta, psi); */
  /*  y = 3x1 matrix containing bodyfixed coordinates */
  /* '<S14>:1:7' */
  tmp[0] = cos(rtb_Switch_idx_2);
  tmp[3] = sin(rtb_Switch_idx_2);
  tmp[6] = 0.0;
  tmp[1] = -sin(rtb_Switch_idx_2);
  tmp[4] = cos(rtb_Switch_idx_2);
  tmp[7] = 0.0;

  /* Integrator: '<S15>/Integrator2' */
  ctrl_custom_B.Integrator2[0] = ctrl_custom_X.Integrator2_CSTATE[0];

  /* Sum: '<S11>/Sum' */
  ctrl_custom_B.Sum[0] = ctrl_custom_B.Integrator2[0] - rtb_Switch_idx_0;

  /* MATLAB Function: '<S11>/NED->Body' */
  tmp[2] = 0.0;

  /* Sum: '<S11>/Sum1' incorporates:
   *  Integrator: '<S11>/Integrator'
   *  MATLAB Function: '<S11>/NED->Body'
   *  Product: '<S11>/Multiply'
   *  Product: '<S11>/Multiply1'
   */
  rtb_Switch_idx_0 = ctrl_custom_B.Ki * ctrl_custom_X.Integrator_CSTATE_f[0] +
    ctrl_custom_B.Sum[0] * ctrl_custom_B.Kp;

  /* Integrator: '<S15>/Integrator2' */
  ctrl_custom_B.Integrator2[1] = ctrl_custom_X.Integrator2_CSTATE[1];

  /* Sum: '<S11>/Sum' */
  ctrl_custom_B.Sum[1] = ctrl_custom_B.Integrator2[1] - rtb_Switch_idx_1;

  /* MATLAB Function: '<S11>/NED->Body' */
  tmp[5] = 0.0;

  /* Sum: '<S11>/Sum1' incorporates:
   *  Integrator: '<S11>/Integrator'
   *  MATLAB Function: '<S11>/NED->Body'
   *  Product: '<S11>/Multiply'
   *  Product: '<S11>/Multiply1'
   */
  rtb_Switch_idx_1 = ctrl_custom_B.Ki * ctrl_custom_X.Integrator_CSTATE_f[1] +
    ctrl_custom_B.Sum[1] * ctrl_custom_B.Kp;

  /* Integrator: '<S15>/Integrator2' */
  ctrl_custom_B.Integrator2[2] = ctrl_custom_X.Integrator2_CSTATE[2];

  /* Sum: '<S11>/Sum' */
  ctrl_custom_B.Sum[2] = ctrl_custom_B.Integrator2[2] - rtb_Switch_idx_2;

  /* MATLAB Function: '<S11>/NED->Body' */
  tmp[8] = 1.0;

  /* Sum: '<S11>/Sum1' incorporates:
   *  Integrator: '<S11>/Integrator'
   *  MATLAB Function: '<S11>/NED->Body'
   *  Product: '<S11>/Multiply'
   *  Product: '<S11>/Multiply1'
   */
  u_m_idx_1 = ctrl_custom_B.Ki * ctrl_custom_X.Integrator_CSTATE_f[2] +
    ctrl_custom_B.Sum[2] * ctrl_custom_B.Kp;

  /* MATLAB Function: '<S10>/NED->Body' */
  tmp_0[0] = cos(rtb_Switch_idx_2);
  tmp_0[3] = sin(rtb_Switch_idx_2);
  tmp_0[6] = 0.0;
  tmp_0[1] = -sin(rtb_Switch_idx_2);
  tmp_0[4] = cos(rtb_Switch_idx_2);
  tmp_0[7] = 0.0;
  for (rtb_Flag_f = 0; rtb_Flag_f < 3; rtb_Flag_f++) {
    /* MATLAB Function: '<S11>/NED->Body' */
    ctrl_custom_B.y[rtb_Flag_f] = 0.0;
    ctrl_custom_B.y[rtb_Flag_f] += tmp[rtb_Flag_f] * rtb_Switch_idx_0;
    ctrl_custom_B.y[rtb_Flag_f] += tmp[rtb_Flag_f + 3] * rtb_Switch_idx_1;
    ctrl_custom_B.y[rtb_Flag_f] += tmp[rtb_Flag_f + 6] * u_m_idx_1;

    /* MATLAB Function: '<S10>/NED->Body' */
    tmp_0[2 + 3 * rtb_Flag_f] = b[rtb_Flag_f];
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  MATLAB Function: '<S10>/NED->Body'
   *  SignalConversion: '<S12>/TmpSignal ConversionAt SFunction Inport2'
   */
  if (ctrl_custom_B.DirectControl_or_Dp > ctrl_custom_P.Switch_Threshold_f) {
    for (rtb_Flag_f = 0; rtb_Flag_f < 3; rtb_Flag_f++) {
      rtb_Switch_f[rtb_Flag_f] = (tmp_0[rtb_Flag_f + 3] * ctrl_custom_B.FyDes +
        tmp_0[rtb_Flag_f] * ctrl_custom_B.FXDes) + tmp_0[rtb_Flag_f + 6] *
        ctrl_custom_B.MomentDes;
    }
  } else {
    for (rtb_Flag_f = 0; rtb_Flag_f < 3; rtb_Flag_f++) {
      rtb_Switch_f[rtb_Flag_f] = ctrl_custom_B.y[rtb_Flag_f];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* MATLAB Function: '<S7>/Adjustable Alpha' */
  /* MATLAB Function 'Thrust Allocation/Adjustable Alpha': '<S21>:1' */
  /* '<S21>:1:20' */
  /* '<S21>:1:5' */
  /* f=[fBT f2x f2y f3x f3y] */
  /* '<S21>:1:7' */
  /* '<S21>:1:8' */
  /* '<S21>:1:15' */
  /* '<S21>:1:16' */
  /* '<S21>:1:17' */
  /* '<S21>:1:20' */
  for (rtb_Flag_f = 0; rtb_Flag_f < 5; rtb_Flag_f++) {
    rtb_U[rtb_Flag_f] = a[rtb_Flag_f + 10] * rtb_Switch_f[2] + (a[rtb_Flag_f + 5]
      * rtb_Switch_f[1] + a[rtb_Flag_f] * rtb_Switch_f[0]);
  }

  /* '<S21>:1:22' */
  rtb_Switch_idx_1 = sqrt(rtb_U[1] * rtb_U[1] + rtb_U[2] * rtb_U[2]);
  rtb_Switch_idx_2 = sqrt(rtb_U[3] * rtb_U[3] + rtb_U[4] * rtb_U[4]);

  /* '<S21>:1:23' */
  /* '<S21>:1:24' */
  /* '<S21>:1:25' */
  /* TEST: */
  /* '<S21>:1:31' */
  /* '<S21>:1:32' */
  /* '<S21>:1:33' */
  /* '<S21>:1:34' */
  rtb_Flag_f = 0;

  /* MATLAB Function: '<S7>/Fixed Alhpa' */
  /* '<S21>:1:38' */
  /* '<S21>:1:49' */
  /* '<S21>:1:50' */
  /* '<S21>:1:52' */
  /* MATLAB Function 'Thrust Allocation/Fixed Alhpa': '<S22>:1' */
  /* '<S22>:1:17' */
  /* '<S22>:1:16' */
  u_m_idx_1 = rtb_Switch_f[0] - rtb_Switch_f[1] * 0.0;
  u_m_idx_2 = ((rtb_Switch_f[2] - rtb_Switch_f[1] * 0.3875) - u_m_idx_1 * -0.055)
    / 0.11;
  u_m_idx_1 -= u_m_idx_2;

  /* MATLAB Function: '<S7>/Adjustable Alpha' */
  /* '<S22>:1:17' */
  rtb_Switch = rtb_U[0];

  /* '<S21>:1:38' */
  if (rtb_U[0] > 1.0) {
    /* '<S21>:1:39' */
    /* '<S21>:1:40' */
    rtb_Switch = 1.0;

    /* '<S21>:1:41' */
    rtb_Flag_f = 1;
  } else {
    if (rtb_U[0] < -1.0) {
      /* '<S21>:1:42' */
      /* '<S21>:1:43' */
      rtb_Switch = -1.0;

      /* '<S21>:1:44' */
      rtb_Flag_f = 1;
    }
  }

  rtb_Switch_idx_0 = rtb_Switch;

  /* MATLAB Function: '<S7>/Fixed Alhpa' */
  u_m_idx_0 = ((rtb_Switch_f[1] - u_m_idx_2 * 0.0) - u_m_idx_1 * 0.0) / 2.629;

  /* MATLAB Function: '<S7>/Adjustable Alpha' */
  rtb_Switch = rtb_Switch_idx_1;

  /* '<S21>:1:38' */
  if (rtb_Switch_idx_1 > 1.0) {
    /* '<S21>:1:39' */
    /* '<S21>:1:40' */
    rtb_Switch = 1.0;

    /* '<S21>:1:41' */
    rtb_Flag_f = 1;
  } else {
    if (rtb_Switch_idx_1 < -1.0) {
      /* '<S21>:1:42' */
      /* '<S21>:1:43' */
      rtb_Switch = -1.0;

      /* '<S21>:1:44' */
      rtb_Flag_f = 1;
    }
  }

  rtb_Switch_idx_1 = rtb_Switch;

  /* MATLAB Function: '<S7>/Fixed Alhpa' */
  u_m_idx_1 /= 1.165;

  /* MATLAB Function: '<S7>/Adjustable Alpha' */
  rtb_Switch = rtb_Switch_idx_2;

  /* '<S21>:1:38' */
  if (rtb_Switch_idx_2 > 1.0) {
    /* '<S21>:1:39' */
    /* '<S21>:1:40' */
    rtb_Switch = 1.0;

    /* '<S21>:1:41' */
    rtb_Flag_f = 1;
  } else {
    if (rtb_Switch_idx_2 < -1.0) {
      /* '<S21>:1:42' */
      /* '<S21>:1:43' */
      rtb_Switch = -1.0;

      /* '<S21>:1:44' */
      rtb_Flag_f = 1;
    }
  }

  /* MATLAB Function: '<S7>/Fixed Alhpa' */
  u_m_idx_2 /= 1.165;

  /* '<S22>:1:18' */
  /* '<S22>:1:20' */
  rtb_Switch_idx_2 = 0.0;

  /* '<S22>:1:20' */
  alpha_2 = 0.0;

  /* Switching Alpha */
  if (u_m_idx_1 < 0.0) {
    /* '<S22>:1:22' */
    /* '<S22>:1:23' */
    u_m_idx_1 = -u_m_idx_1;

    /* '<S22>:1:24' */
    rtb_Switch_idx_2 = 3.1415926535897931;
  }

  if (u_m_idx_2 < 0.0) {
    /* '<S22>:1:26' */
    /* '<S22>:1:27' */
    u_m_idx_2 = -u_m_idx_2;

    /* '<S22>:1:28' */
    alpha_2 = 3.1415926535897931;
  }

  /* '<S22>:1:31' */
  Flag = 0;

  /* '<S22>:1:32' */
  u_m = u_m_idx_0;

  /* '<S22>:1:32' */
  if (u_m_idx_0 > 1.0) {
    /* '<S22>:1:33' */
    /* '<S22>:1:34' */
    u_m = 1.0;

    /* '<S22>:1:35' */
    Flag = 1;
  } else {
    if (u_m_idx_0 < -1.0) {
      /* '<S22>:1:36' */
      /* '<S22>:1:37' */
      u_m = -1.0;

      /* '<S22>:1:38' */
      Flag = 1;
    }
  }

  u_m_idx_0 = u_m;
  u_m = u_m_idx_1;

  /* '<S22>:1:32' */
  if (u_m_idx_1 > 1.0) {
    /* '<S22>:1:33' */
    /* '<S22>:1:34' */
    u_m = 1.0;

    /* '<S22>:1:35' */
    Flag = 1;
  }

  u_m_idx_1 = u_m;
  u_m = u_m_idx_2;

  /* '<S22>:1:32' */
  if (u_m_idx_2 > 1.0) {
    /* '<S22>:1:33' */
    /* '<S22>:1:34' */
    u_m = 1.0;

    /* '<S22>:1:35' */
    Flag = 1;
  }

  /* Switch: '<S7>/Switch1' incorporates:
   *  MATLAB Function: '<S7>/Fixed Alhpa'
   */
  /* '<S22>:1:42' */
  /* '<S22>:1:43' */
  if (ctrl_custom_B.ThrustAlocMethod > ctrl_custom_P.Switch1_Threshold) {
    ctrl_custom_B.Switch1 = rtb_Flag_f;
  } else {
    ctrl_custom_B.Switch1 = Flag;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Switch: '<S7>/Switch' incorporates:
   *  MATLAB Function: '<S7>/Adjustable Alpha'
   *  MATLAB Function: '<S7>/Fixed Alhpa'
   */
  if (ctrl_custom_B.ThrustAlocMethod > ctrl_custom_P.Switch_Threshold_n) {
    ctrl_custom_B.Switch[0] = rtb_Switch_idx_0;
    ctrl_custom_B.Switch[1] = rtb_Switch_idx_1;
    ctrl_custom_B.Switch[2] = rtb_Switch;
    ctrl_custom_B.Switch[3] = rt_atan2d_snf(rtb_U[2], rtb_U[1]);
    ctrl_custom_B.Switch[4] = rt_atan2d_snf(rtb_U[4], rtb_U[3]);
  } else {
    ctrl_custom_B.Switch[0] = u_m_idx_0;
    ctrl_custom_B.Switch[1] = u_m_idx_1;
    ctrl_custom_B.Switch[2] = u_m;
    ctrl_custom_B.Switch[3] = rtb_Switch_idx_2;
    ctrl_custom_B.Switch[4] = alpha_2;
  }

  ctrl_custom_B.Switch[5] = 0.0;
  ctrl_custom_B.Switch[6] = 0.0;

  /* End of Switch: '<S7>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  /* InitialCondition: '<S13>/IC' */
  if ((ctrl_custom_DW.IC_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_custom_DW.IC_FirstOutputTime == ctrl_custom_M->Timing.t[0])) {
    ctrl_custom_DW.IC_FirstOutputTime = ctrl_custom_M->Timing.t[0];
    ctrl_custom_B.IC[0] = ctrl_custom_P.IC_Value[0];
    ctrl_custom_B.IC[1] = ctrl_custom_P.IC_Value[1];
    ctrl_custom_B.IC[2] = ctrl_custom_P.IC_Value[2];
  } else {
    ctrl_custom_B.IC[0] = ctrl_custom_B.EtaSetX;
    ctrl_custom_B.IC[1] = ctrl_custom_B.EtaSetY;
    ctrl_custom_B.IC[2] = ctrl_custom_B.EtaSetPsi;
  }

  /* End of InitialCondition: '<S13>/IC' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  /* Integrator: '<S15>/Integrator' */
  ctrl_custom_B.Integrator[0] = ctrl_custom_X.Integrator_CSTATE_i[0];
  ctrl_custom_B.Integrator[1] = ctrl_custom_X.Integrator_CSTATE_i[1];
  ctrl_custom_B.Integrator[2] = ctrl_custom_X.Integrator_CSTATE_i[2];
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  /* Saturate: '<S15>/Saturation4' incorporates:
   *  Integrator: '<S15>/Integrator1'
   */
  if (ctrl_custom_X.Integrator1_CSTATE[0] > ctrl_custom_P.Saturation4_UpperSat[0])
  {
    ctrl_custom_B.Saturation4[0] = ctrl_custom_P.Saturation4_UpperSat[0];
  } else if (ctrl_custom_X.Integrator1_CSTATE[0] <
             ctrl_custom_P.Saturation4_LowerSat[0]) {
    ctrl_custom_B.Saturation4[0] = ctrl_custom_P.Saturation4_LowerSat[0];
  } else {
    ctrl_custom_B.Saturation4[0] = ctrl_custom_X.Integrator1_CSTATE[0];
  }

  /* Sum: '<S15>/Sum3' incorporates:
   *  Gain: '<S15>/ciwni'
   *  Gain: '<S15>/w_n1'
   *  Gain: '<S15>/w_n2'
   *  Integrator: '<S15>/Integrator1'
   *  Sum: '<S15>/Sum2'
   */
  ctrl_custom_B.Sum3[0] = (ctrl_custom_P.w_n2_Gain[0] *
    ctrl_custom_B.Integrator[0] - ctrl_custom_P.w_n1_Gain[0] *
    ctrl_custom_B.Integrator2[0]) - ctrl_custom_P.ciwni_Gain[0] *
    ctrl_custom_X.Integrator1_CSTATE[0];

  /* Gain: '<S15>/w_n' incorporates:
   *  Sum: '<S15>/Sum'
   */
  ctrl_custom_B.w_n[0] = (ctrl_custom_B.IC[0] - ctrl_custom_B.Integrator[0]) *
    ctrl_custom_P.w_n_Gain[0];

  /* Saturate: '<S15>/Saturation4' incorporates:
   *  Integrator: '<S15>/Integrator1'
   */
  if (ctrl_custom_X.Integrator1_CSTATE[1] > ctrl_custom_P.Saturation4_UpperSat[1])
  {
    ctrl_custom_B.Saturation4[1] = ctrl_custom_P.Saturation4_UpperSat[1];
  } else if (ctrl_custom_X.Integrator1_CSTATE[1] <
             ctrl_custom_P.Saturation4_LowerSat[1]) {
    ctrl_custom_B.Saturation4[1] = ctrl_custom_P.Saturation4_LowerSat[1];
  } else {
    ctrl_custom_B.Saturation4[1] = ctrl_custom_X.Integrator1_CSTATE[1];
  }

  /* Sum: '<S15>/Sum3' incorporates:
   *  Gain: '<S15>/ciwni'
   *  Gain: '<S15>/w_n1'
   *  Gain: '<S15>/w_n2'
   *  Integrator: '<S15>/Integrator1'
   *  Sum: '<S15>/Sum2'
   */
  ctrl_custom_B.Sum3[1] = (ctrl_custom_P.w_n2_Gain[1] *
    ctrl_custom_B.Integrator[1] - ctrl_custom_P.w_n1_Gain[1] *
    ctrl_custom_B.Integrator2[1]) - ctrl_custom_P.ciwni_Gain[1] *
    ctrl_custom_X.Integrator1_CSTATE[1];

  /* Gain: '<S15>/w_n' incorporates:
   *  Sum: '<S15>/Sum'
   */
  ctrl_custom_B.w_n[1] = (ctrl_custom_B.IC[1] - ctrl_custom_B.Integrator[1]) *
    ctrl_custom_P.w_n_Gain[1];

  /* Saturate: '<S15>/Saturation4' incorporates:
   *  Integrator: '<S15>/Integrator1'
   */
  if (ctrl_custom_X.Integrator1_CSTATE[2] > ctrl_custom_P.Saturation4_UpperSat[2])
  {
    ctrl_custom_B.Saturation4[2] = ctrl_custom_P.Saturation4_UpperSat[2];
  } else if (ctrl_custom_X.Integrator1_CSTATE[2] <
             ctrl_custom_P.Saturation4_LowerSat[2]) {
    ctrl_custom_B.Saturation4[2] = ctrl_custom_P.Saturation4_LowerSat[2];
  } else {
    ctrl_custom_B.Saturation4[2] = ctrl_custom_X.Integrator1_CSTATE[2];
  }

  /* Sum: '<S15>/Sum3' incorporates:
   *  Gain: '<S15>/ciwni'
   *  Gain: '<S15>/w_n1'
   *  Gain: '<S15>/w_n2'
   *  Integrator: '<S15>/Integrator1'
   *  Sum: '<S15>/Sum2'
   */
  ctrl_custom_B.Sum3[2] = (ctrl_custom_P.w_n2_Gain[2] *
    ctrl_custom_B.Integrator[2] - ctrl_custom_P.w_n1_Gain[2] *
    ctrl_custom_B.Integrator2[2]) - ctrl_custom_P.ciwni_Gain[2] *
    ctrl_custom_X.Integrator1_CSTATE[2];

  /* Gain: '<S15>/w_n' incorporates:
   *  Sum: '<S15>/Sum'
   */
  ctrl_custom_B.w_n[2] = (ctrl_custom_B.IC[2] - ctrl_custom_B.Integrator[2]) *
    ctrl_custom_P.w_n_Gain[2];
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* ManualSwitch: '<S16>/Manual Switch' incorporates:
     *  Constant: '<S16>/DR on '
     *  Constant: '<S16>/Dead Reckoning'
     */
    if (ctrl_custom_P.ManualSwitch_CurrentSetting == 1) {
      rtb_Switch_idx_1 = ctrl_custom_P.DRon_Value;
    } else {
      rtb_Switch_idx_1 = ctrl_custom_P.DeadReckoning_Value;
    }

    /* End of ManualSwitch: '<S16>/Manual Switch' */

    /* Sum: '<S16>/Add' incorporates:
     *  Constant: '<S16>/Dummy'
     */
    ctrl_custom_B.Add = ctrl_custom_P.Dummy_Value - rtb_Switch_idx_1;
  }

  /* Sum: '<S17>/eta_bar' */
  u_m_idx_0 = ctrl_custom_B.x_m - ctrl_custom_B.etahat[0];
  u_m_idx_1 = ctrl_custom_B.y_m - ctrl_custom_B.etahat[1];
  u_m_idx_2 = ctrl_custom_B.psi_m - ctrl_custom_B.etahat[2];

  /* MATLAB Function: '<S17>/Body->Ned' */
  /* MATLAB Function 'OBserver/SimpleObserver/Body->Ned': '<S18>:1' */
  /* '<S18>:1:5' */
  /* '<S18>:1:2' */
  /* Bodyvector = u; - skrevet av studass */
  /* '<S18>:1:5' */
  /* R = Rzyx(phi, theta, psi); */
  /*  y = 3x1 matrix containing bodyfixed coordinates */
  /* '<S18>:1:8' */
  tmp[0] = cos(-ctrl_custom_B.etahat[2]);
  tmp[3] = sin(-ctrl_custom_B.etahat[2]);
  tmp[6] = 0.0;
  tmp[1] = -sin(-ctrl_custom_B.etahat[2]);
  tmp[4] = cos(-ctrl_custom_B.etahat[2]);
  tmp[7] = 0.0;
  for (rtb_Flag_f = 0; rtb_Flag_f < 3; rtb_Flag_f++) {
    /* MATLAB Function: '<S17>/Body->Ned' */
    tmp[2 + 3 * rtb_Flag_f] = b_0[rtb_Flag_f];

    /* Gain: '<S17>/L1' incorporates:
     *  Product: '<S17>/Multiply'
     */
    tmp_1[rtb_Flag_f] = ctrl_custom_P.L1_Gain[rtb_Flag_f + 6] * u_m_idx_2 +
      (ctrl_custom_P.L1_Gain[rtb_Flag_f + 3] * u_m_idx_1 +
       ctrl_custom_P.L1_Gain[rtb_Flag_f] * u_m_idx_0);
  }

  for (rtb_Flag_f = 0; rtb_Flag_f < 3; rtb_Flag_f++) {
    /* Sum: '<S17>/Add' incorporates:
     *  Integrator: '<S17>/Integrator1'
     *  MATLAB Function: '<S17>/Body->Ned'
     *  Product: '<S17>/Multiply'
     */
    ctrl_custom_B.d_etahat[rtb_Flag_f] = ((tmp[rtb_Flag_f + 3] *
      ctrl_custom_X.Integrator1_CSTATE_j[1] + tmp[rtb_Flag_f] *
      ctrl_custom_X.Integrator1_CSTATE_j[0]) + tmp[rtb_Flag_f + 6] *
      ctrl_custom_X.Integrator1_CSTATE_j[2]) + ctrl_custom_B.Add *
      tmp_1[rtb_Flag_f];

    /* Product: '<S17>/Multiply1' incorporates:
     *  Gain: '<S17>/L2 '
     */
    rtb_Multiply1_d[rtb_Flag_f] = ctrl_custom_B.Add *
      (ctrl_custom_P.L2_Gain[rtb_Flag_f + 6] * u_m_idx_2 +
       (ctrl_custom_P.L2_Gain[rtb_Flag_f + 3] * u_m_idx_1 +
        ctrl_custom_P.L2_Gain[rtb_Flag_f] * u_m_idx_0));
  }

  /* MATLAB Function: '<S17>/Ned-Body1' */
  ctrl_custom_NedBody(ctrl_custom_B.etahat[2], rtb_Multiply1_d,
                      &ctrl_custom_B.sf_NedBody1);

  /* Integrator: '<S17>/B' */
  rtb_B[0] = ctrl_custom_X.B_CSTATE[0];
  rtb_B[1] = ctrl_custom_X.B_CSTATE[1];
  rtb_B[2] = ctrl_custom_X.B_CSTATE[2];

  /* MATLAB Function: '<S17>/Ned-Body' */
  ctrl_custom_NedBody(ctrl_custom_B.etahat[2], rtb_B, &ctrl_custom_B.sf_NedBody);
  for (rtb_Flag_f = 0; rtb_Flag_f < 3; rtb_Flag_f++) {
    /* Product: '<S17>/Multiply2' incorporates:
     *  Gain: '<S17>/L3'
     */
    ctrl_custom_B.Multiply2[rtb_Flag_f] = ctrl_custom_B.Add *
      (ctrl_custom_P.L3_Gain[rtb_Flag_f + 6] * u_m_idx_2 +
       (ctrl_custom_P.L3_Gain[rtb_Flag_f + 3] * u_m_idx_1 +
        ctrl_custom_P.L3_Gain[rtb_Flag_f] * u_m_idx_0));

    /* Sum: '<S17>/Add1' incorporates:
     *  Gain: '<S17>/D (somewhat weird with 7.25) '
     *  Gain: '<S17>/invM'
     *  Integrator: '<S17>/Integrator1'
     */
    tmp_1[rtb_Flag_f] = ((ctrl_custom_B.sf_NedBody1.y[rtb_Flag_f] +
                          rtb_Switch_f[rtb_Flag_f]) -
                         ((ctrl_custom_P.Dsomewhatweirdwith725_Gain[rtb_Flag_f +
      3] * ctrl_custom_X.Integrator1_CSTATE_j[1] +
      ctrl_custom_P.Dsomewhatweirdwith725_Gain[rtb_Flag_f] *
      ctrl_custom_X.Integrator1_CSTATE_j[0]) +
                          ctrl_custom_P.Dsomewhatweirdwith725_Gain[rtb_Flag_f +
                          6] * ctrl_custom_X.Integrator1_CSTATE_j[2])) +
      ctrl_custom_B.sf_NedBody.y[rtb_Flag_f];
  }

  /* Gain: '<S17>/invM' */
  for (rtb_Flag_f = 0; rtb_Flag_f < 3; rtb_Flag_f++) {
    ctrl_custom_B.invM[rtb_Flag_f] = 0.0;
    ctrl_custom_B.invM[rtb_Flag_f] += ctrl_custom_P.invM_Gain[rtb_Flag_f] *
      tmp_1[0];
    ctrl_custom_B.invM[rtb_Flag_f] += ctrl_custom_P.invM_Gain[rtb_Flag_f + 3] *
      tmp_1[1];
    ctrl_custom_B.invM[rtb_Flag_f] += ctrl_custom_P.invM_Gain[rtb_Flag_f + 6] *
      tmp_1[2];
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }
}

/* Model update function */
void ctrl_custom_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Update for UnitDelay: '<S9>/Delay Input1' */
    ctrl_custom_DW.DelayInput1_DSTATE = ctrl_custom_B.DirectControl_or_Dp;
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_custom_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_custom_M->Timing.clockTick0)) {
    ++ctrl_custom_M->Timing.clockTickH0;
  }

  ctrl_custom_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_custom_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_custom_M->Timing.clockTick1)) {
      ++ctrl_custom_M->Timing.clockTickH1;
    }

    ctrl_custom_M->Timing.t[1] = ctrl_custom_M->Timing.clockTick1 *
      ctrl_custom_M->Timing.stepSize1 + ctrl_custom_M->Timing.clockTickH1 *
      ctrl_custom_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_custom_derivatives(void)
{
  XDot_ctrl_custom_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_custom_T *) ctrl_custom_M->derivs);

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_custom_B.d_etahat[0];

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE_f[0] = ctrl_custom_B.Sum[0];

  /* Derivatives for Integrator: '<S15>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_custom_B.Saturation4[0];

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE_i[0] = ctrl_custom_B.w_n[0];

  /* Derivatives for Integrator: '<S15>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_custom_B.Sum3[0];

  /* Derivatives for Integrator: '<S17>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j[0] = ctrl_custom_B.invM[0];

  /* Derivatives for Integrator: '<S17>/B' */
  _rtXdot->B_CSTATE[0] = ctrl_custom_B.Multiply2[0];

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = ctrl_custom_B.d_etahat[1];

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE_f[1] = ctrl_custom_B.Sum[1];

  /* Derivatives for Integrator: '<S15>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = ctrl_custom_B.Saturation4[1];

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE_i[1] = ctrl_custom_B.w_n[1];

  /* Derivatives for Integrator: '<S15>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = ctrl_custom_B.Sum3[1];

  /* Derivatives for Integrator: '<S17>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j[1] = ctrl_custom_B.invM[1];

  /* Derivatives for Integrator: '<S17>/B' */
  _rtXdot->B_CSTATE[1] = ctrl_custom_B.Multiply2[1];

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = ctrl_custom_B.d_etahat[2];

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE_f[2] = ctrl_custom_B.Sum[2];

  /* Derivatives for Integrator: '<S15>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = ctrl_custom_B.Saturation4[2];

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE_i[2] = ctrl_custom_B.w_n[2];

  /* Derivatives for Integrator: '<S15>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = ctrl_custom_B.Sum3[2];

  /* Derivatives for Integrator: '<S17>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j[2] = ctrl_custom_B.invM[2];

  /* Derivatives for Integrator: '<S17>/B' */
  _rtXdot->B_CSTATE[2] = ctrl_custom_B.Multiply2[2];
}

/* Model initialize function */
void ctrl_custom_initialize(void)
{
  /* Start for InitialCondition: '<S13>/IC' */
  ctrl_custom_DW.IC_FirstOutputTime = (rtMinusInf);
  ctrl_custom_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S9>/Delay Input1' */
  ctrl_custom_DW.DelayInput1_DSTATE = ctrl_custom_P.DetectChange_vinit;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE[0] = ctrl_custom_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S11>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE_f[0] = ctrl_custom_P.Integrator_IC_h;

  /* InitializeConditions for Integrator: '<S15>/Integrator2' */
  ctrl_custom_X.Integrator2_CSTATE[0] = ctrl_custom_P.Integrator2_IC[0];

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE_i[0] = ctrl_custom_P.Integrator_IC_g[0];

  /* InitializeConditions for Integrator: '<S15>/Integrator1' */
  ctrl_custom_X.Integrator1_CSTATE[0] = ctrl_custom_P.Integrator1_IC[0];

  /* InitializeConditions for Integrator: '<S17>/Integrator1' */
  ctrl_custom_X.Integrator1_CSTATE_j[0] = ctrl_custom_P.Integrator1_IC_p;

  /* InitializeConditions for Integrator: '<S17>/B' */
  ctrl_custom_X.B_CSTATE[0] = ctrl_custom_P.B_IC;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE[1] = ctrl_custom_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S11>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE_f[1] = ctrl_custom_P.Integrator_IC_h;

  /* InitializeConditions for Integrator: '<S15>/Integrator2' */
  ctrl_custom_X.Integrator2_CSTATE[1] = ctrl_custom_P.Integrator2_IC[1];

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE_i[1] = ctrl_custom_P.Integrator_IC_g[1];

  /* InitializeConditions for Integrator: '<S15>/Integrator1' */
  ctrl_custom_X.Integrator1_CSTATE[1] = ctrl_custom_P.Integrator1_IC[1];

  /* InitializeConditions for Integrator: '<S17>/Integrator1' */
  ctrl_custom_X.Integrator1_CSTATE_j[1] = ctrl_custom_P.Integrator1_IC_p;

  /* InitializeConditions for Integrator: '<S17>/B' */
  ctrl_custom_X.B_CSTATE[1] = ctrl_custom_P.B_IC;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE[2] = ctrl_custom_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S11>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE_f[2] = ctrl_custom_P.Integrator_IC_h;

  /* InitializeConditions for Integrator: '<S15>/Integrator2' */
  ctrl_custom_X.Integrator2_CSTATE[2] = ctrl_custom_P.Integrator2_IC[2];

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  ctrl_custom_X.Integrator_CSTATE_i[2] = ctrl_custom_P.Integrator_IC_g[2];

  /* InitializeConditions for Integrator: '<S15>/Integrator1' */
  ctrl_custom_X.Integrator1_CSTATE[2] = ctrl_custom_P.Integrator1_IC[2];

  /* InitializeConditions for Integrator: '<S17>/Integrator1' */
  ctrl_custom_X.Integrator1_CSTATE_j[2] = ctrl_custom_P.Integrator1_IC_p;

  /* InitializeConditions for Integrator: '<S17>/B' */
  ctrl_custom_X.B_CSTATE[2] = ctrl_custom_P.B_IC;
}

/* Model terminate function */
void ctrl_custom_terminate(void)
{
  /* (no terminate code required) */
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
  ctrl_custom_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_custom_update();
  UNUSED_PARAMETER(tid);
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
  ctrl_custom_initialize();
}

void MdlTerminate(void)
{
  ctrl_custom_terminate();
}

/* Registration function */
RT_MODEL_ctrl_custom_T *ctrl_custom(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_custom_M, 0,
                sizeof(RT_MODEL_ctrl_custom_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_custom_M->solverInfo,
                          &ctrl_custom_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_custom_M->solverInfo, &rtmGetTPtr(ctrl_custom_M));
    rtsiSetStepSizePtr(&ctrl_custom_M->solverInfo,
                       &ctrl_custom_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_custom_M->solverInfo, &ctrl_custom_M->derivs);
    rtsiSetContStatesPtr(&ctrl_custom_M->solverInfo, (real_T **)
                         &ctrl_custom_M->contStates);
    rtsiSetNumContStatesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ctrl_custom_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_custom_M)));
    rtsiSetRTModelPtr(&ctrl_custom_M->solverInfo, ctrl_custom_M);
  }

  rtsiSetSimTimeStep(&ctrl_custom_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_custom_M->intgData.y = ctrl_custom_M->odeY;
  ctrl_custom_M->intgData.f[0] = ctrl_custom_M->odeF[0];
  ctrl_custom_M->intgData.f[1] = ctrl_custom_M->odeF[1];
  ctrl_custom_M->intgData.f[2] = ctrl_custom_M->odeF[2];
  ctrl_custom_M->intgData.f[3] = ctrl_custom_M->odeF[3];
  ctrl_custom_M->contStates = ((real_T *) &ctrl_custom_X);
  rtsiSetSolverData(&ctrl_custom_M->solverInfo, (void *)&ctrl_custom_M->intgData);
  rtsiSetSolverName(&ctrl_custom_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_custom_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_custom_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_custom_M->Timing.sampleTimes = (&ctrl_custom_M->
      Timing.sampleTimesArray[0]);
    ctrl_custom_M->Timing.offsetTimes = (&ctrl_custom_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_custom_M->Timing.sampleTimes[0] = (0.0);
    ctrl_custom_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_custom_M->Timing.offsetTimes[0] = (0.0);
    ctrl_custom_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_custom_M, &ctrl_custom_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_custom_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_custom_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_custom_M, -1);
  ctrl_custom_M->Timing.stepSize0 = 0.01;
  ctrl_custom_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ctrl_custom_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_custom_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_custom_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_custom_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_custom_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_custom_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_custom_M->rtwLogInfo, (NULL));
  }

  ctrl_custom_M->solverInfoPtr = (&ctrl_custom_M->solverInfo);
  ctrl_custom_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_custom_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_custom_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_custom_M->blockIO = ((void *) &ctrl_custom_B);
  (void) memset(((void *) &ctrl_custom_B), 0,
                sizeof(B_ctrl_custom_T));

  /* parameters */
  ctrl_custom_M->defaultParam = ((real_T *)&ctrl_custom_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_custom_X;
    ctrl_custom_M->contStates = (x);
    (void) memset((void *)&ctrl_custom_X, 0,
                  sizeof(X_ctrl_custom_T));
  }

  /* states (dwork) */
  ctrl_custom_M->dwork = ((void *) &ctrl_custom_DW);
  (void) memset((void *)&ctrl_custom_DW, 0,
                sizeof(DW_ctrl_custom_T));

  /* Initialize Sizes */
  ctrl_custom_M->Sizes.numContStates = (21);/* Number of continuous states */
  ctrl_custom_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_custom_M->Sizes.numY = (0);     /* Number of model outputs */
  ctrl_custom_M->Sizes.numU = (0);     /* Number of model inputs */
  ctrl_custom_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_custom_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_custom_M->Sizes.numBlocks = (97);/* Number of blocks */
  ctrl_custom_M->Sizes.numBlockIO = (40);/* Number of block outputs */
  ctrl_custom_M->Sizes.numBlockPrms = (292);/* Sum of parameter "widths" */
  return ctrl_custom_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.75
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Tue Jan 29 11:21:24 2019
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_custom
#include "ni_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: NIRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double NIRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,11,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 31:
    return (( double *)ptr)[subindex];

   case 32:
    return (( double *)ptr)[subindex];

   case 33:
    return (( double *)ptr)[subindex];

   case 34:
    return (( double *)ptr)[subindex];

   case 35:
    return (( double *)ptr)[subindex];

   case 36:
    return (( double *)ptr)[subindex];

   case 37:
    return (( double *)ptr)[subindex];

   case 38:
    return (( double *)ptr)[subindex];

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 40:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

/*========================================================================*
 * Function: NIRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NIRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 17:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 11, Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 31:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 32:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 33:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 34:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 35:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 36:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 37:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 38:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 40:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_custom_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_custom/SIXAIS_INN
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.SIXAIS_INN, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Ki
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Ki, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Kp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Kp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/EtaSetX
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.EtaSetX, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/EtaSetY
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.EtaSetY, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/EtaSetPsi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.EtaSetPsi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/MomentDes
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.MomentDes, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Pose/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/FXDes
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.FXDes, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Pose/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/FyDes
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.FyDes, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Pose/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.psi_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/ThrustAlocMethod
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.ThrustAlocMethod, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_custom/OBserver/Useobserver4Eta
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Useobserver4Eta, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_custom/DirectControl_or_Dp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.DirectControl_or_Dp, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 21;
}

int32_t NumOutputPorts(void)
{
  return 13;
}

double ni_extout[13];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_custom/SIXAIS_OUT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.SIXAIS_INN, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_custom/QTM_SCOPEX: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.x_m, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/QTM_SCOPEY: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.y_m, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/QTM_SCOPEPSI: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.psi_m, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/SaturationFlag: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch1, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 4, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 5, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 6, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 3, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 0, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 1, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 2, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/IMU_SCOPEZ: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Acc_z, 0, 0, 0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: NI_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // ctrl_custom/SIXAIS_OUT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.SIXAIS_INN, 0, 0,
    0);

  // ctrl_custom/QTM_SCOPEX: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.x_m, 0, 0, 0);

  // ctrl_custom/QTM_SCOPEY: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.y_m, 0, 0, 0);

  // ctrl_custom/QTM_SCOPEPSI: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.psi_m, 0, 0, 0);

  // ctrl_custom/SaturationFlag: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch1, 0, 0, 0);

  // ctrl_custom/u/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 4, 21, 0);

  // ctrl_custom/u/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 5, 21, 0);

  // ctrl_custom/u/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 6, 21, 0);

  // ctrl_custom/u/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 3, 21, 0);

  // ctrl_custom/u/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 0, 21, 0);

  // ctrl_custom/u/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 1, 21, 0);

  // ctrl_custom/u/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 2, 21, 0);

  // ctrl_custom/IMU/IMU_SCOPEZ: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Acc_z, 0, 0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_custom/OBserver/Dead Reckoning ON//OFF  /Dead Reckoning/Value",
    offsetof(P_ctrl_custom_T, DeadReckoning_Value), 39, 1, 2, 0, 0 },

  { 1, "ctrl_custom/OBserver/Dead Reckoning ON//OFF  /DR on/Value", offsetof
    (P_ctrl_custom_T, DRon_Value), 39, 1, 2, 2, 0 },

  { 2, "ctrl_custom/OBserver/SimpleObserver/Integrator/InitialCondition",
    offsetof(P_ctrl_custom_T, Integrator_IC), 39, 1, 2, 4, 0 },

  { 3, "ctrl_custom/OBserver/Switch/Threshold", offsetof(P_ctrl_custom_T,
    Switch_Threshold), 39, 1, 2, 6, 0 },

  { 4,
    "ctrl_custom/Find tau_body/Simple DP controller/Integrator/InitialCondition",
    offsetof(P_ctrl_custom_T, Integrator_IC_h), 39, 1, 2, 8, 0 },

  { 5,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator2/InitialCondition",
    offsetof(P_ctrl_custom_T, Integrator2_IC), 26, 3, 2, 10, 0 },

  { 6, "ctrl_custom/Find tau_body/Switch/Threshold", offsetof(P_ctrl_custom_T,
    Switch_Threshold_f), 39, 1, 2, 12, 0 },

  { 7, "ctrl_custom/Thrust Allocation/Switch1/Threshold", offsetof
    (P_ctrl_custom_T, Switch1_Threshold), 39, 1, 2, 14, 0 },

  { 8, "ctrl_custom/Thrust Allocation/Switch/Threshold", offsetof
    (P_ctrl_custom_T, Switch_Threshold_n), 39, 1, 2, 16, 0 },

  { 9,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/IC/Value",
    offsetof(P_ctrl_custom_T, IC_Value), 26, 3, 2, 18, 0 },

  { 10,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator/InitialCondition",
    offsetof(P_ctrl_custom_T, Integrator_IC_g), 26, 3, 2, 20, 0 },

  { 11,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator1/InitialCondition",
    offsetof(P_ctrl_custom_T, Integrator1_IC), 26, 3, 2, 22, 0 },

  { 12,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Saturation4/UpperLimit",
    offsetof(P_ctrl_custom_T, Saturation4_UpperSat), 27, 3, 2, 24, 0 },

  { 13,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Saturation4/LowerLimit",
    offsetof(P_ctrl_custom_T, Saturation4_LowerSat), 27, 3, 2, 26, 0 },

  { 14,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/w_n2/Gain",
    offsetof(P_ctrl_custom_T, w_n2_Gain), 27, 3, 2, 28, 0 },

  { 15,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/w_n1/Gain",
    offsetof(P_ctrl_custom_T, w_n1_Gain), 27, 3, 2, 30, 0 },

  { 16,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/ciwni/Gain",
    offsetof(P_ctrl_custom_T, ciwni_Gain), 27, 3, 2, 32, 0 },

  { 17,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/w_n/Gain",
    offsetof(P_ctrl_custom_T, w_n_Gain), 27, 3, 2, 34, 0 },

  { 18, "ctrl_custom/OBserver/Dead Reckoning ON//OFF  /Dummy/Value", offsetof
    (P_ctrl_custom_T, Dummy_Value), 39, 1, 2, 36, 0 },

  { 19, "ctrl_custom/OBserver/SimpleObserver/L1/Gain", offsetof(P_ctrl_custom_T,
    L1_Gain), 29, 9, 2, 38, 0 },

  { 20, "ctrl_custom/OBserver/SimpleObserver/Integrator1/InitialCondition",
    offsetof(P_ctrl_custom_T, Integrator1_IC_p), 39, 1, 2, 40, 0 },

  { 21, "ctrl_custom/OBserver/SimpleObserver/L2/Gain", offsetof(P_ctrl_custom_T,
    L2_Gain), 29, 9, 2, 42, 0 },

  { 22, "ctrl_custom/OBserver/SimpleObserver/D (somewhat weird with 7.25)/Gain",
    offsetof(P_ctrl_custom_T, Dsomewhatweirdwith725_Gain), 29, 9, 2, 44, 0 },

  { 23, "ctrl_custom/OBserver/SimpleObserver/B/InitialCondition", offsetof
    (P_ctrl_custom_T, B_IC), 39, 1, 2, 46, 0 },

  { 24, "ctrl_custom/OBserver/SimpleObserver/L3/Gain", offsetof(P_ctrl_custom_T,
    L3_Gain), 29, 9, 2, 48, 0 },

  { 25, "ctrl_custom/OBserver/SimpleObserver/invM/Gain", offsetof
    (P_ctrl_custom_T, invM_Gain), 29, 9, 2, 50, 0 },

  { 26,
    "ctrl_custom/OBserver/Dead Reckoning ON//OFF  /Manual Switch/CurrentSetting",
    offsetof(P_ctrl_custom_T, ManualSwitch_CurrentSetting), 40, 1, 2, 52, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 27;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  3, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  3, 1,                                /* Parameter at index 9 */
  3, 1,                                /* Parameter at index 10 */
  3, 1,                                /* Parameter at index 11 */
  1, 3,                                /* Parameter at index 12 */
  1, 3,                                /* Parameter at index 13 */
  1, 3,                                /* Parameter at index 14 */
  1, 3,                                /* Parameter at index 15 */
  1, 3,                                /* Parameter at index 16 */
  1, 3,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  3, 3,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  3, 3,                                /* Parameter at index 21 */
  3, 3,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  3, 3,                                /* Parameter at index 24 */
  3, 3,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_custom/SIXAIS_INN", 0, "", offsetof(B_ctrl_custom_T, SIXAIS_INN) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_custom/Ki", 0, "", offsetof(B_ctrl_custom_T, Ki) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_custom/Kp", 0, "", offsetof(B_ctrl_custom_T, Kp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_custom/EtaSetX", 0, "", offsetof(B_ctrl_custom_T, EtaSetX) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_custom/EtaSetY", 0, "", offsetof(B_ctrl_custom_T, EtaSetY) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_custom/EtaSetPsi", 0, "", offsetof(B_ctrl_custom_T, EtaSetPsi) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_custom/MomentDes", 0, "", offsetof(B_ctrl_custom_T, MomentDes) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_custom/Pose/x_m", 0, "", offsetof(B_ctrl_custom_T, x_m) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_custom/FXDes", 0, "", offsetof(B_ctrl_custom_T, FXDes) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_custom/Pose/y_m", 0, "", offsetof(B_ctrl_custom_T, y_m) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_custom/FyDes", 0, "", offsetof(B_ctrl_custom_T, FyDes) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_custom/Pose/psi_m", 0, "", offsetof(B_ctrl_custom_T, psi_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_custom/ThrustAlocMethod", 0, "", offsetof(B_ctrl_custom_T,
    ThrustAlocMethod) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_custom/OBserver/SimpleObserver/Integrator", 0, "etahat(1, 1)",
    offsetof(B_ctrl_custom_T, etahat) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 14, "ctrl_custom/OBserver/SimpleObserver/Integrator", 0, "etahat(1, 2)",
    offsetof(B_ctrl_custom_T, etahat) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 15, "ctrl_custom/OBserver/SimpleObserver/Integrator", 0, "etahat(1, 3)",
    offsetof(B_ctrl_custom_T, etahat) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 16, "ctrl_custom/OBserver/Useobserver4Eta", 0, "", offsetof(B_ctrl_custom_T,
    Useobserver4Eta) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_custom/DirectControl_or_Dp", 0, "", offsetof(B_ctrl_custom_T,
    DirectControl_or_Dp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_custom/Find tau_body/Detect Change/Delay Input1", 0, "U(k-1)",
    offsetof(B_ctrl_custom_T, Uk1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 19,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator2/(1, 1)",
    0, "", offsetof(B_ctrl_custom_T, Integrator2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 20,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator2/(1, 2)",
    0, "", offsetof(B_ctrl_custom_T, Integrator2) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 21,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator2/(1, 3)",
    0, "", offsetof(B_ctrl_custom_T, Integrator2) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 22, "ctrl_custom/Find tau_body/Simple DP controller/Sum/(1, 1)", 0, "",
    offsetof(B_ctrl_custom_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 23, "ctrl_custom/Find tau_body/Simple DP controller/Sum/(1, 2)", 0, "",
    offsetof(B_ctrl_custom_T, Sum) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 24, "ctrl_custom/Find tau_body/Simple DP controller/Sum/(1, 3)", 0, "",
    offsetof(B_ctrl_custom_T, Sum) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 25, "ctrl_custom/Thrust Allocation/Switch1", 0, "", offsetof(B_ctrl_custom_T,
    Switch1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 26, "ctrl_custom/Thrust Allocation/Switch/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Switch) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 27, "ctrl_custom/Thrust Allocation/Switch/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Switch) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 28, "ctrl_custom/Thrust Allocation/Switch/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Switch) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 29, "ctrl_custom/Thrust Allocation/Switch/(1, 4)", 0, "", offsetof
    (B_ctrl_custom_T, Switch) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 30, "ctrl_custom/Thrust Allocation/Switch/(1, 5)", 0, "", offsetof
    (B_ctrl_custom_T, Switch) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 31, "ctrl_custom/Thrust Allocation/Switch/(1, 6)", 0, "", offsetof
    (B_ctrl_custom_T, Switch) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 32, "ctrl_custom/Thrust Allocation/Switch/(1, 7)", 0, "", offsetof
    (B_ctrl_custom_T, Switch) + (6*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 33,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/IC/(1, 1)",
    0, "", offsetof(B_ctrl_custom_T, IC) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 34,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/IC/(1, 2)",
    0, "", offsetof(B_ctrl_custom_T, IC) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 35,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/IC/(1, 3)",
    0, "", offsetof(B_ctrl_custom_T, IC) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 36,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator/(1, 1)",
    0, "", offsetof(B_ctrl_custom_T, Integrator) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 37,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator/(1, 2)",
    0, "", offsetof(B_ctrl_custom_T, Integrator) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 38,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Integrator/(1, 3)",
    0, "", offsetof(B_ctrl_custom_T, Integrator) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 39,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Saturation4/(1, 1)",
    0, "", offsetof(B_ctrl_custom_T, Saturation4) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 40,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Saturation4/(1, 2)",
    0, "", offsetof(B_ctrl_custom_T, Saturation4) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 41,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Saturation4/(1, 3)",
    0, "", offsetof(B_ctrl_custom_T, Saturation4) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 42,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Sum3/(1, 1)",
    0, "", offsetof(B_ctrl_custom_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 43,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Sum3/(1, 2)",
    0, "", offsetof(B_ctrl_custom_T, Sum3) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 44,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/Sum3/(1, 3)",
    0, "", offsetof(B_ctrl_custom_T, Sum3) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 45,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/w_n/(1, 1)",
    0, "", offsetof(B_ctrl_custom_T, w_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 46,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/w_n/(1, 2)",
    0, "", offsetof(B_ctrl_custom_T, w_n) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 47,
    "ctrl_custom/Find tau_body/Simple DP controller/(Ref mod from  MARREG-1, not really part of task)/Reference Model/w_n/(1, 3)",
    0, "", offsetof(B_ctrl_custom_T, w_n) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 48, "ctrl_custom/OBserver/Dead Reckoning ON//OFF  /Add", 0, "", offsetof
    (B_ctrl_custom_T, Add) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 49, "ctrl_custom/OBserver/SimpleObserver/Add", 0, "d_etahat(1, 1)", offsetof
    (B_ctrl_custom_T, d_etahat) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 50, "ctrl_custom/OBserver/SimpleObserver/Add", 0, "d_etahat(1, 2)", offsetof
    (B_ctrl_custom_T, d_etahat) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 51, "ctrl_custom/OBserver/SimpleObserver/Add", 0, "d_etahat(1, 3)", offsetof
    (B_ctrl_custom_T, d_etahat) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 52, "ctrl_custom/OBserver/SimpleObserver/Multiply2/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Multiply2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 53, "ctrl_custom/OBserver/SimpleObserver/Multiply2/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Multiply2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 54, "ctrl_custom/OBserver/SimpleObserver/Multiply2/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Multiply2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 55, "ctrl_custom/OBserver/SimpleObserver/invM/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, invM) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 56, "ctrl_custom/OBserver/SimpleObserver/invM/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, invM) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 57, "ctrl_custom/OBserver/SimpleObserver/invM/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, invM) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 58, "ctrl_custom/IMU/Acc_z", 0, "", offsetof(B_ctrl_custom_T, Acc_z) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 59, "ctrl_custom/IMU/Acc_x", 0, "", offsetof(B_ctrl_custom_T, Acc_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 60, "ctrl_custom/IMU/Acc_y", 0, "", offsetof(B_ctrl_custom_T, Acc_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 61, "ctrl_custom/IMU/Gyro_x", 0, "", offsetof(B_ctrl_custom_T, Gyro_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 62, "ctrl_custom/IMU/Gyro_y", 0, "", offsetof(B_ctrl_custom_T, Gyro_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 63, "ctrl_custom/IMU/Gyro_z", 0, "", offsetof(B_ctrl_custom_T, Gyro_z) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 64, "ctrl_custom/Find tau_body/Simple DP controller/NED->Body", 0, "(1, 1)",
    offsetof(B_ctrl_custom_T, y) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 65, "ctrl_custom/Find tau_body/Simple DP controller/NED->Body", 0, "(1, 2)",
    offsetof(B_ctrl_custom_T, y) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 66, "ctrl_custom/Find tau_body/Simple DP controller/NED->Body", 0, "(1, 3)",
    offsetof(B_ctrl_custom_T, y) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 67, "ctrl_custom/Find tau_body/Detect Change/FixPt Relational Operator", 0,
    "", offsetof(B_ctrl_custom_T, FixPtRelationalOperator) + (0*sizeof(boolean_T)),
    BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 68, "ctrl_custom/OBserver/SimpleObserver/Ned-Body1", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, sf_NedBody1.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 69, "ctrl_custom/OBserver/SimpleObserver/Ned-Body1", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, sf_NedBody1.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 70, "ctrl_custom/OBserver/SimpleObserver/Ned-Body1", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, sf_NedBody1.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 71, "ctrl_custom/OBserver/SimpleObserver/Ned-Body", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, sf_NedBody.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 72, "ctrl_custom/OBserver/SimpleObserver/Ned-Body", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, sf_NedBody.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 73, "ctrl_custom/OBserver/SimpleObserver/Ned-Body", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, sf_NedBody.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 74;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 34;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "SIXAIS_INN", 1, EXT_IN, 1, 1, 1 },

  { 2, "Ki", 0, EXT_IN, 1, 1, 1 },

  { 3, "Kp", 0, EXT_IN, 1, 1, 1 },

  { 4, "EtaSetX", 0, EXT_IN, 1, 1, 1 },

  { 5, "EtaSetY", 0, EXT_IN, 1, 1, 1 },

  { 6, "EtaSetPsi", 0, EXT_IN, 1, 1, 1 },

  { 7, "MomentDes", 0, EXT_IN, 1, 1, 1 },

  { 8, "Pose/x_m", 0, EXT_IN, 1, 1, 1 },

  { 9, "FXDes", 0, EXT_IN, 1, 1, 1 },

  { 10, "Pose/y_m", 0, EXT_IN, 1, 1, 1 },

  { 11, "FyDes", 0, EXT_IN, 1, 1, 1 },

  { 12, "Pose/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 13, "ThrustAlocMethod", 0, EXT_IN, 1, 1, 1 },

  { 14, "OBserver/Useobserver4Eta", 0, EXT_IN, 1, 1, 1 },

  { 15, "DirectControl_or_Dp", 0, EXT_IN, 1, 1, 1 },

  { 16, "IMU/Acc_z", 1, EXT_IN, 1, 1, 1 },

  { 17, "IMU/Acc_x", 1, EXT_IN, 1, 1, 1 },

  { 18, "IMU/Acc_y", 1, EXT_IN, 1, 1, 1 },

  { 19, "IMU/Gyro_x", 1, EXT_IN, 1, 1, 1 },

  { 20, "IMU/Gyro_y", 1, EXT_IN, 1, 1, 1 },

  { 21, "IMU/Gyro_z", 1, EXT_IN, 1, 1, 1 },

  { 1, "SIXAIS_OUT", 1, EXT_OUT, 1, 1, 1 },

  { 2, "QTM_SCOPEX", 0, EXT_OUT, 1, 1, 1 },

  { 3, "QTM_SCOPEY", 0, EXT_OUT, 1, 1, 1 },

  { 4, "QTM_SCOPEPSI", 0, EXT_OUT, 1, 1, 1 },

  { 5, "SaturationFlag", 0, EXT_OUT, 1, 1, 1 },

  { 6, "u/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 7, "u/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 8, "u/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 9, "u/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 10, "u/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 11, "u/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 12, "u/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 13, "IMU/IMU_SCOPEZ", 1, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_custom";
static const char* NI_CompiledModelVersion = "1.75";
static const char* NI_CompiledModelDateTime = "Tue Jan 29 11:21:24 2019";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2017.0.0.143 (2017) for Simulink Coder 8.11 (R2016b)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2017.0.0.143";

/*========================================================================*
 * Function: NIRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, NI_builder, NI_CompiledModelName,
                     NI_CompiledModelVersion, NI_BuilderVersion,
                     NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, NI_builder, NI_CompiledModelName,
             NI_CompiledModelVersion, NI_BuilderVersion,
             NI_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len,
  char* blkname, int32_t *bnlen,
  int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t*
  dims, int32_t* numdim)
{
  int32_t sigidx = *sidx;
  int32_t i = 0;
  char *addr = NULL;
  char *IDblk = 0;
  int32_t IDport = 0;
  if (sigidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0)) {
      /* parse ID into blkname and port */
      addr = strrchr(ID, ':');
      if (addr == NULL) {
        return NI_SigListSize;
      }

      /* Calculate the char offset into the string after the port */
      i = addr - ID;

      /* malformed ID */
      if (i<=0) {
        return NI_SigListSize;
      }

      IDblk = ID;
      IDport = atoi(ID+i+1);

      /* lookup the table for matching ID */
      for (i=0; i<NI_SigListSize; i++) {
        /* 11 to accomodate ':','/', port number and null character */
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname) + 11, sizeof(char));
        if (strlen(NI_SigList[i].signalname)>0) {
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        } else {
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        }

        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1)) {
          break;
        }

        free(tempID);
      }

      if (i < NI_SigListSize) {
        sigidx = *sidx = i;
      } else {
        return NI_SigListSize;
      }
    } else {
      // no index or ID specified.
      return NI_SigListSize;
    }
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID != NULL) {
      // no need for return string to be null terminated!
      /* 11 to accomodate ':','/', port number and null character */
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0) {
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      } else {
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      }

      if ((int32_t)strlen(tempID)<*ID_len) {
        *ID_len = strlen(tempID);
      }

      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].blockname)<*bnlen) {
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      }

      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].signalname)<*snlen) {
        *snlen = strlen(NI_SigList[sigidx].signalname);
      }

      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum != NULL) {
      *portnum = NI_SigList[sigidx].portno;
    }

    if (dattype != NULL) {
      *dattype = NI_SigList[sigidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_SigList[sigidx].numofdims;
      } else if (dims != NULL) {
        for (i=0;i < *numdim; i++) {
          dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
        }
      }
    }

    return NI_OK;
  }

  return NI_SigListSize;
}

/*========================================================================*
 * Function: NIRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterIndices(int32_t* indices, int32_t* len)
{
  int32_t i;
  if ((len == NULL) || (indices == NULL)) {
    return NI_ERROR;
  }

  if (*len == -1) {
    *len = NI_ParamListSize;
  } else {
    for (i=0; (i < NI_ParamListSize) && (i < *len); i++) {
      indices[i] = NI_ParamList[i].idx;
    }

    *len = i;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	NI_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t*
  ID_len, char* paramname, int32_t *pnlen,
  int32_t *dattype, int32_t* dims, int32_t* numdim)
{
  int32_t i = 0;
  int32_t paramidx = *pidx;
  if (paramidx < 0) {
    // check if ID has been specified.
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0) ) {
      // lookup the table for matching ID
      for (i=0; i < NI_ParamListSize; i++) {
        if (strcmp(ID,NI_ParamList[i].paramname) == 0) {
          /* found matching string */
          break;
        }
      }

      if (i < NI_ParamListSize) {
        /* note the index into the rtParamAttribs */
        paramidx = *pidx = i;
      } else {
        return NI_ParamListSize;
      }
    } else {
      // no index or ID specified.
      return NI_ParamListSize;
    }
  }

  if ((paramidx >= 0) && (paramidx<NI_ParamListSize)) {
    if (ID != NULL) {
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *ID_len) {
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *pnlen) {
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype != NULL) {
      *dattype = NI_ParamList[paramidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_ParamList[paramidx].numofdims;
      } else if (dims != NULL) {
        for (i = 0; i < *numdim; i++) {
          dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset + i];
        }
      }
    }

    return NI_OK;
  }

  return NI_ParamListSize;
}

/*========================================================================*
 * Function: NIRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	NI_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return NI_ExtListSize;
  }

  if (idx != NULL) {
    *idx = NI_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = NI_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = NI_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    }
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NI_ProbeOneSignal
 *
 * Abstract:
 *		Helper function to probe one signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: Returns the last index value probed in a vector signal
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
    SetSITErrorMessage("NI_ProbeOneSignal: Received request to probe a virtual signal, but was expecting a ground source. Ignoring virtual signal probe. Report this behavior to National Instruments.",
                       0);
    return 0;
  } else {
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ? S->blockIO :
                        S->inputs) + (uintptr_t)NI_SigList[idx].addr;
    int32_t subindex = (vLength == -1) ? 0 : vOffset;
    int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
      vOffset);
    while ((subindex < sublength) && (*count < len))
      value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++,
        NI_SigList[idx].datatype, NI_SigList[idx].IsComplex);
    return *count;
  }
}

/*========================================================================*
 * Function: NIRT_ProbeSignals
 *
 * Abstract:
 *	returns the latest signal values.
 *
 * Input Parameters:
 *	sigindices	: list of signal indices to be probed.
 *	numsigs		: length of sigindices array.
 *
 *		NOTE: (Implementation detail) the sigindices array that is passed in is delimited by a value of -1.
 *		Thus the # of valid indices in the sigindices table is min(numsigs, index of value -1) - 1.
 *		Reason for subtracting 1, the first index in the array is used for bookkeeping and should be copied
 *		into the 0th index in the signal values buffer.
 *		Also, the 1st index in the signal values buffer should contain the current timestamp. Hence valid
 *		signal data should be filled in starting from index 2. Any non-scalar signals should be added to the
 *		buffer in row-order.
 *
 * Input/Output Parameters
 *	num			: (in) length of sigvalues buffer (out) number of values returned in the buffer
 *
 * Output Parameters:
 *	value		: array of signal values
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_ProbeSignals(int32_t* sigindices, int32_t numsigs,
  double* value, int32_t* len)
{
  int32_t i = 0;
  int32_t idx = 0;
  int32_t count = 0;
  if (!SITexportglobals.inCriticalSection) {
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  }

  /* Get the index to the first signal */
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  /* Get the second and other signals */
  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0) {
      break;
    }

    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        int32_t vidx = NI_VirtualBlockSources[NI_SigList[idx].addr];
        NI_ProbeOneSignal(vidx, value, *len, &count, 0, -1);
      } else {
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
      }
    }
  }

  *len = count;
  return count;
}

int32_t NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_custom_P, sizeof(P_ctrl_custom_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_custom_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_custom_T));
  return NI_OK;
}

static int32_t NI_SetParamTxStatus = NI_OK;

/*========================================================================*
 * Function: NIRT_SetParameter
 *
 * Abstract:
 *	Set parameter value. Called either in scheduler loop or a background loop.
 *
 * Input Parameters:
 *	index	: index of the parameter (as specified in Parameter Information)
 *	subindex: index in the flattened array, if parameter is n-D array
 *	val		: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  char* ptr = NULL;

  /* Check bounds */
  if (index >= NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_custom_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0) {
        /* No values to commit */
        return NI_OK;
      } else {
        SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                           1);
        WriteSideDirtyFlag = 0;
        return NI_ERROR;
      }
    }

    /* If an error occurred and we have values to commit, then save to the write side and return error */
    if (NI_SetParamTxStatus == NI_ERROR) {
      // fail the transaction.
      // copy old list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1) {
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_custom_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_custom_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex >= NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_custom_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, value, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_SetVectorParameter
 *
 * Abstract:
 *	Sets the value to a parameter array.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	paramvalues	: array of values to set
 *	paramlength	: Length of parameter values.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetVectorParameter( uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  uint32_t i = 0;
  int32_t retval = NI_OK;
  char* ptr = NULL;

  /* verify that index is within bounds*/
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_custom_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char*)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  while (i < paramlength) {
    /* Convert the incoming double datatype to the parameter's internal datatype and update value */
    retval = retval & NIRT_SetValueByDataType(ptr, i, paramvalues[i],
      NI_ParamList[index].datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

/*========================================================================*
 * Function: NIRT_SetScalarParameterInline
 *
 * Abstract:
 *	Sets the value to a parameter immediately without the need of a commit request.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	subindex	: offset of the element within the parameter
 *	paramvalue	: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetScalarParameterInline( uint32_t index, uint32_t
  subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, paramvalue, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_GetParameter
 *
 * Abstract:
 *	Get the current value of a parameter.
 *
 * Input Parameters:
 *	index	: index of the parameter
 *	subindex: element index into the flattened array if an array
 *
 * Output Parameters:
 *	val		: value of the parameter
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  char* ptr = NULL;

  /* Check index boundaries */
  if (index >= NI_ParamListSize || index < 0 || (subindex>=NI_ParamList[index].
       width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;

  /* Convert the parameter's internal datatype to double and return its value */
  *value = NIRT_GetValueByDataType(ptr, subindex, NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetVectorParameter
 *
 * Abstract:
 *	Get the current value of a vector parameter.
 *
 * Input Parameters:
 *	index: index of the parameter
 *	paramLength: length of the parameter
 *
 * Output Parameters:
 *	paramValues: an array of the parameter's value
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  char* ptr = NULL;
  uint32_t i = 0;
  if (index >= (uint32_t)NI_ParamListSize || index < 0 || (paramlength !=
       (uint32_t)NI_ParamList[index].width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  while (i<paramlength) {
    /* Convert the parameter's internal datatype to double and return its value */
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSimState(int32_t* numContStates, char
  * contStatesNames, double* contStates, int32_t* numDiscStates, char
  * discStatesNames, double* discStates, int32_t* numClockTicks, char
  * clockTicksNames, int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 21;
      *numDiscStates = 451;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator_CSTATE_f), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_f");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator_CSTATE_f), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_f");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator_CSTATE_f), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_f");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator_CSTATE_i), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator_CSTATE_i), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator_CSTATE_i), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator1_CSTATE_j), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_j");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator1_CSTATE_j), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_j");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator1_CSTATE_j), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_j");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.B_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "B_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.B_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "B_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.B_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "B_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.DelayInput1_DSTATE,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.DelayInput1_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.SIXAIS_INN_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.SIXAIS_INN_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Ki_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Ki_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Kp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Kp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.SIXAIS_OUT_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.SIXAIS_OUT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.EtaSetX_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.EtaSetX_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.EtaSetY_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.EtaSetY_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.EtaSetPsi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.EtaSetPsi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.MomentDes_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.MomentDes_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.QTM_SCOPEX_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.QTM_SCOPEX_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.FXDes_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.FXDes_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.QTM_SCOPEY_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.QTM_SCOPEY_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.FyDes_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.FyDes_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.QTM_SCOPEPSI_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.QTM_SCOPEPSI_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ThrustAlocMethod_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ThrustAlocMethod_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Useobserver4Eta_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Useobserver4Eta_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.DirectControl_or_Dp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.DirectControl_or_Dp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.SaturationFlag_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.SaturationFlag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.omega_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.omega_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_BT_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.IC_FirstOutputTime,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.IC_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.IMU_SCOPEZ_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.IMU_SCOPEZ_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Scope_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Scope_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Scope_PWORK_f, 0,
      20, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Scope_PWORK_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Scope_PWORK_f, 1,
      20, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Scope_PWORK_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Scope1_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Scope1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Scope5_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Scope5_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Scope_PWORK_g, 0,
      20, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Scope_PWORK_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Scope_PWORK_g, 1,
      20, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Scope_PWORK_g");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.SIXAIS_INN_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.SIXAIS_INN_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Ki_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Ki_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Kp_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Kp_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.SIXAIS_OUT_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.SIXAIS_OUT_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.EtaSetX_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.EtaSetX_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.EtaSetY_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.EtaSetY_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.EtaSetPsi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.EtaSetPsi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.MomentDes_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.MomentDes_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.QTM_SCOPEX_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.QTM_SCOPEX_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.FXDes_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.FXDes_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.QTM_SCOPEY_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.QTM_SCOPEY_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.FyDes_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.FyDes_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.QTM_SCOPEPSI_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.QTM_SCOPEPSI_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.ThrustAlocMethod_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.ThrustAlocMethod_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.Useobserver4Eta_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.Useobserver4Eta_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.DirectControl_or_Dp_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.DirectControl_or_Dp_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.SaturationFlag_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.SaturationFlag_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.alpha_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.omega_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.omega_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.alpha_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_BT_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_z_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.IMU_SCOPEZ_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.IMU_SCOPEZ_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_z_DWORK2");
    }
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_SetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetSimState(double* contStates, double* discStates,
  int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if (contStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE_f), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE_f), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE_f), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE_i), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE_i), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE_i), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE_j), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE_j), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE_j), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.B_CSTATE), 0, contStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.B_CSTATE), 1, contStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.B_CSTATE), 2, contStates[idx++], 0,
      0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_custom_DW.DelayInput1_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.SIXAIS_INN_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Ki_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Kp_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.SIXAIS_OUT_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.EtaSetX_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.EtaSetY_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.EtaSetPsi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.MomentDes_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEX_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.FXDes_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEY_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.FyDes_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEPSI_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ThrustAlocMethod_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Useobserver4Eta_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.DirectControl_or_Dp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.SaturationFlag_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u_BT_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.IC_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.IMU_SCOPEZ_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Scope_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Scope_PWORK_f, 0, discStates[idx++],
      20, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Scope_PWORK_f, 1, discStates[idx++],
      20, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Scope1_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Scope5_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Scope_PWORK_g, 0, discStates[idx++],
      20, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Scope_PWORK_g, 1, discStates[idx++],
      20, 0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.SIXAIS_INN_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Ki_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Kp_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.SIXAIS_OUT_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.EtaSetX_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.EtaSetY_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.EtaSetPsi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.MomentDes_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEX_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.FXDes_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEY_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.FyDes_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEPSI_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.ThrustAlocMethod_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Useobserver4Eta_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.DirectControl_or_Dp_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.SaturationFlag_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_BT_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.IMU_SCOPEZ_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK2, count,
        discStates[idx++], 19, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_custom
