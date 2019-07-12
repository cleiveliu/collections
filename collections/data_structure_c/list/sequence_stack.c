#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int datatype;

typedef struct
{
    datatype a[MAXSIZE];
    int top;
}sequence_stack;


void init(sequence_stack *stack)
{
    stack->top = 0;
}

int empty(sequence_stack stack)
{
    return (stack.top ==0?0:1);
}

datatype read(sequence_stack stack)
{
    if (stack.top == 0)
    {
        printf("The satck is empty\n");
        exit(1);
    }
    return stack.a[stack.top-1];
}

void push(sequence_stack *stack,datatype x)
{
    if (stack->top >= MAXSIZE)
    {
        printf("The stack is full\n");
        exit(1);
    }
    stack->a[stack->top] = x;
    stack->top++;
}

datatype pop(sequence_stack *stack)
{
    if (stack->top ==0)
    {
        printf("The stack is empty\n");
        exit(1);
    }
    datatype ret = stack->a[stack->top];
    stack->top--;
    return ret;
}


