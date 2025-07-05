#ifndef KTL_MATH_HPP
#define KTL_MATH_HPP

#include <cstddef>
#include "system.hpp"

namespace ktl
{
  struct alignas(8) vec2f
  {
    union
    {
      float x, y;
      float data[2];

      KTL_FLOAT2_T simd;
    };
  };

  struct alignas(16) vec3f
  {
    union
    {
      float x, y, z, _padding;
      float data[4];

      KTL_FLOAT4_T simd;
    };
  };

  struct alignas(16) vec4f
  {
    vec4f();
    vec4f(float m_x, float m_y, float m_z, float m_w);

    union
    {
      float x, y, z, w;
      float data[4];

      KTL_FLOAT4_T simd;
    };
  };

  void vsum(const vec4f & lhs, const vec4f & rhs, vec4f & res);
  void vmul(const vec4f & lhs, const vec4f & rhs, vec4f & res);

  void ssum(const vec4f & lhs, float rhs, vec4f & res);
  void smul(const vec4f & lhs, float rhs, vec4f & res);  
}

#endif
