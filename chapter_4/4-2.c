/**
 * @description Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally signed exponent.
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include "../lib.h"

bool test(char[], float);

int main()
{
    bool success = TRUE;

    printf("Integers\n");
    success &= test("0", 0.0);
    success &= test("1", 1.0);
    success &= test("+1", 1.0);
    success &= test("-1", -1.0);
    success &= test("99", 99.0);

    printf("Decimals\n");
    success &= test("0.1", 0.1);
    success &= test("+0.1", 0.1);
    success &= test("-0.1", -0.1);
    success &= test(".1", 0.1);
    success &= test("+.1", 0.1);
    success &= test("-.1", -0.1);
    success &= test("0.001", 0.001);

    printf("Scientific notation\n");
    success &= test("0e1", 0.0);
    success &= test("1e1", 10.0);
    success &= test("1E1", 10.0);
    success &= test("1e+1", 10.0);
    success &= test("1e-1", 0.1);
    success &= test("-99.0101e3", -99010.1);

    return success ? 0 : 1;
}

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = s[i] == '-' ? -1 : 1;
    if (is_sign(s[i]))
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    double exp = 1.0;
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        int exp_sign = s[i] == '-' ? -1 : 1;
        if (is_sign(s[i]))
        {
            i++;
        }

        double exp_val;
        for (exp_val = 0.0; isdigit(s[i]); i++)
        {
            exp_val = 10.0 * exp_val + (s[i] - '0');
        }
        exp = pow(10.0, exp_sign * exp_val);
    }

    return sign * val / power * exp;
}

bool test(char s[], float expected)
{
    return test_equal_doubles(s, atof(s), expected);
}
