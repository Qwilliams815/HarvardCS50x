#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("test\n");
    FILE *dict = fopen("dictionaires/large", "r");
    char word[45];
    fgets(word, 45, dict);
    printf("%s", word);
    fclose(dict);

}
