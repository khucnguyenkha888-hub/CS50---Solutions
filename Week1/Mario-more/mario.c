#include <cs50.h>
#include <stdio.h>

int ask_Height(void);
void rows_increaseR(int Width, int Increase);
void rows_increaseL(int Width, int Increase);

int main(void)
{
    int n = ask_Height();
    int k = n;
    for (int i = 0; i < n; i++)
    {
        k--;
        rows_increaseR(n,k);
        printf ("  ");
        rows_increaseL(n,k);
    }

}

int ask_Height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    return n;
}

void rows_increaseR(int Width, int Increase)
{
    for (int i = 0; i < Width; i++)
    {
        if (i < Increase)
        {
           printf(" ");
        }
        else
        {
           printf("#");
        }
    }
}

void rows_increaseL(int Width, int Increase)
{
    for (int i = 0; i < Width; i++)
    if (i < Width - Increase)
    {
        printf("#");
    }
    printf("\n");
}
