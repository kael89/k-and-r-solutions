/**
 * @description In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of bitcount. 
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_BITS 32

int bitcount(unsigned x);
void print_test(unsigned input, int expected);

int main()
{
    print_test(0b0, 0);
    print_test(0b1, 1);
    print_test(0b10, 1);
    print_test(0b11, 2);
    print_test(0b1000, 1);
    print_test(0b1001, 2);
    print_test(0b1010, 2);
    print_test(0b1110, 3);
    print_test(0b1011, 3);
    print_test(0b1111, 4);
}

void print_test(unsigned input, int expected)
{
    char bits[MAX_BITS];

    get_bits(input, bits);
    printf("Input: %4s, Expected: %d", bits, expected);
    test_equal_ints(bitcount(input), expected);
    printf("\n");
}

int bitcount(unsigned x)
{
    int b = 0;
    while (x != 0)
    {
        x &= (x - 1);
        b++;
    }

    return b;
}