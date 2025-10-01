#include <stdio.h>
#define       MAXCHAR       1000 

void copy(char s1[], char s2[]) // copy s1 to s2; assume s2 is big enough
{
  int i;

  i = 0;
  while ((s2[i] = s1[i]) != '\0')
    ++i;
}

int m_getline(char s[], int lim)
{
  int c, i;

  for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) 
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return(i);
} 

int main() {
  // 
  // Exercise 1-15: Write a program to print all lines that are longer than 80 characters.
  //

  int len;
  char line[MAXCHAR];
  
  while ((len = m_getline(line, MAXCHAR)) > 0) {
    if(len > 80) {
      printf("length: %d, \"%s\"\n", len, line);  
    }
  }

  return 0;
}
