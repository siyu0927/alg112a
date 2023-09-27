#include<stdio.h>
#include<math.h>
int main()
{
    int number;
    printf("Enter a number for truthtable bits : ");
    scanf("%d",&number);

    if(number<1)
    {
        printf("number must be positive \n");
        return 0;
    }

    int row = (int)pow(2, number);  //多一位數會是平方
    int d=0;

    for ( d= 0; d < row; d++) {
        int binary[number];
        int temp = d;

        for (int i = number - 1; i >= 0; i--) //轉成2進制
            {
                binary[i] = temp % 2;
                temp /= 2;
            }

        printf("%d\t", d);
        for (int i = 0; i < number; i++) {
            printf("%d ", binary[i]);
        }
        printf("\n");
    }

    return 0;

}
