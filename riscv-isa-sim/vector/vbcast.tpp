#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"

template <class T>
T v_bcast(T in, int idx, int ew, int m, T mask, int vl)  
{
  static T out;
  int maxvl;

  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
         out.e8[0] = in.e8[idx];
	 maxvl = MAXVL >> OFFSETMAXEW8;
	 maskVector(out.e8, mask.e8, m, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit
         out.e16[0] = in.e16[idx];
	 maxvl = MAXVL >> OFFSETMAXEW16;
	 maskVector(out.e16, mask.e16, m, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit
         out.e32[0] = in.e32[idx];
	 maxvl = MAXVL >> OFFSETMAXEW32;
	 maskVector(out.e32, mask.e32, m, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit addition
         out.e64[0] = in.e64[idx];
	 maxvl = MAXVL >> OFFSETMAXEW64;
	 maskVector(out.e64, mask.e64, m, vl, maxvl);
      break;
  }
  return out;
}


template <class T>
T v_bcast(T value, int ew, int vl)  
{
  int maxvl;
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
         maxvl = MAXVL >> OFFSETMAXEW8;
	 maskVector(value.e8, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit
         maxvl = MAXVL >> OFFSETMAXEW16;
	 maskVector(value.e16, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit
         maxvl = MAXVL >> OFFSETMAXEW32;
	 maskVector(value.e32, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit addition
         maxvl = MAXVL >> OFFSETMAXEW64;
	 maskVector(value.e64, vl, maxvl);
      break;
  }
  return value;
}


// template <class T>
// void v_bcast(T value, float32_t in, int ew, int vl)  
// {
//   switch(ew) // switch based on element width
//   {
//     case 8: // 8 bit
//          value.e8[0] = 0;
// 	 maskVector(value.e8, vl);	
//       break;
//     case 16: // 16 bit
//          value.e16[0] = 0;
// 	 maskVector(value.e16, vl);
//       break;
//     case 32: // 32 bit
//          value.e32[0] = rf32(in);
// 	 maskVector(value.e32, vl);
//       break;
//     case 64: // 64 bit addition
//          value.e64[0] = 0;	
// 	 maskVector(value.e64, vl);
//       break;
//   }
// }
