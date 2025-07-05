#ifndef KTL_MATH_HPP
#define KTL_MATH_HPP

#if defined(__APPLE__)
#include <arm_neon.h>
#endif

#if defined(__linux__) || defined(__WIN32)
#include <immintrin.h>
#endif

/*

requires NEON/AVX??

*/

namespace ktl
{
  struct alignas(8) vec2
  {
    float x, y;
  };

  struct alignas(16) vec3
  {
    float x, y, z;
    float _padding;
  };

  struct alignas(16) vec4f
  {
    union
    {
      float x, y, z, w;
      float data[4];

      #if defined(__AVX__)
      __m128 avx;

      #elif defined(__ARM_NEON)
      float32x4_t neon;

      #else
      #error "update your pc (please)"
      #endif
    };
  };
}

#endif
