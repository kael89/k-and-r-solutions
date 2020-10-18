/**
 * @description Write a function expand(s1,s2) that expands shorthand notations like az in the
 * string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of
 * either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */

#include <stdio.h>
#include "../lib.h"

void expand(char s1[], char s2[]);
char get_range_end(char c);
int copy_range(char t[], int p, char range[]);
bool test(char input[], char expected[]);

int main()
{
    bool success = TRUE;

    success &= test("a", "a");
    success &= test("z", "z");
    success &= test("a-b", "ab");
    success &= test("a-c", "abc");
    success &= test("a-b-c", "abc");
    success &= test("a-b-e", "abcde");
    success &= test("a-z", "abcdefghijklmnopqrstuvwxyz");
    success &= test("e-ha-c", "efghabc");
    success &= test("-a", "-a");
    success &= test("a-", "a-");
    success &= test("-a-", "-a-");
    success &= test("-a-c", "-abc");
    success &= test("a-c-", "abc-");
    success &= test("-a-c-", "-abc-");

    success &= test("A-Z", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    success &= test("0", "0");
    success &= test("0-1-5", "012345");
    success &= test("0-9", "0123456789");

    success &= test("b-d6-8", "bcd678");
    success &= test("6-8b-d", "678bcd");
    success &= test("-b-d6-8-", "-bcd678-");
    success &= test("-b-d6-8e-", "-bcd678e-");

    return success ? 0 : 1;
}

void expand(char s1[], char s2[])
{
    int i = 0;
    int j = 0;

    if (s1[i] == '-')
    {
        s2[j++] = s1[i++];
    }

    char range[2] = "";
    char c;
    while ((c = s1[i]) != '\0' && s1[i + 1] != '\0')
    {
        if (c != '-')
        {
            if (s1[i + 2] == '\0')
            {
                // No group, exit loop
                break;
            }
            // New range detected
            if (range[0] != '\0')
            {
                // A range already exists
                int n = copy_range(s2, j, range);
                j += n;
            }

            range[0] = s1[i++];
        }

        i++; // skip '-'
        range[1] = s1[i++];
    }

    if (range[0] != '\0')
    {
        // A range already exists, copy it
        int n = copy_range(s2, j, range);
        j += n;
    }

    do
    {
        // Copy remaining chars
        s2[j++] = s1[i++];
    } while (s1[i] != '\0');
}

/**
 * Returns the number of characters that were copied
 */
int copy_range(char t[], int p, char range[])
{
    char c;
    for (c = range[0]; c <= range[1]; c++, p++)
    {
        t[p] = c;
    }

    return c - range[0];
}

bool test(char input[], char expected[])
{
    char result[100] = "";
    expand(input, result);
    return test_equal_strings(input, result, expected);
}