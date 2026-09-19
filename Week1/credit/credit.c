#include <cs50.h>
#include <stdio.h>

void BAN_K(long equal_n);
long get_numbers(void);

int main(void)
{
    long n = get_numbers();
    BAN_K(n);
}

long get_numbers(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n <= 0);
    return n;
}

void BAN_K(long equal_n)
{
    long equal_k = equal_n;
    int digits = 0;
    int All = 0;
    while (equal_n > 0)
    {
        digits++;
        equal_n /= 10;
    }

    int k = 0;
    int Double;
    int Card[digits];
    for (int i = digits - 1; i >= 0; i--)
    {
        Card[i] = equal_k % 10;
        equal_k /= 10;
        Double = Card[i] * 2;

        if (k % 2 == 0)
        {
            All += Card[i];
        }
        else
        {
            if (Double > 9)
            {
                Double -= 9;
            }
            All += Double;
        }
        k++;
    }

    if (All % 10 == 0 && Card[0] == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
    }
    else if (All % 10 == 0 && Card[0] == 5 && (Card[1] > 0 && Card[1] <= 5) && digits == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (All % 10 == 0 && Card[0] == 3 && (Card[1] == 4 || Card[1] == 7) && digits == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
