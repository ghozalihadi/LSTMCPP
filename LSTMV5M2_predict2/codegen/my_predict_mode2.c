/*
 * File: my_predict_mode2.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 17:01:37
 */

/* Include Files */
#include "my_predict_mode2.h"
#include "my_predict_mode2_data.h"
#include "my_predict_mode2_initialize.h"
#include "my_predict_mode2_internal_types.h"
#include "predict.h"

/* Variable Definitions */
static boolean_T mynet_not_empty;

/* Function Definitions */
/*
 * A persistent object mynet is used to load the series network object.
 *  At the first call to this function, the persistent object is constructed and
 *  setup. When the function is called subsequent times, the same object is
 * reused to call predict on inputs, thus avoiding reconstructing and reloading
 * the network object.
 *
 * Arguments    : double in
 * Return Type  : float
 */
float my_predict_mode2(double in)
{
  static c_coder_ctarget_DeepLearningNet mynet;
  if (!isInitialized_my_predict_mode2) {
    my_predict_mode2_initialize();
  }
  /*  load network according to mode */
  if (!mynet_not_empty) {
    mynet.IsInitialized = false;
    mynet_not_empty = true;
  }
  /*  pass in input    */
  return DeepLearningNetwork_predict(&mynet, in);
}

/*
 * A persistent object mynet is used to load the series network object.
 *  At the first call to this function, the persistent object is constructed and
 *  setup. When the function is called subsequent times, the same object is
 * reused to call predict on inputs, thus avoiding reconstructing and reloading
 * the network object.
 *
 * Arguments    : void
 * Return Type  : void
 */
void my_predict_mode2_init(void)
{
  mynet_not_empty = false;
}

/*
 * File trailer for my_predict_mode2.c
 *
 * [EOF]
 */
