#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 

#include "fixed_tools.h"
#include "fixed_struct.h"

int main() {

  float num = 1.667;
  float nuu = 0.25;

  struct fixed8 a = float_to_fixed8(num, 6);
  struct fixed8 b = float_to_fixed8(nuu, 7);
  
  struct fixed8 c = fixed8_mul(a, b);

  return 1;
}

