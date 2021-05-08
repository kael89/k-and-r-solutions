/**
 * @description Add the commands to print the top elements of the stack without popping,
 * to duplicate it, and to swap the top two elements. Add a command to clear the stack.
 *
 * Note: For simplicity, we used `int` as the stack element type
 */

#include <limits.h>
#include <stdio.h>
#include "../lib.h"

#define MAXVAL 100
#define INVALID INT_MIN

void clear(void);
void duplicate_top(void);
int peek(void);
int pop(void);
void push(int);
bool swap(void);
bool test(char[], int[], int);

int sp = 0;
int val[MAXVAL];

int main()
{
    bool success = TRUE;

    push(1);
    push(2);
    int stack1[] = {1, 2};
    success &= test("push 1, push 2", stack1, sizeof stack1 / sizeof *stack1);

    pop();
    int stack2[] = {1};
    success &= test("pop 1", stack2, sizeof stack2 / sizeof *stack2);

    peek();
    success &= test_equal_ints("peek", peek(), 1);
    int stack3[] = {1};
    success &= test("stack is the same after peek", stack3, sizeof stack3 / sizeof *stack3);

    push(3);
    push(4);
    push(5);
    clear();
    int stack4[] = {};
    success &= test("push 3, push 4, push 4, clear", stack4, sizeof stack4 / sizeof *stack4);

    push(6);
    push(7);
    int stack5[] = {7, 6};
    swap();
    success &= test("swap", stack5, sizeof stack5 / sizeof *stack5);

    duplicate_top();
    int stack6[] = {7, 6, 6};
    success &= test("duplicate top", stack6, sizeof stack6 / sizeof *stack6);

    return success ? 0 : 1;
}

void push(int el)
{
    if (sp < MAXVAL)
    {
        val[sp++] = el;
    }
    else
    {
        printf("error: stack full, can't push %d\n", el);
    }
}

int pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return INVALID;
    }
}

int peek(void)
{
    if (sp > 0)
    {
        return val[sp - 1];
    }
    else
    {
        printf("error: stack empty\n");
        return INVALID;
    }
}

void duplicate_top(void)
{
    push(peek());
}

bool swap(void)
{
    if (sp < 2)
    {
        return FALSE;
    }
    int temp = val[sp - 2];
    val[sp - 2] = val[sp - 1];
    val[sp - 1] = temp;
    return TRUE;
}

void clear(void)
{
    for (; sp > 0; sp--)
    {
        val[sp] = 0;
    }
}

bool test(char description[], int expected[], int expected_len)
{
    return test_equal_int_arrays(description, val, sp, expected, expected_len);
}
