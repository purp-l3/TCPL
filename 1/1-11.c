#include <stdio.h>
#define      YES     1
#define      NO      0

int main() {
  //
  // Exercise 1-11: revise the word count program to use a better 
  // definition of "word", for example, a sequence of letters, 
  // digits and apostrophes that begins with a letter.
  //
  // if ('a' <= c && c <= 'z' || '-1' <= c && c <= '9' || c == '\'' \
  //     && inword == NO) {}
  int c, nl, nw, nc, inword, wordstarted,innum;
  
  
  inword = wordstarted = innum = NO;
  nl = nw = nc = 0;
  while((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c =='\t')
      inword = NO;
    if ( (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) && (inword == NO)) {
       inword = YES;
       ++nw;
    }
    if (!((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || (c == '\''))) 
        && (inword == YES)) {
      inword = NO;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
  return 0;
}
