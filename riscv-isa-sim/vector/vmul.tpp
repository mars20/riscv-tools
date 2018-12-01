#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"


//Multiplication

template <class T>
T v_mul(T a, T b, int ew, int m, T mask, int vl)  //assuming both a and b are of same type and length
{
  static T c;
  int maxvl;
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit multiplcation
    	 for(int i = 0; i < vl; i++)
    	 {
		c.e8[i] = a.e8[i] * b.e8[i];	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW8;
	 maskVector(c.e8, mask.e8, m, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit multiplcation
     	 for(int i = 0; i < vl; i++)
    	 {
		c.e16[i] = a.e16[i] * b.e16[i];	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW16;
	 maskVector(c.e16, mask.e16, m, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit multiplcation
        for(int i = 0; i < vl; i++)
   	 {
		c.e32[i] = a.e32[i] * b.e32[i];	
   	 }
	 maxvl = MAXVL >> OFFSETMAXEW32;
	 maskVector(c.e32, mask.e32, m, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit multiplcation
    	for(int i = 0; i < vl; i++)
    	{
		c.e64[i] = a.e64[i] * b.e64[i];	
    	}
	maxvl = MAXVL >> OFFSETMAXEW64;
	maskVector(c.e64, mask.e64, m, vl, maxvl);
      break;
  }
  return c;
}