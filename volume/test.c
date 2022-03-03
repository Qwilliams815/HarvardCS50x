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
    char *word = "H'ello";
    // string new_word = toupper(word[0]) - 'A';
    printf("%c\n", toupper(word[1]));
    // printf("%s\n", new_word);
}