#include <iostream>

#include "math.hpp"
#include "array.hpp"
#include "features.hpp"

int main()
{
  const ktl::features sysft = ktl::get_system_features();
  ktl::array< ktl::vec3, 1000 > colors(sysft);
}
