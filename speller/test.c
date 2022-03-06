#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("test\n");
    FILE *dict = fopen("dictionaries/large", "r");

    // READING LINE BY LINE WITH SPECIFIED BUFFER SIZE

    char word[45];
    while (fgets(word, 45, dict))
    {
        if (*word == "abacus") {
            break;
        }

        printf("%s", word);
    }

    fclose(dict);
    return 0;
}
