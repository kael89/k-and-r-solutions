/**
 * @description Write a program to print the corresponding Celsius to Fahrenheit table
 */

#include <stdio.h>

int main()
{
    float fahrenheit;
    float celsius;
    int lower = 0;
    int upper = 300;
    int step = 20;

    celsius = lower;
    while (celsius <= upper)
    {
        fahrenheit = celsius * (9.0 / 5.0) + 32.0;
        printf("%3.0f %3.0f \n", celsius, fahrenheit);
        celsius += step;
    }
}