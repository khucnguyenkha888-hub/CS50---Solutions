#include <cs50.h>
#include <stdio.h>

int ask_Height(void);
void print_row(int width, int k);

int main(void)
{
    int n = ask_Height();
    int k = n;

    for (int i = 0; i < n; i++)
    {
        k--;
        print_row(n, k);

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


void print_row(int width, int increase)
{
     for (int j = 0; j < width; j++)
         {
            if (j < increase)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
         }
    printf("\n");
}





