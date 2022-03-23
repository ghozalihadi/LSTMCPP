/*
 * File: lstmForward.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 17:01:37
 */

#ifndef LSTMFORWARD_H
#define LSTMFORWARD_H

/* Include Files */
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_lstmForwardUsingExplicitLoops(const float X[32], const float W[2048],
                                     const float R[1024], const float b[64],
                                     const float c0[16], const float b_y0[16],
                                     float CS[16], float YT[16]);

void lstmForwardUsingExplicitLoops(float X, const float W[128],
                                   const float R[4096], const float b[128],
                                   const float c0[32], const float b_y0[32],
                                   float CS[32], float YT[32]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for lstmForward.h
 *
 * [EOF]
 */
