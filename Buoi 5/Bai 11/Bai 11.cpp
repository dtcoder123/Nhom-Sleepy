#include <iostream>

using namespace std;

// Hàm d? quy tìm s? Fibonacci l?n nh?t nh? hon n
int fibonacci_max_less_than_n_recursive(int n, int a = 0, int b = 1) {
    int next = a + b;
    if (next >= n) {
        return a;
    }
    return fibonacci_max_less_than_n_recursive(n, b, next);
}

// Hàm kh? d? quy tìm s? Fibonacci l?n nh?t nh? hon n
int fibonacci_max_less_than_n_iterative(int n) {
    int a = 0, b = 1;
    while (true) {
        int next = a + b;
        if (next >= n) {
            return a;
        }
        a = b;
        b = next;
    }
}

int main() {
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;
    
    if (n <= 1) {
        cout << "Gia tri n phai lon hon 1." << endl;
        return 1;
    }

    int result_recursive = fibonacci_max_less_than_n_recursive(n);
    int result_iterative = fibonacci_max_less_than_n_iterative(n);

    cout << "So Fibonacci lon nhat nho hon " << n << " (de quy): " << result_recursive << endl;
    cout << "So Fibonacci lon nhat nho hon " << n << " (khu de quy): " << result_iterative << endl;

    return 0;
}

