#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int algo(string words);
int main(void)
{
    int n = 2;
    string player[n];
    for (int i = 0; i < n; i++)
    {
        player[i] = get_string("Player %i: ", i + 1);
    }

    int Total_1 = algo(player[0]);
    int Total_2 = algo(player[1]);

    if (Total_1 == Total_2)
    {
        printf("Tie!\n");
    }
    else if (Total_1 > Total_2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int algo(string words)
{
    int Sum = 0;
    char c;
    for (int i = 0, len = strlen(words); i < len; i++)
    {
        c = toupper(words[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' || c == 'R' ||
            c == 'S' || c == 'T' || c == 'U')
        {
            Sum += 1;
        }
        else if (c == 'D' || c == 'G')
        {
            Sum += 2;
        }
        else if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
        {
            Sum += 3;
        }
        else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
        {
            Sum += 4;
        }
        else if (c == 'K')
        {
            Sum += 5;
        }
        else if (c == 'J' || c == 'X')
        {
            Sum += 8;
        }
        else if (c == 'Q' || c == 'Z')
        {
            Sum += 10;
        }
    }
    return Sum;
}
