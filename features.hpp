#ifndef KTL_FEATURES_HPP
#define KTL_FEATURES_HPP

#include <unistd.h>

#include <cstddef>

namespace ktl
{
  static const long page_size = sysconf(_SC_PAGESIZE);

  enum class simd_t
  {
    /* X86 */ SSE,
              SSE2,
              SSE3,
              SSSE3,
              SSE4_1,
              SSE4_2,
              AVX,
              AVX2,
              AVX512,

    /* ARM */ NEON,
              SVE,

    UNKNOWN
  };

  struct features
  {
    simd_t method;
    size_t alignment;
    size_t packet;
    size_t cacheline;
  };

  features get_system_features();
}

#if defined(__APPLE__)
namespace ktl
{
}
#endif

#if defined(__linux__)
namespace ktl
{
  struct system_ft
  {}; // todo
}
#endif

#if defined(__WIN32)
namespace ktl
{
  struct system_ft
  {}; // todo
}
#endif

#endif
