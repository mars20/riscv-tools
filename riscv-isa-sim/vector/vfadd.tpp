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

//Addition
template <class T>
T v_fadd(T a, T b, int ew, int m, T mask, int vl)  //assuming both a and b are of same type and length
{
  static T c;
  int maxvl;
  
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit addition
      c.e8[0] = 0;
      maxvl = MAXVL >> OFFSETMAXEW8;
      maskVector(c.e8, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit addition
     	 for(int i = 0; i < vl; i++)
    	 {
		c.e16[i] = rf16(f16_add(fr16(a.e16[i]), fr16(b.e16[i]))); 	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW16;
	 maskVector(c.e16, mask.e16, m, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit addition
        for(int i = 0; i < vl; i++)
   	 {
		c.e32[i] = rf32(f32_add(fr32(a.e32[i]), fr32(b.e32[i]))); 	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW32;
	 maskVector(c.e32, mask.e32, m, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit addition
    	for(int i = 0; i < vl; i++)
    	{
		c.e64[i] = rf64(f64_add(fr64(a.e64[i]), fr64(b.e64[i])));
    	}
	maxvl = MAXVL >> OFFSETMAXEW64;
	maskVector(c.e64, mask.e64, m, vl, maxvl);
      break;
  }
  return c;
}