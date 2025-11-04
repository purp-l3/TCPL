#include <stdio.h>

int any(char s1[], char s2[]) {
  
  for (int i = 0; s1[i] != '\0'; i++) {
    for (int j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) 
        return i;
    }
  }

  return -1;
}

int main() {
  //
  // Exercise 2-4: Write the function any(s1, s2) which returns 
  // the first location in the string s1 where any character from
  // the string s2 occurs, or -1 if s1 contains no characters from 
  // s2.
  //
  char t1[] = "ANY TO ANY";
  char t2[] = "algun a Alguno";

  printf("%d", any(t1, t2));
  
  return 0;
}

