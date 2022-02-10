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
    // Value
    char alleles[3];
    // Points to next
    struct person *parents[2];
}
person;

int main(void)
{
    person *new_person = malloc(sizeof(person));
    new_person->alleles[0] = 'A';
    new_person->alleles[1] = 'B';
    new_person->alleles[2] = 'C';


    new_person.*parents[0] = "Dad";
    new_person->*parents[1] = "Mom";


    printf("allele: %p, Parent: %s\n", &new_person.alleles[1], new_person.parents[0]);

}
