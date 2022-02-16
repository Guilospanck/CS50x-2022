#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Malloc (memory allocation) and free
int main(void)
{

  char *s = "hi!";

  // allocates memory
  char *t = malloc(strlen(s) + 1); // length of the string plus one for the "\0" (trailing null character)
  if (t == NULL)
  {
    return 1;
  }

  // one option to copy str
  // for (int i = 0, n = strlen(s) + 1; i < n; i++)
  // {
  //   t[i] = s[i];
  // }

  // another
  strcpy(t, s);

  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
  }

  printf("s: %s\n", s);
  printf("t: %s\n", t);

  // frees memory
  free(t);
}