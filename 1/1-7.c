#include <stdio.h>

int main() {
  //
  // Exercise 1-7: write a program to copy its input to its output, 
  // replacing each string of one or more blanks by a single blank.
  //
  
  int c, last_char;
  
  while ((c = getchar()) != EOF) {
    if(c != ' ' || last_char != ' ')
      putchar(c);
    last_char = c;

  }


  return 0;
}
