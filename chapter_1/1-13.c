/**
 * @description Write a program to print a histogram of the lengths of words in its input. It is easy to draw the
 * histogram with the bars horizontal; a vertical orientation is more challenging.
 */

#include <stdio.h>

#define MAX_LENGTH 30

int main()
{
    int current_length = 0;
    int lengths[MAX_LENGTH + 1];

    // Initialize length array
    for (int length = 0; length <= MAX_LENGTH; length++)
    {
        lengths[length] = 0;
    }

    // Calculate lengths
    int c;
    while ((c = getchar()) != EOF)
    {
        int char_is_whitespace = c == ' ' || c == '\n' || c == '\t';
        if (char_is_whitespace)
        {
            if (current_length <= MAX_LENGTH)
            {
                lengths[current_length]++;
            }
            current_length = 0;
        }
        else
        {
            current_length++;
        }
    }
    if (current_length <= MAX_LENGTH)
    {
        lengths[current_length]++;
    }

    // Calculate maximum count
    int maxCount = 0;
    for (int length = 0; length < MAX_LENGTH; length++)
    {
        int count = lengths[length];
        if (count > maxCount)
        {
            maxCount = count;
        }
    }

    // Calculate maximum non zero length
    int maxNonZeroLength = 0;
    for (int length = MAX_LENGTH; length > 0; length--)
    {
        int count = lengths[length];
        if (count > 0)
        {
            maxNonZeroLength = length;
            break;
        }
    }

    int chartLimit = maxNonZeroLength;

    // Print horizontal chart
    printf("\nWord count (horizontal histogram)\n");
    printf("---------------------------------\n");
    for (int length = 1; length <= chartLimit; length++)
    {
        printf("%2d | ", length);
        int count = lengths[length];
        for (int i = 0; i < count; i++)
        {
            printf("*");
        }
        putchar('\n');
    }

    // Print vertical chart
    printf("\nWord count (vertical histogram)\n");
    printf("-------------------------------\n");
    if (chartLimit < 1)
    {
        putchar('\n');
        return 0;
    }

    for (int count = maxCount; count > 0; count--)
    {
        for (int length = 1; length <= chartLimit; length++)
        {
            char point = lengths[length] >= count ? '*' : ' ';
            printf("%3c ", point);
        }
        putchar('\n');
    }

    for (int length = 1; length <= chartLimit; length++)
    {
        printf("----");
    }
    putchar('\n');
    for (int length = 1; length <= chartLimit; length++)
    {
        printf("%3d ", length);
    }
    putchar('\n');
}