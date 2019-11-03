#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct double_link_node
{
    datatype info;
    struct double_link_node *left, *right;
} node;

node *init()
{
    return NULL;
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
        while (p)
        {
            printf("%5d", p->info);
            p = p->right;
        }
    }
}

//find ith node,i start from 1
node *find(node *head, int i)
{
    int j = 1;
    node *p = head;
    if (i < 1)
    {
        printf("The %dth node does not exist\n", i);
        return NULL;
    }
    while (p && i != j)
    {
        p = p->right;
        j++;
    }
    if (!p)
    {
        printf("%dth node does not exist\n", i);
        return NULL;
    }
    return p;
}

//add a new node after ith node,i==0 means add a new node before the first node
node *insert(node *head, datatype x, int i)
{
    node *p, *cur;
    p = (node *)malloc(sizeof(node));
    p->info = x;

    if (i == 0)
    {
        if (!head)
        {
            p->left = NULL;
            p->right = head;
            head = p;
            return head;
        }
        else
        {
            p->left = NULL;
            p->right = head;
            head->left = p;
            head = p;
            return head;
        }
    }
    cur = find(head, i);
    if (!cur)
    {
        printf("The %dth node does not exist\n", i);
        free(p);
        return head;
    }
    if (cur->right == NULL)
    {
        p->right = NULL;
        p->left = cur;
        cur->right = p;
        return head;
    }
    else
    {
        p->right = cur->right;
        cur->right->left = p;
        p->left = cur;
        cur->right = p;
        return head;
    }
}

node *delete (node *head, datatype x)
{
    node *cur;
    if (!head)
    {
        printf("The list is empty\n");
        return head;
    }
    cur = head;
    while (cur && cur->info != x)
    {
        cur = cur->right;
    }
    if (cur->info != x)
    {
        printf("Canot find node %d", x);
        return head;
    }
    if (cur == head)
    {
        if (!head->right)
        {
            free(cur);
            return NULL;
        }
        else
        {
            head = head->right;
            head->left = NULL;
            free(cur);
            return head;
        }
    }
    if (cur->right == NULL)
    {
        cur->left->right = NULL;
        free(cur);
        return head;
    }
    else
    {
        cur->right->left = cur->left;
        cur->left->right = cur->right;
        free(cur);
        return head;
    }
}
