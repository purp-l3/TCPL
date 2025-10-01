#include <stdio.h>
#define     MAXLINE       1000 
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
  // Exercise 1-14.c: Revise the main routine of the longest-line program
  // so it will correctly print the length of arbitrarily long input lines,
  // and as much as possible of the text
  //

  int len; // current line length
  char line[MAXLINE]; // current input line
  char save[MAXLINE]; // longest line, saved
  
  int max = 0;
  while ((len = m_getline(line, MAXLINE)) > 0)
    if (len > 0) {
      max = len;
      copy(line, save);
      printf("length: %d, \"%s\"", max, save);
    }
 }


