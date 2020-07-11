/**
 * @description Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value? 
 */

#include <stdio.h>
#include <ctype.h>
#include "../lib.h"

#define SIZE 2014

int getfloat(float *pn);
void print_numbers(float numbers[], int count);

int main()
{
    float array[SIZE];

    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int result = getfloat(&array[count]);
        if (result == EOF)
        {
            break;
        }
        if (result > 0)
        {
            count++;
        }
    }

    print_numbers(array, count);
    return 0;
}

int getfloat(float *pn)
{
    int c;
    int sign;

    while (isspace(c = getch()))
    {
    }
    if (!is_numeric_char(c))
    {
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (is_sign(c))
    {
        c = getch();
    }

    // Read whole number part
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + char_to_digit(c);
    }

    if (is_decimal_point(c))
    {
        c = getch();
    }

    // Read fractional part
    float multiplier = 1.0 / 10.0;
    while (isdigit(c))
    {
        *pn += (char_to_digit(c) * multiplier);
        multiplier /= 10.0;
        c = getch();
    }

    *pn *= sign;

    return c;
}

void print_numbers(float numbers[], int count)
{
    if (count > 0)
    {
        printf("%g", numbers[0]);
    }
    for (int i = 1; i < count; i++)
    {
        printf(" %g", numbers[i]);
    }

    putchar('\n');
}
