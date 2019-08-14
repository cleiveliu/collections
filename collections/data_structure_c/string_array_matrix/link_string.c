#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
}link_str_node;

typedef link_str_node *link_string;

//create str from keyboard
//temporory hard to understand here
//????????????
void str_create(link_string *s)
{
    char c;
    link_str_node *p,*r;
    *s = NULL; r = NULL;
    while ((c = getchar() != '\n')
    {
        p = (link_str_node*) malloc (sizeof(link_str_node));
        p->data = c;
        if (*s == NULL)
        {
            *s = p;
        }
        else
        {
            r->next = p;
            r = p;
        }
        if (r != NULL)
        {
            r->next = NULL;
        }
    } 
}

void str_insert(link_string *s,int i,link_string t)
{
    int k;
    link_string p,q;
    p = *s;
    k = 1;
    while (p && k<i-1)
    {
        p = p->next;
        k++;
    }
    if (!p)
    {
        printf("Error\n");
    }
    else
    {
        q = t;
        while (q && q->next)
        {
            q = q->next;
        }
        q->next = p->next;
        p->next = t;
    }
}

void str_delete(link_string *s,int i,int len)
{
    int k;
    link_string p,q,r;
    p = *s, q =NULL, k =1;
    while (p && k<i)
    {
        q = p;
        p = p->next;
        k++;
    }
    if (!p)
    {
        printf("Error\n");
    }
    else
    {
        k = 1;
        while (k<len && p)
        {
            p = p->next;
            k++;
        }
        if (!p)
        {
            printf("Eror2\n");
        }
        else
        {
            if (!q)
            {
                r = *s;
                *s = p->next;
            }
            else
            {
                r = q->next;
                q->next = p->next;
            }
            p->next = NULL;
            while (r != NULL)
            {
                p = r;
                r = r->next;
                free(p);
            }
        }   
    }
}

void str_contact(link_string *s1,link_string *s2)
{
    link_string p;
    if (!(*s1))
    {
        *s1 = s2;
        return;
    }
    else
    {
        if (s2)
        {
            p = *s1;
        }
        while (p->next)
        {
            p = p->next;
        }
        p->next = s2;
    }
}

/* 
link_string sub_string(link_string s,int i,int len)
{

}

*/