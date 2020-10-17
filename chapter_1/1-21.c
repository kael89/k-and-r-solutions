/**
 * @description Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
 * @interactive
 */

#include <stdio.h>
#include "../lib.h"

void entab(int tab_size);
void print_whitespace(int space_count, int tab_size);

int main()
{
    entab(8);

    return 0;
}

void entab(int tab_size)
{
    int space_count = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            space_count++;
        }
        else
        {
            print_whitespace(space_count, tab_size);
            space_count = 0;
            putchar(c);
        }
    }
}

void print_whitespace(int space_count, int tab_size)
{
    if (space_count > 0)
    {
        repeat('\t', space_count / tab_size);
        repeat(' ', space_count % tab_size);
    }
}
