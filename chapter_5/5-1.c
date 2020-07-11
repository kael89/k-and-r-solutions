/**
 * @description As written, getint treats a + or - not followed by a digit as a valid representation of zero.
 * Fix it to push such a character back on the input.
 */

#include <ctype.h>
#include <stdio.h>
#include "../lib.h"

#define SIZE 2014

int getint(int *);
void print_numbers(int numbers[], int count);

int main()
{
    int array[SIZE];

    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int result = getint(&array[count]);
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

int getint(int *pn)
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

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    return c;
}

void print_numbers(int numbers[], int count)
{
    if (count > 0)
    {
        printf("%d", numbers[0]);
    }
    for (int i = 1; i < count; i++)
    {
        printf(" %d", numbers[i]);
    }

    putchar('\n');
}
