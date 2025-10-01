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

void copy(char s1[], char s2[]) // copy s1 to s2; assume s2 is big enough
{
  int i;

  i = 0;
  while ((s2[i] = s1[i]) != '\0')
    ++i;
}

int main() {
  //
  // Exercise 1-17: Write a function reverse(s) which reverses the character
  // string s. Use it to write a program which reverses its input a line at 
  // a time.
  //
  
  char line[MAX];
  char save[MAX];
  int len, i; 

  while ((len = m_getline(line, MAX)) != EOF) {
    copy(line, save);
    for (i = 0; i < len-1; ++i) {
      line[i] = save[len-2-i];
    }
    line[len] = '\0';
    line[len-1] = '\n';
    printf("%s", line);
  }


  return 0;
}

