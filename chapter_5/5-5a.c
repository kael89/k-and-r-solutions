/**
 * @description Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most
 * the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int str_len(char *s);
char *strn_cpy(char *s, char *t, int n);

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    int n;

    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &n);
    printf("%s\n", strn_cpy(str1, str2, n));

    return 0;
}

char *strn_cpy(char *s, char *t, int n)
{
    char *result_p = s;
    int length_t = str_len(t);

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

int str_len(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }

    return i;
}
