#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Get user Text input
    string text = get_string("Text: ");

    // Find total letters, words, and sentances
    int letters = 0;
    int words = 0;
    int sentances = 0;

    // Loop over each letter in text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        else if (isspace(text[i]))
        {
            words += 1;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            words += 1;
            sentances += 1;
            if (text[i + 1] == ' ')
            {
                words -= 1;
            }
        }
    }

    // Coleman-Liau formula
    float index = 0.0588 * letters / words * 100 - 0.296 * sentances / words * 100 - 15.8;

    // Grade min/max handler
    if (round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (round(index) < 1)
    {
        printf("Grade Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}
