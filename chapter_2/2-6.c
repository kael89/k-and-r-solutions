/**
 * @description Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
 * position p set to the rightmost n bits of y, leaving the other bits unchanged. 
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_BITS 15

void print_test(unsigned x, int p, int n, unsigned y, unsigned expected);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    print_test(0b0, 0, 1, 0b1, 0b1);
    print_test(0b1, 0, 1, 0b0, 0b0);
    print_test(0b1001, 0, 1, 0b0, 0b1000);
    print_test(0b11101101, 5, 2, 0b10110011, 0b11111101);
    print_test(0b10000001, 6, 3, 0b11101, 0b11010001);
    print_test(0b1, 3, 4, 0b100100, 0b00100);
}

void print_test(unsigned x, int p, int n, unsigned y, unsigned expected)
{
    char x_bits[MAX_BITS];
    char y_bits[MAX_BITS];
    char result_bits[MAX_BITS];
    char expected_bits[MAX_BITS];

    get_bits(x, x_bits);
    get_bits(y, y_bits);
    get_bits(setbits(x, p, n, y), result_bits);
    get_bits(expected, expected_bits);

    printf("x: %10s, p: %d, n: %d, y: %10s, Results: %10s, Expected: %10s\n", x_bits, p, n, y_bits, result_bits, expected_bits);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    int keep_right_bits_mask = ~(~0 << n);
    int left_shift = (p - n + 1);

    unsigned replacement = (y & keep_right_bits_mask) << left_shift;
    unsigned removal_mask = ~(keep_right_bits_mask << left_shift);
    return (x & removal_mask) | replacement;
}
