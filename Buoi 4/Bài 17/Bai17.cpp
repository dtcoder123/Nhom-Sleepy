#include <stdio.h>


int Xn(int n) {

    if (n == 1 || n == 2) {
        return 1;
    }
    

    return Xn(n - 1) + (n - 1) * Xn(n - 2);
}

int main() {
    int n;
    

    printf("Nhap gia tri n: ");
    scanf("%d", &n);
    

    if (n < 1) {
        printf("Gia tri n phai >= 1\n");
        return 1;
    }
    

    printf("X_%d = %d\n", n, Xn(n));
    
    return 0;
}

