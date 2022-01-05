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
    BYTE bytes[HEADER_SIZE];
    //Read Header from input file
    //long header;
    fread(bytes[0], sizeof(BYTE), HEADER_SIZE, input);
    fwrite(bytes[0], sizeof(BYTE), HEADER_SIZE, output);
    printf("%s", bytes);
    // Iterate Over first 44 bits.
    //for (int i=0; i<HEADER_SIZE; i++) {
    //    // Write each bit to ouput file header
    //    fwrite(bytes[i], sizeof(BYTE), HEADER_SIZE, output);
    //    printf("%i ", bytes[i]);
    //}
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
