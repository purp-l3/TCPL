#include <stdio.h>

unsigned setBits(unsigned x, int p, int n, unsigned y) {
  // get the rightmost n bits of y
  unsigned rightbits_mask = ~(~0 << n);
  unsigned rightbits = y & rightbits_mask;

  // set bits of x starting at pos p TO rightbits
  // 111111000011 == ~0 & ((~0 << p) & (~0 << (p - n)))
  unsigned carveOut = ~((~(~0 << n)) << p);
  return (x & carveOut) | (rightbits << p);
}



int main() {
  //
  // Exercise 2-6: Write a function setbits(x, p, n, y) that returns x with the n bits that begin at 
  // position p set to the rightmost n bits of y, leaving the other bits unchanged.
  //
 
  return 0;
}
