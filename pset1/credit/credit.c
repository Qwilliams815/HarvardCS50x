#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for card number
    long card_number = get_long("Number: ");

    // Finding first 2 digits and length of card_number
    long first_two_numbers = card_number;
    int card_number_length = 2;
    while (first_two_numbers >= 100)
    {
        first_two_numbers = first_two_numbers / 10;
        card_number_length++;
    }

    // Luhn's Algorithm
    int checksum_first = 0;
    int checksum_second = card_number % 10;
    int i = 1;

    // Getting every other CC digit starting from right
    while (card_number >= 10)
    {
        card_number = card_number / 10;
        i++;

        // Creating 1st checksum group of numbers
        if (i % 2 == 0)
        {
            int digit = card_number % 10;
            digit = digit * 2;

            // Check if multiplied digit is greater than 10
            if (digit >= 10)
            {
                checksum_first += digit % 10;
                digit = digit / 10;
            }
            checksum_first += digit;

            // Creating 2nd group of checksum numbers
        }
        else
        {
            int digit = card_number % 10;
            checksum_second += digit;
        }
    }
    int checksum_total = checksum_first + checksum_second;

    // Length, Starting digit, and Checksum qualifiers
    if (card_number_length >= 13 && card_number_length <= 16)
    {
        if (checksum_total % 10 == 0)
        {

            if (first_two_numbers == 34 || first_two_numbers == 37)
            {
                if (card_number_length == 15)
                {
                    printf("AMEX\n");
                }
            }
            else if (first_two_numbers >= 51 && first_two_numbers <= 55)
            {
                if (card_number_length == 16)
                {
                    printf("MASTERCARD\n");
                }
            }
            else if (first_two_numbers / 10 == 4)
            {
                if (card_number_length == 13 || card_number_length == 16)
                {
                    printf("VISA\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
