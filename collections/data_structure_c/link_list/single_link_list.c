#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct link_node{
    datatype info;
    struct  link_node *next;
}node;


node* init()
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
            printf("%d",p->info);
            p = p->next;
        }
    }
    
}

//return ith node,start from 1
node* find(node *head,int i)
{
    if (i< 1)
    {
        return NULL;
    }
    int j = 1;
    node *p;
    p = head;
    while (p && i!=j)
    {
        p=p->next;
        j++;
    }
    return p;
}

//insert a new node after ith node,i=0 means insert a new node before head node
node* insert(node *head,datatype x,int i)
{
    node *p,*q;
    q = find(head,i);
    if (!q && i!=0)
    {
        printf("can not find %dth node,can not insert %d\n",i,x);
    }
    else
    {
        p = (node*)malloc(sizeof(node));
        p->info = x;
        if (i==0)
        {
            p->next = head;
            head = p;
        }
        else
        {
            p->next = q->next;
            q->next = p;
        }
    }
    return head;   
}

//delete first node if node.info = x 
node* delete(node *head,datatype x)
{
    node *pre = NULL,*p;
    if (!head)
    {
        printf("The list is empty\n");
        exit(1);
    }
    while (p && p->info != x)
    {
        pre = p;
        p = p->next;
    }
    if (p)
    {
        if (!pre)
        {
            head = head->next;
        }
        else
        {
            pre->next = p->next;
        }
        free(p);
    }
    return head;
}
