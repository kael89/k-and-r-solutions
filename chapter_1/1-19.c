/**
 * @description Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 * @interactive
 */

#include <stdio.h>
#include "../lib.h"

#define LINE_BUFFER_LENGTH 1024

int main()
{
    char line[LINE_BUFFER_LENGTH];

    while (get_line(line, LINE_BUFFER_LENGTH) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
}
