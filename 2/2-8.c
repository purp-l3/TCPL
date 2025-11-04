#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
  int bit_count = sizeof(unsigned) * 8; 
  // get rightmost x bits
  unsigned mask = ~(~0 << n); 
  unsigned rightmost = x & mask;

  unsigned xshift = x >> n;
//  mask = ~(~0 >> n);
  return xshift | (rightmost << (bit_count -n));

}

int main() {
  //
  // Exercise 2-8: Write a function rightrot(x, n) that returns the value of the integer x rotated
  // to the right by n positions.
  //
  
  return 0;
}
  
