#ifndef KTL_MATH_HPP
#define KTL_MATH_HPP

#include <cstddef>
#include "system.hpp"

namespace ktl::math
{
  using vec2f  = ktl_float2_t;
  using vec2f2 = ktl_float4_t;
  using vec4f  = ktl_float4_t;

  vec4f lenght4(const vec4f * rhs, size_t newt = 1);

  void add_first_write(vec4f & lhs, const vec4f & rhs);
  vec4f add_returnable(const vec4f & lhs, const vec4f & rhs);
  void mul_scalar(vec4f & rhs, float k);
}

#endif
