#include <stdio.h>

int main() {
  //
  // Exercise 1-8: write a program to replace each tab by the three-character
  // sequence >, backspace, -, which prints as ->, and each backspace by the 
  // similar sequence <- this makes tabs and backspaces visible
  //
  
  int c;


  while ((c = getchar()) != EOF) {
    if(c == '\t') {
      // > \b -  
      putchar('>');
      putchar('\b');
      putchar('-');
    } else if (c == '\b') {
      // < \b -
      putchar('<');
      putchar('\b');
      putchar('-');

    } else {
      putchar(c);
    }
  }

  return 0;
}
