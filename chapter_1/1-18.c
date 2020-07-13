/**
 * @description Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_INPUT_SIZE 8086
#define MAX_LINE_SIZE 1024

void trim_right(char string[]);

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
