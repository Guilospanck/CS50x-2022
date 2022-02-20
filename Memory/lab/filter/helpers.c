#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];
  memcpy(copy, image, height * width * sizeof(RGBTRIPLE));

  for (int row = 0; row < height; row++)
  {
    for (int column = 0; column < width; column++)
    {
      int blue = copy[row][column].rgbtBlue;
      int green = copy[row][column].rgbtGreen;
      int red = copy[row][column].rgbtRed;
      double medium = (blue + green + red) / 3;

      image[row][column].rgbtBlue = floor(medium);
      image[row][column].rgbtGreen = floor(medium);
      image[row][column].rgbtRed = floor(medium);
    }
  }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];
  memcpy(copy, image, height * width * sizeof(RGBTRIPLE));

  for (int row = 0; row < height; row++)
  {
    for (int column = 0; column < width; column++)
    {
      image[row][column].rgbtBlue = copy[row][width - column].rgbtBlue;
      image[row][column].rgbtGreen = copy[row][width - column].rgbtGreen;
      image[row][column].rgbtRed = copy[row][width - column].rgbtRed;
    }
  }
  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];
  memcpy(copy, image, height * width * sizeof(RGBTRIPLE));

  for (int row = 0; row < height; row++)
  {
    for (int column = 0; column < width; column++)
    {
      _getNeighborhood(row, column, copy);
    }
  }
  return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
  return;
}

void _getNeighborhood(int row, int column, RGBTRIPLE copy[height][width])
{
  int topX = column;
  int topY = row - 1;

  int bottomX = column;
  int bottomY = row + 1;

  int leftX = column - 1;
  int leftY = row;

  int rightX = column + 1;
  int rightY = row;

  int leftTopDiagX = column - 1;
  int leftTopDiagY = row - 1;

  int rightTopDiagX = column + 1;
  int rightTopDiagY = row + 1;

  int leftBottomDiagX = column - 1;
  int leftBottomDiagY = row + 1;

  int rightBottomDiagX = column + 1;
  int rightBottomDiagY = row + 1;

  // elements of those lines
  RGBTRIPLE elements[9];
  _setElement(leftTopDiagX, leftTopDiagY, 0, elements, copy);
  _setElement(topX, topY, 1, elements, copy);
  _setElement(rightTopDiagX, rightTopDiagY, 2, elements, copy);
  _setElement(leftX, leftY, 3, elements, copy);
  _setElement(column, row, 4, elements, copy);
  _setElement(rightX, rightY, 5, elements, copy);
  _setElement(leftBottomDiagX, leftBottomDiagY, 6, elements, copy);
  _setElement(bottomX, bottomY, 7, elements, copy);
  _setElement(rightBottomDiagX, rightBottomDiagY, 8, elements, copy);
}

void _setElement(int xIdx, int yIdx, int elemIdx, RGBTRIPLE elements[9], RGBTRIPLE copy[height][width])
{
  if (xIdx < 0 || yIdx < 0)
  {
    RGBTRIPLE el;
    el.rgbtBlue = 0;
    el.rgbtGreen = 0;
    el.rgbtRed = 0;

    elements[elemIdx] = el;
  } else {
    RGBTRIPLE el;
    el.rgbtBlue = copy[yIdx][xIdx].rgtBlue;
    el.rgbtGreen = copy[yIdx][xIdx].rgtGreen;
    el.rgbtRed = copy[yIdx][xIdx].rgtRed;
  }
}

void _calculateMediumRGBValues(RGBTRIPLE elements[9], RGBTRIPLE image[height][width], int row, int column){
  int rValues = 0;
  int gValues = 0;
  int bValues = 0;

  for(int i = 0; i < 9; i++){
    rValues += elements[i].rgbtRed;
    gValues += elements[i].rgbtGreen;
    bValues += elements[i].rgbtBlues;
  }

  int rMedium = floor(rValues/9);
  int gMedium = floor(gValues/9);
  int bMedium = floor(bValues/9);

  RGBTRIPLE el;
  el.rgbtBlue = bMedium;
  el.rgbtGreen = gMedium;
  el.rgbtRed = rMedium;

  image[row][column] = el;

}