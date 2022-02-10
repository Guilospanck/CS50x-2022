#include <stdio.h>

int linearSearch(int number);

int main(void)
{
  return linearSearch(0);
}

int linearSearch(int number)
{
  int numbers[] = {4, 6, 8, 2, 7, 5, 0};

  int count = 0;
  for (int i = 0; i < sizeof(numbers); i++)
  {
    count++;
    if (numbers[i] == number)
    {
      printf("Found at %d after %d!\n", i, count);
      return 0;
    }
  }

  printf("Not found!\n");
  return 1;
}