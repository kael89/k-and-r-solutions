/**
 * @description Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. 
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_BITS 32

void print_test(unsigned x, int p, int n, unsigned expected);
unsigned invert(unsigned x, int p, int n);

int main()
{
    print_test(0b0, 0, 1, 0b1);
    print_test(0b1, 0, 1, 0b0);
    print_test(0b1001, 0, 1, 0b1000);
    print_test(0b11101101, 5, 2, 0b11011101);
    print_test(0b10000001, 6, 3, 0b11110001);
    print_test(0b1, 3, 4, 0b1110);
    print_test(0b1, 7, 2, 0b11000001);
}

void print_test(unsigned x, int p, int n, unsigned expected)
{
    char x_bits[MAX_BITS];
    char result_bits[MAX_BITS];
    char expected_bits[MAX_BITS];

    get_bits(x, x_bits);
    get_bits(invert(x, p, n), result_bits);
    get_bits(expected, expected_bits);

    printf("x: %10s, p: %d, n: %d", x_bits, p, n);
    test_equal_strings(result_bits, expected_bits);
    printf("\n");
}

unsigned invert(unsigned x, int p, int n)
{
    int keep_mask = ~(~0 << n) << (p - n + 1);
    int removal_mask = ~keep_mask;
    return (x & removal_mask) | (~x & keep_mask);
}