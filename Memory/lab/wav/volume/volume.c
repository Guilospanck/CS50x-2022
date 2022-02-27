// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
  // Check command-line arguments
  if (argc != 4)
  {
    printf("Usage: ./volume input.wav output.wav factor\n");
    return 1;
  }

  // Open files and determine scaling factor
  FILE *input = fopen(argv[1], "r");
  if (input == NULL)
  {
    printf("Could not open file.\n");
    return 1;
  }

  FILE *output = fopen(argv[2], "w");
  if (output == NULL)
  {
    printf("Could not open file.\n");
    return 1;
  }

  float factor = atof(argv[3]);

  // Copy header from input file to output file
  WAVFileHeader wh;
  fread(&wh, sizeof(wh), 1, input);
  fwrite(&wh, sizeof(wh), 1, output);

  int16_t sample;

  // bytes per sample = byte_rate / (sample_rate * num_channels)
  int bytesPerSample = wh.byte_rate / (wh.sample_rate * wh.num_channels);
  size_t sizeOfSample = sizeof(sample);
  size_t sampleByteSize = (sizeOfSample / bytesPerSample) * sizeof(int8_t);  

  // Number of samples = data_bytes / (num_channels * sample byte size)
  int numSamples = wh.data_bytes / (wh.num_channels * sampleByteSize);

  // update volume
  for (int i = 0; i < numSamples; i++)
  {
    fread(&sample, sizeof(sample), 1, input);
    sample *= factor;
    fwrite(&sample, sizeof(sample), 1, output);
  }

  // Close files
  fclose(input);
  fclose(output);
}
