#include <stdio.h>
#define         MAXLINE         1000

int strindex(char s[], char t[]);

int main() {
  //
  // Exercise 4-1: Write the function strindex(s, t) which returns the position of the rightmost
  // occurence of t in s, or -1 if there is none.
  //
  
  return 0;
}


int strindex(char s[], char t[]) {
  int lastOcc = -1;
  int j, k;

  for (int i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      
    }
    if (k > 0 && t[k] == '\0') {
      lastOcc = i;
    } 
  } 
  return lastOcc;
}
