/**
 * @description Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define PRINTABLE_LINE_LIMIT 80

void print_line(char line[]);

int main()
{
    int max_line_index = PRINTABLE_LINE_LIMIT - 1;
    char line_buffer[max_line_index + 1];

    char c;
    int index = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            if (index > max_line_index)
            {
                putchar('\n');
            }
            index = 0;
            continue;
        }

        if (index > max_line_index)
        {
            putchar(c);
        }
        else
        {
            line_buffer[index] = c;
            if (index == max_line_index)
            {
                printf("%s", line_buffer);
            }
        }

        index++;
    }
}
