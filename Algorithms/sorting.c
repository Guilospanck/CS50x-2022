#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "sorting.h"

int main()
{
  int numbers[] = {50, 20, 40, 22, 5, 100, 1, 444, 124, 0, 4, 77, 1102, 12};
  int arraySize = (int)((sizeof(numbers) / sizeof(numbers[0])));

  // Selection Sort
  int numbersForSelectionSort[arraySize];
  memcpy(numbersForSelectionSort, numbers, sizeof(numbers));
  // selectionSortAlgorithm(numbersForSelectionSort, arraySize);

  // Bubble sort
  int numbersForBubbleSort[arraySize];
  memcpy(numbersForBubbleSort, numbers, sizeof(numbers));
  bool reversed = false;
  // bubbleSortAlgorithm(numbersForBubbleSort, arraySize, reversed);

  // Merge sort
  int numbersForMergeSort[arraySize];
  memcpy(numbersForMergeSort, numbers, sizeof(numbers));
  mergeSortAlgorithm(numbersForMergeSort, arraySize);

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
  printsArray(numbers, arraySize);
}

void bubbleSortAlgorithm(int *numbers, int arraySize, bool reversed, bool print)
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

  if (print)
  {
    printsArray(numbers, arraySize);
  }
}

void mergeSortAlgorithm(int numbers[], int arraySize)
{

  if (arraySize == 1)
  {
    printf("%d\n", numbers[0]);
  }
  else
  {
    int middle = getMiddle(arraySize);
    bool isLeft = true;

    int leftArraySize = middle;
    int rightArraySize = arraySize - middle;

    int leftArray[middle];
    int rightArray[arraySize - middle];

    getHalfArray(numbers, arraySize, middle, isLeft, leftArray);
    getHalfArray(numbers, arraySize, middle, !isLeft, rightArray);

    // Prints before
    printf("[MERGE SORT] original complete Array:\n");
    printsArray(numbers, arraySize);
    printf("[MERGE SORT] original Left Array:\n");
    printsArray(leftArray, leftArraySize);
    printf("[MERGE SORT] original Right Array:\n");
    printsArray(rightArray, rightArraySize);

    // Sort each half
    bubbleSortAlgorithm(leftArray, leftArraySize, false, false);
    bubbleSortAlgorithm(rightArray, rightArraySize, false, false);

    // Prints each half after sorting
    printf("[MERGE SORT] sorted Left Array:\n");
    printsArray(leftArray, leftArraySize);
    printf("[MERGE SORT] sorted Right Array:\n");
    printsArray(rightArray, rightArraySize);

    int mergeArray[arraySize];
    mergeArrays(rightArray, leftArray, rightArraySize, leftArraySize, mergeArray);

    // prints array after merge
    printf("[MERGE SORT] original Merged Array:\n");
    printsArray(mergeArray, arraySize);

    // sorts the merged array
    bubbleSortAlgorithm(mergeArray, arraySize, false, false);

    // prints the merged array after sort
    printf("[MERGE SORT] sorted Merged Array:\n");
    printsArray(mergeArray, arraySize);
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

void getHalfArray(int numbers[], int arraySize, int middle, bool isLeft, int *array)
{
  if (isLeft)
  {
    for (int i = 0; i < middle; i++)
    {
      array[i] = numbers[i];
    }
  }
  else
  {
    int counter = 0;
    for (int i = middle; i < arraySize; i++)
    {
      array[counter] = numbers[i];
      counter++;
    }
  }
}

void printsArray(int numbers[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    if (i == arraySize - 1)
    {
      printf("%d\n\n", numbers[i]);
    }
    else
    {
      printf("%d-", numbers[i]);
    }
  }
}

void mergeArrays(int firstArray[], int secondArray[], int firstArrayLength, int secondArrayLength, int *arrayToMerge)
{

  int counter = 0;
  for (int i = 0; i < firstArrayLength; i++)
  {
    arrayToMerge[counter] = firstArray[i];
    counter++;
  }

  for (int i = 0; i < secondArrayLength; i++)
  {
    arrayToMerge[counter] = secondArray[i];
    counter++;
  }
}