#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Math(string before, string after);
bool Not_same(string s);
bool Only_digits(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters\n.");
        return 1;
    }
    else if (!Only_digits(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    else if (!Not_same(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string words = get_string("plaintext: ");
    Math(words, argv[1]);
    return 0;
}

void Math(string before, string after)
{
    printf("ciphertext: ");
    int n;
    char base;
    for (int i = 0, len = strlen(before); i < len; i++)
    {
        if (!isalpha(before[i]))
        {
            printf("%c", before[i]);
        }

        else if (isupper(before[i]))
        {

            base = 'A';
            n = before[i] - base;
            printf("%c", toupper(after[n]));
        }

        else
        {
            base = 'a';
            n = before[i] - base;
            printf("%c", tolower(after[n]));
        }
    }
    printf("\n");
}

bool Only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool Not_same(string s)
{
    int v;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        for (v = i + 1; v < len; v++)
        {
            if (tolower(s[i]) == tolower(s[v]))
            {
                return false;
            }
        }
    }
    return true;
}
