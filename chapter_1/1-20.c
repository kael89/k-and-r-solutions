/**
 * @description  Write a program detab that replaces tabs in the input with the proper number of
 * blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>
#include "../lib.h"

void detab(int tab_size);
void print_spaces(int count);

int main()
{
    detab(8);

    return 0;
}

void detab(int tab_size)
{
    int spaces_to_tab = tab_size;
    char c;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\t':
            repeat(' ', spaces_to_tab);
            spaces_to_tab = 0;
            break;
        case '\n':
            putchar(c);
            spaces_to_tab = 0;
            break;
        default:
            putchar(c);
            spaces_to_tab--;
            break;
        }

        if (spaces_to_tab == 0)
        {
            spaces_to_tab = tab_size;
        }
    }
}
