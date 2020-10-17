/**
 * @description Verify that the expression getchar() != EOF is 0 or 1.
 * @interactive
 */

#include <stdio.h>

int main()
{
    int c;
    do
    {
        c = getchar() != EOF;
        putchar(c + '0');
    } while (c);
    printf("\n");
}
