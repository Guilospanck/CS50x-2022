# Bitmap
Basically a Bitmap image is as the name suggests: a map of bits.

For a Black And White image, we have only one bit representing each pixel. 1 for white and 0 for black.

For a colorful image, usually a 24-bit image, we have 8 bits (1 byte) representing each color and 24-bit (8 bytes) representing each pixel.

The pixel, then, is a composition of the amount of three different colors: Red, Green and Blue (RGB).

The RGB files are actually stored as BGR files.

## Grayscale Filter
Basically you get each pixel and apply the same value for RGB (because if they are the same, you'll get a scale of gray color). One option is to get the average of the values of RGB and apply this average them.

For example:
- Pixel A: R: 250 G: 42 B: 99
- Average Pixel A: (250+42+99)/3 = 130
- New Pixel A (grayscaled): R: 130 G: 130 B: 130

## Reflection filter
You just swap pixels of each row.

For example:
- Row 1: pixel A, pixel B, pixel C
- New Row 1: pixel C, pixel B, pixel A

## Blur Filter
There are many ways to achieve this result of a blurred image, but let's stick to the "box blur".

You get a pixel and then you get a 3x3 box around it (it included).

Then you get the average value of each color of each pixel and apply it to the central pixel you're working on.

For example:

[image]

Based on the image above, if we get to blur the pixel 6, you would do the following:
- Get RGB values of those pixels forming a 3x3 box around pixel 6, which are: 1, 2, 3, 5, 6, 7, 9, 10, 11 (notice how the 6 is also included).
- Then, take the average of theses values. Let's say that we got the sum of RGB as this: R: 270 G: 360 B: 540. Then we'll take the average, coming with:
  - R: 270/9 = 30
  - G: 360/9 = 40
  - B: 540/9 = 60
- With these values in hand, we then apply them to the RGB values of our pixel 6.

## Edges
Edges are lines in the image that create a boundary between one object and another.

One way of getting edges out of an image is by using the [Sobel Operator](https://en.wikipedia.org/wiki/Sobel_operator).

### Sobel Operator
You have those two 3x3 matrixes (kernels):

[image]

Then we'll get the 3x3 box around a pixel (like we did with the blur filter) and, for each color (R, G and B) we will multiply its value for the Gx matrix and then for the Gy matrix.

Example:

Supposing we have those values of the channel R for the pixels around the pixel 6 (as in the blur filter):

|25 27 46|

|44 200 99|

|77 73 65|

In this example, the value of the channel R of the pixel 6 is 200.

Now we apply each value for its corresponding Gx and Gy.

|25*(-1) 27*(0) 46*(1)|

|44*(-2) 200*(0) 99*(2)|

|77*(-1) 73*(0) 65*(1)|

Resulting in:

|-25 0 46|

|-88 0 198|

|-77 0 65|

Summing up those values, we get:
```
-25+0+46+(-88)+0+198+(-77)+0+65 = 119
```
Therefore, we have that the Gx of the channel R of the pixel 6 is 119.

Now we do the same process, but using the Gy kernel.
```
-25+(-54)+(-46)+0+0+0+77+146+65 = 163
```
Therefore, we have that the Gy of the channel R of the pixel 6 is 119.

These values of Gx and Gy gets the gradient of color of the image. Using the kernels stated in the image above, if we get for Gx a very large positive or negative number, that means that the image has a change of color in that direction (right -> positive, left -> negative) which means a probability of edge.

The same is true for Gy, but in the vertical way.

- Now we have those values for Gx and Gy, but the color channel only takes one value. What do we do?
  - We get the `square root of Gx^2+Gy^2` and make sure that the value don't surpass 255 (8 bits).

- How about the edges?
  - Treat the missing values on the edges as zeroes.


----
## Info
### Calloc
It's like `malloc` but for more than one block of memory.
```c
void *calloc(size_t num, size_t size);
```
- num: number of elements to allocate.
- size: size of each element.



