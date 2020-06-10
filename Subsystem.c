/*
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Jun 10 02:01:51 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Subsystem.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Subsystem_step(void)
{
  real_T _BmzAmz_tmp;
  real_T _Rz_tmp;
  real_T _1Sz_tmp;

  /* DiscreteFilter: '<S1>/_Bm(z)//Am(z)' incorporates:
   *  Inport: '<Root>/In1'
   */
  _BmzAmz_tmp = (rtU.In1 - -1.2451 * rtDW._BmzAmz_states[0]) - 0.40657 *
    rtDW._BmzAmz_states[1];
  _Rz_tmp = 0.16148 * _BmzAmz_tmp;

  /* DiscreteFilter: '<S1>/_1//S(z)' incorporates:
   *  DiscreteFilter: '<S1>/_R(z)'
   *  DiscreteFilter: '<S1>/_T(z)'
   *  Inport: '<Root>/In2'
   *  Sum: '<S1>/_Sum1'
   */
  _1Sz_tmp = ((((3.3333 * _Rz_tmp + -4.5807 * rtDW._Tz_states[0]) + 1.6225 *
                rtDW._Tz_states[1]) - ((3.0 * rtU.In2 + -3.939 *
    rtDW._Rz_states[0]) + 1.3142 * rtDW._Rz_states[1])) - -0.3742 *
              rtDW._1Sz_states[0]) - -0.6258 * rtDW._1Sz_states[1];

  /* Outport: '<Root>/Out1' incorporates:
   *  DiscreteFilter: '<S1>/_1//S(z)'
   */
  rtY.Out1 = _1Sz_tmp;

  /* Update for DiscreteFilter: '<S1>/_Bm(z)//Am(z)' */
  rtDW._BmzAmz_states[1] = rtDW._BmzAmz_states[0];
  rtDW._BmzAmz_states[0] = _BmzAmz_tmp;

  /* Update for DiscreteFilter: '<S1>/_T(z)' incorporates:
   *  DiscreteFilter: '<S1>/_T(z)'
   */
  rtDW._Tz_states[1] = rtDW._Tz_states[0];
  rtDW._Tz_states[0] = _Rz_tmp;

  /* Update for DiscreteFilter: '<S1>/_R(z)' incorporates:
   *  Inport: '<Root>/In2'
   */
  rtDW._Rz_states[1] = rtDW._Rz_states[0];
  rtDW._Rz_states[0] = rtU.In2;

  /* Update for DiscreteFilter: '<S1>/_1//S(z)' */
  rtDW._1Sz_states[1] = rtDW._1Sz_states[0];
  rtDW._1Sz_states[0] = _1Sz_tmp;
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
