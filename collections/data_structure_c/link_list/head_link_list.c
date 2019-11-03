#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct head_link_list
{
    datatype info;
    struct head_link_list *next;
} node;

node *init()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
}

void display(node *head)
{
    node *p;
    p = head->next;
    if (!p)
    {
        printf("The list is empty\n");
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

// i start from 0,point to the head node
node *find(node *head, int i)
{
    int j = 0;
    node *p = head;
    if (i < 0)
    {
        printf("The %dth node does not exist\n", i);
        return NULL;
    }

    while (p && i != j)
    {
        p = p->next;
        j++;
    }
    return p;
}

//insert a new node after ith node if ith node exist,i start form 0,
node *insert(node *head, datatype x, int i)
{
    node *p, *q;
    q = find(head, i);
    if (!q)
    {
        printf("The %dth node does not exist\n", i);
        return head;
    }
    p = (node *)malloc(sizeof(node));
    p->info = x;
    p->next = q->next;
    q->next = p;
    return head;
}

node *delete (node *head, datatype x)
{
    node *pre, *cur;
    pre = head;
    cur = head->next;
    while (cur && cur->info != x)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur)
    {
        pre->next = cur->next;
        free(cur);
    }
    return head;
}