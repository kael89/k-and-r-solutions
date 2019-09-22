/**
 * Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most
 * the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void read_str(char *str);
int str_len(char *s);
char *strn_cpy(char *s, char *t, int n);

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char n_input[MAX_LENGTH];

    read_str(str1);
    read_str(str2);
    read_str(n_input);
    int n = atoi(n_input);
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

void read_str(char *str)
{
    while ((*str = getchar()) != '\n')
    {
        str++;
        ;
    }
    *str = '\0';
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
