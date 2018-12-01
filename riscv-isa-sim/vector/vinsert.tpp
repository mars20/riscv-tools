#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"


//Insert an element in to vector register

template <class T>
T v_insert(T output, unsigned int input, int idx, int ew, int m, T mask, int vl)
{
  int maxvl;
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
         maxvl = MAXVL >> OFFSETMAXEW8;
         if(idx < maxvl)
            output.e8[idx] = (uint8_t)input;	
	 maskVector(output.e8, mask.e8, m, maxvl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit
         maxvl = MAXVL >> OFFSETMAXEW16;
         if(idx < maxvl)
          output.e16[idx] = (uint16_t)input;	
	 maskVector(output.e16, mask.e16, m, maxvl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit
         maxvl = MAXVL >> OFFSETMAXEW32;
         if(idx < maxvl)
           output.e32[idx] = (uint32_t)input;	
	 maskVector(output.e32, mask.e32, m, maxvl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit addition
         maxvl = MAXVL >> OFFSETMAXEW64;
         if(idx < maxvl)
           output.e64[idx] = (uint64_t)input;	
	 maskVector(output.e64, mask.e64, m, maxvl, maxvl);
      break;
  }
  return output;
}
