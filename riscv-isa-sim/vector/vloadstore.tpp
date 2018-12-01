#include <cstdint>
#include <string.h>
#include <strings.h>
#include <cinttypes>
#include "vector_types.h"


//load

template <class T>
T v_load(T value, int ew, int m, T mask, int vl)  //assuming both a and b are of same type and length
{
  int maxvl;
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
          maxvl = MAXVL >> OFFSETMAXEW8;
	  maskVector(value.e8, mask.e8, m, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit
         maxvl = MAXVL >> OFFSETMAXEW16;
	 maskVector(value.e16, mask.e16, m, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit
         maxvl = MAXVL >> OFFSETMAXEW32;
	 maskVector(value.e32, mask.e32, m, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit
        maxvl = MAXVL >> OFFSETMAXEW64;
	maskVector(value.e64, mask.e64, m, vl, maxvl);
      break;
  }
  return value;
}

//store

template <class T>
T v_store(T value, int ew, int m, T mask, int vl)  //assuming both a and b are of same type and length
{
  int maxvl;
  switch(ew) // switch based on element width
  {
    case MaxElementWidth8: // 8 bit
          maxvl = MAXVL >> OFFSETMAXEW8;
	  maskVector(value.e8, mask.e8, m, vl, maxvl);	
      break;
    case MaxElementWidth16: // 16 bit
         maxvl = MAXVL >> OFFSETMAXEW16;
	 maskVector(value.e16, mask.e16, m, vl, maxvl);
      break;
    case MaxElementWidth32: // 32 bit
         maxvl = MAXVL >> OFFSETMAXEW32;
	 maskVector(value.e32, mask.e32, m, vl, maxvl);
      break;
    case MaxElementWidth64: // 64 bit
        maxvl = MAXVL >> OFFSETMAXEW64;
	maskVector(value.e64, mask.e64, m, vl, maxvl);
      break;
  }
  return value;
}
