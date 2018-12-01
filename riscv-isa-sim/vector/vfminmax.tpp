#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"
#include "softfloat_types.h"
#include "platform.h"
#include "internals.h"
#include "specialize.h"
#include "softfloat.h"


template <class T>
T v_fmin(T in, T min, int ew, int vl)
{
  static T out;

  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
      out.e8[0]=0;
      maskVector(out.e8, vl, MAXVL >> OFFSETMAXEW8);
      break;
    case MaxElementWidth16: // 16 bit
      for (int i = 0; i < vl; i++)
        out.e16[i] = rf16(fpmin(fr16(in.e16[i]), fr16(min.e16[i])));
      break;
    case MaxElementWidth32: // 32 bit
      for (int i = 0; i < vl; i++)
         out.e32[i] = rf32(fpmin(fr32(in.e32[i]), fr32(min.e32[i])));
      break;
    case MaxElementWidth64: // 64 bit
      for (int i = 0; i < vl; i++)
         out.e64[i] = rf64(fpmin(fr64(in.e64[i]), fr64(min.e64[i])));
      break;
  }
  return out;
}


template <class T>
T v_fmax(T in, T max, int ew, int vl)
{
  static T out;

  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
      out.e8[0]=0;
      maskVector(out.e8, vl, MAXVL >> OFFSETMAXEW8);
      break;
    case MaxElementWidth16: // 16 bit
      for (int i = 0; i < vl; i++)
        out.e16[i] = rf16(fpmax(fr16(in.e16[i]), fr16(max.e16[i])));
      break;
    case MaxElementWidth32: // 32 bit
      for (int i = 0; i < vl; i++)
         out.e32[i] = rf32(fpmax(fr32(in.e32[i]), fr32(max.e32[i])));
      break;
    case MaxElementWidth64: // 64 bit
      for (int i = 0; i < vl; i++)
         out.e64[i] = rf64(fpmax(fr64(in.e64[i]), fr64(max.e64[i])));
      break;
  }
  return out;
}
