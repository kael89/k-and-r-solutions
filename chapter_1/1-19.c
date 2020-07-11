/**
 * @description Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time. 
 */

#include <stdio.h>
#include "../lib.h"

#define LINE_BUFFER_LENGTH 1024

void reverse(char s[]);

int main()
{
    char line[LINE_BUFFER_LENGTH];

    while (get_line(line, LINE_BUFFER_LENGTH) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
}

void reverse(char s[])
{

    int len;
    len = str_len(s);
    if (s[len - 1] == '\n')
    {
        len--;
    }

    for (int i = 0, j = len - 1; i < (len - 1) / 2; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}