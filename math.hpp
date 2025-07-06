#ifndef KTL_MATH_HPP
#define KTL_MATH_HPP

#include <cstddef>
#include "system.hpp"

namespace ktl::math
{
  struct alignas(8) vec2f
  {
    union
    {
      float data[2];
      ktl_float2_t simd;
    };
  };

  struct alignas(16) vec4f
  {
    vec4f();
    vec4f(float x, float y, float z, float w);
    vec4f(ktl_float4_t rhs);

    union
    {
      float data[4];
      ktl_float4_t simd;
    };
  };

  vec4f lenght4(const vec4f * rhs, size_t newt = 1);
}

#endif
