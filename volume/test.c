#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    char *n = "Hello!";
    //int *p = n;
    //printf("%p\n", n);
    //printf("%c\n", n[4]);
    FILE *input = fopen("input.wav", "r");

    printf("%s", input);

}
