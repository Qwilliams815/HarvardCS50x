#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("test\n");
    FILE *dict = fopen("dictionaries/large", "r");
    char word[45];
    while (fgets(word, 45, dict) != EOF) {
        printf("%s", word);
    }
    fclose(dict);
}
