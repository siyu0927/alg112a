#include<stdio.h>
int main()
{
    long long n,i,fn;
    printf("How many number of Fibonacci?\n");
    scanf("%lld",&n);
    long long f0=0;
    long long f1=1;

    if(n==0)
    {
        printf("Ans: 0\n");
        return 0;
    }
    else if(n==1)
    {
        printf("Ans:1\n");
        return 0;
    }
    else
    {
        for(i=2;i<=n;i++)
            {
                fn=f0+f1;
                f0=f1;
                f1=fn;
            }
        printf("Ans:%lld\n",fn);
    }
    return 0;
}
