/**
 * Write the function strend(s,t), which returns 1 if the string t occurs
 * at the end of the string s, and zero otherwise.
 */

#include <stdio.h>

#define MAX_LENGTH 100

void read_str(char *str);
int str_len(char *s);
int strend(char *s, char *t);

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    read_str(str1);
    read_str(str2);
    int result = strend(str1, str2);
    printf("%d\n", result);

    return 0;
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

int strend(char *s, char *t)
{
    int length_s = str_len(s);
    int length_t = str_len(t);

    if (length_t > length_s)
    {
        return 0;
    }

    s += length_s;
    t += length_t;
    while (length_t-- > 0 && *--s == *--t)
    {
    }

    return *s == *t;
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
