#include <stdio.h>

// int lower(int c) {
//  if (c >= 'A' && c <= 'Z')
//      return c + 'a' - 'A';
//  else 
//      return c;
// }

int lowerIfItWasShorterWaitThisIsIronic(int c) {
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A': c;
}

int main() {
  //
  // Exercise 2-10: Rewritw the function lower, which converts upper
  // case letters to lower case, with a conditional expression instead
  // of if-else.
  //
  char A = 'A';
  char B = 'B';
  char c = 'c';
  char d = 'd';

  printf("A converts to %c\n", lowerIfItWasShorterWaitThisIsIronic(A));
  printf("B converts to %c\n", lowerIfItWasShorterWaitThisIsIronic(B)); 
  printf("c converts to %c\n", lowerIfItWasShorterWaitThisIsIronic(c));
  printf("d converts to %c\n", lowerIfItWasShorterWaitThisIsIronic(d)); return 0; }
