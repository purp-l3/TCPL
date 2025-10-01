#include <stdio.h>
#define         YES         1
#define         NO          0
#define         NO_COMMENT  0
#define         SINGLE_LINE 1
#define         MULTI_LINE  2

int main() {
  //
  // Exercise 1-22: Write a program to remove all comments from a C program. 
  // Don't forget to handle quoted strings and character constants properly.

  printf("// string");          // preserved
  char tmp = '/';                 // preserved  
                                  // comment           // removed
  /* comment */        // removed
  printf("/* not comment */");// preserved


  char *line = NULL;
  size_t len;
  ssize_t nread;
  int inComment = NO_COMMENT;
  int afterSlash = NO; 
    int inString = NO;
    int inChar = NO;
    int escapeSeq = NO;

  while((nread = getline(&line, &len, stdin)) != -1) {
    
    
    for (int i = 0; i < nread; ++i) {
      char k = line[i];
      /* if incomment:
       * else if escapeSeq:
       * else if (inString OR inChar)
       * else: below sequence.
       */
      if (inComment != NO_COMMENT) {
        if (inComment == SINGLE_LINE) {
          if (k == '\n') {
            inComment = NO_COMMENT;
            putchar(k);
          } 
        } else if (inComment == MULTI_LINE) {
          if (k == '*' && i < nread-1 && line[i+1] == '/') {
            inComment = NO_COMMENT;
            i++;
          }
        } 
      }
      else if (escapeSeq == YES) {
        putchar(k);
        escapeSeq = NO;
      }
      else if ((inString == YES) || (inChar == YES)) {
        putchar(k);  // Output string/char content

        if (k == '\\') {
          escapeSeq = YES;
        } else if ((inString && k == '"') || (inChar && k == '\'')) {
          inString = NO;    
          inChar = NO;      
        }
      }
      else {
        /*if () {

        } else */if ((i != nread-1) && (afterSlash == NO) && (k == '/')) {
          afterSlash = YES;
        } else if ((afterSlash == YES) && (k == '/')) {
          // this is a newline comment!
          afterSlash = NO;
          inComment = SINGLE_LINE;
        } else if ((afterSlash == YES) && (k == '*')) {
          // this is a multiline comment!
          afterSlash = NO;
          inComment = MULTI_LINE;
          continue;
        } else {
          if (k == '"') {
            inString = YES;
          } else if (k == '\'') {
            inChar = YES;
          }
          afterSlash = NO;
          putchar(k);
        }
      }
    }
  }
  return 0;
}

