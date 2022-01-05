// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef int16_t BYTE2;

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

    // TODO: Copy header from input file to output file
    BYTE bytes[HEADER_SIZE];
    fread(bytes, sizeof(BYTE), HEADER_SIZE, input);
    //fwrite(bytes, sizeof(BYTE), HEADER_SIZE, output);

    //printf("%s", bytes);
    // Iterate Over first 44 bits.
    int header[HEADER_SIZE];
    for (int i=0; i<HEADER_SIZE; i++) {
        // Write each bit to ouput file header
        //fwrite(bytes[i], sizeof(BYTE), HEADER_SIZE, output);
        header[i] = bytes[i];
        printf("%i", header[i]);
    }
    BYTE2 samples[];
    while (i != EOF)
    //fwrite(header, sizeof(BYTE), HEADER_SIZE, output);
    //while bit != eof

    printf("\n");

    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}
