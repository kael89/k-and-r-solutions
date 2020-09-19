/**
 * @description  Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.
 */

#include <stdio.h>
#include "../lib.h"

int lower(int c);
void print_test(char input, char expected);

int main()
{
    print_test('A', 'a');
    print_test('a', 'a');
    print_test('Z', 'z');
    print_test('z', 'z');
}

void print_test(char input, char expected)
{
    printf("Input: %c, Expected: %c", input, expected);
    test_equal_chars(lower(input), expected);
    printf("\n");
}

int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
