#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

//typedef uint8_t BYTE;
typedef int16_t BYTE2;
typedef struct person
{
    struct person *parents[2];
    char alleles[3];
}
person;

int main(void)
{
    person new_person;
    new_person.alleles[0] = "A";
    new_person.alleles[1] = "B";
    new_person.alleles[2] = "O";

    new_person.parents[0]->"Dad";
    new_person.parents[1]->"mom";


    printf("allele: %p, Parent: %s\n", &new_person.alleles[1], new_person.parents[0]);

}
