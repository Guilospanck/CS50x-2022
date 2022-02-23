#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

void _getNeighborhood(int row, int column, int height, int width, RGBTRIPLE copy[height][width], RGBTRIPLE image[height][width]);
void _setElement(int xIdx, int yIdx, int elemIdx, int height, int width, RGBTRIPLE elements[9], RGBTRIPLE copy[height][width]);
void _calculateMediumRGBValues(RGBTRIPLE elements[9], int height, int width, RGBTRIPLE image[height][width], int row, int column);
