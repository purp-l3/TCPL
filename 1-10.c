#include <stdio.h>

int main() {
  //
  // Write a program which prints the words in its input, one per line.
  //
  int c;
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\t' || c == '\v')
      putchar('\n');
    else { putchar(c); }
  }
  return 0;
}
