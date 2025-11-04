#include <stdio.h>

unsigned invert(unsigned x, int n, int p) {
  // make a mask  to get n bits at position p
  unsigned mask = ~(~0 << n) << p;
  // i think the lesson here is XOR can flip the bits where mask is.
  return x ^ mask;
}

int main() {
  //
  // Exercise 2-7: Write a function invert(x,p,n) that returns x with the n bits that begin at
  // position p inverted (ie 1 changed into 0 and vice versa), leaving the others unchanged.:
  //
  printf("this can run!\n");
  return 0;
}

