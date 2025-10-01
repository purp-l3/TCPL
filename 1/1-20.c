#include <stdio.h>
#include <stdlib.h>
#define         TABSIZE         4


int main() {
  //
  // Exercise 1-20: Write the program entab which replaces strings of blanks
  // by the minimum number of tabs and blanks to achieve the same spacing.
  // Use the same tab stops as for detab (1-19)
  //
  char *line = NULL;
  size_t len;
  ssize_t nread;

  while((nread = getline(&line, &len, stdin)) != -1) {
    int spaces = 0;
    for (int i = 0; i < nread; ++i) {
      if(line[i] == ' ') {
        ++spaces;
      }
      else {
        while (spaces >= TABSIZE) {
          printf("\t");
          spaces -= TABSIZE;
        }

        while (spaces > 0) {
          putchar(' ');
          spaces--;
        }
        putchar(line[i]);
      }
    }
  }
  free(line);
  return 0;
}

