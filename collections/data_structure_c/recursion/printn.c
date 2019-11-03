#include <stdio.h>

void printn(int n)
{
    int i;
    if (n > 0)
    {
        printn(n - 1);
        for (i = 1; i <= n; i++)
        {
            printf("%5d", n);
        }
        printf("\n");
    }
}

void print_n_ntimes(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d", n);
    }
    printf("\n");
}

void printn1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        print_n_ntimes(i);
    }
}

int main()
{
    printn(5);
    printn1(5);
    return 0;
}