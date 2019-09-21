/**
 * As written, getint treats a + or - not followed by a digit as a valid representation of zero.
 * Fix it to push such a character back on the input.
 */

#include <ctype.h>
#include <stdio.h>

#define bool int
#define FALSE 0
#define TRUE 1
#define SIZE 2014

int getch(void);
void ungetch(int c);
int getint(int *);
bool is_valid_character(char c);
bool is_sign(char c);
bool is_sign_followed_by_digit(char c);
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

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    return c;
}

bool is_valid_character(char c)
{
    return isdigit(c) || c == EOF || is_sign_followed_by_digit(c);
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

bool is_sign(char c)
{
    return c == '+' || c == '-';
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