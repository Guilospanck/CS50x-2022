#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Prototypes
void selectionSortAlgorithm(int numbers[], int arraySize);
void bubbleSortAlgorithm(int numbers[], int arraySize, bool reversed);

int main()
{
  int numbers[] = {50, 20, 40, 22, 5, 100, 1, 444, 124, 0, 4, 77, 1102, 12};
  int arraySize = (int)((sizeof(numbers) / sizeof(numbers[0])));

  // Selection Sort
  // selectionSortAlgorithm(numbers, arraySize);

  // Bubble sort
  bool reversed = false;
  bubbleSortAlgorithm(numbers, arraySize, reversed);

  return 0;
}

void selectionSortAlgorithm(int numbers[], int arraySize)
{
  int smallestNumber = INT_MAX;
  int indexOfSmallesNumber = 0;

  for (int i = 0; i < arraySize; i++)
  {
    for (int j = i; j < arraySize; j++)
    {
      if (numbers[j] < smallestNumber)
      {
        smallestNumber = numbers[j];
        indexOfSmallesNumber = j;
      }
    }
    // swap then
    int numberAtICopy = numbers[i];
    numbers[i] = smallestNumber;
    numbers[indexOfSmallesNumber] = numberAtICopy;

    // resets variables
    smallestNumber = INT_MAX;
    indexOfSmallesNumber = 0;
  }

  // Prints the sorted array!
  for (int i = 0; i < arraySize; i++)
  {
    if (i == arraySize - 1)
    {
      printf("%d\n", numbers[i]);
    }
    else
    {
      printf("%d-", numbers[i]);
    }
  }
}

void bubbleSortAlgorithm(int numbers[], int arraySize, bool reversed)
{

  bool swapped = false;

  for (int j = 0; j < arraySize; j++)
  {
    for (int i = 0; i < arraySize - 1; i++)
    {
      int firstPair = numbers[i];
      int secondPair = numbers[i + 1];

      if (firstPair > secondPair && !reversed)
      {
        // swap then
        numbers[i] = secondPair;
        numbers[i + 1] = firstPair;
        swapped = true;
      }
      else if (firstPair < secondPair && reversed)
      {
        // swap then
        numbers[i] = secondPair;
        numbers[i + 1] = firstPair;
        swapped = true;
      }
    }

    if (!swapped)
    {
      break;
    }
  }

  // Prints the sorted array!
  for (int i = 0; i < arraySize; i++)
  {
    if (i == arraySize - 1)
    {
      printf("%d\n", numbers[i]);
    }
    else
    {
      printf("%d-", numbers[i]);
    }
  }
}