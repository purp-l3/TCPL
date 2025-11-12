#include <stdio.h>
#include <string.h>
#include <limits.h>
#define         abs(x)          ((x) < 0 ? -(x) : (x))

void reverse(char s[]) {
  int i, j;
  char c;

  for (i=0, j = strlen(s)-1; i < j; i++, j--) {
    c =s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) // record sign
    n = -n;
  i = 0;
  do { // generate digits in reverse order 
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0); // delete it
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void fixed_itoa(int n, char s[]) {
  int i, sign;
  unsigned int num;
  if (n < 0) {
    // cast THEN reverse
    num = -((unsigned int)n);
  } 
  else { 
    num = n;
  }
  do {
    s[i++] = n % 10 + '0';
  } while ((num /= 10) > 0);
  if (n < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main() {
  //
  // Exercise 3-4: in a two's complement number of representation, our version of itoa does not 
  // handle the largest negative number, that is, the value of n equal to -(2^(wordsize - 1)). 
  // Explain why not. Modify it to print that value correctly, regardless of the machine on
  // which it runs
  //
  // ans: it occurs due to the fact that in a 2's complement system, the spot where the last
  // negative number should be is reserved for the sign bit.
  //
  char b[64], f[64], lol[64];
  int test = INT_MIN;
  int lolmao = test+1;
  itoa(test, b);
  itoa(lolmao, lol);
  printf("INT_MIN = %d\n", test);
  printf("broken version of itoa:  \"%s\"\n", b);
  printf("INT_MIN + 1: \"%s\"\n", lol);
  return 0;
}

