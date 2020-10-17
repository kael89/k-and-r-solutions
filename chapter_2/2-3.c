/**
 * @description Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
 * through 9, a through f, and A through F.
 */

#include <stdio.h>
#include "../lib.h"

bool test(char hex[], int expected);
int htoi(char s[]);
int digit_to_int(char digit);

int main()
{
    bool success = TRUE;
    success &= test("0x9", 9);
    success &= test("0X9", 9);
    success &= test("0", 0);
    success &= test("9", 9);
    success &= test("A", 10);
    success &= test("F", 15);
    success &= test("99", 153);
    success &= test("FF", 255);

    return success ? 0 : 1;
}

bool test(char hex[], int expected)
{
    return test_equal_ints(hex, htoi(hex), expected);
}

int htoi(char s[])
{
    bool uses_prefix = s[0] == '0' && (s[1] == 'x' || s[1] == 'X');
    int i = uses_prefix ? 2 : 0;
    int j = 0;
    while (s[i] != '\0')
    {
        i++;
        j++;
    }
    i--;
    j--;

    int power = 1;
    int result = 0;
    while (j >= 0)
    {
        result += digit_to_int(s[i--]) * power;
        power *= 16;
        j--;
    }

    return result;
}

int digit_to_int(char digit)
{
    int value = '0' <= digit && digit <= '9' ? digit - '0' : digit - 'A' + 10;
    return value;
}
