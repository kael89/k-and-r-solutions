/**
 * @description Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>
#include "../lib.h"

#define INPUT_BUFFER_LENGTH 8086
#define LINE_BUFFER_LENGTH 1024

void trim_right(char string[]);

int main()
{
    char input[INPUT_BUFFER_LENGTH];
    char line[LINE_BUFFER_LENGTH];

    int position = 0;
    while (read_line(line, LINE_BUFFER_LENGTH) > 0)
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
