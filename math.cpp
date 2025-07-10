#include "math.hpp"

ktl::math::vec4f
ktl::math::lenght4(const vec4f * rhs, size_t newt)
{
  vec4f v1 = *(rhs + 0);
  vec4f v2 = *(rhs + 1);
  vec4f v3 = *(rhs + 2);
  vec4f v4 = *(rhs + 3);

  ktl_float4_t vm[4] = {
    ktl_mul(v1, v1),
    ktl_mul(v2, v2),
    ktl_mul(v3, v3),
    ktl_mul(v4, v4)
  };

  ktl_float4_t va = {
    ktl_vadd(vm[0]),
    ktl_vadd(vm[1]),
    ktl_vadd(vm[2]),
    ktl_vadd(vm[3])
  };

  ktl_float4_t inv_sqrt = ktl_invsq(va);
  for (size_t i = 0; i < newt; ++i)
  {
    inv_sqrt = ktl_mul(inv_sqrt, ktl_newt(va, ktl_mul(inv_sqrt, inv_sqrt)));
  }

  return ktl_mul(va, inv_sqrt);
}

void
ktl::math::add_first_write(vec4f & lhs, const vec4f & rhs)
{
  lhs = ktl_add(lhs, rhs);
}

ktl::math::vec4f
ktl::math::add_returnable(const vec4f & lhs, const vec4f & rhs)
{
  return ktl_add(lhs, rhs);
}

void
ktl::math::mul_scalar(vec4f & rhs, float k)
{
  /* rhs.simd = ; */
}
