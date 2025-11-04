#include <stdio.h>
#define         YES         1
#define         NO          0

// void squeeze(char s[], int c) {
//  int i, j;
//  for (i = j = 0; s[i] != '\0'; i++)
//      if (s[i] != c)
//          s[j++] = s[i]
//  s[j] = '\0';
// }

void deleteSqueeze(char s[], char s2[]) {
  int i, j;
  i = j = 0;
  for (; s[i] != '\0'; i++) {
    int match = NO;
    for (int k = 0; s2[k] != '\0'; k++) {
      if (s2[k] == s[i]) {
        match = YES;
        break;
      }
    }

    if (!match) {
      s[j++] = s[i];
    }
    

  }
  s[j] = '\0';
}

int main() {
  //
  // Exercise 2-3: Write an alternate version of squeeze(s1, s2)
  // which deletes each character in s1 which matches any character
  // in the string s2.
  //
 
  char t1[] = "I love marijuana";
  char t2[] = "marijuana is for losers";

  // Iv

  deleteSqueeze(t1, t2);

  printf(t1);
  printf("\n");
  char t3[] = "She BeliEvEd";
  char t4[] = "he lied";

  deleteSqueeze(t3, t4);
  printf(t3); printf("\n");

  return 0;
}

