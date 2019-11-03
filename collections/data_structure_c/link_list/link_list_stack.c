#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct link_list_stack
{
    datatype info;
    struct link_list_stack *next;
} node;

node *init()
{
    return NULL;
}

int empty(node *top)
{
    return (top == NULL ? 1 : 0);
}

datatype read(node *head)
{
    if (!head)
    {
        printf("The stack is empty\n");
        exit(1);
    }
    else
    {
        return head->info;
    }
}
void display(node *top)
{
    if (!top)
    {
        printf("The stack is empty\n");
    }
    else
    {
        node *p = top;
        while (p)
        {
            printf("%5d", p->info);
            p = p->next;
        }
    }
}

node *push(node *top, datatype x)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->info = x;
    p->next = top;
    top = p;
    return top;
}

node *pop(node *top)
{
    if (!top)
    {
        printf("The stack is empty\n");
        return NULL;
    }
    node *p;
    p = top;
    top = top->next;
    free(p);
    return top;
}
