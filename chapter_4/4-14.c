/**
 * @description Define a macro swap(t,x,y) that interchanges two arguments of type t.
 * (Block structure will help.)
 */

#include <stdio.h>
#include "../lib.h"

bool test_ints();
bool test_doubles();
bool test_name_conflict();

#define swap(t, x, y) \
    {                 \
        t temp = x;   \
        x = y;        \
        y = temp;     \
    }

int main()
{
    bool success = TRUE;

    success &= test_ints();
    success &= test_doubles();
    success &= test_name_conflict();

    return success ? 0 : 1;
}

bool test_ints()
{
    int a = 1;
    int b = 2;
    swap(int, a, b);
    int received[] = {a, b};
    int expected[] = {2, 1};

    return test_equal_int_arrays("integers", received, 2, expected, 2);
}

bool test_doubles()
{
    double a = 1.1;
    double b = 2.2;
    swap(double, a, b);
    double received[] = {a, b};
    double expected[] = {2.2, 1.1};

    return test_equal_double_arrays("doubles", received, 2, expected, 2);
}

bool test_name_conflict()
{
    int temp = 1;
    int y = 2;
    swap(int, temp, y);
    int received[] = {temp, y};
    int expected[] = {1, 2};

    char description[] = "no conflict between variables used in the macro invocation and the ones in its internal implementation";
    return test_equal_int_arrays(description, received, 2, expected, 2);
}
