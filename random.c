#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate_yes_or_no()
{
    int random_number = 1 + rand() % 2;
    srand(time(NULL));
    if (random_number == 1)
    {
        printf("%s%s\n", "The answer is: ", "Yes\n");
    }
    else
    {
        printf("%s%s\n", "The answer is: ", "No\n");
    }
}