#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


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

char random_allele();

int main(void)
{
    person *new_person = malloc(sizeof(person));
    new_person->alleles[0] = 'A';
    new_person->alleles[1] = 'B';
    new_person->alleles[2] = 'C';

    person *dad = malloc(sizeof(person));
    person *mom = malloc(sizeof(person));
    dad = NULL;
    mom = NULL;
    new_person->parents[0] = dad;
    new_person->parents[1] = mom;


    //printf("allele: %c, Parent: %p\n", new_person->alleles[1], new_person->parents[0]);
    //if (mom == NULL) {
    //    printf("Mom is null\n");
    //}

    printf("%c\n", random_allele());


}

    char random_allele()
{
    int r = rand() % 3;
    printf("%i\n", r);
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}