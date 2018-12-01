#ifndef _VECTOR_TYPES_H
#define _VECTOR_TYPES_H

#include <cstdint>
#include <cinttypes>
#include "config.h"
#include "common.h"

#define MAXVL 256
#define OFFSETMAXEW8 3
#define OFFSETMAXEW16 4
#define OFFSETMAXEW32 5
#define OFFSETMAXEW64 6


enum max_element_width
{
  MaxElementWidth8 = 1,
  MaxElementWidth16 = 2,
  MaxElementWidth32 = 3,
  MaxElementWidth64 = 4
};

typedef union u256_t
{
  uint8_t e8[32];
  uint16_t e16[16];
  uint32_t e32[8];
  uint64_t e64[4];
}vec256_t;

typedef struct {uint8_t ele[32];} u256_8_t;
typedef struct {uint16_t ele[16];} u256_16_t;
typedef struct {uint32_t ele[8];} u256_32_t;
typedef struct {uint64_t ele[4];} u256_64_t;

typedef struct {int8_t ele[32];} i256_8_t;
typedef struct {int16_t ele[16];} i256_16_t;
typedef struct {int32_t ele[8];} i256_32_t;
typedef struct {int64_t ele[4];} i256_64_t;

typedef u256_32_t uint256_t;

#endif
