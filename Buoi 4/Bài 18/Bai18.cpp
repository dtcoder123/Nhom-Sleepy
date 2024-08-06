#include <stdio.h>


int x(int n) {
    // Ği?u ki?n d?ng
    if (n == 0) return 1; 
    if (n == 1) return 2; 

    int result = 0;

    for (int i = 0; i < n; i++) {
        result += (n - i) * x(i);
    }
    return result;
}

int main() {
    int n;


    printf("Nhap n: ");
    scanf("%d", &n);


    printf("x_%d = %d\n", n, x(n));

    return 0;
}

