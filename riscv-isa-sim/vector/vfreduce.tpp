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
T v_freduce(T in, int type, int ew, int vl)
{
  static T out;
  int maxvl;
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
    	  out.e8[0]=0;
	  maxvl = MAXVL >> OFFSETMAXEW8;
	  maskVector(out.e8, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit
          out.e16[0]=0;   
          for (int i =0; i<vl; i++)
	  {
	    out.e16[0] = rf16(f16_add(fr16(in.e16[i]), fr16(out.e16[0]))); 
	  }
	  maxvl = MAXVL >> OFFSETMAXEW16;
	  maskVector(out.e16, vl, maxvl);

      break;
    case MaxElementWidth32: // 32 bit
    	  out.e32[0]=0;   
          for (int i =0; i<vl; i++)
	  {
	    out.e32[0] = rf32(f32_add(fr32(in.e32[i]), fr32(out.e32[0]))); 
	  }
	  maxvl = MAXVL >> OFFSETMAXEW32;
	  maskVector(out.e32, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit
    	 out.e64[0]=0;   
          for (int i =0; i<vl; i++)
	  {
	    out.e64[0] = rf64(f64_add(fr64(in.e64[i]), fr64(out.e64[0]))); 
	  }
	  maxvl = MAXVL >> OFFSETMAXEW64;
	  maskVector(out.e64, vl, maxvl);
      break;
  }
  return out;
}

