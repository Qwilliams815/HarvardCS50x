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
}