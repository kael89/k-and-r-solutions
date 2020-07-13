/**
 * @description Write the function any(s1,s2), which returns the first location in a string s1
 * where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The
 * standard library function strpbrk does the same job but returns a pointer to the location.) 
 */

#include <stdio.h>
#include "../lib.h"

#define NOT_FOUND -1

void print_test(char input[], char target[], int expected);
int any(char s1[], char s2[]);

int main()
{
    print_test("The big brown FOX jumped over", "rob", 4);
    printf("\n");
    print_test("The big brown FOX jumped over", "OX", 15);

    return 0;
}

void print_test(char input[], char target[], int expected)
{
    printf("Input: '%s'\n", input);
    printf("Search chars: '%s'\n", target);
    printf("Result: %d, Expected: %d\n", any(input, target), expected);
}

int any(char s1[], char s2[])
{
    int pos = NOT_FOUND;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                pos = i;
                break;
            }
        }
        if (pos != NOT_FOUND)
        {
            break;
        }
    }

    return pos;
}