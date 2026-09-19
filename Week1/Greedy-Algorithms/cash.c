#include <cs50.h>
#include <stdio.h>

int Change_owed(void);
void algorithm(int n);

int main(void)
{
    int n = Change_owed();
    algorithm(n);

}

    

int Change_owed(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 1);
    return n;
}

void algorithm(int n)
{
     int k = 0;
     do
     {if (n >= 25)
     {
       n -= 25;
       k++;
     }
     else if (n >= 10)
     {
        n -= 10;
        k++;
     }
     else if (n >= 5)
     {
        n -= 5;
        k++;
     }
     else
     {
        n -= 1;
        k++;
     }
    }
    while (n >= 1);
    printf("%i\n", k);

}
