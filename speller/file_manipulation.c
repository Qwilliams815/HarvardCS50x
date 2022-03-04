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
        printf("%s", word);
    }

    // READING CHARACTER BY CHARACTER (SLOWER)
    // char ch;
    // while ((ch = fgetc(dict)) != EOF)
    //{
    //    printf("%c", ch);
    //};

    fclose(dict);
    return 0;
}
