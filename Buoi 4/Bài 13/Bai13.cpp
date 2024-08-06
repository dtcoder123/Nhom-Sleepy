#include <stdio.h>
#include <math.h>

double capSoNhan(int n, double a, double q) {
    if (n <= 0) {
        printf("Vi tri phan tu phai la so nguyen duong.\n");
        return -1;  
    }
    return a * pow(q, n - 1);
}

int main() {
    int n;
    double a, q;


    printf("Nhap gia tri hang dau a: ");
    scanf("%lf", &a);
    printf("Nhap cong boi q: ");
    scanf("%lf", &q);
    printf("Nhap vi tri phan tu n: ");
    scanf("%d", &n);


    double result = capSoNhan(n, a, q);
    if (result != -1) {
        printf("Gia tri phan tu thu %d cua cap so nhan la: %.2lf\n", n, result);
    }

    return 0;
}

