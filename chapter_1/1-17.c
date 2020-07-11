/**
 * @description Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define MAX_LINE 1024
#define PRINT_THRESHOLD 80

void print_line(char line[]);

int main()
{
    char line_buffer[MAX_LINE];

    char c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        line_buffer[i++] = c;
        if (c == '\n')
        {
            if (i > PRINT_THRESHOLD)
            {
                line_buffer[i] = '\0';
                printf("%s", line_buffer);
            }
            i = 0;
        }
    }
}
