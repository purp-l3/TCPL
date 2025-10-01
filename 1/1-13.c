#include <stdio.h>

int lower(int c) {
  if ( ('A' <= c) && (c <= 'Z') )
    return c + ('a' - 'A');
  return c;
}
int main() {
  // 
  // Exercise 1-13: Write a program to convert its input to lower case, using a
  // function lower(c) which returns c if c is not a letter, and the lower case
  // value of c if it a letter.
  //
  
  int c;
  c = 0;

  while ((c = getchar()) != EOF) {
    c = lower(c);
    putchar(c);

  }

  return 0;
}

