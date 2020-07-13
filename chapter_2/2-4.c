/**
 * @description Write an alternative version of squeeze(s1,s2) that deletes each character in
 * s1 that matches any character in the string s2. 
 */

#include <stdio.h>
#include "../lib.h"

void squeeze(char s1[], char s2[]);

int main()
{
    char input[] = "The big brown FOX jumped over";
    squeeze(input, "bor");
    char expected[] = "The ig wn FOX jumped ve";

    printf("'%s' should equal: '%s'\n", input, expected);
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