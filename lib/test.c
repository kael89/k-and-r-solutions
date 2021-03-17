#include <float.h>
#include <math.h>
#include <stdio.h>
#include "output.h"
#include "string.h"

typedef enum
{
    CHAR,
    DOUBLE,
    INT,
    STRING,
} type;

void print_unknown_type()
{
    print_error("Not supported type - must be one of CHAR, INT, STRING\n");
}

bool compare_typed_values(type t, void *a_p, void *b_p)
{
    switch (t)
    {
    case CHAR:
        return *((char *)a_p) == *((char *)b_p);
    case DOUBLE:;
        double a = *((double *)a_p);
        double b = *((double *)b_p);
        double maximum = fmax(fabs(a), fabs(b));
        return fabs(a - b) <= FLT_EPSILON * maximum;
    case INT:
        return *((int *)a_p) == *((int *)b_p);
    case STRING:
        return str_equals((char *)a_p, (char *)b_p);
    default:
        print_unknown_type();
        return FALSE;
    }
}

void print_typed_value(type t, void *value_p)
{
    switch (t)
    {
    case CHAR:
        printf("%c", *((char *)value_p));
        break;
    case DOUBLE:
        printf("%f", *((double *)value_p));
        break;
    case INT:
        printf("%d", *((int *)value_p));
        break;
    case STRING:
        printf("%s", (char *)value_p);
        break;
    default:
        print_unknown_type();
        break;
    }
}

bool test_equal(type t, char description[], void *received_p, void *expected_p)
{
    bool are_equal = compare_typed_values(t, received_p, expected_p);

    if (are_equal)
    {
        print_success(" ✔");
        printf(" %s\n", description);
        return TRUE;
    }
    else
    {
        print_error("❌");
        printf(" %s\n", description);
        print_error("   Received: ");
        print_typed_value(t, received_p);
        print_success("\n   Expected: ");
        print_typed_value(t, expected_p);
        printf("\n");
        return FALSE;
    }
}

bool test_equal_chars(char description[], char received, char expected)
{
    return test_equal(CHAR, description, &received, &expected);
}

bool test_equal_doubles(char description[], double received, double expected)
{
    return test_equal(DOUBLE, description, &received, &expected);
}

bool test_equal_ints(char description[], int received, int expected)
{
    return test_equal(INT, description, &received, &expected);
}

bool test_equal_strings(char description[], char received[], char expected[])
{
    return test_equal(STRING, description, received, expected);
}
