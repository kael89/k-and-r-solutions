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

bool test_equal_ints(char description[], int received, int expected)
{
    if (received == expected)
    {
        log_success(" ✔");
        printf(" %s\n", description);
        return TRUE;
    }
    else
    {
        log_error("❌");
        printf(" %s\n", description);
        log_error("   Received: ");
        printf("%d", received);
        log_success("\n   Expected: ");
        printf("%d", expected);
        printf("\n");
        return FALSE;
    }
}

bool test_equal_chars(char description[], char received, char expected)
{
    if (received == expected)
    {
        log_success(" ✔");
        printf(" %s\n", description);
        return TRUE;
    }
    else
    {
        log_error("❌");
        printf(" %s\n", description);
        log_error("   Received: ");
        printf("%c", received);
        log_success("\n   Expected: ");
        printf("%c", expected);
        printf("\n");
        return FALSE;
    }
}

bool test_equal_strings(char description[], char received[], char expected[])
{
    if (str_equals(received, expected))
    {
        log_success("✔ ");
        printf(" %s\n", description);
        return TRUE;
    }
    else
    {
        log_error("❌");
        printf(" %s\n", description);
        log_error("   Received: ");
        printf("%s", received);
        log_success("\n   Expected: ");
        printf("%s", expected);
        printf("\n");
        return FALSE;
    }
}
