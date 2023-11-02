//借助chatGPT的幫助,謝謝它
#include <stdio.h>
#include <math.h>

double target_function(double x, double y) {
    //return -1 * (x * x + y * y);  // 負號表示要找極大值
    //return -1 *(x*x + y - 11)*(x*x +y -11) + (x + y*y - 7)*(x + y*y - 7);
    //return -1*(x * x * x * x - 16 * x * x + 5 * x + y * y * y * y - 16 * y * y + 5 * y);
    return -1 * (1 - x) * (1 - x) + 100 * (y - x * x) * (y - x * x);
}

// 爬山演算法
void hill_climbing() {
    double x = 0.1;  // 開始位置 x
    double y = 0.0;  // 開始位置 y
    double step = 0.0001;  // 一步距離

    while (1) {
        double current_value = target_function(x, y);
        double next_x = x + step;
        double next_y = y + step;
        double next_value = target_function(next_x, next_y);

        if (next_value > current_value) {
            x = next_x;
            y = next_y;
        } else {
            break;  // 下一步小於現在的就停
        }
    }

    printf("局部極大值: (%lf, %lf), 函數值: %lf\n", x, y, target_function(x, y));
}

int main() {
    hill_climbing();
    return 0;
}
