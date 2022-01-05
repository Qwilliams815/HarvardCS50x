#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)

{   string text = "Hello, World";
    string key = "VCHPRZGJNTLSKFBDQWAXEUYMOI";

    for (int i=0, n=strlen(text); i < n; i++) {
        char letter = toupper(text[i]);
        int alpha_index = letter - 65;
        char key_letter = tolower(key[alpha_index]);
        printf("%c - %i - %c\n", letter, alpha_index, key_letter);
    }


    //for (int i=0, n=strlen(text); i < n; i++) {
    //    char item = text[i];
    //    printf("%c - ", item);
//
    //    for (int i2=0; i2 < n; i2++) {
    //        char item2 = text[i2];
    //        printf("%c", item2);
    //    }
    //    printf("\n");
    //}

    int i = 0;
    while (i < strlen(text)) {
        char let = text[i];
        for (i=0; i < strlen(text); i++) {
            //printf("%c - %c\n", let, text[i]);
        }
        i++;
    }
};
