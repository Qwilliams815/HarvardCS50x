#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

//typedef uint8_t BYTE;
//typedef int16_t BYTE2;

int main(void)
{
    //char *n = "Hello!";
    //int *p = n;
    //printf("%p\n", n);
    //printf("%c\n", n[4]);

    FILE *input = fopen("input.wav", "r");

    uint8_t header[44];
    fread(header, 1, 44, input);
    fwrite(header, 1, 44, output);

    fwrite()

    for (int i=0; i<44; i++) {
        printf("%i ", header[i]);
    }

    printf("\n");

    fclose(input);

}
