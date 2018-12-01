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

//Multiplication

template <class T>
T v_fmadd(T a, T b, T c, int ew, int m, T mask, int vl)  //assuming both a and b are of same type and length
{
  static T d;
  int maxvl;

  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit multiplication
      d.e8[0] = 0;
      maxvl = MAXVL >> OFFSETMAXEW8;
      maskVector(d.e8, vl, maxvl);
      break;
    case MaxElementWidth16: // 16 bit multiplication
     	 for(int i = 0; i < vl; i++)
    	 {
		d.e16[i] = rf16(f16_mulAdd(fr16(a.e16[i]), fr16(b.e16[i]), fr16(c.e16[i]))); 	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW16;
	 maskVector(d.e16, mask.e16, m, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit multiplication
        for(int i = 0; i < vl; i++)
   	 {
		d.e32[i] = rf32(f32_mulAdd(fr32(a.e32[i]), fr32(b.e32[i]), fr32(c.e32[i]))); 	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW32;
	 maskVector(d.e32, mask.e32, m, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit multiplication
    	for(int i = 0; i < vl; i++)
    	{
		d.e64[i] = rf64(f64_mulAdd(fr64(a.e64[i]), fr64(b.e64[i]), fr64(c.e64[i]))); 	
    	}
	maxvl = MAXVL >> OFFSETMAXEW64;
	maskVector(d.e64, mask.e64, m, vl, maxvl);
      break;
  }
  return d;
}