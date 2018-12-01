#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"

template <class T>
void merge(T* input1, T* input2, T* output, T* mask, int masktype, int vl, int maxvl)
{
   int i;
   switch(masktype)
  {
    case 0: // destination reg is scalar
      output[0] = input1[0];
      maskVector(output, vl, maxvl);
      break;
    case 1: //destination reg is vector
      output[0] = 0;
      maskVector(output, vl, maxvl);
      break;
    case 2: //masked vector (mask.LSB = 0)
      for(i=0; i< vl; i++)
      {
       output[i] = (mask[i] & 1) ? input1[i]: input2[i];
      }
      for(i=vl; i< maxvl; i++)
      {
        output[i] = 0;
      }
      break;
    case 3: //masked vector (mask.LSB = 1 )
      for(i=0; i< vl; i++)
      {
        output[i] = (mask[i] & 1) ? input2[i] : input1[i];
      }
      for(i=vl; i< maxvl; i++)
      {
        output[i] = 0;
      }
      break;
  }
}


template <class T>
T v_merge(T input1, T input2, int ew, int vl, T mask, int masktype)
{
  static T out;
  int maxvl;
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
          maxvl = MAXVL >> OFFSETMAXEW8;
    	  merge(input1.e8, input2.e8, out.e8, mask.e8, masktype, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit
          maxvl = MAXVL >> OFFSETMAXEW16;
    	  merge(input1.e16, input2.e16, out.e16, mask.e16, masktype, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit
          maxvl = MAXVL >> OFFSETMAXEW32;
    	  merge(input1.e32, input2.e32, out.e32, mask.e32, masktype, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit
          maxvl = MAXVL >> OFFSETMAXEW64;
    	  merge(input1.e64, input2.e64, out.e64, mask.e64, masktype, vl, maxvl);
      break;
  }
  return out;
}