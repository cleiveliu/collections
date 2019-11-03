#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct circle_link_list
{
    datatype info;
    struct circle_link_list *next;
} node;

node *init()
{
    return NULL;
}

//get the last node,which node.next point to head
node *rear(node *head)
{
    node *p;
    if (!head)
    {
        p = NULL;
    }
    else
    {
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
    }
    return p;
}

void display(node *head)
{
    node *p;
    p = head;
    if (!p)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("%5d", p->info);
        p = p->next;
        while (p != head)
        {
            printf("%5d", p->info);
            p = p->next;
        }
    }
}

node *find(node *head, datatype x)
{
    node *p;
    if (!head)
    {
        printf("The list is empty\n");
        return NULL;
    }
    else
    {
        p = head;
        while (p->next != head && p->info != x)
        {
            p = p->next;
        }
        if (p->info == x)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
}

//insert a new node after ith node,i==0 means add a new node before first node
node *insert(node *head, datatype x, int i)
{
    node *p, *q, *myrear;
    int j;
    p = (node *)malloc(sizeof(node));
    p->info = x;
    if (i < 0)
    {
        printf("The ops canot be down\n");
        return head;
    }
    if (i == 0 && !head)
    {
        p->next = p;
        head = p;
        return head;
    }
    if (i == 0 && head)
    {
        myrear = rear(head);
        p->next = head;
        myrear->next = p;
        return head;
    }
    if (i > 0 && !head)
    {
        printf("Canot find %5dth position\n", i);
        free(p);
        return head;
    }
    if (i > 0 && head)
    {
        q = head;
        j = 1;
        while (q->next != head && j != i)
        {
            q = q->next;
            j++;
        }
        if (i != j)
        {
            printf("Canot find %5dth position\n", i);
            free(p);
            return head;
        }
        else
        {
            p->next = q->next;
            q->next = p;
            return head;
        }
    }
    return head;
}

node *delete (node *head, datatype x)
{
    node *pre, *cur;
    pre = NULL;
    if (!head)
    {
        printf("The list is empty\n");
        return head;
    }
    cur = head;
    while (cur->info != x && cur->next != head)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur->info != x)
    {
        printf("Canot find %5d\n", x);
        return head;
    }
    else
    {
        if (cur != head)
        {
            pre->next = cur->next;
            free(cur);
            return head;
        }
        else
        {
            if (head->next == head)
            {
                free(cur);
                head = NULL;
                return head;
            }
            else
            {
                pre = head->next;
                while (pre->next != cur)
                {
                    pre = pre->next;
                }
                head = head->next;
                pre->next = head;
                free(cur);
                return head;
            }
        }
    }
}
