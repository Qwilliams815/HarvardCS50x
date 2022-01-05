#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long first_number_index = number;
    int i = 1;
    int checksum_first = 0;
    int checksum_second = first_number_index % 10;

    while (first_number_index >= 10) {
        first_number_index = first_number_index / 10;
        i++;
        if (i % 2 == 0) {
            int digit = first_number_index % 10;
            //printf("digit: %ld\n", digit);
            digit = digit * 2;
            while (digit >= 10) {
                checksum_first += digit % 10;
                digit = digit / 10;
            }
            checksum_first += digit;
            //printf("checksum: %i\n", checksum_first);
        } else {
            int digit = first_number_index % 10;
            //printf("digit: %ld\n", digit);
            checksum_second += digit;
            //printf("checksum2: %i\n", checksum_second);
        }

    }
    int checksum_total = checksum_first + checksum_second;
    printf("checksum: %i\n", checksum_first);
    printf("checksum 2: %i\n", checksum_second);
    printf("checksum total: %i\n", checksum_total);
    if (checksum_total % 10 == 0) {
        Card is valid!
    }
    //printf("%i\n", checksum);
}
