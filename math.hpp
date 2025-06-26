#ifndef KTL_MATH_HPP
#define KTL_MATH_HPP

namespace ktl
{
  struct alignas(8) vec2
  {
    float x, y;
  };

  struct alignas(16) vec3
  {
    float x, y, x;
    float _padding;
  };

  struct alignas(16) vec4
  {
    float x, y, z, t;
  };
}

#endif
