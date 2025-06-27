# ktl
kochou template library

### ARRAY
1. No exceptions
2. No STL
3. No RTTI
4. Full memory control (mmap)
5. Allocate once

```cpp
ktl::features sysft = {...};
ktl::array< ktl::vec3, 4096 > colors;
```
#### DATA ACCESS (DATA SIZE)
#### SIMD ACCESS (SIMD SIZE)
#### CHUNK ACCESS (CACHELINE SIZE)
#### PAGE ACCESS (PAGE SIZE)
