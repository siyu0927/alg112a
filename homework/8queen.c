//有使用ChatGPT輔助

#include <stdio.h>
int Queenes[8]={0},Counts=0;
int Check(int line,int list){  //看能不能放皇后
    for (int index=0; index<line; index++) {
        int data=Queenes[index];
        if (list==data) {  //同一列
            return 0;
        }
        if ((index+data)==(line+list)) {  //斜上
            return 0;
        }
        if ((index-data)==(line-list)) {  //斜下
            return 0;
        }
    }

    return 1;
}
void print()
{
    for (int line = 0; line < 8; line++)
    {
        int list;
        for (list = 0; list < Queenes[line]; list++)
            printf("0");
        printf("#"); //皇后
        for (list = Queenes[line] + 1; list < 8; list++){
            printf("0");
        }
        printf("\n");
    }
    printf("================\n");
}
void eight_queen(int line){  //排序
    for (int list=0; list<8; list++) {
        if (Check(line, list)) {
            Queenes[line]=list;
            if (line==7) {  //有找到
                Counts++;
                print();
                Queenes[line]=0;
                return;
            }
            eight_queen(line+1);
            Queenes[line]=0;
        }
    }
}
int main() {
    eight_queen(0);
    printf("共有%d種解法",Counts);
    return 0;
}
