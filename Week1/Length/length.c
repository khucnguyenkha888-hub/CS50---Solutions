#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("Before: ");
    printf("After:  ");

    for (int i = 0, len = strlen(name); i < len; i++)
    {

            printf("%c", toupper(name[i]));
    }

    printf("\n");
}
