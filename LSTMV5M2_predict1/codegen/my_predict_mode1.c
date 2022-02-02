/*
 * File: my_predict_mode1.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 18:03:05
 */

/* Include Files */
#include "my_predict_mode1.h"
#include "my_predict_mode1_data.h"
#include "my_predict_mode1_initialize.h"
#include "my_predict_mode1_internal_types.h"
#include "predict.h"
#include <string.h>

/* Variable Definitions */
static unsigned char mynet_not_empty;

/* Function Definitions */
/*
 * A persistent object mynet is used to load the series network object.
 *  At the first call to this function, the persistent object is constructed and
 *  setup. When the function is called subsequent times, the same object is
 * reused to call predict on inputs, thus avoiding reconstructing and reloading
 * the network object.
 *
 * Arguments    : double in[210]
 * Return Type  : float
 */
float my_predict_mode1(double in[210])
{
  static c_coder_ctarget_DeepLearningNet mynet;
  double sequence[210];
  double avgd_seq[105];
  double x_data[70];
  double d;
  double y;
  int i;
  int in_tmp_tmp;
  int l;
  int m;
  if (!isInitialized_my_predict_mode1) {
    my_predict_mode1_initialize();
  }
  /*  load network according to mode */
  if (!mynet_not_empty) {
    mynet.IsInitialized = 0;  //////change false to 0
    mynet_not_empty = 1; //////change true to 1
  }
  /*  pre-processing steps (INSERT DIRECTLY BELOW THIS LINE!) */
  /*  Voltage Normalization */
  /*  (input -minimun)/ratio , ratio is max-min */
  /*  Current Normalization */
  /*  (input -minimun)/ratio , ratio is max-min */
  /*  Moving Average (Window Size is 50) */
  for (i = 0; i < 70; i++) {
    y = (in[3 * i] - -21.0) / 42.0;
    in[3 * i] = y;
    in_tmp_tmp = 3 * i + 1;
    d = (in[in_tmp_tmp] - -10.5) / 20.5;
    in[in_tmp_tmp] = d;
    sequence[3 * i] = y;
    sequence[in_tmp_tmp] = d;
    in_tmp_tmp = 3 * i + 2;
    sequence[in_tmp_tmp] = in[in_tmp_tmp];
  }
  memset(&avgd_seq[0], 0, 105U * sizeof(double));
  for (l = 0; l < 3; l++) {
    for (i = 0; i < 21; i++) {
      avgd_seq[l + 5 * i] = sequence[l + 3 * (i + 49)];
    }
    if (l + 1 < 3) {
      for (m = 0; m < 21; m++) {
        for (i = 0; i < 50; i++) {
          x_data[i] = sequence[l + 3 * (m + i)];
        }
        y = sequence[l + 3 * m];
        for (in_tmp_tmp = 2; in_tmp_tmp < 51; in_tmp_tmp++) {
          y += x_data[in_tmp_tmp - 1];
        }
        avgd_seq[(l + 5 * m) + 3] = y / 50.0;
        /* take the average of the windowed section */
      }
    }
  }
  /*  pass in input    */
  return DeepLearningNetwork_predict(&mynet, avgd_seq);
  /*  Post -processing step : inverse the normalization */
  /*  gold = (norm_labels{i}.*norm(i,2))+norm(i,1) */
  /*  ratio = ?? */
  /*  min = ?? */
  /*  out=out*ratio + min; */
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
void my_predict_mode1_init(void)
{
  mynet_not_empty = 0; //////change false to 0
}

/*
 * File trailer for my_predict_mode1.c
 *
 * [EOF]
 */
