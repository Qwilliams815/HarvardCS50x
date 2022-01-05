#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef int16_t BYTE2;

int main(void)
{
    char *n = "Hello!";
    //int *p = n;
    //printf("%p\n", n);
    //printf("%c\n", n[4]);
    FILE *input = fopen("input.wav", "r");

    int data[44];
    fread(data, sizeof(BYTE), 44, input);
    printf("%i", data[0]);
    printf("\n");

    fclose(input);

    //int i = 44;
    //while (i != EOF) {
    //    int sample = file[i];
    //    print file[i]
    //    i++;
    //}
}
