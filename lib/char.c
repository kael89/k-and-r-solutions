#include <stdio.h>
#include <ctype.h>
#include "defs.h"
#include "stack.h"

int char_to_digit(char c)
{
    return c - '0';
}

bool is_decimal_point(char c)
{
    return c == DECIMAL_POINT;
}

bool is_sign(char c)
{
    return c == '+' || c == '-';
}

bool is_sign_followed_by_digit(char c)
{
    if (!is_sign(c))
    {
        return FALSE;
    }

    char next_c = getch();
    ungetch(next_c);

    return isdigit(next_c);
}

bool is_numeric_char(char c)
{
    return isdigit(c) || c == EOF || c == DECIMAL_POINT || is_sign_followed_by_digit(c);
}

bool is_whitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

void repeat(char c, int count)
{
    for (int i = 0; i < count; i++)
    {
        putchar(c);
    }
}
