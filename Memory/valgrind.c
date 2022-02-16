#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // Allocating 3 ints
  int *x = malloc(3 * sizeof(int));

  // First error: we are not beginning the index at 0.
  // valgrind will give us an error that we are touching an area of memory (Invalid write of size 4)
  // that wasn't allocated for us.
  // x[1] = 73;
  // x[2] = 77;
  // x[3] = 79;

  // => Fix: begin at index 0
  x[0] = 73;
  x[1] = 77;
  x[2] = 79;

  // if we end our program right now, it will give us another error.
  // We are allocating memory, but no freeing it. 
  // This will produce a memory leak.
  // LEAK SUMMARY:
  // ==5411==    definitely lost: 12 bytes in 1 blocks

  // => Fix: free memory allocated
  free(x);

}