/**
 * @description Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 * @interactive
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_INPUT_SIZE 8086
#define MAX_LINE_SIZE 1024

void trim_right(char[]);

int main()
{
    char input[MAX_INPUT_SIZE];
    char line[MAX_LINE_SIZE];

    int position = 0;
    while (get_line(line, MAX_LINE_SIZE) > 0)
    {
        trim_right(line);
        int length = str_len(line);
        // Non blank line
        if (length > 1)
        {
            append(input, line, position);
            position += length;
        }
    }

    printf("%s", input);
}

void trim_right(char string[])
{
    int length = str_len(string);

    for (int i = length; i >= 0; i++)
    {
        if (!is_whitespace(string[i]))
        {
            if (is_line(string))
            {
                string[i + 1] = '\n';
            }
            break;
        }
        string[i] = '\0';
    }
}
