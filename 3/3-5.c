#include <stdio.h>
#include <string.h>
#define         MAXLINE         1000

void reverse(char s[]) {
  int i, j;
  char c;

  for (i=0, j = strlen(s)-1; i < j; i++, j--) {
    c =s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itob(int n, char str[], int b) {
   int i = 0;
   unsigned int un = (n < 0) ? -n : n; 
   do {
      
     int rem = un % b;
     str[i++] = (rem < 10) ? rem + '0' : rem - 10 + 'A';
     un /= b;

   } while (un != 0);
// base 10 gets more attention than i did while getting raised here:
   if (n < 0 && b == 10) {
     str[i++] = '-';
   }

   reverse(str);
   str[i] = '\0';
}

int main() {
  //
  // Exercise 3-5: Write the function itob(int n, char str[], int b) that converts the integer
  // n into a base b character representation in the string s. In particular, itob(n, s, 16) 
  // formats s as a hexadecimal integer in s.
  //
  
  return 0;
}

