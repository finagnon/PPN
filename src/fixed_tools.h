#include <stdint.h>
#include "fixed_struct.h"

// conversion functions
struct fixed8 float_to_fixed8(float num, int8_t INT_TARGET);
struct fixed16 float_to_fixed16(float num, int8_t INT_TARGE);

// arithmetic operations
struct fixed8 fixed8_add(struct fixed8 a, struct fixed8 b);
struct fixed8 fixed8_sub(struct fixed8 a, struct fixed8 b);
struct fixed8 fixed8_mul(struct fixed8 a, struct fixed8 b);
struct fixed16 fixed16_add(struct fixed16 a, struct fixed16 b);
struct fixed16 fixed16_sub(struct fixed16 a, struct fixed16 b);
struct fixed16 fixed16_mul(struct fixed16 a, struct fixed16 b);
