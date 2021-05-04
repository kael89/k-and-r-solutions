/**
 * @description Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value?
 * @interactive
 */

#include <ctype.h>
#include <stdio.h>
#include "../lib.h"

#define DECIMAL_POINT '.'

int getfloat(float *pn);

int main()
{
    float n;
    int result;

    bool non_int_input = FALSE;
    do
    {
        result = getfloat(&n);
        if (result == 0)
        {
            if (!non_int_input)
            {
                non_int_input = TRUE;
                printf("\nNon float: ");
            }
            printf("%c", getch());
        }
        else if (result != EOF)
        {
            non_int_input = FALSE;
            printf("\nFloat: %g", n);
        }
    } while (result != EOF);
}

int getfloat(float *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && !is_sign(c) && c != DECIMAL_POINT)
    {
        ungetch(c);
        return 0;
    }

    sign = c == '-' ? -1 : 1;
    if (is_sign(c))
    {
        int sign_char = c;
        c = getch();
        if (!isdigit(c) && c != DECIMAL_POINT)
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

    if (c == DECIMAL_POINT)
    {
        c = getch();
        for (float decimal_power = 1.0; isdigit(c); c = getch())
        {
            decimal_power /= 10.0;
            *pn = *pn + (c - '0') * decimal_power;
        }
    }

    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
