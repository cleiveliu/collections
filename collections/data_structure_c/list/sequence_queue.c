#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100

typedef int datatype;

typedef struct 
{
    datatype a[MAXSIZE];
    int front;
    int rear;
}sequence_queue;

void init(sequence_queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

int empty(sequence_queue queue)
{
    return (queue.front == queue.rear?1:0);
}

void display(sequence_queue queue)
{
    if (empty(queue))
    {
        printf("The queue is empty\n");
    }
    else
    {
    for (int i = queue.front;i<queue.rear;i++)
    {
        printf("%5d",queue.a[i]);
    }
    printf("\n");
    }
}

datatype get(sequence_queue queue)
{
    if (empty(queue))
    {
        printf("The queue is empty\n");
        exit(1);
    }
    return queue.a[queue.front];
}

void insert(sequence_queue *queue,datatype value)
{
    if (queue->rear == MAXSIZE)
    {
        printf("The queue is full\n");
        exit(1);
    }
    queue->a[queue->rear] = value;
    queue->rear++;
}

void delete(sequence_queue *queue)
{
    if (queue->front == queue->rear)
    {
        printf("The queue is empty\n");
        exit(1);
    }
    queue->front++;
}

