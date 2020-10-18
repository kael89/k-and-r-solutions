/**
 * @description Write a function rightrot(x,n) that returns the value of the integer x rotated
 * to the right by n positions.
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_BITS 33

bool test(unsigned x, int n, unsigned expected);
unsigned rightrot(unsigned x, int n);

int main()
{
    bool success = TRUE;
    success &= test(0b0, 0, 0b0);
    success &= test(0b0, 1, 0);
    success &= test(0b1, 1, 0b10000000000000000000000000000000);
    success &= test(0b1, 2, 0b1000000000000000000000000000000);
    success &= test(0b1001, 2, 0b1000000000000000000000000000010);
    success &= test(0b11000, 2, 0b110);
    success &= test(0b10101000, 3, 0b10101);

    return success ? 0 : 1;
}

bool test(unsigned x, int n, unsigned expected)
{
    char x_bits[MAX_BITS];
    char result_bits[MAX_BITS];
    char expected_bits[MAX_BITS];

    get_bits(x, x_bits);
    get_bits(rightrot(x, n), result_bits);
    get_bits(expected, expected_bits);

    char description[50] = "";
    sprintf(description, "x: %s, n: %d", x_bits, n);
    return test_equal_strings(description, result_bits, expected_bits);
}

unsigned rightrot(unsigned x, int n)
{
    int bit_length = sizeof(unsigned) * 8;
    return (x << (bit_length - n)) | (x >> n);
}
