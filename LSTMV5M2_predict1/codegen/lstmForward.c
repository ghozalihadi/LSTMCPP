/*
 * File: lstmForward.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 09-Aug-2021 18:03:05
 */

/* Include Files */
#include "lstmForward.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const float X[672]
 *                const float W[2048]
 *                const float R[1024]
 *                const float b[64]
 *                const float c0[16]
 *                const float b_y0[16]
 *                float CS[336]
 *                float YT[336]
 * Return Type  : void
 */
void b_lstmForwardUsingExplicitLoops(const float X[672], const float W[2048],
                                     const float R[1024], const float b[64],
                                     const float c0[16], const float b_y0[16],
                                     float CS[336], float YT[336])
{
  float G[1344];
  float cellGateOp[16];
  float forgetGateOp[16];
  float ipGateOp[16];
  float outputGateOp[16];
  float f;
  float f1;
  float f2;
  float f3;
  float f4;
  int CS_tmp;
  int b_i;
  int b_tt;
  int c_tt;
  int i;
  int i1;
  int tt;
  memset(&G[0], 0, 1344U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i, CS_tmp, c_tt, f, b_i, f1, f2, f3, f4, i1)

  for (i = 0; i < 16; i++) {
    for (c_tt = 0; c_tt < 21; c_tt++) {
      b_i = i + (c_tt << 6);
      f = G[b_i];
      f1 = G[b_i + 16];
      f2 = G[b_i + 32];
      f3 = G[b_i + 48];
      for (CS_tmp = 0; CS_tmp < 32; CS_tmp++) {
        f4 = X[CS_tmp + (c_tt << 5)];
        i1 = i + (CS_tmp << 6);
        f += W[i1] * f4;
        f1 += W[i1 + 16] * f4;
        f2 += W[i1 + 32] * f4;
        f3 += W[i1 + 48] * f4;
      }
      G[b_i + 48] = f3;
      G[b_i + 32] = f2;
      G[b_i + 16] = f1;
      G[b_i] = f;
    }
    f = G[i];
    f1 = G[i + 16];
    f2 = G[i + 32];
    f3 = G[i + 48];
    for (CS_tmp = 0; CS_tmp < 16; CS_tmp++) {
      b_i = i + (CS_tmp << 6);
      f4 = b_y0[CS_tmp];
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
  for (tt = 0; tt < 20; tt++) {
    b_tt = tt + 2;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i, CS_tmp, b_i, f, f1, f2, f3, f4, i1)

    for (i = 0; i < 16; i++) {
      b_i = i + ((b_tt - 1) << 6);
      f = G[b_i];
      f1 = G[b_i + 16];
      f2 = G[b_i + 32];
      f3 = G[b_i + 48];
      for (CS_tmp = 0; CS_tmp < 16; CS_tmp++) {
        f4 = YT[CS_tmp + ((b_tt - 2) << 4)];
        i1 = i + (CS_tmp << 6);
        f += R[i1] * f4;
        f1 += R[i1 + 16] * f4;
        f2 += R[i1 + 32] * f4;
        f3 += R[i1 + 48] * f4;
      }
      G[b_i] = 1.0F / (expf(-(f + b[i])) + 1.0F);
      G[b_i + 16] = 1.0F / (expf(-(f1 + b[i + 16])) + 1.0F);
      G[b_i + 32] = tanhf(f2 + b[i + 32]);
      G[b_i + 48] = 1.0F / (expf(-(f3 + b[i + 48])) + 1.0F);
    }
    memcpy(&ipGateOp[0], &G[b_tt * 64 + -64], 16U * sizeof(float));
    memcpy(&forgetGateOp[0], &G[b_tt * 64 + -48], 16U * sizeof(float));
    memcpy(&cellGateOp[0], &G[b_tt * 64 + -32], 16U * sizeof(float));
    memcpy(&outputGateOp[0], &G[b_tt * 64 + -16], 16U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(f, CS_tmp)

    for (i = 0; i < 16; i++) {
      f = cellGateOp[i] * ipGateOp[i] +
          forgetGateOp[i] * CS[i + ((b_tt - 2) << 4)];
      CS_tmp = i + ((b_tt - 1) << 4);
      CS[CS_tmp] = f;
      YT[CS_tmp] = tanhf(f) * outputGateOp[i];
    }
  }
}

/*
 * Arguments    : const float X[105]
 *                const float W[640]
 *                const float R[4096]
 *                const float b[128]
 *                const float c0[32]
 *                const float b_y0[32]
 *                float CS[672]
 *                float YT[672]
 * Return Type  : void
 */
void lstmForwardUsingExplicitLoops(const float X[105], const float W[640],
                                   const float R[4096], const float b[128],
                                   const float c0[32], const float b_y0[32],
                                   float CS[672], float YT[672])
{
  float G[2688];
  float cellGateOp[32];
  float forgetGateOp[32];
  float ipGateOp[32];
  float outputGateOp[32];
  float f;
  float f1;
  float f2;
  float f3;
  float f4;
  int CS_tmp;
  int b_i;
  int b_tt;
  int c_tt;
  int i;
  int i1;
  int tt;
  memset(&G[0], 0, 2688U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i, CS_tmp, c_tt, f, b_i, f1, f2, f3, f4, i1)

  for (i = 0; i < 32; i++) {
    for (c_tt = 0; c_tt < 21; c_tt++) {
      b_i = i + (c_tt << 7);
      f = G[b_i];
      f1 = G[b_i + 32];
      f2 = G[b_i + 64];
      f3 = G[b_i + 96];
      for (CS_tmp = 0; CS_tmp < 5; CS_tmp++) {
        f4 = X[CS_tmp + 5 * c_tt];
        i1 = i + (CS_tmp << 7);
        f += W[i1] * f4;
        f1 += W[i1 + 32] * f4;
        f2 += W[i1 + 64] * f4;
        f3 += W[i1 + 96] * f4;
      }
      G[b_i + 96] = f3;
      G[b_i + 64] = f2;
      G[b_i + 32] = f1;
      G[b_i] = f;
    }
    f = G[i];
    f1 = G[i + 32];
    f2 = G[i + 64];
    f3 = G[i + 96];
    for (CS_tmp = 0; CS_tmp < 32; CS_tmp++) {
      b_i = i + (CS_tmp << 7);
      f4 = b_y0[CS_tmp];
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
  for (tt = 0; tt < 20; tt++) {
    b_tt = tt + 2;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i, CS_tmp, b_i, f, f1, f2, f3, f4, i1)

    for (i = 0; i < 32; i++) {
      b_i = i + ((b_tt - 1) << 7);
      f = G[b_i];
      f1 = G[b_i + 32];
      f2 = G[b_i + 64];
      f3 = G[b_i + 96];
      for (CS_tmp = 0; CS_tmp < 32; CS_tmp++) {
        f4 = YT[CS_tmp + ((b_tt - 2) << 5)];
        i1 = i + (CS_tmp << 7);
        f += R[i1] * f4;
        f1 += R[i1 + 32] * f4;
        f2 += R[i1 + 64] * f4;
        f3 += R[i1 + 96] * f4;
      }
      G[b_i] = 1.0F / (expf(-(f + b[i])) + 1.0F);
      G[b_i + 32] = 1.0F / (expf(-(f1 + b[i + 32])) + 1.0F);
      G[b_i + 64] = tanhf(f2 + b[i + 64]);
      G[b_i + 96] = 1.0F / (expf(-(f3 + b[i + 96])) + 1.0F);
    }
    memcpy(&ipGateOp[0], &G[b_tt * 128 + -128], 32U * sizeof(float));
    memcpy(&forgetGateOp[0], &G[b_tt * 128 + -96], 32U * sizeof(float));
    memcpy(&cellGateOp[0], &G[b_tt * 128 + -64], 32U * sizeof(float));
    memcpy(&outputGateOp[0], &G[b_tt * 128 + -32], 32U * sizeof(float));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(f, CS_tmp)

    for (i = 0; i < 32; i++) {
      f = cellGateOp[i] * ipGateOp[i] +
          forgetGateOp[i] * CS[i + ((b_tt - 2) << 5)];
      CS_tmp = i + ((b_tt - 1) << 5);
      CS[CS_tmp] = f;
      YT[CS_tmp] = tanhf(f) * outputGateOp[i];
    }
  }
}

/*
 * File trailer for lstmForward.c
 *
 * [EOF]
 */
