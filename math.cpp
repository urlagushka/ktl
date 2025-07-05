#include "math.hpp"

ktl::vec4f::vec4f():
  data{0.0f, 0.0f, 0.0f, 0.0f}
{}

ktl::vec4f::vec4f(float m_x, float m_y, float m_z, float m_w):
  data{m_x, m_y, m_z, m_w}
{}
