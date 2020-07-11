/**
 * @description Revise the main routine of the longest-line program so it will correctly print the length of
 * arbitrary long input lines, and as much as possible of the text.
 */

#include <stdio.h>

#define BUFFER_LENGTH 1000
#define bool int

int get_line(char line[], int max_length);
bool is_line(char string[]);
void copy(char to[], char from[]);

int main()
{
    char line[BUFFER_LENGTH];
    char subline[BUFFER_LENGTH];
    char longest_line[BUFFER_LENGTH];

    int max_length = 0;
    int line_length = 0;
    int subline_length;
    int subline_id = 0;
    while ((subline_length = get_line(subline, BUFFER_LENGTH)) > 0)
    {
        subline_id++;
        line_length += subline_length;

        if (subline_id == 1)
        {
            copy(line, subline);
        }

        if (is_line(subline))
        {
            if (line_length > max_length)
            {
                max_length = line_length;
                copy(longest_line, line);
            }

            subline_id = 0;
            line_length = 0;
        }
    }

    if (max_length > 0)
    {
        printf("%s", longest_line);
    }

    return 0;
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

bool is_line(char string[])
{
    int i = 0;
    int c;
    while ((c = string[i]) != '\0')
    {
        i++;
    }

    return string[i - 1] == '\n';
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}