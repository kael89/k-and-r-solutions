/**
 * @description Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch.
Write a function for the other direction as well, converting escape sequences into the real
characters. 
 */

#include <stdio.h>
#include "../lib.h"

void escape(char s[], char t[]);
void print_test(char input[], char expected[]);

int main()
{
    // print_test("", "");
    print_test("A", "A");
    print_test("A\ttab", "A\\ttab");
    // print_test("Includes\ttab", "Includes\\ttab");
    // print_test("Includes\nnewline", "Includes\\nnewline");
    // print_test("Includes\tmixed\n\ncombination\tof escape\tchars", "Includes\\tmixed\\n\\ncombination\\tof escape\\tchars");
    return 0;
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

void print_test(char input[], char expected[])
{
    char result[100];
    escape(input, result);
    test_equal_strings(result, expected);
}