#include <stdio.h>
#include "string.h"

#define ANSI_COLOR_GREEN "\033[0;32m"
#define ANSI_COLOR_RED "\033[0;31m"
#define ANSI_COLOR_DEFAULT "\033[0m"

void print_with_color(char message[], char ansi_color[])
{
    printf("%s%s%s", ansi_color, message, ANSI_COLOR_DEFAULT);
}

void print_success(char message[])
{
    print_with_color(message, ANSI_COLOR_GREEN);
}

void print_error(char message[])
{
    print_with_color(message, ANSI_COLOR_RED);
}

void print_int_array(int integers[], int length)
{
    printf("{");
    for (int i = 0; i < length; i++)
    {
        printf(" %d", integers[i]);
        if (i != length - 1)
        {
            putchar(',');
        }
    }
    printf(" }");
}