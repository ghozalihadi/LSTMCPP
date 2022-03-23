/*
 * File: my_predict_mode1_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 18:03:05
 */

/* Include Files */
#include "my_predict_mode1_initialize.h"
#include "my_predict_mode1.h"
#include "my_predict_mode1_data.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void my_predict_mode1_initialize(void)
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  my_predict_mode1_init();
  isInitialized_my_predict_mode1 = true;
}

/*
 * File trailer for my_predict_mode1_initialize.c
 *
 * [EOF]
 */
