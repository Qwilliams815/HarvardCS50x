#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ./recover card.raw
    if (argc != 2) {
        printf("usage: ./recover filename");
        return 1;
    }

    // if file cant be read, return 1

    // generated files must be 000.jpg, 001.jpg, ect.

    FILE *f = fopen(argv[1], "r");

    // read file 512b block by 512b block
    // if block starts with 0xff     0xd8     0xff, open a write file as 000.

}