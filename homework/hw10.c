//GPT生成的,謝謝GPT

#include <stdio.h>
#include <math.h>

// 定義 n 次多項式的目標函數
double target_function(double *coefficients, int n, double x) {
    double result = 0;
    for (int i = 0; i <= n; ++i) {
        result += coefficients[i] * pow(x, n - i);
    }
    return result;
}

// 定義 n 次多項式的導數
double derivative(double *coefficients, int n, double x) {
    double result = 0;
    for (int i = 0; i < n; ++i) {
        result += (n - i) * coefficients[i] * pow(x, n - i - 1);
    }
    return result;
}

// 梯度下降法求解 n 次多項式的根
void gradient_descent(double *coefficients, int n) {
    double x = 0.1;  // 開始位置 x
    double learning_rate = 0.0001;  // 學習率

    for (int i = 0; i < 10000; ++i) {  // 限制迭代次數，避免無窮迴圈
        double current_value = target_function(coefficients, n, x);
        double current_derivative = derivative(coefficients, n, x);
        x = x - learning_rate * current_derivative;  // 更新 x 的值

        // 可加入收斂條件，例如當導數趨近於零時停止迭代
        if (fabs(current_derivative) < 0.0001) {
            break;
        }
    }

    printf("多項式的根為: %lf\n", x);
}

int main() {
    // 輸入 n 次多項式的係數，例如：x^2 - 5x + 6 的係數為 {1, -5, 6}
    int n;
    printf("輸入多項式的最高次數 n: ");
    scanf("%d", &n);

    double coefficients[n + 1];
    printf("輸入多項式的係數，由高次到低次，以空格分隔: ");
    for (int i = 0; i <= n; ++i) {
        scanf("%lf", &coefficients[i]);
    }

    // 求解多項式的根
    gradient_descent(coefficients, n);

    return 0;
}
