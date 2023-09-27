#include<stdio.h>
int main()
{
    float two=0;
    float ans=0;
    float i=0;

    for(i=-100;i<100;i=i+0.1)
    {
        two=i*i;
        ans=two-(3*i)+1;
        if(ans<=0.05&&ans>=-0.05)
        {
            printf("ans = %f ",i);
            return 0;
        }

    }

    return 0;
}
