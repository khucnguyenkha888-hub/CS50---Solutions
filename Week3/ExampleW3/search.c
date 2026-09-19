#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string names;
    string rank;
} person;

int main(void)
{
    person people[3];

    people[0].names = "Kelly";
    people[0].rank = "Second place";

    people[1].names = "Old man";
    people[1].rank = "Third place";

    people[2].names = "Thomas";
    people[2].rank = "First place";


    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].names, name) == 0)
        {
            printf("%s is the %s\n", people[i].names, people[i].rank);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
