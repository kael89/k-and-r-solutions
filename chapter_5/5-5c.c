/**
 * Write versions of the library functions strncpy, strn_cat, and strncmp, which operate on at most
 * the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void read_str(char *str);
char *strn_cat(char *str1, char *str2, int n);

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char n_input[MAX_LENGTH];

    read_str(str1);
    read_str(str2);
    read_str(n_input);
    int n = atoi(n_input);
    printf("%s\n", strn_cat(str1, str2, n));

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

void read_str(char *str)
{
    while ((*str = getchar()) != '\n')
    {
        str++;
        ;
    }
    *str = '\0';
}
