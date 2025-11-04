#include <stdio.h>

int htoi(char hex[]) {
  int n, i;
  n = i = 0;
  
  if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
    i = 2;
  
  for(; hex[i] != '\0'; ++i) {
    n *= 16;
    if ( '0' <= hex[i] && hex[i] <= '9') {
      n += hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'z') {
      n += hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'Z') {
      n += hex[i]  - 'A' + 10;
    } else {
      printf("error: bad input\n");
      return -1;
    }
  }
  return n;
}
int main() {
  //
  // Exercise 2-2: Write the function htoi(s), which converts a string
  // of hexadecimal digits to its equivalent integer value. The allowable
  // digits are 0 through 9, a through f, and A through F.
  //
  printf("%d\n", htoi("1A3"));    // 419
  printf("%d\n", htoi("0xFF"));   // 255
  printf("%d\n", htoi("dead"));   // 57005
  printf("%d\n", htoi("BEEF"));   // 48879 
  return 0;
}

