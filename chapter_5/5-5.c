/**
 * @description  Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings.
 * For  example, strncpy(s,t,n) copies at most n characters of t to s
 */

#include <stdio.h>
#include "../lib.h"

#define MAX_LENGTH 32

typedef enum
{
    LT = -1,
    EQ = 0,
    GT = 1,
} comparison;

bool test_strncat(char[], char[], int, char[]);
bool test_strncmp(char[], char[], int, int);
bool test_strncpy(char[], char[], int, char[]);

int main()
{
    bool success = TRUE;

    printf("* strncat\n");
    success &= test_strncat("", "", 0, "");
    success &= test_strncat("", "", 1, "");
    success &= test_strncpy("", "", -1, "");
    success &= test_strncat("a", "", 0, "a");
    success &= test_strncat("a", "", 1, "a");
    success &= test_strncat("a", "b", 1, "ab");
    success &= test_strncpy("a", "b", -1, "a");
    success &= test_strncat("alpha", "beta", 2, "alphabe");
    success &= test_strncat("alpha", "beta", 4, "alphabeta");
    success &= test_strncat("alpha", "beta", 10, "alphabeta");

    printf("* strncmp\n");
    success &= test_strncmp("", "", 0, EQ);
    success &= test_strncmp("", "", 1, EQ);
    success &= test_strncmp("", "", -1, EQ);
    success &= test_strncmp("a", "", 0, EQ);
    success &= test_strncmp("a", "", 1, GT);
    success &= test_strncmp("", "a", 1, LT);
    success &= test_strncmp("a", "a", 1, EQ);
    success &= test_strncmp("a", "b", 1, LT);
    success &= test_strncmp("a", "b", -1, EQ);
    success &= test_strncmp("aa", "a", 1, EQ);
    success &= test_strncmp("aa", "a", 2, GT);
    success &= test_strncmp("a", "aaa", 2, LT);
    success &= test_strncmp("aa", "aaa", 3, LT);
    success &= test_strncmp("aaa", "aa", 3, GT);
    success &= test_strncmp("a", "A", 1, GT);
    success &= test_strncmp("A", "a", 1, LT);

    printf("* strncpy\n");
    success &= test_strncpy("", "", 0, "");
    success &= test_strncpy("", "", 1, "");
    success &= test_strncpy("", "", -1, "");
    success &= test_strncpy("a", "", 0, "a");
    success &= test_strncpy("a", "", 1, "");
    success &= test_strncpy("a", "b", 1, "b");
    success &= test_strncpy("a", "b", -1, "a");
    success &= test_strncpy("alpha", "cat", 2, "capha");
    success &= test_strncpy("alpha", "cat", 3, "catha");
    success &= test_strncpy("alpha", "cat", 10, "cat");
    printf("\n");

    return success ? 0 : 1;
}

void _strncat(char *s, char *t, int n)
{
    while (*s != '\0')
    {
        s++;
    }
    while (n-- > 0 && (*s++ = *t++) != '\0')
    {
        ;
    }
}

int _strncmp(char *s, char *t, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    while (n-- > 0 && (*s == *t) && *s != '\0' && *t != '\0')
    {
        if (n > 0)
        {
            s++;
            t++;
        }
    }
    return *s - *t;
}

void _strncpy(char *s, char *t, int n)
{
    while (n-- > 0 && (*s++ = *t++) != '\0')
    {
        ;
    }
    while (n-- > 0 && *s != '\0')
    {
        *s++ = '\0';
    }
}

void get_test_description(char *description, char *s, char *t, int n)
{
    char s_description[MAX_LENGTH] = "";
    char t_description[MAX_LENGTH] = "";

    stringify(s_description, s);
    stringify(t_description, t);
    sprintf(description, "%s, %s, %d", s_description, t_description, n);
}

bool test_strncpy(char s_input[], char t_input[], int n, char expected[])
{
    char description[2 * MAX_LENGTH + 10] = "";
    get_test_description(description, s_input, t_input, n);

    char s[MAX_LENGTH] = "";
    char t[MAX_LENGTH] = "";
    copy_str(s, s_input);
    copy_str(t, t_input);
    _strncpy(s, t, n);

    return test_equal_strings(description, s, expected);
}

bool test_strncat(char s_input[], char t_input[], int n, char expected[])
{
    char description[2 * MAX_LENGTH + 10] = "";
    get_test_description(description, s_input, t_input, n);

    char s[MAX_LENGTH] = "";
    char t[MAX_LENGTH] = "";
    copy_str(s, s_input);
    copy_str(t, t_input);
    _strncat(s, t, n);

    return test_equal_strings(description, s, expected);
}

bool test_strncmp(char s_input[], char t_input[], int n, int expected)
{
    char description[2 * MAX_LENGTH + 10] = "";
    get_test_description(description, s_input, t_input, n);

    char s[MAX_LENGTH] = "";
    char t[MAX_LENGTH] = "";
    copy_str(s, s_input);
    copy_str(t, t_input);

    return test_equal_signs(description, _strncmp(s, t, n), expected);
}