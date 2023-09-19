#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter a number n for power2^n: \n");
    scanf("%d",&n);
    printf("solution1: %d\n",power2na(n));
    printf("solution2: %d\n",power2nb(n));
    printf("solution3: %d\n",power2nc(n));
    printf("solution4: %d\n",power2nd(n));
    return 0;
}

int power2na(int n) //方法1
{
    return (int)pow(2,n);
}

int power2nb(int n)//方法2
{

    if(n==0) return 1;
    else
    {
        return power2nb(n-1)+power2nb(n-1);
    }
}

int power2nc(int n)//方法3
{
    if(n==0) return 1;
    else
    {
        return 2* power2nc(n-1);
    }
}



int power2nd(int n)//方法4
{
    int table[10000];
    if (table[n] != 0) {
        return table[n];
    }

    if (n == 0) {
        return 1;
    } else {
        int ans =  power2nd(n-1)+power2nd(n-1);
        table[n] = ans;
        return ans;
    }
}
