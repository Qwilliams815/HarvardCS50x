#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("test\n");
    FILE *dict = fopen("dictionaries/large", "r");
    //char word[45];
    //while (fgets(word, 45, dict)) {
    //    printf("%s", word);
    //}

    //char ch[1];
    //while (fgetc(ch, 1, dict)) {
    //    char word[];
    //}
    string word = "Hello";
    word += " world!";

    printf("%s", word);

    fclose(dict);
    return 0;
}
