#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct link_node
{
    datatype info;
    struct link_node *next;
} node;

typedef struct
{
    node *front, *rear;
} queue;

queue *init()
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int empty(queue *q)
{
    return (q->front == NULL && q->rear == NULL ? 1 : 0);
}

void display(queue *q)
{
    node *p = q->front;
    if (!p)
    {
        printf("The queue is empty\n");
    }
    else
    {
        while (p)
        {
            printf("%5d", p->info);
            p = p->next;
        }
    }
}

datatype read(queue q)
{
    if (!q.front)
    {
        printf("The queue is empty\n");
        exit(1);
    }
    return q.front->info;
}

queue *insert(queue *q, datatype x)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->info = x;
    p->next = NULL;

    if (!q->front)
    {
        q->front = q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
    return q;
}

queue *delete (queue *q)
{
    if (!q->front)
    {
        return q;
    }
    node *p;
    p = q->front;
    q->front = p->next;
    free(p);
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    return q;
}
