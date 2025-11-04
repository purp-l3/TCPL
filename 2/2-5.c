#include <stdio.h>

int getbits(unsigned int x, unsigned int p, unsigned int n) {
  // int: 32-bit by default
  return ((x >> (32 - p - n)) & ~(~0 << n));
}
int main() {
  //
  // Exercise 2-5: modify getbits to number bits from left to right
  //
  /*
   * int getbits(unsigned int x, unsigned int p, unsigned int n) {
   *    return((x>> (p+1-n)) & ~(~0 << n))
   * }
   */ 
  unsigned int x = 0xABCD1234;
  unsigned int p = 4;
  unsigned int n = 8;
  int result = getbits(x, p, n);

  printf("result:0x%X\n", result);
  return 0;
}

