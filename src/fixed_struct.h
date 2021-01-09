#ifndef __FIXED_STRUCT_H_
#define __FIXED_STRUCT_H_

#include <stdint.h>

struct fixed8 {
  int8_t num;
  int8_t INT_PART;
  int8_t FRAC_PART;
};

struct fixed16 {
  int16_t num;
  int8_t  INT_PART;
  int8_t  FRAC_PART;
};

struct fixed32 {
  int32_t num;
  int8_t INT_PART;
  int8_t FRAC_PART;
};

#endif
