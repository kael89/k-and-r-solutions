/**
 * Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
 */

#include <stdio.h>

#define LOWER_TEMP 0
#define UPPER_TEMP 300
#define STEP 20

float fahrenheit_to_celsius(int fahrenheit);

int main()
{
    int fahrenheit = LOWER_TEMP;
    for (fahrenheit = LOWER_TEMP; fahrenheit <= UPPER_TEMP; fahrenheit += STEP)
    {
        printf("%3.0f %6.1f\n", (float)fahrenheit, fahrenheit_to_celsius(fahrenheit));
    }
}

float fahrenheit_to_celsius(int fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}