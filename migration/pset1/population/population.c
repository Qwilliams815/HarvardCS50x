#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for start size
    int lama_pop;
    do
    {
        lama_pop = get_int("Starting Population: ");
    }
    while (lama_pop < 9);

    //Prompt for end size
    int ending_lama_pop;
    do
    {
        ending_lama_pop = get_int("Ending Population: ");
    } 
    while (ending_lama_pop < lama_pop);

    //Calculate number of years until we reach threshold
    int years = 0;

    while (true)
    {
        if (lama_pop >= ending_lama_pop)
        {
            break;
        }
        int lamas_born = lama_pop / 3;
        int lamas_died = lama_pop / 4;
        lama_pop = lama_pop + lamas_born - lamas_died;
        years++;
    }

    //Print number of years
    printf("Years: %i\n", years);
}