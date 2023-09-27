#include <stdio.h>
float f1(float x) {
    return (x*x+1.0)/3.0;
}

float f2(float x) {
    return (x-1.0)*(x-1.0);
}

float f3(float x) {

    return 3-(1/x);
}

int main() {
    float x1 = 1.0, x2 = 1.0, x3 = 1.0;

    for (int i = 0; i < 20; i++) {
        x1 = f1(x1);
        x2 = f2(x2);
        x3 = f3(x3);

        printf("x1: %f, x2: %f, x3: %f\n", x1, x2, x3);
    }

    return 0;
}
