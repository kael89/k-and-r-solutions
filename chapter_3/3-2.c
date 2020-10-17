/**
 * @description Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch.
Write a function for the other direction as well, converting escape sequences into the real
characters.
 */

#include <stdio.h>
#include "../lib.h"

void escape(char s[], char t[]);
bool test(char description[], char input[], char expected[]);

int main()
{
    bool success = TRUE;
    success &= test("empty string", "", "");
    success &= test("single letter", "A", "A");
    success &= test("tab", "A\ttab", "A\\ttab");
    success &= test("new line", "Includes\nnewline", "Includes\\nnewline");
    success &= test("mixed", "Includes\tmixed\n\ncombination\tof escape\tchars", "Includes\\tmixed\\n\\ncombination\\tof escape\\tchars");

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

bool test(char description[], char input[], char expected[])
{
    char result[100];
    escape(input, result);
    return test_equal_strings(description, result, expected);
}
