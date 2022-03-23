/*
 * File: my_predict_mode1_internal_types.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 18:03:05
 */

#ifndef MY_PREDICT_MODE1_INTERNAL_TYPES_H
#define MY_PREDICT_MODE1_INTERNAL_TYPES_H

/* Include Files */
#include "my_predict_mode1_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3
typedef struct {
  float f1[32];
} cell_wrap_3;
#endif /* typedef_cell_wrap_3 */

#ifndef typedef_cell_wrap_4
#define typedef_cell_wrap_4
typedef struct {
  float f1[16];
} cell_wrap_4;
#endif /* typedef_cell_wrap_4 */

#ifndef typedef_cell_5
#define typedef_cell_5
typedef struct {
  cell_wrap_3 f1[2];
  cell_wrap_4 f2[2];
} cell_5;
#endif /* typedef_cell_5 */

#ifndef typedef_c_coder_ctarget_DeepLearningNet
#define typedef_c_coder_ctarget_DeepLearningNet
typedef struct {
  cell_5 State;
  boolean_T IsInitialized;
} c_coder_ctarget_DeepLearningNet;
#endif /* typedef_c_coder_ctarget_DeepLearningNet */

#endif
/*
 * File trailer for my_predict_mode1_internal_types.h
 *
 * [EOF]
 */
