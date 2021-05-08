/**
 * @description Write a recursive version of the function reverse(s),which reverses
 * the string s in place.
 */

#include <stdio.h>
#include "../lib.h"

bool test(char s[], char expected[]);

int main()
{
    bool success = TRUE;

    success &= test("", "");
    success &= test("a", "a");
    success &= test("ab", "ba");
    success &= test("aba", "aba");
    success &= test("alpha beta", "ateb ahpla");

    return success ? 0 : 1;
}

void swap(char s[], int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void _reverse(char s[])
{
    static int start = -1;
    static int end = -1;

    // Initial recursion
    if (start == -1)
    {
        start = 0;
        while (s[++end] != '\0')
        {
        }
        end--;
    }

    if (start < end)
    {
        swap(s, start++, end--);
        _reverse(s);
    }
    else
    {
        // Restore variables for future calls
        start = -1;
        end = -1;
    }
}

bool test(char s[], char expected[])
{
    char input[100];
    char received[100];
    copy_str(input, s);
    copy_str(received, s);

    _reverse(received);
    return test_equal_strings(input, received, expected);
}
