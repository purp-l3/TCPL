#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define         MAXOP           100
#define         NUMBER          '0'
#define         MAXVAL          100 

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main() {
  //
  // Exercise 4-3: given the basic framework, it's straightforward to extend the calculator.
  // Add the modulus (%) operator and provisions for negative numbers.
  //
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: division by zero");
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

double val[MAXVAL];
int sp = 0;

/* push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else {
    printf("error: stack full, cannot push %g\n", f);
  }
}

/* pop: pop and return top value from stack */ 
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#define         BUFSIZE         100
char buf[BUFSIZE]; // ungetch buffer
int bufp = 0;

int getch(void) // get a possibly pushed-back character
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else 
    buf[bufp++] = c;
}

int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch() == ' ' || c =='\t'))
      ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c)) 
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') 
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}


