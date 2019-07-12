#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int datatype;

typedef struct
{
    datatype a[MAXSIZE];
    int front;
    int rear;
    int used;
}circle_queue;

void init(circle_queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->used = 0;
}

datatype get(circle_queue q)
{
    if (q.used == 0)
    {
        printf("The queue is empty\n");
        exit(1);
    }
    return q.a[q.front];
}

void insert(circle_queue *q,datatype value)
{
    if (q->used >= MAXSIZE)
    {
        printf("The queue is full\n");
        exit(1);
    }
    q->a[q->rear] = value;
    q->rear = (q->rear+1)%(MAXSIZE);
    q->used++;
}

void delete(circle_queue *q)
{
    if (q->used == 0)
    {
        printf("The queue is empty\n");
        exit(1);
    }
    q->front = (q->front+1)%(MAXSIZE);
    q->used--;
}

void display(circle_queue q)
{
    if (q.used == 0)
    {
        printf("The queue is empty\n");
    }
    else
    {
        if (q.front < q.rear)
        {
            for (int i=q.front;i<q.rear;i++)
            {
                printf("%5d",q.a[i]);
            }
        }
        else
        {
            for (int i=q.front;i<MAXSIZE;i++)
            {
                printf("%5d",q.a[i]);
            }
            for (int i=0;i<q.rear;i++)
            {
                printf("%5d",q.a[i]);
            }
            printf("\n");
        }
        
    }
    
}