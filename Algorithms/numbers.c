#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "numbers.h"

int main(void)
{
  // linearSearch(0);
  binarySearch(5);
  return 0;
}

void linearSearch(int number)
{
  int numbers[] = {4, 6, 8, 2, 7, 5, 0};

  int count = 0;
  for (int i = 0; i < sizeof(numbers); i++)
  {
    count++;
    if (numbers[i] == number)
    {
      printf("Found at %d after %d!\n", i, count);
    }
  }

  printf("Not found!\n");
}

void binarySearch(int number)
{
  int numbers[] = {0, 1, 2, 3, 4, 5, 6};
  int numbersLength = (int)(sizeof(numbers) / sizeof(numbers[0]));

  int middle = getMiddle(numbersLength);
  int numberAtMiddle = numbers[middle];

  if (number == numberAtMiddle)
  {
    printf("Found!\n");
  }
  else
  {
    recursiveBinarySearch(numbers, middle, number, numbersLength);
  }
}

void recursiveBinarySearch(int numbers[], int middle, int number, int numbersLength)
{
  if (numbersLength == 1)
  {
    if (numbers[0] == number)
    {
      printf("Found!\n");
    }
    else
    {
      printf("Not found!\n");
    }
    return;
  }

  int newArraySize = numbersLength - middle;

  if (number > numbers[middle])
  {
    int rightHalf[newArraySize];
    int index = 0;
    for (int i = middle; i < numbersLength; i++)
    {
      rightHalf[index] = numbers[i];
      printf("Right Half Array at [%d] = %d\n", index, numbers[i]);
      index++;
    }

    middle = getMiddle(newArraySize);
    printf("Right Half length is [%d] Middle is [%d]\n", newArraySize, middle);
    if (number == rightHalf[middle])
    {
      printf("Found right!\n");
    }
    else
    {
      recursiveBinarySearch(rightHalf, middle, number, newArraySize);
    }
  }
  else
  {
    int leftHalf[newArraySize];
    for (int i = 0; i < middle; i++)
    {
      leftHalf[i] = numbers[i];
      printf("Left Half Array at [%d] = %d\n", i, numbers[i]);
    }

    middle = getMiddle(newArraySize);
    printf("Right Half length is [%d] Middle is [%d]\n", newArraySize, middle);
    if (number == leftHalf[middle])
    {
      printf("Found left!\n");
    }
    else
    {
      recursiveBinarySearch(leftHalf, middle, number, newArraySize);
    }
  }
}

int getMiddle(int length)
{
  bool IS_EVEN = false;
  if (length % 2 == 0)
  {
    IS_EVEN = true;
  }

  int middle = 0;
  if (IS_EVEN)
  {
    middle = length / 2;
  }
  else
  {
    middle = floor(length / 2);
  }

  return middle;
}