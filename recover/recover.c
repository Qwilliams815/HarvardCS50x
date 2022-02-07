#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Multiple arguments handler
    if (argc != 2)
    {
        printf("usage: ./recover filename\n");
        return 1;
    }

    // Invalid file error handler
    FILE *finput = fopen(argv[1], "r");
    if (finput == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Establishing custom '###.jpg' filename memory, .jpg file buffer size, .jpg counter, first file qualifier, and .jpg output file.
    char filename[8];
    BYTE buffer[512];
    int count = 0;
    bool file_open = false;
    FILE *foutput;

    // Loop through card memory 512 bytes at a time
    while (fread(buffer, sizeof(BYTE), 512, finput) != 0)
    {
        // Check for qualifying .jpg header bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Skip closing 1st qualifying file because it hasn't been opened yet
            if (count != 0)
            {
                fclose(foutput);
            }

            // Establish first file has been opened
            file_open = true;

            // Create custom .jpg output filename with count data
            sprintf(filename, "%03i.jpg", count);
            foutput = fopen(filename, "w");
            count++;
        }

        // 1st .jpg file has been found and the close/open chain has started
        if (file_open == true)
        {
            fwrite(buffer, sizeof(BYTE), 512, foutput);
        }
    }
    fclose(finput);
}