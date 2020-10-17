/**
 * @description Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 * @interactive
 */

#include <stdio.h>

int main()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\t':
            printf("\\t");
            break;
        case '\b':
            printf("\\b");
            break;
        case '\\':
            printf("\\\\");
            break;
        default:
            putchar(c);
            break;
        }
    }
}
