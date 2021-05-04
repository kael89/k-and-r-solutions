/**
 * @description As written, getint treats a + or - not followed by a digit as a
 * valid representation of zero. Fix it to push such a character back on the input.
 * @interactive
 */

#include <ctype.h>
#include <stdio.h>
#include "../lib.h"

int getint(int *pn);

int main()
{
    int n;
    int result;

    bool non_int_input = FALSE;
    do
    {
        result = getint(&n);
        if (result == 0)
        {
            if (!non_int_input)
            {
                non_int_input = TRUE;
                printf("\nNon integer: ");
            }
            printf("%c", getch());
        }
        else if (result != EOF)
        {
            non_int_input = FALSE;
            printf("\nInteger: %d", n);
        }
    } while (result != EOF);
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && !is_sign(c))
    {
        ungetch(c);
        return 0;
    }

    sign = c == '-' ? -1 : 1;
    if (is_sign(c))
    {
        int sign_char = c;
        c = getch();
        if (!isdigit(c))
        {
            ungetch(c);
            ungetch(sign_char);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
