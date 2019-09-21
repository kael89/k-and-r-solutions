/**
 * As written, getint treats a + or - not followed by a digit as a valid representation of zero.
 * Fix it to push such a character back on the input.
 */

#include <ctype.h>
#include <stdio.h>

#define bool int
#define DECIMAL_POINT '.'
#define FALSE 0
#define TRUE 1
#define SIZE 2014

int getch(void);
void ungetch(int c);
int getfloat(float *);
int char_to_digit(char c);
bool is_decimal_point(char c);
bool is_valid_character(char c);
bool is_sign(char c);
bool is_sign_followed_by_digit(char c);
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
        ;
    }
    if (!is_valid_character(c))
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

bool is_decimal_point(char c)
{
    return c == DECIMAL_POINT;
}

bool is_valid_character(char c)
{
    return isdigit(c) || c == EOF || c == DECIMAL_POINT || is_sign_followed_by_digit(c);
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

int char_to_digit(char c)
{
    return c - '0';
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

#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch too many characters");
    }
    else
    {
        buf[bufp++] = c;
    }
}
