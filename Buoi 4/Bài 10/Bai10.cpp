#include <stdio.h>


unsigned long long fibonacci(int n) {
    if (n <= 1) return n;
    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


void printFibonacciInRange(int m, int n) {
    int i = 0;
    unsigned long long fib;

 
    while ((fib = fibonacci(i)) <= n) {
        if (fib >= m) {
            printf("%llu ", fib);
        }
        i++;
    }
    printf("\n");
}

int main() {
    int m, n;
    

    printf("Nhap m: ");
    scanf("%d", &m);
    printf("Nhap n: ");
    scanf("%d", &n);
    

    printf("Day so Fibonacci trong doan [%d, %d]:\n", m, n);
    printFibonacciInRange(m, n);
    
    return 0;
}

