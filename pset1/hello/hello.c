#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets users name input
    string name = get_string("Name: ");

    printf("hello, %s\n", name);
}