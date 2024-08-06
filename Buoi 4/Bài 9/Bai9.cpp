#include <stdio.h>


double S1_khuDeQuy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

double S1_deQuy(int n) {
    if (n == 1) {
        return 1.0 / (1 * 2 * 3);
    } else {
        return 1.0 / (n * (n + 1) * (n + 2)) + S1_deQuy(n - 1);
    }
}


int S2_khuDeQuy(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int S2_deQuy(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * n + S2_deQuy(n - 1);
    }
}


int S3_khuDeQuy(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
    }
    return sum;
}

int S3_deQuy(int n) {
    if (n == 1) {
        return 1;
    } else {
        return (n * (n + 1)) / 2 + S3_deQuy(n - 1);
    }
}


double S4_khuDeQuy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (double)((-1) * (i % 2 ? -1 : 1) * (2 * i - 1)) / (2 * i);
    }
    sum += 2 * n;
    return sum;
}

double S4_deQuy(int n) {
    if (n == 1) {
        return -1.0 / 2 + 2;
    } else {
        return (double)((-1) * (n % 2 ? -1 : 1) * (2 * n - 1)) / (2 * n) + S4_deQuy(n - 1) + 2;
    }
}

int main() {
    int n;
    printf("Nhap vao so nguyen duong n: ");
    scanf("%d", &n);

   
    printf("Ket qua S1_khuDeQuy(%d) = %lf\n", n, S1_khuDeQuy(n));
    printf("Ket qua S1_deQuy(%d) = %lf\n", n, S1_deQuy(n));

  
    printf("Ket qua S2_khuDeQuy(%d) = %d\n", n, S2_khuDeQuy(n));
    printf("Ket qua S2_deQuy(%d) = %d\n", n, S2_deQuy(n));

   
    printf("Ket qua S3_khuDeQuy(%d) = %d\n", n, S3_khuDeQuy(n));
    printf("Ket qua S3_deQuy(%d) = %d\n", n, S3_deQuy(n));

  
    printf("Ket qua S4_khuDeQuy(%d) = %lf\n", n, S4_khuDeQuy(n));
    printf("Ket qua S4_deQuy(%d) = %lf\n", n, S4_deQuy(n));

    return 0;
}

