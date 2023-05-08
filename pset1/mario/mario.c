#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get user input (1-8) for number of rows
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (1 > height || height > 8);

    int row_length = height;
    int row_index = 1;

    // Establishing/iterating number of rows
    while (height > 0)
    {
        int num_of_hashtags = row_index;
        int spaces = row_length - row_index;

        // Printing Spaces in each row
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        };

        // Printing First Half of #'s
        for (int i = 0; i < num_of_hashtags; i++)
        {
            printf("#");
        };

        // Splitting the Pyramid
        printf("  ");

        // Printing Second Half of #'s
        for (int i = 0; i < num_of_hashtags; i++)
        {
            printf("#");
        };

        printf("\n");

        row_index++;
        height--;
    }
}