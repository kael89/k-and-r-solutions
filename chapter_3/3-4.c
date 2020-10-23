/**
 * @description  In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain
 * why not. Modify it to print that value correctly, regardless of the machine on which it runs.
 */

#include <limits.h>
#include <stdio.h>
#include "../lib.h"

void itoa(int n, char s[]);
bool test(int n, char expected[]);

int main()
{
    bool success = TRUE;
    printf("%d\n", INT_MAX);

    printf("Values\n");
    test(0, "0");
    test(1, "1");
    test(9, "9");
    test(10, "10");
    test(999, "999");
    test(1234, "1234");

    printf("Max value\n");
    test(-2147483647, "-2147483647");

    return success ? 0 : 1;
}

void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
    {
        n = -n;
    }

    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

bool test(int n, char expected[])
{
    char result[100] = "";
    itoa(n, result);
    return test_equal_strings(expected, result, expected);
}
