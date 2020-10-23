/**
 * @description Write a program to determine the ranges of char, short, int, and long
* variables, both signed and unsigned, by printing appropriate values from standard headers
* and by direct computation. Harder if you compute them: determine the ranges of the various
* floating-point types. 
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

void from_headers();
void calculated();
void get_signed_limits(int, double[]);
void get_unsigned_limits(int, double[]);

int main()
{
    printf("\n/* From Headers */\n");
    from_headers();
    printf("\n/* Calculated */\n");
    calculated();

    return 0;
}

void from_headers()
{
    printf("(signed) char:      [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char:      [%d, %d]\n", 0, UCHAR_MAX);

    printf("(signed) int:       [%d, %d]\n", INT_MIN, INT_MAX);
    printf("unsigned int:       [%u, %u]\n", 0, UINT_MAX);

    printf("(signed) short int: [%hd, %hd]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int: [%u, %u]\n", 0, USHRT_MAX);

    printf("(signed) long int:  [%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int:  [%d, %lu]\n", 0, ULONG_MAX);

    printf("float (+):          [%g, %g]\n", FLT_MIN, FLT_MAX);
    printf("float (-):          [%g, %g]\n", -FLT_MIN, -FLT_MAX);
    printf("double: (+)         [%g, %g]\n", DBL_MIN, DBL_MAX);
    printf("double: (-)         [%g, %g]\n", -DBL_MIN, -DBL_MAX);
    printf("long double (+):    [%Lg, %Lg]\n", LDBL_MIN, LDBL_MAX);
    printf("long double (-):    [%Lg, %Lg]\n", LDBL_MIN, LDBL_MAX);
}

void calculated()
{
    double limits[4];

    // get_signed_limits(sizeof(char), limits);
    // printf("(signed) char:      [%d, %d]\n", (char)limits[0], (char)limits[1]);
    // get_unsigned_limits(sizeof(unsigned char), limits);
    // printf("unsigned char:      [%u, %u]\n", (unsigned char)limits[0], (unsigned char)limits[1]);

    // get_signed_limits(sizeof(int), limits);
    // printf("(signed) int:       [%d, %d]\n", (int)limits[0], (int)limits[1]);
    // get_unsigned_limits(sizeof(unsigned int), limits);
    // printf("unsigned int:       [%u, %u]\n", (unsigned int)limits[0], (unsigned int)limits[1]);

    // get_signed_limits(sizeof(short), limits);
    // printf("(signed) short int: [%hd, %hd]\n", (short)limits[0], (short)limits[1]);
    // get_unsigned_limits(sizeof(unsigned short), limits);
    // printf("unsigned short int: [%u, %u]\n", (unsigned short)limits[0], (unsigned short)limits[1]);

    // get_signed_limits(sizeof(long), limits);
    // printf("(signed) long int:  [%ld, %ld]\n", (long)limits[0], (long)limits[1]);
    get_unsigned_limits(sizeof(unsigned long), limits);
    printf("unsigned long int:  [%lu, %lu]\n", (unsigned long)limits[0], (unsigned long)limits[1]);
}

void get_signed_limits(int bytes, double limits[])
{
    double max = pow(2, bytes * 8 - 1) - 1;
    limits[0] = -1 * max - 1;
    limits[1] = max;
}

void get_unsigned_limits(int bytes, double limits[])
{
    limits[0] = 0;
    limits[1] = pow(2, bytes * 8) - 1;
}
