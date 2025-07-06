#include <iostream>
#include <format>

#include "math.hpp"
#include "array.hpp"
#include "features.hpp"

int main()
{
  ktl::math::vec4f v1(2.9f, 2.3f, 0.3f, 3.3f);
  ktl::math::vec4f v2(3.9f, 2.3f, 0.3f, 3.3f);
  ktl::math::vec4f v3(4.9f, 2.3f, 0.3f, 3.3f);
  ktl::math::vec4f v4(5.9f, 2.3f, 0.3f, 3.3f);
  
  ktl::math::vec4f va[4] = {v1, v2, v3, v4};
  ktl::math::vec4f la = ktl::math::lenght4(va);

  std::cout << std::format("{}, {}, {}, {}\n", la.data[0], la.data[1], la.data[2], la.data[3]);
  // const ktl::features sysft = ktl::get_system_features();
  // ktl::array< ktl::vec3, 1000 > colors(sysft);
}
