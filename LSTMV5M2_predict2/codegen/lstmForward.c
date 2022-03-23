/*
 * File: lstmForward.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 17:01:37
 */

/* Include Files */
#include "lstmForward.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const float X[32]
 *                const float W[2048]
 *                const float R[1024]
 *                const float b[64]
 *                const float c0[16]
 *                const float b_y0[16]
 *                float CS[16]
 *                float YT[16]
 * Return Type  : void
 */
void b_lstmForwardUsingExplicitLoops(const float X[32], const float W[2048],
                                     const float R[1024], const float b[64],
                                     const float c0[16], const float b_y0[16],
                                     float CS[16], float YT[16])
{
  float G[64];
  float cellGateOp[16];
  float forgetGateOp[16];
  float ipGateOp[16];
  float outputGateOp[16];
  float f;
  float f1;
  float f2;
  float f3;
  float f4;
  int b_i;
  int i;
  int p;
  memset(&G[0], 0, 64U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i, p, f, f1, f2, f3, b_i, f4)

  for (i = 0; i < 16; i++) {
    f = G[i];
    f1 = G[i + 16];
    f2 = G[i + 32];
    f3 = G[i + 48];
    for (p = 0; p < 32; p++) {
      b_i = i + (p << 6);
      f4 = X[p];
      f += W[b_i] * f4;
      f1 += W[b_i + 16] * f4;
      f2 += W[b_i + 32] * f4;
      f3 += W[b_i + 48] * f4;
    }
    for (p = 0; p < 16; p++) {
      b_i = i + (p << 6);
      f4 = b_y0[p];
      f += R[b_i] * f4;
      f1 += R[b_i + 16] * f4;
      f2 += R[b_i + 32] * f4;
      f3 += R[b_i + 48] * f4;
    }
    G[i] = 1.0F / (expf(-(f + b[i])) + 1.0F);
    G[i + 16] = 1.0F / (expf(-(f1 + b[i + 16])) + 1.0F);
    G[i + 32] = tanhf(f2 + b[i + 32]);
    G[i + 48] = 1.0F / (expf(-(f3 + b[i + 48])) + 1.0F);
  }
  memcpy(&ipGateOp[0], &G[0], 16U * sizeof(float));
  memcpy(&forgetGateOp[0], &G[16], 16U * sizeof(float));
  memcpy(&cellGateOp[0], &G[32], 16U * sizeof(float));
  memcpy(&outputGateOp[0], &G[48], 16U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(f)

  for (i = 0; i < 16; i++) {
    f = cellGateOp[i] * ipGateOp[i] + forgetGateOp[i] * c0[i];
    CS[i] = f;
    YT[i] = tanhf(f) * outputGateOp[i];
  }
}

/*
 * Arguments    : float X
 *                const float W[128]
 *                const float R[4096]
 *                const float b[128]
 *                const float c0[32]
 *                const float b_y0[32]
 *                float CS[32]
 *                float YT[32]
 * Return Type  : void
 */
void lstmForwardUsingExplicitLoops(float X, const float W[128],
                                   const float R[4096], const float b[128],
                                   const float c0[32], const float b_y0[32],
                                   float CS[32], float YT[32])
{
  float G[128];
  float cellGateOp[32];
  float forgetGateOp[32];
  float ipGateOp[32];
  float outputGateOp[32];
  float f;
  float f1;
  float f2;
  float f3;
  float f4;
  int b_i;
  int i;
  int p;
  memset(&G[0], 0, 128U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    p, i, f, f1, f2, f3, b_i, f4)

  for (i = 0; i < 32; i++) {
    f = G[i] + W[i] * X;
    f1 = G[i + 32] + W[i + 32] * X;
    f2 = G[i + 64] + W[i + 64] * X;
    f3 = G[i + 96] + W[i + 96] * X;
    for (p = 0; p < 32; p++) {
      b_i = i + (p << 7);
      f4 = b_y0[p];
      f += R[b_i] * f4;
      f1 += R[b_i + 32] * f4;
      f2 += R[b_i + 64] * f4;
      f3 += R[b_i + 96] * f4;
    }
    G[i] = 1.0F / (expf(-(f + b[i])) + 1.0F);
    G[i + 32] = 1.0F / (expf(-(f1 + b[i + 32])) + 1.0F);
    G[i + 64] = tanhf(f2 + b[i + 64]);
    G[i + 96] = 1.0F / (expf(-(f3 + b[i + 96])) + 1.0F);
  }
  memcpy(&ipGateOp[0], &G[0], 32U * sizeof(float));
  memcpy(&forgetGateOp[0], &G[32], 32U * sizeof(float));
  memcpy(&cellGateOp[0], &G[64], 32U * sizeof(float));
  memcpy(&outputGateOp[0], &G[96], 32U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(f)

  for (i = 0; i < 32; i++) {
    f = cellGateOp[i] * ipGateOp[i] + forgetGateOp[i] * c0[i];
    CS[i] = f;
    YT[i] = tanhf(f) * outputGateOp[i];
  }
}

/*
 * File trailer for lstmForward.c
 *
 * [EOF]
 */
