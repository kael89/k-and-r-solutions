/**
 * @description Write a function rightrot(x,n) that returns the value of the integer x rotated
 * to the right by n positions. 
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_BITS 33

void print_test(unsigned x, int n, unsigned expected);
unsigned rightrot(unsigned x, int n);

int main()
{
    print_test(0b0, 0, 0b0);
    print_test(0b0, 1, 0);
    print_test(0b1, 1, 0b10000000000000000000000000000000);
    print_test(0b1, 2, 0b1000000000000000000000000000000);
    print_test(0b1001, 2, 0b1000000000000000000000000000010);
    print_test(0b11000, 2, 0b110);
    print_test(0b10101000, 3, 0b10101);
}

void print_test(unsigned x, int n, unsigned expected)
{
    char x_bits[MAX_BITS];
    char result_bits[MAX_BITS];
    char expected_bits[MAX_BITS];

    get_bits(x, x_bits);
    get_bits(rightrot(x, n), result_bits);
    get_bits(expected, expected_bits);

    printf("x: %10s, n: %d", x_bits, n);
    test_equal_strings(result_bits, expected_bits);
    printf("\n");
}

unsigned rightrot(unsigned x, int n)
{
    int bit_length = sizeof(unsigned) * 8;
    return (x << (bit_length - n)) | (x >> n);
}
