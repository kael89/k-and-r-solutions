/**
 * @description Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16) formats s as a
 * hexadecimal integer in s.
 */

#include <stdio.h>
#include "../lib.h"

bool test(int, int, char[]);

int main()
{
    bool success = TRUE;

    printf("Hex values\n");
    success &= test(0, 16, "0");
    success &= test(1, 16, "1");
    success &= test(10, 16, "A");
    success &= test(15, 16, "F");
    success &= test(16, 16, "10");
    success &= test(26, 16, "1A");
    success &= test(31, 16, "1F");

    printf("Sign\n");
    success &= test(-0, 16, "0");
    success &= test(+0, 16, "0");
    success &= test(-1, 16, "-1");
    success &= test(+1, 16, "1");

    printf("Other bases\n");
    success &= test(8, 8, "10");
    success &= test(9, 8, "11");
    success &= test(8, 9, "8");
    success &= test(9, 9, "10");
    success &= test(10, 9, "11");
    success &= test(25, 26, "P");
    success &= test(26, 26, "10");
    success &= test(27, 26, "11");
    success &= test(649, 26, "OP");

    return success ? 0 : 1;
}

char get_digit(int n, int b)
{
    int value = n % b;

    if (value > 9)
    {
        value -= 10;
        return value + 'A';
    }
    return value + '0';
}

void itob(int n, char s[], int b)
{
    int i = 0;
    bool is_negative = FALSE;

    if (n < 0)
    {
        is_negative = TRUE;
        n = -n;
    }

    do
    {
        s[i++] = get_digit(n, b);
    } while ((n /= b) > 0);

    if (is_negative)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

bool test(int n, int b, char expected[])
{
    char result[100] = "";
    itob(n, result, b);
    return test_equal_strings(expected, result, expected);
}
