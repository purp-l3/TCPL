#include <stdio.h>
#include <string.h>
#define         MAXLINE         1000

void escape(char s[], char t[]) {
  char c;
  int j = 0;
  for (int i = 0; t[i] != '\0'; i++) {
    c = t[i];
    switch (c) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default: 
        s[j++] = t[i];
        break;
    }
  }
  s[j] = '\0';
}

void unescape(char s[], char t[]) {
  //char c;
  int j = 0;
  for (int i = 0; t[i]!= '\0'; i++) {
    char c = t[i];
    switch(c) {
      case '\\':
        switch(t[i+1]) {
          case 'n':
            s[j++] = '\n';
            i++;
            break;
          case 't':
            s[j++] = '\t';
            i++;
            break;
          default:
            s[j++] = '\\';
            if (t[i+1] == '\\') i++;
            continue;
            //break;
        } 
        break;

      default:
        s[j++] = c;
        //if (t[i + 1] == '\\') i++;
        break;
    }
  }
  s[j] = '\0';

}

static void expect_str(const char *label, const char *got, const char *exp) {
    printf("%-24s | got: \"%s\" | exp: \"%s\" | %s\n",
           label, got, exp, (strcmp(got, exp) == 0 ? "PASS" : "FAIL"));
}

static void test_escape(void) {
    char out[MAXLINE];

    struct { const char *in; const char *exp; const char *name; } cases[] = {
        {"",                             "",                         "escape: empty"},
        {"no specials",                  "no specials",              "escape: none"},
        {"a\nb",                         "a\\nb",                    "escape: newline mid"},
        {"\nstart",                      "\\nstart",                 "escape: newline start"},
        {"end\n",                        "end\\n",                   "escape: newline end"},
        {"a\tb",                         "a\\tb",                    "escape: tab mid"},
        {"\tlead",                       "\\tlead",                  "escape: tab start"},
        {"trail\t",                      "trail\\t",                 "escape: tab end"},
        {"mix\tand\nmatch",              "mix\\tand\\nmatch",        "escape: mixed"},
        {"backslash \\",                 "backslash \\",             "escape: backslash literal"},
        {"tabs\t\tand\n\nnewlines",      "tabs\\t\\tand\\n\\nnewlines", "escape: doubled"}
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i) {
        memset(out, 0, sizeof out);
        escape(out, (char*)cases[i].in);
        expect_str(cases[i].name, out, cases[i].exp);
    }
}

static void test_unescape(void) {
    char out[MAXLINE];

    struct { const char *in; const char *exp; const char *name; } cases[] = {
        {"",                             "",                         "unescape: empty"},
        {"no specials",                  "no specials",              "unescape: none"},
        {"a\\nb",                        "a\nb",                     "unescape: newline mid"},
        {"\\nstart",                     "\nstart",                  "unescape: newline start"},
        {"end\\n",                       "end\n",                    "unescape: newline end"},
        {"a\\tb",                        "a\tb",                     "unescape: tab mid"},
        {"\\tlead",                      "\tlead",                   "unescape: tab start"},
        {"trail\\t",                     "trail\t",                  "unescape: tab end"},
        {"mix\\tand\\nmatch",            "mix\tand\nmatch",          "unescape: mixed"},
        {"backslash \\\\",               "backslash \\",             "unescape: backslash literal"},
        {"tabs\\t\\tand\\n\\nnewlines",  "tabs\t\tand\n\nnewlines",  "unescape: doubled"},
        {"unknown \\x stays",            "unknown \\x stays",        "unescape: unknown escape passthrough"}
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i) {
        memset(out, 0, sizeof out);
        unescape(out, (char*)cases[i].in);
        expect_str(cases[i].name, out, cases[i].exp);
    }
}

int main(void) {
   //
   // Exercise 3-2: Write a function escape(s, t) that converts characters like newline and tab into
   // visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
   // function for the other direction as well, converting escape sequences into the real characters.
   //   
    puts("== ESCAPE TESTS ==");
    test_escape();

    puts("\n== UNESCAPE TESTS ==");
    test_unescape();

    return 0;
}
