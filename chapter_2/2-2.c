/**
 * @description Write a loop equivalent to the for loop above without using && or ||.
 */

#include <stdio.h>

#define MAX_LINE 1024

int main()
{
    int i;
    int lim = MAX_LINE;
    char c;
    char s[MAX_LINE];

    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if ((c == '\n') + (c == EOF) > 0)
        {
            break;
        }
        s[i] = c;
    }
    s[i] = '\0';
    printf("%s\n", s);

    return 0;
}