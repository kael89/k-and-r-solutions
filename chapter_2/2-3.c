/**
 * @description Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
 * through 9, a through f, and A through F. 
 */

#include <stdio.h>
#include "../lib.h"

void print_test(char hex[], char expected[]);
int htoi(char s[]);
int digit_to_int(char digit);

int main()
{
    print_test("0x9", "9");
    print_test("0X9", "9");
    print_test("0", "0");
    print_test("9", "9");
    print_test("A", "10");
    print_test("F", "15");
    print_test("99", "153");
    print_test("FF", "255");

    return 0;
}

void print_test(char hex[], char expected[])
{
    printf("Hex: %6s, Dec: %4d, Expected: %4s\n", hex, htoi(hex), expected);
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
