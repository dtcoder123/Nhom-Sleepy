#include <stdio.h>


unsigned long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


unsigned long long findLargestFibonacciLessThanRecursive(int n) {
    int i = 0;
    unsigned long long fib;

 
    while ((fib = fibonacci(i)) < n) {
        i++;
    }

 
    return fibonacci(i - 1);
}


unsigned long long findLargestFibonacciLessThanIterative(int n) {
    unsigned long long a = 0, b = 1, c;

   
    if (n <= 1) return 0;

  
    while (b < n) {
        c = a + b;
        a = b;
        b = c;
    }


    return a;
}

int main() {
    int n;

  
    printf("Nhap n: ");
    scanf("%d", &n);


    printf("So Fibonacci lon nhat nho hon %d (de quy): %llu\n", n, findLargestFibonacciLessThanRecursive(n));
    

    printf("So Fibonacci lon nhat nho hon %d (khu de quy): %llu\n", n, findLargestFibonacciLessThanIterative(n));
    
    return 0;
}

