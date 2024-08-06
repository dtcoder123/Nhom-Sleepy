#include <iostream>

using namespace std;

// Hàm tính s? Fibonacci th? n
int fibonacci(int n) {
    if (n <= 2) return 1;
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Hàm xu?t dãy s? Fibonacci thu?c do?n [m, n]
void printFibonacciInRange(int m, int n) {
    int index = 1;
    int fib = fibonacci(index);

    while (fib < m) {
        ++index;
        fib = fibonacci(index);
    }

    cout << "Danh sach so Fibonacci trong doan [" << m << ", " << n << "]:" << endl;

    while (fib <= n) {
        cout << fib << " ";
        ++index;
        fib = fibonacci(index);
    }
    cout << endl;
}

int main() {
    int m, n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    printFibonacciInRange(m, n);

    return 0;
}

