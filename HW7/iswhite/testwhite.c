// testdigits.c

#include <stdio.h>

extern int myiswhite(char c);

int main()
{
  static char test_chars[] = { 'a', '5', ' ', '\n', 48, '\t', 'G', '!' };
  int i;
  static char *result;

  for (i = 0; i < sizeof(test_chars); i++) {
    if (myiswhite(test_chars[i]))
      result = "yes";
    else
      result = "no";
    printf("%c %s\n", test_chars[i], result);
  }
}
