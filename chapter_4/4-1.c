/**
 * @description Write the function strindex(s,t) which returns the position of the rightmost
 * occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#include "../lib.h"

bool test(char[], char[], int);

int main()
{
    bool success = TRUE;

    success &= test("A", "A", 0);
    success &= test("A", "a", -1);
    success &= test("A", "b", -1);
    success &= test("Alpha", "A", 0);
    success &= test("Alpha", "a", 4);
    success &= test("Alpha", "b", -1);
    success &= test("Alpha A", "A", 6);
    success &= test("Alpha", "L", -1);
    success &= test("Alpha", "p", 2);
    success &= test("Test case", "Test", 0);
    success &= test("Test case", "case", 5);
    success &= test("Test case case", "case", 10);
    success &= test("Test case Case", "Case", 10);
    success &= test("Test case case", "Case", -1);

    return success ? 0 : 1;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    int s_len = str_len(s);
    int t_len = str_len(t);

    for (i = s_len - 1; i >= 0; i--)
    {
        for (j = i, k = t_len - 1; k >= 0 && s[j] == t[k]; j--, k--)
            ;

        if (k < 0)
        {
            return i - t_len + 1;
        }
    }
    return -1;
}

bool test(char s[], char t[], int expected)
{
    char description[50] = "";
    sprintf(description, "s: %s, t: %s", s, t);
    return test_equal_ints(description, strindex(s, t), expected);
}
