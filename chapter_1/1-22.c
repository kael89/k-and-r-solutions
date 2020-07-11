/**
 * @description Write a program to ``fold'' long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of input.
 * Make sure your program does something intelligent with very long lines,
 * and if there are no blanks or tabs before the specified column.
 */

#define TAB_SIZE 8
#define N 2

#include <stdio.h>

int main()
{
    int max_line_length = TAB_SIZE * N;

    int char_count = 0;
    int spaces_to_tab = TAB_SIZE;
    char whitespace_buffer[TAB_SIZE];
    int buffer_index = 0;

    char c;
    while ((c = getchar()) != EOF)
    {
        char_count += c == '\t' ? spaces_to_tab : 1;
        if (c == '\n' || char_count >= max_line_length)
        {
            putchar(c);
            if (c != '\n')
            {
                putchar('\n');
            }
            char_count = 0;
            spaces_to_tab = TAB_SIZE;
            buffer_index = 0;
            continue;
        }

        if (c == '\t' || c == ' ')
        {
            whitespace_buffer[buffer_index] = c;
            buffer_index++;
        }
        else
        {
            for (int i = 0; i < buffer_index; i++)
            {
                putchar(whitespace_buffer[i]);
            }
            buffer_index = 0;

            putchar(c);
        }

        spaces_to_tab--;
        if (c == '\t' || spaces_to_tab == 0)
        {
            spaces_to_tab = TAB_SIZE;
        }
    }
}