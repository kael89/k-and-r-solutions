/**
 * @description Write an alternative version of squeeze(s1,s2) that deletes each character in
 * s1 that matches any character in the string s2. 
 */

#include <stdio.h>
#include "../lib.h"

void squeeze(char s1[], char s2[]);
bool test(char input[], char search[], char expected[]);

int main()
{
    char input[] = "The big brown FOX jumped over";
    printf("Input: %s\n", input);
    bool success = test(input, "bor", "The ig wn FOX jumped ve");
    return success ? 0 : 1;
}

void squeeze(char s1[], char s2[])
{
    int i;
    int j;
    for (i = j = 0; s1[i] != '\0'; i++)
    {
        bool found = FALSE;
        for (int k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i] == s2[k])
            {
                found = TRUE;
                break;
            }
        }
        if (!found)
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

bool test(char input[], char search[], char expected[])
{
    char result[100];
    copy_str(result, input);
    squeeze(result, search);
    return test_equal_strings(search, result, expected);
}