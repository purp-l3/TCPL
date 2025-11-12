#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
  int i, j;
  char c;

  for (i=0, j = strlen(s)-1; i < j; i++, j--) {
    c =s[i];
    s[i] = s[j];
    s[j] = c;
  }
}


void special_itoa(int n, char s[], int minWidth) {
  int i, sign;
  unsigned int un = (n < 0) ? -n : n;

  if ((sign = n) < 0) // record sign
    n = -n;
  i = 0;
  do { // generate digits in reverse order 
    s[i++] = un % 10 + '0';
  } while ((un /= 10) > 0); // delete it
                           //
  if (sign < 0)
    s[i++] = '-';

  while (i < minWidth) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}

int main() {
  //
  // Exercise 3-6: Write a version of itoa that accepts three arguments instead of two. The third
  // argument is a minimum field width; the converted number must be padded with blanks on the
  // left if necessary to make it wide enough
  //

  char s[64];
  special_itoa(123, s, 8);
  printf("'%s'\n", s);

  special_itoa(-42, s, 6);
  printf("'%s'\n", s);

  special_itoa(0, s, 4);
  printf("'%s'\n", s);

  special_itoa(-2147483648, s, 15);
  printf("'%s'\n", s);

  return 0;
}

