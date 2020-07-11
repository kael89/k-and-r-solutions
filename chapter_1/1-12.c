/**
 * @description Write a program that prints its input one word per line.
 */

#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main()
{
    int previous_char_is_whitespace = TRUE;

    int c;
    while ((c = getchar()) != EOF)
    {
        int current_char_is_whitespace = c == ' ' || c == '\n' || c == '\t';
        if (current_char_is_whitespace)
        {
            if (!previous_char_is_whitespace)
            {
                putchar('\n');
            }
        }
        else
        {
            putchar(c);
        }

        previous_char_is_whitespace = current_char_is_whitespace;
    }
}