/*
 * File: predict.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 17:01:37
 */

#ifndef PREDICT_H
#define PREDICT_H

/* Include Files */
#include "my_predict_mode2_internal_types.h"
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
float DeepLearningNetwork_predict(c_coder_ctarget_DeepLearningNet *obj,
                                  double varargin_1);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for predict.h
 *
 * [EOF]
 */
