/**
 * @description
 * 4-3: Given the basic framework, it's straightforward to extend the calculator.
 * Add the modulus (%) operator and provisions for negative numbers
 * 4-4: Add the commands to print the top elements of the stack without popping, to duplicate it,
 * and to swap the top two elements. Add a command to clear the stack.
 * 4-6: Add commands for handling variables. (It's easy to provide twenty-six variables with
 * single-letter names.) Add a variable for the most recently printed value.
 * @interactive
 */

/**
 * Tests
 * -----
 * Input             Expected
 * 0                 0
 * 1 2 +             3
 * 1 -1 +            0
 * 1 -2 + 4 5 * -    -21
 * 10 20 +           30
 *     1    2 +      3
 *
 * 2 3 pow           8
 * 2 3 pow 3 +       11
 *
 * 0 sin             0
 * 45 sin            0.70710678
 * 90 sin            1
 *
 * 0 exp             1
 * 1 exp             2.7182818
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib.h"

#define MAXOP 100
#define MAXVAL 100
#define M_PI 3.14159265358979323846

enum symbols
{
    ADD = '+',
    DIV = '/',
    MOD = '%',
    MUL = '*',
    SUB = '-',
    LINE = '\n',
    INVALID = 0,
    NUMBER,
    EXP,
    POW,
    SIN,
};

int OPS[] = {ADD, DIV, MOD, MUL, SUB};

bool is_empty(void);
int getop(char[]);
double pop(void);
void push(double);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case ADD:
            push(pop() + pop());
            break;
        case MUL:
            push(pop() * pop());
            break;
        case SUB:
            op2 = pop();
            push(pop() - op2);
            break;
        case DIV:
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: zero divisor\n");
                return 1;
            }
            break;
        case MOD:
            op2 = pop();
            if (op2 != 0.0)
            {
                push((int)pop() % (int)op2);
            }
            else
            {
                printf("error: zero divisor\n");
                return 1;
            }
            break;
        case NUMBER:
            push(atof(s));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case SIN:
            push(sin(pop() / 360.0 * (2.0 * M_PI)));
            break;
        case LINE:
            if (!is_empty())
            {
                printf("\t%.8g\n", pop());
            }
            break;
        case INVALID:
        default:
            printf("error: unknown command %s\n", s);
            return 1;
            break;
        }
    }

    return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

bool is_empty(void)
{
    return sp == 0;
}

bool is_operator(char c)
{
    for (int i = 0; i < sizeof OPS / sizeof *OPS; i++)
    {
        if (c == OPS[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool is_valid_number(char s[])
{
    bool has_decimal = FALSE;
    bool has_exp = FALSE;

    int i = 0;
    if (is_sign(s[0]))
    {
        i++;
    }

    int c;
    while ((c = s[i++]) != '\0')
    {
        if (isdigit(c))
        {
            continue;
        }

        if (c == '.' && !has_decimal && !has_exp)
        {
            has_decimal = TRUE;
            continue;
        }
        if ((c == 'e' || c == 'E') && !has_exp)
        {
            has_exp = TRUE;
            if (is_sign(s[i + 1]))
            {
                i++;
            }
            continue;
        }

        return FALSE;
    }

    return TRUE;
}

void read_word(char s[])
{
    int c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    if (c == '\n')
    {
        s[1] = '\0';
        return;
    }

    int i = 1;
    while ((s[i++] = c = getch()) != ' ' && c != '\t' && c != EOF && c != '\n')
        ;

    ungetch(c);
    s[--i] = '\0';
}

int getop(char s[])
{
    read_word(s);

    if (s[1] == '\0' && (is_operator(s[0]) || s[0] == '\n' || s[0] == EOF))
    {
        return s[0];
    }
    if (str_equals(s, "exp"))
    {
        return EXP;
    }
    if (str_equals(s, "pow"))
    {
        return POW;
    }
    if (str_equals(s, "sin"))
    {
        return SIN;
    }
    return is_valid_number(s) ? NUMBER : INVALID;
}
