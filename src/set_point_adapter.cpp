//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: set_point_adapter.cpp
//
// Code generated for Simulink model 'set_point_adapter'.
//
// Model version                  : 6.2
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Jan 28 17:16:08 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "set_point_adapter.h"
#include "rtwtypes.h"
#include "set_point_adapter_types.h"

// Block signals (default storage)
B_set_point_adapter_T set_point_adapter_B;

// Block states (default storage)
DW_set_point_adapter_T set_point_adapter_DW;

// Real-time model
RT_MODEL_set_point_adapter_T set_point_adapter_M_ = RT_MODEL_set_point_adapter_T
  ();
RT_MODEL_set_point_adapter_T *const set_point_adapter_M = &set_point_adapter_M_;

// Model step function
void set_point_adapter_step(void)
{
  SL_Bus_set_point_adapter_std_msgs_Float64 b_varargout_2;
  SL_Bus_set_point_adapter_std_msgs_Float64 rtb_BusAssignment1;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S3>/SourceBlock'
  b_varargout_1 = Sub_set_point_adapter_31.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  // Start for MATLABSystem: '<S3>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S4>/In1'
    set_point_adapter_B.In1 = b_varargout_2;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Gain: '<Root>/Gain'

  rtb_BusAssignment1.Data = set_point_adapter_P.Gain_Gain *
    set_point_adapter_B.In1.Data;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_set_point_adapter_44.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
}

// Model initialize function
void set_point_adapter_initialize(void)
{
  {
    int32_T i;
    char_T b_zeroDelimTopic[16];
    char_T b_zeroDelimTopic_0[8];
    static const char_T b_zeroDelimTopic_1[16] = "acc/set_point_2";
    static const char_T b_zeroDelimTopic_2[8] = "cmd_vel";

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S4>/In1' incorporates:
    //   Outport: '<S4>/Out1'

    set_point_adapter_B.In1 = set_point_adapter_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    set_point_adapter_DW.obj_g.matlabCodegenIsDeleted = false;
    set_point_adapter_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_set_point_adapter_31.createSubscriber(&b_zeroDelimTopic[0], 1);
    set_point_adapter_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    set_point_adapter_DW.obj.matlabCodegenIsDeleted = false;
    set_point_adapter_DW.obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Pub_set_point_adapter_44.createPublisher(&b_zeroDelimTopic_0[0], 1);
    set_point_adapter_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'
  }
}

// Model terminate function
void set_point_adapter_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!set_point_adapter_DW.obj_g.matlabCodegenIsDeleted) {
    set_point_adapter_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!set_point_adapter_DW.obj.matlabCodegenIsDeleted) {
    set_point_adapter_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
