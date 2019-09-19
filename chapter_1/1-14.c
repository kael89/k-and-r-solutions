/**
 * Write a program to print a histogram of the frequencies of different characters in its input.
 */

#include <stdio.h>

#define FALSE 0
#define TRUE 1

#define CHAR_COUNT 26

int main()
{
    int counts[CHAR_COUNT];

    // Initialize count array
    for (int i = 0; i <= CHAR_COUNT; i++)
    {
        counts[i] = 0;
    }

    // Calculate counts
    int c;
    while ((c = getchar()) != EOF)
    {
        int is_uppercase = c >= 'A' && c <= 'Z';
        int is_lowercase = c >= 'a' && c <= 'z';
        if (!is_uppercase && !is_lowercase)
        {
            continue;
        }

        int index = is_uppercase ? c - 'A' : c - 'a';
        counts[index]++;
    }

    // Print chart
    printf("\nCharacter count\n");
    printf("---------------\n");
    for (int i = 0; i <= CHAR_COUNT; i++)
    {
        int count = counts[i];
        // if (count == 0)
        // {
        //     continue;
        // }

        printf("%2c | ", 'a' + i);
        for (int i = 0; i < count; i++)
        {
            printf("*");
        }
        putchar('\n');
    }
}