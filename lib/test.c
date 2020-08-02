#include <stdio.h>
#include "string.h"

#define ANSI_COLOR_GREEN "\033[0;32m"
#define ANSI_COLOR_RED "\033[0;31m"
#define ANSI_COLOR_DEFAULT "\033[0m"

#define BUFFER_LENGTH 1024

void log_with_color(char message[], char ansi_color[])
{
    printf("%s%s%s", ansi_color, message, ANSI_COLOR_DEFAULT);
}

void log_success(char message[])
{
    log_with_color(message, ANSI_COLOR_GREEN);
}

void log_error(char message[])
{
    log_with_color(message, ANSI_COLOR_RED);
}

void test_equal_ints(int results, int expected)
{
    if (results == expected)
    {
        log_success(" ✔");
    }
    else
    {
        char str[BUFFER_LENGTH];
        sprintf(str, " ❌\n\tResults: %d, Expected: %d", results, expected);
        log_error(str);
    }
}

void test_equal_strings(char results[], char expected[])
{
    if (str_equals(results, expected))
    {
        log_success(" ✔");
    }
    else
    {
        char str[BUFFER_LENGTH];
        sprintf(str, " ❌\n\tResults: %s, Expected: %s", results, expected);
        log_error(str);
    }
}
