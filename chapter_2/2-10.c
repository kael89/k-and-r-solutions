/**
 * @description  Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 */

#include <stdio.h>
#include "../lib.h"

int lower(int c);
bool test(char input, char expected);

int main()
{
    bool success = TRUE;
    success &= test('A', 'a');
    success &= test('a', 'a');
    success &= test('Z', 'z');
    success &= test('z', 'z');

    return success;
}

bool test(char input, char expected)
{
    char description[2] = {input, '\0'};
    return test_equal_chars(description, lower(input), expected);
}

int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
