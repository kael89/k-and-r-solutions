/**
 * Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. 
 */

#include <stdio.h>

#define FALSE 0;
#define TRUE 1;

int main()
{
    char c;
    int previous_is_space = FALSE;

    while ((c = getchar()) != EOF)
    {
        int current_is_space = (c == ' ');
        if (current_is_space && previous_is_space)
        {
            continue;
        }

        putchar(c);
        previous_is_space = current_is_space;
    }
}