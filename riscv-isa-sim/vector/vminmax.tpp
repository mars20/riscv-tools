#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"

template <class T>
T v_min(T in, T min, int ew, int vl)
{
  static T out;

  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
      for (int i = 0; i < vl; i++)
        out.e8[i] = std::min(in.e8[i], min.e8[i]);
      break;
    case MaxElementWidth16: // 16 bit
      for (int i = 0; i < vl; i++)
        out.e16[i] = std::min(in.e16[i], min.e16[i]);
      break;
    case MaxElementWidth32: // 32 bit
      for (int i = 0; i < vl; i++)
        out.e32[i] = std::min(in.e32[i], min.e32[i]);
      break;
    case MaxElementWidth64: // 64 bit
      for (int i = 0; i < vl; i++)
        out.e64[i] = std::min(in.e64[i], min.e64[i]);
      break;
  }
  return out;
}


template <class T>
T v_max(T in, T max, int ew, int vl)
{
  static T out;

  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
      for (int i = 0; i < vl; i++)
        out.e8[i] = std::max(in.e8[i], max.e8[i]);
      break;
    case MaxElementWidth16: // 16 bit
      for (int i = 0; i < vl; i++)
        out.e16[i] = std::max(in.e16[i], max.e16[i]);
      break;
    case MaxElementWidth32: // 32 bit
      for (int i = 0; i < vl; i++)
        out.e32[i] = std::max(in.e32[i], max.e32[i]);
      break;
    case MaxElementWidth64: // 64 bit
      for (int i = 0; i < vl; i++)
        out.e64[i] = std::max(in.e64[i], max.e64[i]);
      break;
  }
  return out;
}
