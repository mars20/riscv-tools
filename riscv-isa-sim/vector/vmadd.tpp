#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"

//multiplication-addition


template <class T>
T v_madd(T a, T b, T c, int ew, int m, T mask, int vl)  //assuming both a and b are of same type and length
{
  static T d;
  int maxvl;
  
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit multiplcation add
    	 for(int i = 0; i < vl; i++)
    	 {
		d.e8[i] = a.e8[i] * b.e8[i] + c.e8[i];	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW8;
	 maskVector(d.e8, mask.e8, m, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit multiplcation add
     	 for(int i = 0; i < vl; i++)
    	 {
		d.e16[i] = a.e16[i] * b.e16[i] + c.e16[i];	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW16;
	 maskVector(d.e16, mask.e16, m, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit multiplcation add
        for(int i = 0; i < vl; i++)
   	 {
		d.e32[i] = a.e32[i] * b.e32[i] + c.e32[i];	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW32;
	 maskVector(d.e32, mask.e32, m, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit multiplcation add
    	for(int i = 0; i < vl; i++)
    	{
		d.e64[i] = a.e64[i] * b.e64[i] + c.e64[i];	
    	}
	maxvl = MAXVL >> OFFSETMAXEW64;
	maskVector(d.e64, mask.e64, m, vl, maxvl);
      break;
  }
  return d;
}
