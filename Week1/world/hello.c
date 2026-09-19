#include <cs50.h>
#include <stdio.h>

void print_S(int Collect);
int main(void)
{
    int n = get_int("What's number? ");
    print_S(n);
}

void print_S(int Collect)
{
    for (int i = 0; i < Collect; i++)
    {
        printf("#\n");
    }
}
