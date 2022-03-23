/*
 * File: my_predict_mode2_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 17:01:37
 */

/* Include Files */
#include "my_predict_mode2_initialize.h"
#include "my_predict_mode2.h"
#include "my_predict_mode2_data.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void my_predict_mode2_initialize(void)
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  my_predict_mode2_init();
  isInitialized_my_predict_mode2 = true;
}

/*
 * File trailer for my_predict_mode2_initialize.c
 *
 * [EOF]
 */
