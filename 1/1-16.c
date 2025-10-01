#include <stdio.h>
#define     MAX       1000

int m_getline(char s[], int lim)
{
  int c, i;

  for (i=0; i < lim-1 && (c = getchar()) != EOF; ++i) 
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
  // Exercise 1-16: Write a program to remove trailing blanks and tabs
  // from each line of input, and to delete entirely blank lines.
  //
  
  int i, len;
  char line[MAX]; 
  while (((len = m_getline(line, MAX)) != EOF)) {
    if (len == 0) 
      continue;
    i = len-2;
    while ( (i >= 0) && ((line[i] == ' ') || (line[i] == '\t') || (line[i] == '\n')))  {
      line[i] = '\0'; 
      --i;
    }

    
  }

  return 0;
}

