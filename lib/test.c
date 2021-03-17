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
    print_error("Not supported type - must be one of CHAR, DOUBLE, INT, STRING\n");
}

void print_unknown_array_type()
{
    print_error("Not supported array type - must be one of INT[]\n");
}

bool compare_typed_values(type t, void *a_p, void *b_p)
{
    switch (t)
    {
    case CHAR:
        return *((char *)a_p) == *((char *)b_p);
    case DOUBLE:;
        double a_double = *((double *)a_p);
        double b_double = *((double *)b_p);
        double maximum = fmax(fabs(a_double), fabs(b_double));
        return fabs(a_double - b_double) <= FLT_EPSILON * maximum;
    case INT:
        return *((int *)a_p) == *((int *)b_p);
    case STRING:
        return str_equals((char *)a_p, (char *)b_p);
    default:
        print_unknown_type();
        return FALSE;
    }
}

bool compare_typed_arrays(type t, void *a_p, void *b_p, int len)
{
    switch (t)
    {
    case INT:;
        for (int i = 0; i < len; i++)
        {
            if (((int *)a_p)[i] != ((int *)b_p)[i])
            {
                return FALSE;
            }
        }
        return TRUE;
    default:
        print_unknown_array_type();
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

void print_typed_array(type t, void *arr_p, int len)
{
    switch (t)
    {
    case INT:;
        for (int i = 0; i < len; i++)
        {
            printf("%d", ((int *)arr_p)[i]);
            if (i != len - 1)
            {
                printf(",");
            }
        }
        break;
    default:
        print_unknown_array_type();
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

bool test_equal_arrays(type t, char description[], void *received_p, int received_len, void *expected_p, int expected_len)
{
    bool are_equal = received_len == expected_len && compare_typed_arrays(t, received_p, expected_p, expected_len);

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
        print_typed_array(t, received_p, received_len);
        print_success("\n   Expected: ");
        print_typed_array(t, expected_p, expected_len);
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

bool test_equal_int_arrays(char description[], int received[], int received_len, int expected[], int expected_len)
{
    return test_equal_arrays(INT, description, received, received_len, expected, expected_len);
}

bool test_equal_strings(char description[], char received[], char expected[])
{
    return test_equal(STRING, description, received, expected);
}
