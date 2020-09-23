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

/* Block parameters (auto storage) */
P_ctrl_custom_T ctrl_custom_P = {
  0.0,                                 /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S9>/Delay Input1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Dead Reckoning'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/DR on '
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
                                        * Referenced by: '<Root>/Ki'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Ki'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Ki'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Ki'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Ki'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Ki'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Kp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Kp'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Kp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Kp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Kp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Kp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/SIXAIS_OUT'
                                        */
  4.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/EtaSetX'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/EtaSetY'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/EtaSetPsi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/MomentDes'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/x_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  8.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/FXDes'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/FXDes'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/FXDes'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/FXDes'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/FXDes'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/FXDes'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/y_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  9.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/FyDes'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/FyDes'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/FyDes'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/FyDes'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/FyDes'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/FyDes'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/psi_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  10.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ThrustAlocMethod'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Useobserver4Eta'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/DirectControl_or_Dp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S15>/Integrator2'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Switch1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/SaturationFlag'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S13>/IC'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S15>/Integrator'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 ;0; 0]
   * Referenced by: '<S15>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [
     0.5600    0.5600    0.2120]
   * Referenced by: '<S15>/Saturation4'
   */
  { 0.56, 0.56, 0.212 },

  /*  Expression: -[
     0.5600    0.5600    0.2120]
   * Referenced by: '<S15>/Saturation4'
   */
  { -0.56, -0.56, -0.212 },

  /*  Expression: [   0.8000    0.8000    2.8000]
   * Referenced by: '<S15>/w_n2'
   */
  { 0.8, 0.8, 2.8 },

  /*  Expression: [ 0.8000    0.8000    2.8000]
   * Referenced by: '<S15>/w_n1'
   */
  { 0.8, 0.8, 2.8 },

  /*  Expression: [
     0.7155    0.7155    1.3387
     ]
   * Referenced by: '<S15>/ciwni'
   */
  { 0.7155, 0.7155, 1.3387 },

  /*  Expression: [0.8944    0.8944    1.6733
     ]
   * Referenced by: '<S15>/w_n'
   */
  { 0.8944, 0.8944, 1.6733 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Dummy'
                                        */

  /*  Expression: diag([1 1 1]*5)
   * Referenced by: '<S17>/L1'
   */
  { 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 5.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator1'
                                        */

  /*  Expression: diag([1 1 1]*5)
   * Referenced by: '<S17>/L2 '
   */
  { 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 5.0 },

  /*  Expression: [0.6555 0 0 ; 0 1.33  7.2500 ;0 0 1.9];
   * Referenced by: '<S17>/D (somewhat weird with 7.25) '
   */
  { 0.6555, 0.0, 0.0, 0.0, 1.33, 0.0, 0.0, 7.25, 1.9 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/B'
                                        */

  /*  Expression: diag([1 1 1]*1)
   * Referenced by: '<S17>/L3'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: [16.11 0 0;0 24.11 0.5291; 0 0.5291 2.76]^-1
   * Referenced by: '<S17>/invM'
   */
  { 0.062073246430788334, 0.0, -0.0, 0.0, 0.041651793511688212,
    -0.0079847695460268965, -0.0, -0.0079847695460268965, 0.36384954404594305 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Acc_z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/IMU_SCOPEZ'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Acc_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Acc_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Gyro_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Gyro_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Gyro_z'
                                        */
  1U                                   /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S16>/Manual Switch'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.75
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Tue Jan 29 11:21:24 2019
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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

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

  { sizeof(uint8_T), 1, 3 },
};

#endif
