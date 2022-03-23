/*
 * File: my_predict_mode1_terminate.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 18:03:05
 */

/* Include Files */
#include "my_predict_mode1_terminate.h"
#include "my_predict_mode1_data.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void my_predict_mode1_terminate(void)
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_my_predict_mode1 = false;
}

/*
 * File trailer for my_predict_mode1_terminate.c
 *
 * [EOF]
 */
