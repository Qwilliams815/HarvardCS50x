#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("test\n");
    FILE *dict = fopen("dictionaries/large", "r");
    char word[45];
    while (*word != EOF) {
        fgets(word, 45, dict);
        printf("%s", word);
    }
    fclose(dict);
}
