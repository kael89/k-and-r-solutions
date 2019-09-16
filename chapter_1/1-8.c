/**
 * Write a program to count blanks, tabs, and newlines. 
 */

#include <stdio.h>

int main()
{
    int spaces = 0;
    int tabs = 0;
    int new_lines = 0;

    char c;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case ' ':
            spaces++;
            break;
        case '\t':
            tabs++;
            break;
        case '\n':
            new_lines++;
            break;
        }
    }

    printf("\n");
    printf("Results:\n");
    printf("spaces: %d\n", spaces);
    printf("tabs: %d\n", tabs);
    printf("new_lines: %d\n", new_lines);
}