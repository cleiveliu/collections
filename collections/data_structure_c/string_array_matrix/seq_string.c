#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct  
{
    char str[MAXSIZE];
    int length;
}string;


//insert string t to s from ith in s ,i start from 1
void str_insert(string *s,int i,string t)
{
    int k;
    if (i < 1 || i > s->length + 1 || s->length + t.length > MAXSIZE-1)
    {
        printf("cannot insert\n");
    }
    else
    {
        for (k = s->length-1;k>i-1;k--)
        {
            s->str[t.length + k] = s->str[k];
        }
        for (k=0;k<t.length;k++)
        {
            s->str[i+k-1] = t.str[k];
        }
        s->length = s->length + t.length;
        s->str[s->length] = '\0';
    }
}

//delete length(len) element from string s from i,i start at 1
void str_delete(string *s,int i,int len)
{
    int k;
    if (i<1 || i>s->length || len > s->length - i+1  || len < 0)
    {
        printf("cannot delete\n");
    }
    else
    {
        k = i-1+len;
        while (s->str[k] != '\0')
        {
            s->str[i-1] = s->str[k];
            k++;
            i++;
        }
        s->str[k] = '\0';
        s->length = s->length - len;
    }
}

string* str_contact(string *s1,string *s2)
{
    int i;
    string *ret;
    if (s1->length + s2->length > MAXSIZE-1)
    {
        printf("cannot contact\n");
        return NULL;
    }
    else
    {
        ret = (string*) malloc(sizeof(string));
        for (i=0;i<s1->length;i++)
        {
            ret->str[i] = s1->str[i];
        }
        for (i=0;i<s2->length;i++)
        {
            ret->str[s1->length+i] = s2->str[i];
        }
        ret->length = s1->length + s2->length;
        ret->str[ret->length] = '\0';
        return ret;
    }
}

//retur substring of s,from ith ,length len,i start from 1
string* sub_string(string s,int i,int len)
{
    int k;
    string *ret;
    if (i<1 || i>s.length || i>s.length - len +1)
    {
        printf("Error\n");
        return NULL;
    }
    else
    {
        ret = (string*) malloc(sizeof(string));
        for (k=0;k<len;k++)
        {
            ret->str[k] = s.str[i-1+k];
        }
        ret->length = len;
        ret->str[ret->length] = '\0';
        return ret;
    }
}