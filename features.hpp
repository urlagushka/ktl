#ifndef KTL_FEATURES_HPP
#define KTL_FEATURES_HPP

#include <cstddef>

namespace ktl
{
  enum class simd_t
  {
    /* X86 */ SSE, AVX, AVX512,
    /* ARM */ NEON,
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
