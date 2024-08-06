#include <stdio.h>


int A(int n) {
    // Co s?
    if (n == 1) {
        return 1;
    }
    

    if (n % 2 == 0) {
        return (n / 2) + A(n / 2) + 2;
    }

    else {
        return ((n / 2) * (n / 2)) + A(n / 2) * A((n / 2) + 1) + 1;
    }
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    
    printf("A(%d) = %d\n", n, A(n));
    return 0;
}

