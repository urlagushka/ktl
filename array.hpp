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

  template< typename T >
  concept aligned_struct_info = ???;

  template< aligned_struct T, unsigned int SIZE >
  class array
  {
    public:
      array() = delete;
      array(features m_features);
      ...
      ~array();

      template< aligned_struct_info INFO >
      void * | size_t allocate(const INFO & info);

      void free(size_t i | void * rhs);

      // common access (T size)
      // T * operator[](size_t i) -> READ/WRITE
      // const T * operator[](size_t i) const -> READ ONLY

      // chunk access (cacheline size)
      // void * chunk(size_t i | void * rhs | ???) -> READ/WRITE

      // simd access (packet size)
      // void * simd(size_t i | void * rhs | ???) -> READ/WRITE

      // page access (page size)
      // void * page(size_t i | void * rhs | ???) -> READ ONLY (threads)

    private:
      constexpr size_t T_SIZE = sizeof(T);
      T const * root = nullptr;
  };
}

#endif
