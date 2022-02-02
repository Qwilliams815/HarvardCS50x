#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Multiple arguments and invalid file error handlers
    if (argc != 2) {
        printf("usage: ./recover filename\n");
        return 1;
    }

    //printf("hello\n");

    FILE *finput = fopen(argv[1], "r");
    if (finput == NULL)

    {
        printf("Could not open file.\n");
        return 1;
    }

    // generated files must be 000.jpg, 001.jpg, ect.
    //fread(bytes, sizeof(BYTE), 3, file);
    char filename[8];

    BYTE buffer[512];
    int count = 0;
    while (fread(buffer, sizeof(BYTE), 512, finput) != 0) {
        //printf("%i ", buffer[0]);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            bool file_open = true;
            FILE *foutput = fopen(filename, 'w');
            fwrite(buffer, sizeof(BYTE), 512, foutput);
            count++;
        //if opne file = true
        //open file = true
         //open a write file as current_file 000
        }
    }
    printf("%i\n", count);

    // for each 512b block in argv[1]
    // if block starts with 0xff 0xd8 0xff,
     //if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
         //open a write file as current_file 000
     //}
    // else write block to the current file
    // write every subsequent block to that file
    //

    fclose(finput);
}