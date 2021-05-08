/**
 * @description Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch.
Write a function for the other direction as well, converting escape sequences into the real
characters.
 */

#include <stdio.h>
#include "../lib.h"

bool test(char[], char[], char[]);

int main()
{
    bool success = TRUE;
    success &= test("empty string", "", "");
    success &= test("single letter", "A", "A");
    success &= test("tab", "\t", "\\t");
    success &= test("tab followed by chars", "A\tword", "A\\tword");
    success &= test("tab followed by 't'", "A\ttab", "A\\ttab");
    success &= test("new line", "\n", "\\n");
    success &= test("new line follwed by chars", "Includes\nanother line", "Includes\\nanother line");
    success &= test("new line follwed by 'n'", "Includes\nnew line", "Includes\\nnew line");
    success &= test("left slash", "\\", "\\");
    success &= test("mixed", "Includes\tmixed\n\ncombination\tof \\escape\tchars\\", "Includes\\tmixed\\n\\ncombination\\tof \\escape\\tchars\\");

    return success ? 0 : 1;
}

void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;
    char c;

    while ((c = s[i++]) != '\0')
    {
        switch (c)
        {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        default:
            t[j++] = c;
        }
    }
    t[j] = '\0';
}

void escape_reverse(char s[], char t[])
{
    int i = 0;
    int j = 0;
    char c;

    while ((c = s[i++]) != '\0')
    {
        if (c == '\\' && (s[i] == 't' || s[i] == 'n'))
        {
            c = s[i] == 't' ? '\t' : '\n';
            i++;
        }
        t[j++] = c;
    }
    t[j] = '\0';
}

bool test(char description[], char input[], char expected[])
{
    char result_escape[100];
    char result_reverse[100];
    char description_reverse[100] = "";
    sprintf(description_reverse, "%s - reverse", description);

    bool success = TRUE;
    escape(input, result_escape);
    success &= test_equal_strings(description, result_escape, expected);
    escape_reverse(expected, result_reverse);
    success &= test_equal_strings(description_reverse, result_reverse, input);

    return success;
}
