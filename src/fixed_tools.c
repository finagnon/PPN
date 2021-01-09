#include "fixed_tools.h"
#include "fixed_const.h"
#include "fixed_struct.h"
#include <stdio.h>

#define Max(a,b) (a>b?a:b)

// Conversion 
struct fixed8 float_to_fixed8(float num, int8_t FRAC_TARGET) {
  struct fixed8 f8 = {.num = (int8_t) (num * (1 << FRAC_TARGET)), .FRAC_PART=FRAC_TARGET, .INT_PART=CHAR_WL-FRAC_TARGET};
  
  if (f8.num > CHAR_MAX_ENCODING) printf("OVERFLOW!!--CONVERSION\n");
  else if (f8.num < -1 * CHAR_MIN_ENCODING) printf("UNDERFLOW!!--CONVERSION\n");
  printf("%f=%d (Q%d.%d)\n", num, f8.num, f8.INT_PART, f8.FRAC_PART);    
  
  return f8;
}

struct fixed16 float_to_fixed16(float num, int8_t FRAC_TARGET) {
  struct fixed16 f16 = {.num = (int16_t) (num * (1 <<FRAC_TARGET)), .FRAC_PART=FRAC_TARGET, .INT_PART=INT_WL-FRAC_TARGET};
  
  if (f16.num > INT_MAX_ENCODING) printf("OVERFLOW!!--CONVERSION\n");
  else if (f16.num < -1 * INT_MIN_ENCODING) printf("UNDERFLOW!!--CONVERSION\n");
  printf("%f=%d (Q%d.%d)\n", num, f16.num, f16.INT_PART, f16.FRAC_PART);
  
  return f16;
}

// Arithmetic Operations
struct fixed8 fixed8_add(struct fixed8 a, struct fixed8 b) {
  struct fixed16 acc;

  if (a.FRAC_PART == b.FRAC_PART) {
   acc.num = a.num+b.num;
   acc.FRAC_PART = a.FRAC_PART;
   acc.INT_PART = a.INT_PART;
  }

  else if (a.FRAC_PART > b.FRAC_PART) {
    int8_t shift = a.FRAC_PART - b.FRAC_PART;
    acc.num = (a.num  + (b.num<<shift));
    
    if (acc.num > CHAR_MAX_ENCODING) printf("OVERFLOW!!--ADDITION\n");
    else if (acc.num < -1 * INT_MIN_ENCODING) printf("UNDERFLOW!!--ADDITION\n");
    
    acc.num = (int8_t)acc.num;
    acc.FRAC_PART = a.FRAC_PART;
    acc.INT_PART = CHAR_WL - acc.FRAC_PART;
  }

  else {
    int8_t shift = b.FRAC_PART - a.FRAC_PART;
    acc.num = (b.num + (a.num<<shift));
    
    if (acc.num > CHAR_MAX_ENCODING) printf("OVERFLOW!!--ADDITION\n");
    else if (acc.num < -1 * INT_MIN_ENCODING) printf("UNDERFLOW!!--ADDITION\n");
    
    acc.num = (int8_t)acc.num;
    acc.FRAC_PART = b.FRAC_PART;
    acc.INT_PART = CHAR_WL - acc.FRAC_PART;
  }
  
  struct fixed8 result = {.num=acc.num, .FRAC_PART=acc.FRAC_PART, .INT_PART=acc.INT_PART};
  printf("%d+%d=%d (Q%d.%d)\n", a.num, b.num, result.num, result.INT_PART, result.FRAC_PART);
  
  return result;
}

struct fixed8 fixed8_sub(struct fixed8 a, struct fixed8 b) {
  struct fixed8 c = {.num = -b.num, .FRAC_PART=b.FRAC_PART, .INT_PART=b.INT_PART};
  
  return fixed8_add(a, c);
}

struct fixed8 fixed8_mul(struct fixed8 a, struct fixed8 b) {
  struct fixed16 acc;
  acc.num = ((int16_t)a.num*(int16_t)b.num);
  acc.num += (1<<(a.FRAC_PART-1));
  acc.FRAC_PART = a.FRAC_PART + b.FRAC_PART - CHAR_WL;
  acc.INT_PART  = a.INT_PART  + b.INT_PART;
  
  struct fixed8 result = {.num=acc.num>>CHAR_WL, .FRAC_PART=acc.FRAC_PART, .INT_PART=acc.INT_PART};
  printf("%d*%d=%d (Q%d.%d)\n", a.num, b.num, result.num, result.INT_PART, result.FRAC_PART);
  
  return result;
}

struct fixed16 fixed16_add(struct fixed16 a, struct fixed16 b) {
  struct fixed32 acc;

  if (a.FRAC_PART == b.FRAC_PART) {
   acc.num = a.num+b.num;
   acc.FRAC_PART = a.FRAC_PART;
   acc.INT_PART = a.INT_PART;
  }

  else if (a.FRAC_PART > b.FRAC_PART) {
    int8_t shift = a.FRAC_PART - b.FRAC_PART;
    acc.num = (a.num  + (b.num<<shift));
    
    if (acc.num > INT_MAX_ENCODING) printf("OVERFLOW!!--ADDITION\n");
    else if (acc.num < -1 * INT_MIN_ENCODING) printf("UNDERFLOW!!--ADDITION\n");
    
    acc.num = (int16_t)acc.num;
    acc.FRAC_PART = a.FRAC_PART;
    acc.INT_PART = INT_WL - acc.FRAC_PART;
  }

  else {
    int8_t shift = b.FRAC_PART - a.FRAC_PART;
    acc.num = (b.num + (a.num<<shift));
    
    if (acc.num > INT_MAX_ENCODING) printf("OVERFLOW!!--ADDITION\n");
    else if (acc.num < -1 * INT_MIN_ENCODING) printf("UNDERFLOW!!--ADDITION\n");
    
    acc.num = (int16_t)acc.num;
    acc.FRAC_PART = b.FRAC_PART;
    acc.INT_PART = INT_WL - acc.FRAC_PART;
  }
  struct fixed16 result = {.num=acc.num, .FRAC_PART=acc.FRAC_PART, .INT_PART=acc.INT_PART};
  
  return result;
}

struct fixed16 fixed16_sub(struct fixed16 a, struct fixed16 b) {
  struct fixed16 c = {.num = -b.num, .FRAC_PART=b.FRAC_PART, .INT_PART=b.INT_PART};
  
  return fixed16_add(a, c);
}
