#include <stdio.h>



int main() {
  //
  // Exercise 1-23: Write a program to check a C program for rudimentary syntax
  // errors like unbalanced parentheses, brackets and braces. Don't forget about 
  // quotes, both single and double, and comments. (This program is hard if you
  // do it in full generality.)
  // {}, [], (), "", '', //\n, /**/
  int bracket_count, paren_count, brace_count, doub_quote_count, single_quote_count;
  bracket_count = paren_count = brace_count = doub_quote_count = single_quote_count = 0;
  char *line = NULL;
  size_t len;
  ssize_t nread;
  
  while ((nread = getline(&line, &len, stdin)) != -1) {
    for (int i = 0; i < nread; ++i) {
      char k = line[i];
      if (k == '[')
        bracket_count++;
      else if (k == ']')
        bracket_count--;
      else if (k == '(')
        paren_count++;
      else if (k == ')')
        paren_count--;
      else if (k=='{')
        brace_count++;
      else if (k == '}')
        brace_count--;
      else if (k == '\"')
        if (doub_quote_count > 0) {
          doub_quote_count--;
        } else {
          doub_quote_count++;
        } 
      else if (k == '\'') {
        if (single_quote_count > 0) {
          single_quote_count--;
         } else {
          single_quote_count++;
        }
      }
    }
  }
  
  if (bracket_count != 0) {
    printf("unbalanced_brackets: %d", bracket_count);
  }

  if (paren_count != 0) 
    printf("unbalanced_parentheses: %d", paren_count);
  if (brace_count != 0)
    printf("unbalanced_braces: %d", brace_count);
  if (doub_quote_count != 0)
    printf("unbalanced_double_quotes: %d", doub_quote_count);
  if (single_quote_count != 0)
    printf("unbalanced_single_quotes: %d", single_quote_count);

  return 0;
}

