#include <cs50.h>
#include <stdio.h>
#include <string.h>

unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';
    for (i=0; i<N; i++) {
        toupper(word[i])
    }
}

int main(void)
{
    printf("test\n");
    FILE *dict = fopen("dictionaries/large", "r");

    // READING LINE BY LINE WITH SPECIFIED BUFFER SIZE

    char word[45];
    while (fgets(word, 45, dict))
    {
        printf("%s", word);

        if (strlen(word) == 12)
        {
            break;
        }
    }

    fclose(dict);
    return 0;
}
