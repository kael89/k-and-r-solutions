/**
 * @description Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>

#define bool int
#define MAX_LENGTH 100

char *strcat(char *str1, char *str2);

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    scanf("%s", str1);
    scanf("%s", str2);
    printf("%s\n", strcat(str1, str2));

    return 0;
}

char *strcat(char *str1, char *str2)
{
    char *result_p = str1;

    while (*str1)
    {
        str1++;
    }
    while (*str1++ = *str2++)
    {
        ;
    }

    return result_p;
}