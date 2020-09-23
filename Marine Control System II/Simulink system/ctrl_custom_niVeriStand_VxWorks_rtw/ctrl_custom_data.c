#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define ctrl_custom_P                  ctrl_custom_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_custom_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.100
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Tue Mar 12 16:19:29 2019
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_custom.h"
#include "ctrl_custom_private.h"

/* Block parameters (auto storage) */
P_ctrl_custom_T ctrl_custom_P = {
  /*  Variable: C1
   * Referenced by: '<S11>/Gain'
   */
  { 0.48543689320388345, 0.0, 0.4854368932038835, 0.0, 0.0,
    -0.0091902893854672388, 0.22203968540691688, 0.0091902893854672353,
    0.22203968540691693, 0.20638959606761148, 0.048613648345453057,
    -0.571384947975954, -0.048613648345453044, -0.57138494797595407,
    0.44771890179934037 },

  /*  Variable: C2
   * Referenced by: '<S10>/Gain'
   */
  { 1.0435340915546265, 0.10275718898485657, -0.028467141232889116,
    0.51192487717105684, 0.72397110421148936, 0.17980881571464868,
    -1.3210964572156305, -1.8683125269973924, 0.51758438605252932 },

  /*  Variable: D
   * Referenced by:
   *   '<S14>/Gain2'
   *   '<S15>/Gain2'
   */
  { 0.6555, 0.0, 0.0, 0.0, 1.33, -0.0, 0.0, 7.25, 1.9 },

  /*  Variable: L_1
   * Referenced by:
   *   '<S14>/Gain7'
   *   '<S15>/Gain7'
   */
  { 12.0, 0.0, 0.0, 0.0, 12.0, 0.0, 0.0, 0.0, 12.0 },

  /*  Variable: L_2
   * Referenced by:
   *   '<S14>/Gain'
   *   '<S15>/Gain'
   */
  { 8.0, 0.0, 0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 8.0 },

  /*  Variable: L_3
   * Referenced by: '<S14>/Gain4'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  0.0,                                 /* Variable: alpha1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  2.3561944901923448,                  /* Variable: alpha2
                                        * Referenced by: '<Root>/Constant2'
                                        */

  /*  Variable: inv_M
   * Referenced by:
   *   '<S14>/Gain1'
   *   '<S15>/Gain1'
   */
  { 0.062073246430788334, 0.0, -0.0, 0.0, 0.041651810141086335,
    -0.0079851500148196766, -0.0, -0.0079851500148196766, 0.36384968931217082 },
  0.0,                                 /* Mask Parameter: DetectIncrease2_vinit
                                        * Referenced by: '<S1>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease3_vinit
                                        * Referenced by: '<S2>/Delay Input1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/SIXAIS_INN'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Arrow_Left'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Arrow_Left'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Arrow_Left'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Arrow_Left'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Arrow_Left'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Arrow_Left'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Arrow_Right'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Arrow_Right'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Arrow_Right'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Arrow_Right'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Arrow_Right'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Arrow_Right'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<Root>/Memory1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Block3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Block3'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Block3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Block3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Block3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Block3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Block4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Block4'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Block4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Block4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Block4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Block4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/x_m'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S8>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_out'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/x_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/y_m'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S8>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_out'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/y_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S23>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_out'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/psi_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_out'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_hat'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_hat'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  16.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  19.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/LR'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/LR'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/LR'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/LR'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/LR'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/LR'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/FB'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/FB'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/FB'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/FB'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/FB'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/FB'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/R2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/R2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/R2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/R2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/R2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/R2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/L2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/L2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/L2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/L2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/L2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/L2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Gain'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Gain2'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<Root>/Constant5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/omega_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S13>/Saturation1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/u_BT'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Saturation2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Saturation2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/u_VSP1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Saturation11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Saturation11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/u_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Integrator2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Acc_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Acc_z'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Acc_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Acc_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Acc_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Acc_z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_SCOPEZ'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/IMU_SCOPEZ'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/IMU_SCOPEZ'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Acc_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Acc_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Acc_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Acc_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Acc_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Acc_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Acc_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Acc_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Acc_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Acc_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Acc_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Acc_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Gyro_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Gyro_x'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Gyro_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Gyro_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Gyro_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Gyro_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Gyro_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Gyro_y'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Gyro_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Gyro_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Gyro_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Gyro_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Gyro_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Gyro_z'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Gyro_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Gyro_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Gyro_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Gyro_z'
                                        */
  1U                                   /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S7>/Manual Switch'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.100
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Tue Mar 12 16:19:28 2019
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_custom_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_ctrl_custom_T), 1 },

  { sizeof(real_T), 15, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(uint8_T), 1, 3 },
};

#endif
