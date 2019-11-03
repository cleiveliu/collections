#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int datatype;

typedef struct
{
    datatype a[MAXSIZE];
    int size;
} sequence_list;

void init(sequence_list *list)
{
    list->size = 0;
}

void append(sequence_list *list, datatype x)
{
    if (list->size >= MAXSIZE)
    {
        printf("The sequence_list is full\n");
        exit(1);
    }
    list->a[list->size] = x;
    list->size = list->size + 1;
}

void display(sequence_list list)
{
    int i;
    if (!list.size)
    {
        printf("The sequence_list is empty\n");
    }
    else
    {
        for (i = 0; i < list.size; i++)
        {
            printf("%6d", list.a[i]);
        }
    }
}

int empty(sequence_list list)
{
    return (list.size == 0 ? 1 : 0);
}

int find(sequence_list list, datatype x)
{
    for (int i = 0; i < list.size; i++)
    {
        if (list.a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

datatype get(sequence_list list, int i)
{
    if (i >= list.size)
    {
        printf("The index is none exist\n");
        exit(1);
    }
    else
    {
        return list.a[i];
    }
}

void insert(sequence_list *list, datatype x, int i)
{
    if (list->size >= MAXSIZE)
    {
        printf("The sequence_list is full\n");
        exit(1);
    }
    if (i < 0 || i > list->size)
    {
        printf("The index none exist\n");
        exit(1);
    }
    for (int index = list->size; index > i; index--)
    {
        list->a[index] = list->a[index - 1];
    }
    list->a[i] = x;
    list->size = list->size + 1;
}

void delete (sequence_list *list, int i)
{
    if (list->size == 0)
    {
        printf("The list is empty\n");
        exit(1);
    }
    if (i >= list->size || i < 0)
    {
        printf("The index none exist\n");
        exit(1);
    }
    for (int index = i; index < list->size - 1; index++)
    {
        list->a[index] = list->a[index + 1];
    }
    list->size--;
}

int main()
{
    return 0;
}
