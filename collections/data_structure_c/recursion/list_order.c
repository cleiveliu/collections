#include <stdio.h>

#define MAXSIZE 20

typedef int listarr[MAXSIZE];

//中序打印List中的元素
void list_order_recv(listarr list,int left,int right)
{
    int mid;
    if (left <= right)
    {
        mid = (left + right)/2;
        printf("%5d",list[mid]);
        list_order_recv(list,left,mid-1);
        list_order_recv(list,mid+1,right);        
    }
}

void list_order(listarr list,int left,int right)
{
    typedef struct 
    {
        int l;
        int r;
    }stack_node;
    stack_node stack[MAXSIZE];
    int top,i,j,mid;
    if (left <= right)
    {
        top = 0;
        i = left; j = right;
        while (i<=j || top != 0)
        {
            if (i<=j)
            {
                mid = (i+j)/2;
                printf("%5d",list[mid]);
                stack[top].l = mid+1;
                stack[top].r = j;
                ++top;
                j = mid-1;
            }
            else
            {
                --top;
                i = stack[top].l;
                j = stack[top].r;
            }
            
        }
        
    }
}


