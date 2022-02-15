#include <stdio.h>

int main() {

  char *s = "Hi!";
  printf("%c\n", s[0]);
  printf("%c\n", s[1]);
  printf("%c\n", s[2]);

  printf("\n");

  // s is a pointer to the beginning to a char (also known as string)
  // then the value to which it points at is the "H"
  // but every string is sequential, so if we want the next, we can do
  // pointer arithmetic
  printf("%c\n", *s);
  printf("%c\n", *(s + 1)); // Gets the value of the next address (address of s plus 1)
  printf("%c\n", *(s + 2)); // ...

}