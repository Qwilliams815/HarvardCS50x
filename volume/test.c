#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

//typedef uint8_t BYTE;
typedef int16_t BYTE2;

int main(void)
{
    //int test1 = 0;
    //int test2 = 0;
    //int test3 = 1;
    //int test4 = 1;
//
    //if (test1 == 0 && test2 == 1) {
    //    printf("first\n");
    //} else if (test1 == 0) {
    //    printf("worked\n");
    //}

    //malloc testing if reaching past arrays limits returns something or not
    //char *s = get_string("s: ");
//
    //char *t = malloc(strlen(s) + 1);
//
    //strcpy(t, s);
//
    //t[0] = toupper(t[0]);
//
    //printf("s: %s\n", s);
    //printf("t: %s\n", t);
//
    //free(t);
//
    //int input[] = {3, 2, 5};
    //int input_copy[3] = input;
    //int length = 0;
//
//
    //for (let length=0; length<)
    //int input_new = malloc(3);

    //int list[] = {5, 5, 2, 3, 7, 3, 1};
    //for (int i=0; i<7; i++) {
    //    if (list[i] == 3) {
    //        continue;
    //    }
    //    printf("%i ", list[i]);
    //}
    //printf("\n");

    //int *b = &a;
    //int *pa = &a;

    //printf("%p\n", &a);
    //printf("%i\n", a);

    //string i = "000";
    //int num = 0;
    //printf("%s\n", i);


    char buffer[13];

    int i = 50;
    sprintf(buffer, "This is CS%i\n", i);
    //This is CS50

    for (int j=0; j<strlen(buffer); j++) {
        printf("%c", buffer[j]);
    }

    float f = 50.0;
    sprintf(buffer, "This is CS%f\n", f);
    //This is CS50

    for (int j=0; j<strlen(buffer); j++) {
        printf("%c", buffer[j]);
    }

    //printf("%s", buffer);
    //char filename[8];
    //int num = 0;
    //string a = "000";
    //string b = "00";
    //string c = "0";
    //if (num < 10) {
    //    sprintf(filename);
    //}




}
