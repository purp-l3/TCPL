#include  <stdio.h>

int main() {
  //
  // Exercise 1-6: write a program to count blanks, tabs, and newlines
  //
  int newLine, tab, blank, c;
  tab = blank = newLine = 0;
  while((c = getchar()) != EOF) {
    if(c == '\n') {
      ++newLine;
    }  
    if(c == '\t') {
      ++tab;
    }
    if(c == ' ') {
      ++blank;
    }
  }

  printf("newlines: %d\n", newLine);
  printf("blanks: %d\n", blank);
  printf("tabs: %d\n", tab);
}
