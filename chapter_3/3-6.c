/**
 * @description Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded with blanks
 * on the left if necessary to make it wide enough
 */

#include <stdio.h>
#include "../lib.h"

void itoa(int n, char s[], int w);
bool test(int n, int w, char expected[]);

int main()
{
    bool success = TRUE;

    printf("Values\n");
    test(0, 0, "0");
    test(1, 0, "1");
    test(9, 0, "9");
    test(10, 0, "10");
    test(999, 0, "999");
    test(1234, 0, "1234");

    printf("Padding\n");
    test(0, 2, "00");
    test(0, 10, "0000000000");
    test(1, 0, "1");
    test(1, 1, "1");
    test(1, 2, "01");
    test(10, 10, "0000000010");

    return success ? 0 : 1;
}

void itoa(int n, char s[], int w)
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

    for (; i < w; i++)
    {
        s[i] = '0';
    }

    s[i] = '\0';
    reverse(s);
}

bool test(int n, int w, char expected[])
{
    char result[100] = "";
    char description[50] = "";

    itoa(n, result, w);
    sprintf(description, "n: %d, w: %d", n, w);
    return test_equal_strings(description, result, expected);
}
