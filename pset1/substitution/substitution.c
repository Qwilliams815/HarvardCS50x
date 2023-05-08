#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Get key
    string key = argv[1];

    // Check for # of arguments and key length
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Key qualifier
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        int dupe_count = 0;
        char letter = key[i];

        // Check for non-alpha chars
        if (!isalpha(letter))
        {
            printf("found non-alpha\n");
            return 1;
        }

        // Nested loop for finding Dupes (sick rhyme)
        for (int i2 = 0; i2 < n; i2++)
        {
            char letter2 = key[i2];
            if (letter == letter2)
            {
                dupe_count += 1;
                if (dupe_count == 2)
                {
                    printf("found dupe\n");
                    return 1;
                }
            }
        }
    }

    // Get plain text input
    string text = get_string("plaintext: ");
    bool case_checker = true;

    // Output cipher text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char letter = text[i];

        // Saving case from input
        if (isupper(letter))
        {
            case_checker = true;
        }
        else
        {
            case_checker = false;
        }

        int alpha_index = toupper(letter) - 65;
        char key_letter = '\0';

        // Sorting out punctuation
        if (!isalpha(letter))
        {
            key_letter = letter;
        }
        else
        {

            // Applying case to output
            if (case_checker == true)
            {
                key_letter = toupper(key[alpha_index]);
            }
            else
            {
                key_letter = tolower(key[alpha_index]);
            }
        }
        printf("%c", key_letter);
    }
    printf("\n");
    return 0;
}
