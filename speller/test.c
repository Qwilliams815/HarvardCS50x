#include <cs50.h>
#include <stdio.h>
#include <string.h>
//#include <math.h>

// Create Node object
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Set Estimated Node list length based on amount of given Keys (dictionary words)
const unsigned int N = 2500;

// Create table for nodes
node *table[N];

unsigned int hash(const char *word)
{
    int ascii = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        ascii += word[i];
    }

    ascii *= strlen(word);
    ascii *= word[0];
    // double new = pow(ascii, strlen(word));
    return printf("%s -- %i\n\n", word, ascii % 2500);
}

int main(void)

{
    printf("test\n");
    FILE *dict = fopen("dictionaries/large", "r");

    // READING LINE BY LINE WITH SPECIFIED BUFFER SIZE

    char word[45];
    while (fgets(word, 45, dict))
    {
        hash(word);

        if (strlen(word) == 12)
        {
            break;
        }
    }

    fclose(dict);
    return 0;
}
