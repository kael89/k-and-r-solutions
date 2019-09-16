/**
 * Modify the temperature conversion program to print the table in reverse order,
 * that is, from 300 degrees to 0
 */

#include <stdio.h>

int main()
{
    int fahrenheit;

    for (fahrenheit = 300; fahrenheit >= 0; fahrenheit -= 20)
    {
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
    }
}