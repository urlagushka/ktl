#ifndef KTL_ARRAY_HPP
#define KTL_ARRAY_HPP

#include <cstdint>

#include "features.hpp"

namespace ktl
{
  enum class error
  {
    NON_VALID = -1,
    BAD_ALLOC = -2
  };

  template< typename T >
  concept aligned_struct = (alignof(T) != 0) && ((alignof(T) & (alignof(T) - 1)) == 0);

  template< aligned_struct DATA, unsigned int SIZE >
  class array
  {
    public:
      array() = delete;
      array(features m_features);
      array(const array< DATA, SIZE > &) = delete;
      array(array< DATA, SIZE > && rhs);
      array< DATA, SIZE > & operator=(const array< DATA, SIZE > &) = delete;
      array< DATA, SIZE > & operator=(array< DATA, SIZE > && rhs);
      ~array();

      int allocate(DATA && rhs);
      void free(int i);

      // common access (T size)
      // T * operator[](size_t i) -> READ/WRITE
      // const T * operator[](size_t i) const -> READ ONLY

      // chunk access (cacheline size)
      // void * chunk(size_t i | void * rhs | ???) -> READ/WRITE

      // simd access (packet size)
      // void * simd(size_t i | void * rhs | ???) -> READ/WRITE

      // page access (page size)
      // void * page(size_t i | void * rhs | ???) -> READ ONLY (threads)

      size_t size() const;

    private:
      size_t __size_bytes;
      size_t __size_elems;

      size_t __data_align;
      size_t __simd_align;
      size_t __page_align;

      size_t __cache_line;
      size_t __simd__size;
      size_t __page__size;
      size_t __chunk_size;

      void * __memory;
      DATA * __mapped;
  };
}

template< ktl::aligned_struct DATA, unsigned int SIZE >
ktl::array< DATA, SIZE >::array(features m_features):
  __size_bytes(0),
  __size_elems(0),

  __data_align(0),
  __simd_align(0),
  __page_align(0),

  __cache_line(0),
  __simd__size(0),
  __page__size(0),
  __chunk_size(0),

  __memory(nullptr),
  __mapped(nullptr)
{
  __size_bytes = (SIZE % page_size == 0) ? SIZE : (SIZE / page_size + 1) * page_size;
  __size_elems = __size_bytes / sizeof(DATA);

  __data_align = alignof(DATA);
  __simd_align = m_features.alignment;
  __page_align = page_size;

  __cache_line = m_features.cacheline;
  __simd__size = m_features.packet;
  __page__size = page_size;
  __chunk_size = (__cache_line % sizeof(DATA) == 0) ? __cache_line : sizeof(DATA);
}

template< ktl::aligned_struct DATA, unsigned int SIZE >
int
ktl::array< DATA, SIZE >::allocate(DATA && rhs)
{
  if (__memory == nullptr)
  {
    #if defined(__APPLE__) || defined(__linux__)
    __memory = mmap(
      nullptr,
      PROT_READ | PROT_WRITE,
      MAP_SHARED | MAP_ANONYMOUS,
      0, 0
    );

    if (__memory == MAP_FAILED)
    {
      return error::BAD_ALLOC;
    }
    #endif

    __mapped = reinterpret_cast< DATA * >(__memory);
  }

  for (size_t i = 0; i < __size_elems; ++i)
  {
    if (__mapped[i] == nullptr)
    {
      __mapped[i] = std::move(rhs);
      return i;
    }
  }

  return error::NON_VALID;
}

#endif
