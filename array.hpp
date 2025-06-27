#ifndef KTL_ARRAY_HPP
#define KTL_ARRAY_HPP

#include <cstdint>

#include "features.hpp"

/*
using mmap for allocate
*/

namespace ktl
{
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

      bool __flags[__size_elems];

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

  __flags({}),

  __memory(nullptr),
  __mapped(nullptr)
{
  // init
}

template< ktl::aligned_struct DATA, unsigned int SIZE >
int
ktl::array< DATA, SIZE >::allocate(DATA && rhs)
{
  if (__memory == nullptr)
  {
    // allocate full memory AND map memory
    if (/* failed to allocate */)
    {
      return -1;
    }
  }

  for (size_t i = 0; i < __size_elems; ++i)
  {
    if (!__flags[i])
    {
      // place DATA here
      return i;
    }
  }

  return -1;
}

#endif
