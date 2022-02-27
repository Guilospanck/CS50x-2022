# WAV
WAV files store audio as a sequence of "samples".

WAV files begin with a 44-byte header that contains information about the file itself, including the size of the file, the number of samples per second, and the size of each sample.

After the header, it contains a sequence of samples, each a single 2-byte integer representing the audio signal at a particular point in time.

Scaling each sample by a given factor has the effect of changing the volume of the audio. Mutiplying each sample value by 2.0, for example, will have the effect of doubling the volume of the original audio. Multiplying each sample by 0.5, meanwhile, will have the effect of cutting the volume in half.