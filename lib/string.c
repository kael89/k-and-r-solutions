#include <stdio.h>
#include "char.h"
#include "defs.h"

int str_len(char string[])
{
    int i = 0;
    while (string[i])
    {
        i++;
    }

    return i;
}

void append(char target[], char source[], int position)
{
    int i = 0;
    while ((target[i + position] = source[i]) != '\0')
    {
        ++i;
    }
}

void copy_str(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

bool is_line(char string[])
{
    return string[str_len(string) - 1] == '\n';
}

int get_line(char line[], int max_length)
{
    int i = 0;
    int c;
    while (i < max_length - 1 && (c = getchar()) != EOF)
    {
        line[i] = c;
        i++;
        if (c == '\n')
        {
            break;
        }
    }

    line[i] = '\0';
    return i;
}

void trim_right(char string[])
{
    int length = str_len(string);

    for (int i = length - 1; i >= 0; i++)
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