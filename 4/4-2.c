#include <stdio.h>
#include <ctype.h>

double m_atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1: 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  } 
  power = 1.0;
  if (s[i] == '.')
    i++;
  for (; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  // handle the scientific notation if present 
  int exp = 0; 
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    int expSign = 1;
    if (s[i] == '-')
    {
      expSign = -1;
      i++;
    }
    else if (s[i] == '+') {
      i++;
    }

    for (; isdigit(s[i]); i++) {
      exp = 10 * exp + (s[i] - '0');
    }
    exp *= expSign;
  }
  double res = sign * val / power;
  if (exp != 0) {
    if (exp > 0) {
      while (exp-- > 0)
        res *= 10.0;
    } else {
      while (exp++ < 0)
        res /= 10;
    }
  }
  return res;
}

int main() {
  //
  // Exercise 4-2: Extend atof to handle scientific notation of the form
  // 123.45e-6 where a floating-point number may be followed by e or E and
  // and optionally signed exponent
  //
  
  return 0;
}

