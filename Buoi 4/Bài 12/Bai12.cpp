#include <stdio.h>

void tinhSoHang(int n, int* x_n, int* y_n) {
    if (n == 0) {
        *x_n = 1;
        *y_n = 0;
        return;
    }

    int x_prev = 1, y_prev = 0;
    int x_curr, y_curr;

    for (int i = 1; i <= n; ++i) {
        x_curr = x_prev + y_prev;
        y_curr = 3 * x_prev + 2 * y_prev;

        x_prev = x_curr;
        y_prev = y_curr;
    }

    *x_n = x_curr;
    *y_n = y_curr;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int x_n, y_n;
    tinhSoHang(n, &x_n, &y_n);

    printf("x_%d = %d\n", n, x_n);
    printf("y_%d = %d\n", n, y_n);

    return 0;
}

