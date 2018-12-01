#ifndef _VECTOR_EXTENSION_H
#define _VECTOR_EXTENSION_H

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

/*=============================================================================================================*/
// floating point helper functions

inline float16_t fr16(uint16_t v) { return { v }; }
inline float32_t fr32(uint32_t v) { return { v }; }
inline float64_t fr64(uint64_t v) { return { v }; }

inline uint16_t rf16(float16_t f) { return  f.v; }
inline uint32_t rf32(float32_t f) { return f.v; }
inline uint64_t rf64(float64_t f) { return f.v; }

#define SIGN_F16 ((uint16_t)1 << 15)
#define SIGN_F32 ((uint32_t)1 << 31)
#define SIGN_F64 ((uint64_t)1 << 63)

inline float16_t fpmax(float16_t in1, float16_t in2)
{
  bool greater = f16_lt_quiet(in2, in1) ||
                 (f16_eq(in2, in1) && (in2.v & SIGN_F16));
  if (isNaNF16UI(in1.v) && isNaNF16UI(in2.v))
    return (fr16(defaultNaNF16UI));
  else
    return(greater || isNaNF16UI(in2.v) ? in1 : in2);
}

inline float32_t fpmax(float32_t in1, float32_t in2)
{
  bool greater = f32_lt_quiet(in2, in1) ||
                 (f32_eq(in2, in1) && (in2.v & SIGN_F32));
  if (isNaNF32UI(in1.v) && isNaNF32UI(in2.v))
    return (fr32(defaultNaNF32UI));
  else
    return(greater || isNaNF32UI(in2.v) ? in1 : in2);
}

inline float64_t fpmax(float64_t in1, float64_t in2)
{
  bool greater = f64_lt_quiet(in2, in1) ||
                 (f64_eq(in2, in1) && (in2.v & SIGN_F64));
  if (isNaNF64UI(in1.v) && isNaNF64UI(in2.v))
    return (fr64(defaultNaNF64UI));
  else
    return(greater || isNaNF64UI(in2.v) ? in1 : in2);
}

inline float16_t fpmin(float16_t in1, float16_t in2)
{
  bool less = f16_lt_quiet(in1, in2) ||
                 (f16_eq(in1, in2) && (in1.v & SIGN_F16));
  if (isNaNF16UI(in1.v) && isNaNF16UI(in2.v))
    return (fr16(defaultNaNF16UI));
  else
    return(less || isNaNF16UI(in2.v) ? in1 : in2);
}

inline float32_t fpmin(float32_t in1, float32_t in2)
{
  bool less = f32_lt_quiet(in1, in2) ||
                 (f32_eq(in1, in2) && (in1.v & SIGN_F32));
  if (isNaNF32UI(in1.v) && isNaNF32UI(in2.v))
    return (fr32(defaultNaNF32UI));
  else
    return(less || isNaNF32UI(in2.v) ? in1 : in2);
}

inline float64_t fpmin(float64_t in1, float64_t in2)
{
  bool less = f64_lt_quiet(in1, in2) ||
                 (f64_eq(in1, in2) && (in1.v & SIGN_F64));
  if (isNaNF64UI(in1.v) && isNaNF64UI(in2.v))
    return (fr64(defaultNaNF64UI));
  else
    return(less || isNaNF64UI(in2.v) ? in1 : in2);
}

/*=============================================================================================================*/
//Masking
template<class T>
void maskVector(T *destReg, T *maskReg,  int m, int vl, int maxvl)
{
  int i;
  switch(m)
  {
    case 0: // destination reg is scalar
      for(i=1; i< vl; i++)
      {
        destReg[i] = destReg[0];
      }
      for(i=vl; i< maxvl; i++)
      {
        destReg[i] = 0;
      }
      break;
    case 1: //destination reg is vector
      for(i=vl; i< maxvl; i++)
      {
        destReg[i] = 0;
      }
      break;
    case 2: //masked vector (mask.LSB = 0)
      for(i=0; i< vl; i++)
      {
        destReg[i] = (maskReg[i] & 1) ? 0: destReg[i];
      }
      for(i=vl; i< maxvl; i++)
      {
        destReg[i] = 0;
      }
      break;
    case 3: //masked vector (mask.LSB = 1 )
      for(i=0; i< vl; i++)
      {
        destReg[i] = (maskReg[i] & 1) ? destReg[i] : 0;
      }
      for(i=vl; i< maxvl; i++)
      {
        destReg[i] = 0;
      }
      break;
  }
}

