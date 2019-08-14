
float legend_recv(int n,float x)
{
    if (n==0)
    {
        return 1.0;
    }
    else if (n==1)
    {
        return x;
    }
    else
    {
        float p1,p2;
        p1 = (2*n-1)*x*p(n-1,x);
        p2 = (n-1)*p(n-2,x);
        return (p1-p2)/n;
    }
}

float legend(int n,float x)
{
    float pre1,pre2,a,b,valueep;
    int i;
    if (n==0)
    {
        return 1.0;
    }
    else if (n==1)
    {
        return x;
    }
    else
    {
        pre1 = 1.0;
        pre2 = x;
        for (i=2;i<=n;i++)
        {
            a = 2*i-1;
            b = i-1;
            valueep = (a*pre2*x-b*pre1)/i;
            pre1 = pre2;
            pre2 = valueep;
        }
        return valueep;
    }
}