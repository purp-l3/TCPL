#include <stdio.h>

int bitcount(unsigned x) {
  /*
 og func:
  int b; 

  for (b = 0; x != 0; x >>= 1) {
    if (x & 01) 
      b++;
  }
  return b;
  */
  
  int b = 0;
  // notice how in the worst case here (0b011111111111),
  // it runs just as slow as the og function. but usually
  // your number isnt a set binary one, so on average
  // it will be faster than the original.
  while(x > 0) {
    x &= (x - 1);
    b++;
  }
  return b;
}

int main() {
  //
  // Exercise 2-9: In a two's complement number system, x &= (x - 1) 
  // deletes the rightmost 1-bit in x. Explain why. Use this 
  // observation to write a faster version of bitcount.
  //

  /*
   * well, x &= (x - 1) === x = x & (x - 1)
   * x - 1 in binary would mean there are 
   * less iterations when we go through - it is just one
   * subtraction that flips every bit past the rightmost 1
   * to the end. the end result is that rightmost 1 is deleted,
   * because the effect of subtracting one has on that bit and 
   * all subsequent bits. the bitwise AND is just one more operation
   * too.
   * 
   */
  


  return 0;
}

