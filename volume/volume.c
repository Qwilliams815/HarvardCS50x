// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
//typedef int16_t BYTE;

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
    //open file fprintf to write to a file
    //FILE *input = fopen(argv[1], "r");
    int len = 40;
    BYTE bytes[HEADER_SIZE];
    fread(bytes, sizeof(BYTE), HEADER_SIZE, input);
    for (int i=0; i<HEADER_SIZE; i++) {
        fwrite(&c, sizeof(char), 1, output)
        printf("%i ", bytes[i]);
    }
    printf("\n");
    //FILE *output = fopen("OUTPUT.wav", "a");
    //int header[44];

    //for (int i=0; i<HEADER_SIZE; i++) {
    //
    //}


    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}
