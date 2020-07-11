/**
 * @description Write a program that prints its input one word per line.
 */

#include <stdio.h>

#define FALSE 0;
#define TRUE 1;

int main()
{
    int previous_char_is_white_space = TRUE;

    int c;
    while ((c = getchar()) != EOF)
    {
        int current_char_is_white_space = c == ' ' || c == '\n' || c == '\t';
        if (current_char_is_white_space)
        {
            if (!previous_char_is_white_space)
            {
                putchar('\n');
            }
        }
        else
        {
            putchar(c);
        }

        previous_char_is_white_space = current_char_is_white_space;
    }
}