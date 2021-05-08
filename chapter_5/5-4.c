/**
 * @description Write the function strend(s,t), which returns 1 if the string t occurs
 * at the end of the string s, and zero otherwise.
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_LENGTH 32

bool test(char[], char[], int);

int main()
{
    bool success = TRUE;
    success &= test("", "", 1);
    success &= test("a", "", 1);
    success &= test("", "a", 0);
    success &= test("a", "a", 1);
    success &= test("aa", "a", 1);
    success &= test("ab", "b", 1);
    success &= test("ab", "a", 0);
    success &= test("a", "aa", 0);
    success &= test("alpha beta", "lpha beta", 1);
    success &= test("alpha beta", "alpha beta", 1);
    success &= test("alpha beta", "blpha beta", 0);
    success &= test("alpha", "alph", 0);

    return success ? 0 : 1;
}

int strend(char *s, char *t)
{
    int s_len = 0;
    int t_len = 0;

    while (*s++ != '\0')
    {
        s_len++;
    }
    s--;
    while (*t++ != '\0')
    {
        t_len++;
    }
    t--;

    while (*--s == *--t && s_len > 0 && t_len > 0)
    {
        s_len--;
        t_len--;
    }

    return t_len == 0;
}

bool test(char s_input[], char t_input[], int expected)
{
    char s_description[MAX_LENGTH] = "";
    char t_description[MAX_LENGTH] = "";
    char description[2 * MAX_LENGTH + 10] = "";

    stringify(s_description, s_input);
    stringify(t_description, t_input);
    sprintf(description, "%s, %s", s_description, t_description);

    char s[MAX_LENGTH] = "";
    char t[MAX_LENGTH] = "";
    // Need to copy input in a new array, cause the input is provided as string literals
    copy_str(s, s_input);
    copy_str(t, t_input);

    return test_equal_ints(description, strend(s, t), expected);
}