template<class T>
void maskVector(T *destReg, int vl, int maxvl)
{
  int i;
  for(i=1; i< vl; i++)
  {
    destReg[i] = destReg[0];
  }
  for(i=vl; i< maxvl; i++)
  {
    destReg[i] = 0;
  }
}
/*=============================================================================================================*/
// load - store
template <class T>
T v_load(T value, int elewidth, int masktype, T mask, int vectlen);

template <class T>
T v_store(T value, int elewidth, int masktype, T mask, int vectlen);
/*=============================================================================================================*/
//Addition

template <class T>
T v_add(T input1, T input2, int elewidth, int masktype, T mask, int vectlen);  //assuming both a and b are of same type and length

template <class T>
T v_fadd(T input1, T input2, int elewidth, int masktype, T mask, int vectlen);  //assuming both a and b are of same type and length

/*=============================================================================================================*/
//multiplication

template <class T>
T v_mul(T input1, T input2, int elewidth, int masktype, T mask, int vectlen);  //assuming both a and b are of same type and length

template <class T>
T v_fmul(T input1, T input2, int elewidth, int masktype, T mask, int vectlen);  //assuming both a and b are of same type and length

/*=============================================================================================================*/

//multiplication addition

template <class T>
T v_madd(T input1, T input2, T input3, int elewidth, int masktype, T mask, int vectlen);  //assuming both a and b are of same type and length

template <class T>
T v_fmadd(T input1, T input2, T input3, int elewidth, int masktype, T mask, int vectlen);  //assuming both a and b are of same type and length

/*=============================================================================================================*/

//broadcast

template <class T>
T v_bcast(T input, int index, int elewidth, int masktype, T mask, int vectlen);

template <class T>
T v_bcast(T value, int elewidth, int vectlen);
// template <class T>
// void v_bcast(T output, unsigned int input, int elewidth, int vectlen);

// template <class T>
// void v_bcast(T output, float32_t input, int elewidth, int vectlen);

/*=============================================================================================================*/


//reduce

template <class T>
T v_reduce(T input, int redtype, int elewidth, int vectlen);


template <class T>
T v_freduce(T input, int redtype, int elewidth, int vectlen);

/*=============================================================================================================*/
//Min Max
template <class T>
T v_min(T input, T min, int elewidth, int vectlen);

template <class T>
T v_max(T input, T max, int elewidth, int vectlen);

template <class T>
T v_fmin(T input, T min, int elewidth, int vectlen);

template <class T>
T v_fmax(T input, T max, int elewidth, int vectlen);

/*=============================================================================================================*/

template <class T>
T v_merge(T input1, T input2, int elewidth, int vectlen, T mask, int masktype);

/*=============================================================================================================*/

template <class T>
T v_insert(T output, unsigned int input, int index, int elewidth, int vectlen, T mask, int masktype);

/*=============================================================================================================*/


#include "vadd.tpp"
#include "vmul.tpp"
#include "vmadd.tpp"
#include "vfadd.tpp"
#include "vfmul.tpp"
#include "vfmadd.tpp"
#include "vreduce.tpp"
#include "vfreduce.tpp"
#include "vbcast.tpp"
#include "vminmax.tpp"
#include "vfminmax.tpp"
#include "vloadstore.tpp"
#include "vmerge.tpp"
#include "vinsert.tpp"

#endif
