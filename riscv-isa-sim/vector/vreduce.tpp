#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"
#include <algorithm>


template <class T>
void reduce(T input[], T  output[], int type, int vl)
{
   switch(type)
   {
     case 0:
         output[0] = 0;
         for(int i = 0; i < vl; i++)
	 	 output[0] += input[i];
     break;
     case 1:
         output[0] = *std::max_element(input, input+vl);
     break;
     case 2:
         output[0] = *std::min_element(input, input+vl);
     break;
     default:
	output[0] = 0;
	break;
   }
}

template <class T>
T v_reduce(T in, int type, int ew, int vl)
{
  static T out;
  int maxvl;
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
    	  reduce(in.e8, out.e8, type, vl);
	  maxvl = MAXVL >> OFFSETMAXEW8;
	  maskVector(out.e8, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit
          reduce(in.e16, out.e16, type, vl);
	  maxvl = MAXVL >> OFFSETMAXEW16;
	  maskVector(out.e16, vl, maxvl);

      break;
    case MaxElementWidth32: // 32 bit
          reduce(in.e32, out.e32, type, vl);
	  maxvl = MAXVL >> OFFSETMAXEW32;
	  maskVector(out.e32, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit
          reduce(in.e64, out.e64, type, vl);
	  maxvl = MAXVL >> OFFSETMAXEW64;
	  maskVector(out.e64, vl, maxvl);
      break;
  }
  return out;
}

