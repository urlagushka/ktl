#ifndef KTL_SYSTEM_HPP
#define KTL_SYSTEM_HPP

#if defined(__AVX__)
  #include <immintrin.h>

  using ktl_float4_t = __mm128;
  using ktl_float2_t = __mm64;

  inline void ktl_add(const ktl_float4_t & lhs, const ktl_float4_t & rhs, ktl_float4_t & res) { res = _mm_add_ps(lhs, rhs); }
  inline void ktl_add(const ktl_float2_t & lhs, const ktl_float2_t & rhs, ktl_float2_t & res) { res = _mm_add_ps(lhs, rhs); }

  inline void ktl_mul(const ktl_float4_t & lhs, const ktl_float4_t & rhs, ktl_float4_t & res) { res = _mm_mul_ps(lhs, rhs); }
  inline void ktl_mul(const ktl_float2_t & lhs, const ktl_float2_t & rhs, ktl_float2_t & res) { res = _mm_mul_ps(lhs, rhs); }

#elif defined(__ARM_NEON)
  #include <arm_neon.h>

  using ktl_float4_t = float32x4_t;
  using ktl_float2_t = float32x2_t;
  using ktl_float_t = float32_t;

  inline ktl_float4_t ktl_add(const ktl_float4_t & lhs, const ktl_float4_t & rhs) { return vaddq_f32(lhs, rhs); }
  inline ktl_float2_t ktl_add(const ktl_float2_t & lhs, const ktl_float2_t & rhs) { return vadd_f32 (lhs, rhs); }

  inline ktl_float4_t ktl_mul(const ktl_float4_t & lhs, const ktl_float4_t & rhs) { return vmulq_f32(lhs, rhs); }
  inline ktl_float2_t ktl_mul(const ktl_float2_t & lhs, const ktl_float2_t & rhs) { return vmul_f32 (lhs, rhs); }

  inline ktl_float_t ktl_vadd(const ktl_float4_t & rhs) { return vaddvq_f32(rhs); }
  inline ktl_float4_t ktl_invsq(const ktl_float4_t & rhs) { return vrsqrteq_f32(rhs); }
  inline ktl_float4_t ktl_newt(const ktl_float4_t & lhs, const ktl_float4_t & rhs) { return vrsqrtsq_f32(lhs, rhs); }

#else
  #error "update your pc (please)"
#endif

#endif
