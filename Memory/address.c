#include <stdio.h>

// INT usually uses 32 bits => max: 0xFFFF
// Pointers usually takes 64 bits
int main(void) {
  int n = 50;

  int *p = &n;

  printf("%p\n", p);
  printf("%i\n", *p); // dereference operator (get the value of the address)

  // strings
  char *s = "Hi!";
  char *pointer = s;

  printf("%p\n", s); // s, which is a pointer, points to the same address of &s[0]
  printf("%p\n", &s[0]);
  printf("%p\n", &s[1]);
  printf("%p\n", &s[2]);
  printf("%p\n", pointer);

  // Defining custom types
  typedef char *string; // now string is going to be a pointer to the beginning of a char

  string name = "hey!";
  printf("%s\n", name);
  printf("%p\n", name); // name, which is a pointer, points to the same address of &name[0]
  printf("%p\n", &name[0]);
  printf("%p\n", &name[1]);
  printf("%p\n", &name[2]);
}