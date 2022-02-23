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
      _applyBlurFilter(row, column, height, width, copy, image);
    }
  }
  return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
  return;
}

void _applyBlurFilter(int row, int column, int height, int width, RGBTRIPLE copy[height][width], RGBTRIPLE image[height][width])
{

  // get neighborhood
  Neighbors neighbor = _getNeighborhood(row, column);

  // elements of those lines
  RGBTRIPLE elements[9];
  _setElement(neighbor.leftTopDiagX, neighbor.leftTopDiagY, 0, height, width, elements, copy);
  _setElement(neighbor.topX, neighbor.topY, 1, height, width, elements, copy);
  _setElement(neighbor.rightTopDiagX, neighbor.rightTopDiagY, 2, height, width, elements, copy);
  _setElement(neighbor.leftX, neighbor.leftY, 3, height, width, elements, copy);
  _setElement(neighbor.centerX, neighbor.centerY, 4, height, width, elements, copy);
  _setElement(neighbor.rightX, neighbor.rightY, 5, height, width, elements, copy);
  _setElement(neighbor.leftBottomDiagX, neighbor.leftBottomDiagY, 6, height, width, elements, copy);
  _setElement(neighbor.bottomX, neighbor.bottomY, 7, height, width, elements, copy);
  _setElement(neighbor.rightBottomDiagX, neighbor.rightBottomDiagY, 8, height, width, elements, copy);

  // set Medium value to central pixel
  _calculateMediumRGBValues(elements, height, width, image, row, column);
}

Neighbors _getNeighborhood(int row, int column)
{
  Neighbors n;

  // Get neighborhood
  int topX = column;
  int topY = row - 1;
  n.topX = topX;
  n.topY = topY;

  int bottomX = column;
  int bottomY = row + 1;
  n.bottomX = bottomX;
  n.bottomY = bottomY;

  int leftX = column - 1;
  int leftY = row;
  n.leftX = leftX;
  n.leftY = leftY;

  int rightX = column + 1;
  int rightY = row;
  n.rightX = rightX;
  n.rightY = rightY;

  int leftTopDiagX = column - 1;
  int leftTopDiagY = row - 1;
  n.leftTopDiagX = leftTopDiagX;
  n.leftTopDiagY = leftTopDiagY;

  int rightTopDiagX = column + 1;
  int rightTopDiagY = row + 1;
  n.rightTopDiagX = rightTopDiagX;
  n.rightTopDiagY = rightTopDiagY;

  int leftBottomDiagX = column - 1;
  int leftBottomDiagY = row + 1;
  n.leftBottomDiagX = leftBottomDiagX;
  n.leftBottomDiagY = leftBottomDiagY;

  int rightBottomDiagX = column + 1;
  int rightBottomDiagY = row + 1;
  n.rightBottomDiagX = rightBottomDiagX;
  n.rightBottomDiagY = rightBottomDiagY;

  int centerX = column;
  int centerY = row;
  n.centerX = centerX;
  n.centerY = centerY;

  return n;
}

void _setElement(int xIdx, int yIdx, int elemIdx, int height, int width, RGBTRIPLE elements[9], RGBTRIPLE copy[height][width])
{
  if (xIdx < 0 || yIdx < 0)
  {
    RGBTRIPLE el;
    el.rgbtBlue = 0;
    el.rgbtGreen = 0;
    el.rgbtRed = 0;

    elements[elemIdx] = el;
  }
  else
  {
    RGBTRIPLE el;
    el.rgbtBlue = copy[yIdx][xIdx].rgbtBlue;
    el.rgbtGreen = copy[yIdx][xIdx].rgbtGreen;
    el.rgbtRed = copy[yIdx][xIdx].rgbtRed;

    elements[elemIdx] = el;
  }
}

void _calculateMediumRGBValues(RGBTRIPLE elements[9], int height, int width, RGBTRIPLE image[height][width], int row, int column)
{
  int rValues = 0;
  int gValues = 0;
  int bValues = 0;

  for (int i = 0; i < 9; i++)
  {
    rValues += elements[i].rgbtRed;
    gValues += elements[i].rgbtGreen;
    bValues += elements[i].rgbtBlue;
  }

  int rMedium = floor(rValues / 9);
  int gMedium = floor(gValues / 9);
  int bMedium = floor(bValues / 9);

  RGBTRIPLE el;
  el.rgbtBlue = bMedium;
  el.rgbtGreen = gMedium;
  el.rgbtRed = rMedium;

  image[row][column] = el;
}