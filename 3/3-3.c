#include <stdio.h>
#define         MAXLINE         1000

int isAlphabetic(int c) {
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z');
}

int isDigit(int c) {
  return (c >= '0' && c <= '9');
}

void expand(char s1[], char s2[]) {
  int j = 0;

  for (int i = 0; s1[i] != '\0'; ++i) {
    char c = s1[i];

    if (i > 0 && s1[i] == '-' && s1[i+1] != '\0') {
      char p, n;
      p = s1[i-1];
      n = s1[i+1];
      // just gonna assume theyre always the same case
      // aka it will probably not work if its A-z or C-a or something.
      if ( ((isAlphabetic(p) && isAlphabetic(n)) ||
            (isDigit(p) && isDigit(n))) && 
          p < n
         ) {

        for (char x = p + 1; x < n; ++x)
          s2[j++] = x;
        continue;
         
      }
    } 
    
    s2[j++] = s1[i];

  }
  s2[j] = '\0';
}

int main() {
  //
  // Exercise 3-3: Write a function expand(s1, s2) that expands shorthand notations like a-z in the
  // string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
  // and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z
  //
  char out[200];
  char *tests[] = {
    "a-d",         // abcd
    "a-b-c",       // abc
    "z-a",         // z-a (invalid)
    "-a-d",        // -abcd
    "a-d-",        // abcd-
    "0-3",         // 0123
    "a-z0-3",      // abc..xyz0123
    "A-Dx",        // ABCDx
    "a--d",        // a--d
    "--a-d--",     // --abcd--
    "3-7-2",       // 345672
    NULL
  };

  for (int i = 0; tests[i]; ++i) {
    expand(tests[i], out);
    printf("\"%s\" -> \"%s\"\n", tests[i], out);
  }

  return 0;
}

