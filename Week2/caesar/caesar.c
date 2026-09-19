#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(string words, int length);
bool Only_digits(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !Only_digits(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    int c = atoi(argv[1]);
    string text = get_string("plaintext: ");

    rotate(text, c);
    return 0;
}

bool Only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]) || s[i] < 0 )
        {
            return false;
        }
    }
    return true;
}

void rotate(string words, int length)
{
    printf("ciphertext: ");
    for (int i = 0, len = strlen(words); i < len; i++)
    {
        if (!isalpha(words[i]))
        {
            printf("%c", words[i]);
        }
        else
        {
            char base;
            if (isupper(words[i]))
            {
                base = 'A';
            }
            else
            {
                base = 'a';
            }
            printf("%c", (words[i] - base + length) % 26 + base);
        }
    }
    printf("\n");
}
