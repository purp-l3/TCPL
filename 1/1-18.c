#include <stdio.h>
#define     MAX      1000

void m_copy(char line[], char save[]) {
  int i = 0;
  while ((save[i] = line[i]) != '\0')
    ++i;
}

int m_getline(char line[]) {
  int len, c, i;
  i = 0;
  while ((c = getchar()) != EOF) { 
  //for (i = 0; i < MAX-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i == MAX-1)
      break;
    if (c == '\n') {
      line[i] = c;
      ++i;
      break;
    } 
    line[i] = c;
    ++i;

  }
  line[i] = '\0';
  return i;
}

int main() {
  //
  // Exercise 1-18: The test in the for statement of m_getline above is rather
  // ungainly. Rewrite the program to make it clearer, but retain the same behavior
  // at end of file or buffer overflow. Is this behavior the most reasonable?
  //
  
  int len, max;
  char save[MAX];
  char line[MAX];
  max = 0;

  while((len = m_getline(line)) > 0)
    if (len > max) {
      max = len;
      m_copy(line, save);
    }
  
  if (max > 0)
      printf("%s", save);
  return 0;
}

