#include "math.hpp"

ktl::math::vec4f::vec4f():
  data{0.0f, 0.0f, 0.0f, 0.0f}
{}

ktl::math::vec4f::vec4f(float x, float y, float z, float w):
  data{x, y, z, w}
{}

ktl::math::vec4f::vec4f(ktl_float4_t rhs):
  simd(rhs)
{}

ktl::math::vec4f
ktl::math::lenght4(const vec4f * rhs, size_t newt)
{
  const vec4f * v1 = rhs;
  const vec4f * v2 = rhs + 1;
  const vec4f * v3 = rhs + 2;
  const vec4f * v4 = rhs + 3;

  ktl_float4_t vm[4] = {
    ktl_mul(v1->simd, v1->simd),
    ktl_mul(v2->simd, v2->simd),
    ktl_mul(v3->simd, v3->simd),
    ktl_mul(v4->simd, v4->simd)
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
  lhs.simd = ktl_add(lhs.simd, rhs.simd);
}
