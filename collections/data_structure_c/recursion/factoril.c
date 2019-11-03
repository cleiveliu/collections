#include <stdio.h>

int Fact(int n)
{
    int m;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        m = n * Fact(n - 1);
        return m;
    }
}

int Fact1(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * Fact1(n - 1);
}

int Fact2(int n)
{
    int ret = 1;
    while (n > 0)
    {
        ret = ret * n;
        n--;
    }
    return ret;
}

int Fact3(int n, int ret)
{
    if (n <= 1)
    {
        return ret;
    }
    return Fact3(n - 1, ret * n);
}

int eq(int a, int b)
{
    if (a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int fib(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        int a, b;
        a = Fact(i);
        b = Fact1(i);
        printf("%7d == %7d ?  %7d\n", a, b, eq(a, b));
    }

    for (int i = 1; i < 10; i++)
    {
        printf("%5d", fib(i));
    }
}
