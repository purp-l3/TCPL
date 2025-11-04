#include <stdio.h>

int main() {
  //
  // Exercise 2-1: Write a loop equivalent to the for loop [on page 39] without using &&
  //
  
  /*
   * for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
   *
   *
   */
  int lim = 15;
  int c;
  int i = 0;
  while (i < lim-1) {//; (c = getchar()) != '\n'; c != EOF; ++i)
    c = getchar();
    if (c == '\n' || c == EOF) {
      break;
    }
    printf("hi\n");
    ++i;
  }
  return 0;
}

