#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string word = "hello";
    int point_sum = 0;
    for (int i=0, n=strlen(word); i < n; i++) {
        char cap_letter = toupper(word[i]);
        int letter_point_index = cap_letter - 65;
        int letter_points = POINTS[letter_point_index];
        point_sum += letter_points;

        printf("%c - %i - %i\n", cap_letter, letter_points, point_sum);
    };
}
