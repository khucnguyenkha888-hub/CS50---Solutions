#include <cs50.h>
#include <stdio.h>

void runcode(int s);
int main(void)
{
    int numbers = get_int("Height: ");
    runcode(numbers);
}

void runcode(int s)
{
    if(s <= 0)
    {
        return;
    }

    runcode(s - 1);
    for (int i = 0; i < s; i++)
    {
        printf("#");
    }
    printf("\n");
}
