#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// typedef uint8_t BYTE;

int main(void)
{
    char *word = "leHol";
    int ascii_value = 0;
    for (int i=0; i<strlen(word); i++) {
        ascii_value += word[i];
    }
    char letter1 = 'A';
    char letter2 = 'B';
    int sum = letter1 + letter2;
    printf("%i\n", letter1);
    printf("%i\n", letter2);
    printf("%i\n", ascii_value);
}