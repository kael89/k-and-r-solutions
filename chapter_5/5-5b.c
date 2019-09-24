/**
 * Write versions of the library functions strncpy, strncat, and strn_cmp, which operate on at most
 * the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int strn_cmp(char *s, char *t, int n);

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    int n;

    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &n);
    printf("%d\n", strn_cmp(str1, str2, n));

    return 0;
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
