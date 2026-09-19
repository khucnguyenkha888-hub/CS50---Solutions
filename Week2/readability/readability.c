#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int Wor(string Words);
int Sen(string Sentences);
int Let(string letters);

int main(void)
{
    string text = get_string("Text: ");
    int TotalLet = Let(text);
    int TotalSen = Sen(text);
    int TotalWor = Wor(text);

    float L = ((float) TotalLet / TotalWor) * 100;
    float S = ((float) TotalSen / TotalWor) * 100;
    float Index = 0.0588 * L - 0.296 * S - 15.8;

    int n = (Index * 10 + 5) / 10;
    if (n < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (n > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", n);
    }
}

int Let(string letters)
{
    int Sum = 0;
    for (int i = 0, len = strlen(letters); i < len; i++)
    {
        if (isalpha(letters[i]))
        {
            Sum++;
        }
    }
    return Sum;
}

int Sen(string Sentences)
{
    int Sum = 0;
    for (int i = 0, len = strlen(Sentences); i < len; i++)
    {
        if (Sentences[i] == '.' || Sentences[i] == '!' || Sentences[i] == '?')
        {
            Sum++;
        }
    }
    return Sum;
}

int Wor(string Words)
{
    int Sum = 0;
    for (int i = 0, len = strlen(Words); i < len; i++)
    {
        if (Words[i] == ' ')
        {
            Sum++;
        }
    }
    Sum++;
    return Sum;
}
