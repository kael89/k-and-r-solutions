/**
 * @description Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

char *strn_cpy(char *s, char *t, int n);
int strn_cmp(char *s, char *t, int n);
char *strn_cat(char *str1, char *str2, int n);

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char str3[MAX_LENGTH];
    char str4[MAX_LENGTH];
    char str5[MAX_LENGTH];
    char str6[MAX_LENGTH];
    int n;

    printf("strn_cpy\n");
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &n);
    printf("%s\n", strn_cpy(str1, str2, n));

    printf("strn_cmp\n");
    scanf("%s", str3);
    scanf("%s", str4);
    scanf("%d", &n);
    printf("%d\n", strn_cmp(str3, str4, n));

    printf("strn_cat\n");
    scanf("%s", str5);
    scanf("%s", str6);
    scanf("%d", &n);
    printf("%s\n", strn_cat(str5, str6, n));

    return 0;
}

char *strn_cpy(char *s, char *t, int n)
{
    char *result_p = s;

    while (n > 0 && (*s++ = *t++))
    {
        n--;
    }

    while (n--)
    {
        *s++ = '\0';
    }

    return result_p;
}

int strn_cmp(char *s, char *t, int n)
{
    while (n-- > 0)
    {
        if (*s != *t)
        {
            return *s - *t;
        }

        s++;
        t++;
    }

    return 0;
}

char *strn_cat(char *str1, char *str2, int n)
{
    char *result_p = str1;

    while (*str1)
    {
        str1++;
    }
    while (n > 0 && (*str1 = *str2))
    {
        n--;
        str1++;
        str2++;
    }

    if (n == 0)
    {
        *str1 = '\0';
    }

    return result_p;
}
