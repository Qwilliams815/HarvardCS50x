#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ./recover card.raw
    if (argc != 2) {
        printf("usage: ./recover filename\n");
        return 1;
    }

    // if file cant be read, return 1
    FILE *finput = fopen(argv[1], "r");
    if (input == NULL)

    {
        printf("Could not open file.\n");
        return 1;
    }

    // generated files must be 000.jpg, 001.jpg, ect.
    //BYTE bytes[3];
    //fread(bytes, sizeof(BYTE), 3, file);

    int buffer[512];
    fread(buffer, 1, 512, finput);

    while (buffer[0] != EOF) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
         //open a write file as current_file 000
     }
    }

    // for each 512b block in argv[1]
    // if block starts with 0xff 0xd8 0xff,
     if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
         //open a write file as current_file 000
     }
    // else write block to the current file
    // write every subsequent block to that file
    //uoiuiuhgfkjhgasdasdasdasdasds

    fclose(finput);
}