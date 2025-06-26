#include "features.hpp"

#if defined(__APPLE__)
#include <sys/sysctl.h>
#include <cstring>

ktl::features
ktl::get_system_features()
{
  bool is_valid = true;
  char buf[64];
  size_t size = sizeof(buf);

  auto get_system_feature_bool = [&](const char * ft) -> bool
  {
    if (sysctlbyname(ft, &buf, &size, NULL, 0) == 0)
    {
      return buf != 0;
    }
    is_valid = false;
    return 0;
  };
  auto get_system_feature_int = [&](const char * ft) -> int
  {
    int buf = 0;
    size_t size = sizeof(buf);
    if (sysctlbyname(ft, &buf, &size, NULL, 0) == 0)
    {
      return buf;
    }
    is_valid = false;
    return -1;
  };

  return features{
    .is_valid = is_valid,
    .is_neon = get_system_feature_bool("hw.optional.neon"),
    .is_advneon = get_system_feature_bool("hw.optional.AdvSIMD"),
    .cacheline = get_system_feature_int("hw.cachelinesize")
  };
}
#endif

#if defined(__linux__)
ktl::system_ft
ktl::get_system_features()
{} // todo
#endif

#if defined(__WIN32)
ktl::system_ft
ktl::get_system_features()
{} // todo
#endif
