#ifndef KTL_SYSTEM_HPP
#define KTL_SYSTEM_HPP

#if defined(__AVX__)
  #include <immintrin.h>

  using   KTL_FLOAT4X4_T = __mm128[4];
  using   KTL_FLOAT4X3_T = __mm128[3];
  using   KTL_FLOAT4X2_T = __mm128[2];

  using   KTL_FLOAT2X4_T = __mm64[3];
  using   KTL_FLOAT2X3_T = __mm64[3];
  using   KTL_FLOAT2X2_T = __mm64[2];

  using   KTL_FLOAT4_T = __mm128;
  using   KTL_FLOAT2_T = __mm64;

  #define KTL_MATRIX_ACCESS(m, i) (m[i]);

  #define KTL_ADD      = ;
  #define KTL_MUL      = ;
  #define KTL_READ     = ;
  #define KTL_WRITE    = ;

#elif defined(__ARM_NEON)
  #include <arm_neon.h>

  using   KTL_FLOAT4X4_T = float32x4x4_t;
  using   KTL_FLOAT4X3_T = float32x4x3_t;
  using   KTL_FLOAT4X2_T = float32x4x2_t;

  using   KTL_FLOAT2X4_T = float32x2x4_t;
  using   KTL_FLOAT2X3_T = float32x2x3_t;
  using   KTL_FLOAT2X2_T = float32x2x2_t;

  using   KTL_FLOAT4_T = float32x4_t;
  using   KTL_FLOAT2_T = float32x2_t;

  #define KTL_MATRIX_ACCESS(m, i) (m.val[i]);

  #define KTL_ADD      = ;
  #define KTL_MUL      = ;
  #define KTL_READ     = ;
  #define KTL_WRITE    = ;
#else
  #error "update your pc (please)"
#endif

#endif
