#include <stdio.h>
#define         FOLD        50
#define         TABSIZE     4

int main() {
  //
  // Exercise 1-21: Write a program to "fold" long input lines after the last
  // non-blank character that occurs before the n-th column of input, where n 
  // is a parameter. Make sure your program does something intelligent with 
  // very long lines, and if there are no blanks or tabs before the specified
  // column.
  //
  char *line = NULL;
  size_t len;
  ssize_t nread;

  while((nread = getline(&line, &len, stdin)) != -1) {
    int col = 0;
    // there is a last non-blank to terminate at when we hit FOLD

    for (int i = 0; i < nread; ++i) 
    {
      if (line[i] == '\n') {
        col = 0;
        printf("%c", line[i]);
      } else if (line[i] == '\t') {
        if (col + TABSIZE > FOLD) {
          printf("\n");
          col = 0;
        }
        printf("%c", line[i]);
        col += TABSIZE;
      } else if (line[i] == '\b') {
        if (col > 0) {
          printf("\b");
          --col;
        }
      }
      else {
        // it is not \n, \t, or \b
        
        if (col >= FOLD) {
          int j = i;
          // Look backwards for the last whitespace
          while (j > 0 && line[j] != ' ' && line[j] != '\t') {
            j--;
          }
          if (j >= 0 && (line[j] == ' ' || line[j] == '\t')) {
            // Found whitespace - break line after it
            printf("\n");
            col = 0;
            // We've already printed up to i, so we need to re-print from j+1 to i on new line
            for (int k = j + 1; k <= i; k++) {
              putchar(line[k]);
              col++;
            }
          } else {
            // No whitespace - break with hyphen
            printf("-\n");
            col = 0;
            // Re-print the current character on new line
            putchar(line[i]);
            col++;
          } 
        } else {
          printf("%c", line[i]);
          ++col;
        }    
      }
    }
  }
  return 0;
}
