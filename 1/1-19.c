#include <stdio.h>
#define   TABSIZE       4 

int main() {
  //
  // Exercise 1-19: Write a program detab which replaces tabs in the input
  // with the proper number of blanks to space the next tab stop/ Assume a
  // fixed set of tab stops, say every n positions
  //
  
  char *line = NULL;
  
  size_t len;
  ssize_t nread;

  while((nread = getline(&line, &len, stdin)) != -1) {
    int col = 0; 
    for (int i = 0; i < nread; ++i) {
      if (line[i] == '\t') {
        int spaces;

        spaces = TABSIZE - (col % TABSIZE);
        for (int j = 0; j < spaces; ++j) {
          printf(" ");
        }
      col += spaces;
      } 
        
      else {
         
        printf("%c", line[i]);
        col++;

        if (line[i] == '\n') {
          col = 0;
        }
      }
    }
  }

  return 0;
  
}

