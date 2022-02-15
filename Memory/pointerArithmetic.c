#include <stdio.h>

int main() {

  char *s = "Hi!";
  printf("%c\n", s[0]);
  printf("%c\n", s[1]);
  printf("%c\n", s[2]);

  printf("\n");

  // s is a pointer to the beginning to a char (also known as string)
  // and a string is an ARRAY
  // then the value to which it points at is the "H"
  // but every string is sequential, so if we want the next, we can do
  // pointer arithmetic
  printf("%c\n", *s);
  printf("%c\n", *(s + 1)); // Gets the value of the next address (address of s plus 1)
  printf("%c\n", *(s + 2)); // ...

  printf("\nNUMBERS \n");

  // using the same thing to numbers (because what's important is that it's an ARRAY)
  int numbers[] = {4, 6, 8, 9, 7, 2};

  printf("%i\n", numbers[0]);
  printf("%i\n", numbers[1]);
  printf("%i\n", numbers[2]);

  printf("\n");

  printf("%i\n", *numbers);
  printf("%i\n", *(numbers + 1));
  printf("%i\n", *(numbers + 2));

}