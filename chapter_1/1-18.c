/**
 * @description Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>

#define INPUT_BUFFER_LENGTH 8086
#define LINE_BUFFER_LENGTH 1024
#define bool int

void append(char target[], char source[], int position);
int get_line(char line[], int max_length);
int get_str_length(char string[]);
bool is_line(char string[]);
bool is_white_space(char c);
void trim_right(char string[]);

int main()
{
    char input[INPUT_BUFFER_LENGTH];
    char line[LINE_BUFFER_LENGTH];

    int position = 0;
    while (get_line(line, LINE_BUFFER_LENGTH) > 0)
    {
        trim_right(line);
        int length = get_str_length(line);
        // Non blank line
        if (length > 1)
        {
            append(input, line, position);
            position += length;
        }
    }

    printf("%s", input);
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
    return string[get_str_length(string) - 1] == '\n';
}

int get_str_length(char string[])
{
    int i = 0;
    int c;
    while ((c = string[i]) != '\0')
    {
        i++;
    }

    return i;
}

void trim_right(char string[])
{
    int length = get_str_length(string);

    for (int i = length - 1; i >= 0; i++)
    {
        if (!is_white_space(string[i]))
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

bool is_white_space(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

void append(char target[], char source[], int position)
{
    int i = 0;
    while ((target[i + position] = source[i]) != '\0')
    {
        ++i;
    }
}