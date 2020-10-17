#include <stdio.h>

#define MAX_BITS 33

void get_bits(unsigned int num, char result[])
{
    char bits_reverse[MAX_BITS];
    int i = 0;
    do
    {
        bits_reverse[i++] = (num % 2) + '0';
        num /= 2;
    } while (num > 0);
    i--;

    int j;
    for (j = 0; i >= 0; j++, i--)
    {
        result[j] = bits_reverse[i];
    }
    result[j] = '\0';
}
