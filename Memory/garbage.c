#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // You should never forget to initialize your variables,
  // otherwise it will read garbage.

  // Garbage is when the computer automatically gives you
  // some random value in its memory.

  int scores[3];

  for (int i = 0; i < 3; i++)
  {
    printf("%d\n", scores[i]);
  }
  
}