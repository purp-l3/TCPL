#include <stdio.h>
#define A_LENGTH 128
#define YES 1
#define NO 0

int main()  {
  // 
  // Exercise 1-12: Write a program to print a histogram of the lengths of words
  // in its input. It is easiest to draw the histogram horizontally; a vertical
  // orientation is more challenging.
  //
  int c, i, ln, j, inword;
  inword = NO;
  c = i = ln = j = 0;

  int hist[A_LENGTH];
  for (i = 0; i < A_LENGTH; ++i) {
    hist[i] = 0;
  }

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c =='\t') {
      if (inword == YES) {  
          hist[ln]++;
          ln = 0;
          inword = NO;
      }
  } else {
      if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
          if (inword == NO) {
              inword = YES;
              ln = 1;
        } else {
              ++ln;        
        }
      }
    }
  }

  ln = 0;
  for (i = 0; i < A_LENGTH; ++i) {
    ln = hist[i];
    if (ln > 0) {
      printf("%d: ", i);
      for (j = 0; j < ln; ++j) {
        printf("[]");
      }
      printf("\n");
    }
  }
  
  return 0;
}
