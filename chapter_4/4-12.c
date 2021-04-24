/**
 * @description  Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string by calling a recursive routine.
 */

#include <stdio.h>
#include "../lib.h"

#include <stdio.h>
#include "../lib.h"

void itoa(int n, char s[]);
bool test(int n, char expected[]);

int main()
{
    bool success = TRUE;

    success &= test(0, "0");
    success &= test(1, "1");
    success &= test(9, "9");
    success &= test(10, "10");
    success &= test(999, "999");
    success &= test(1234, "1234");
    success &= test(-0, "0");
    success &= test(-1, "-1");
    success &= test(-1234, "-1234");

    return success ? 0 : 1;
}

void itoa(int n, char s[])
{
    static int i = 0;
    static int recursion_id = 0;

    recursion_id++;

    if (n < 0)
    {
        s[i++] = '-';
        n *= -1;
    }

    int higherDigits = n / 10;
    if (higherDigits > 0)
    {
        itoa(higherDigits, s);
    }
    s[i++] = n % 10 + '0';

    recursion_id--;
    if (recursion_id == 0)
    {
        s[i] = '\0';
        // Restore i for future calls
        i = 0;
    }
}

bool test(int n, char expected[])
{
    char result[100] = "";
    char description[50] = "";

    itoa(n, result);
    sprintf(description, "%d", n);
    return test_equal_strings(description, result, expected);
}
