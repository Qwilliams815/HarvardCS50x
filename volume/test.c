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
    int i=0;
    while (fread(data, 1, 1, input) != 0) {
        printf("%i", data[i]);
        i++;
    }
    printf("\n");

    fclose(input);


    for int i=0 while i<whole length: i++ {
        if i < 44 {
            write file[i] with 1byte
        } else {
            temp = file[i*factor];
            write factor with 2 bytes
        }
    }

    //int i = 44;
    //while (i != EOF) {
    //    int sample = file[i];
    //    print file[i]
    //    i++;
    //}
}
