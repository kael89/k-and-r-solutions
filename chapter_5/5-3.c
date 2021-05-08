/**
 * @description Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_LENGTH 32

bool test(char[], char[], char[]);

int main()
{
    bool success = TRUE;
    success &= test("", "", "");
    success &= test("a", "a", "aa");
    success &= test("a", "b", "ab");
    success &= test("", "beta", "beta");
    success &= test("alpha", "beta", "alphabeta");
    success &= test("alpha", "", "alpha");

    return success ? 0 : 1;
}

void _strcat(char *s, char *t)
{
    while (*s != '\0')
    {
        s++;
    }
    while ((*s++ = *t++) != '\0')
        ;
}

bool test(char s_input[], char t_input[], char expected[])
{
    char s_description[MAX_LENGTH] = "";
    char t_description[MAX_LENGTH] = "";
    char description[2 * MAX_LENGTH + 10] = "";

    stringify(s_description, s_input);
    stringify(t_description, t_input);
    sprintf(description, "%s + %s", s_description, t_description);

    char s[MAX_LENGTH] = "";
    char t[MAX_LENGTH] = "";
    // Need to copy input in a new array, cause the input is provided as string literals
    copy_str(s, s_input);
    copy_str(t, t_input);

    _strcat(s, t);
    return test_equal_strings(description, s, expected);
}
