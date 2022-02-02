/*
 * File: lstmForward.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 18:03:05
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
void b_lstmForwardUsingExplicitLoops(const float X[672], const float W[2048],
                                     const float R[1024], const float b[64],
                                     const float c0[16], const float b_y0[16],
                                     float CS[336], float YT[336]);

void lstmForwardUsingExplicitLoops(const float X[105], const float W[640],
                                   const float R[4096], const float b[128],
                                   const float c0[32], const float b_y0[32],
                                   float CS[672], float YT[672]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for lstmForward.h
 *
 * [EOF]
 */
