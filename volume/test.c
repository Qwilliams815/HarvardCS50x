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

    buffer = input[44];

    for (int i=0; i<44; i++) {
        printf("%i ", header[i]);
    }












    //int data[44];
    //int i=0;
    //while (fread(data, 1, 1, input)) {
    //    printf("%i", data);
    //}
//
    //for (int i=0; i<44; i++) {
    //    printf("%i", data[i]);
    //}

    //while (i<44) {
    //    fread(data, sizeof(BYTE), 44, input)
    //    printf("%i", data[i]);
    //    i++;
    //}

    //char ch = fgetc(input);
    //char ch;
    //while ((ch = fgetc(input)) != feof) {
    //    printf("%c", ch);
    //}

    //printf("%i", fread(data, sizeof(BYTE), input))

    printf("\n");

    fclose(input);


    //for int i=0 while i<whole length: i++ {
    //    if i < 44 {
    //        write file[i] with 1byte
    //    } else {
    //        temp = file[i*factor];
    //        write factor with 2 bytes
    //    }
    //}

    //int i = 44;
    //while (i != EOF) {
    //    int sample = file[i];
    //    print file[i]
    //    i++;
    //}
}
