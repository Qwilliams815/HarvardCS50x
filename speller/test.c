#include <cs50.h>
#include <stdio.h>
#include <string.h>

unsigned int hash(const char *word)
{
    int ascii = 0;
    for (int i=0; i<strlen(word); i++) {
        ascii += word[i];
    }
    return printf("%s -- %i\n\n", word, ascii);
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
