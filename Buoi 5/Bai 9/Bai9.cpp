#include <iostream>
#include <cmath>

using namespace std;

// Hàm tính giai th?a
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Bi?u th?c 1: S1(n) = 1/(1*2*3) + 1/(2*3*4) + ... + 1/(n*(n+1)*(n+2))
// Ð? quy
double S1_recursive(int n) {
    if (n == 1) {
        return 1.0 / (1 * 2 * 3);
    }
    return 1.0 / (n * (n + 1) * (n + 2)) + S1_recursive(n - 1);
}

// Kh? d? quy
double S1_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

// Bi?u th?c 2: S2(n) = 1^2 + 2^2 + ... + n^2
// Ð? quy
int S2_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    return n * n + S2_recursive(n - 1);
}

// Kh? d? quy
int S2_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i * i;
    }
    return sum;
}

// Bi?u th?c 3: S3(n) = 1 + (1 + 2) + (1 + 2 + 3) + ... + (1 + 2 + 3 + ... + n)
// Ð? quy
int S3_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    return (n * (n + 1)) / 2 + S3_recursive(n - 1);
}

// Kh? d? quy
int S3_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (i * (i + 1)) / 2;
    }
    return sum;
}

// Bi?u th?c 4: S4(n) = -(1+2)/2! + (3+4)/4! - (5+6)/6! + ... + (-1)^n (2n-1 + 2n)/(2n)!
// Ð? quy
double S4_recursive(int n) {
    if (n == 1) {
        return -(1.0 + 2.0) / factorial(2);
    }
    return pow(-1, n) * ((2 * n - 1) + 2 * n) / factorial(2 * n) + S4_recursive(n - 1);
}

// Kh? d? quy
double S4_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += pow(-1, i) * ((2 * i - 1) + 2 * i) / factorial(2 * i);
    }
    return sum;
}

int main() {
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;

    cout << "Ket qua S1 (de quy): " << S1_recursive(n) << endl;
    cout << "Ket qua S1 (khu de quy): " << S1_iterative(n) << endl;
    
    cout << "Ket qua S2 (de quy): " << S2_recursive(n) << endl;
    cout << "Ket qua S2 (khu de quy): " << S2_iterative(n) << endl;
    
    cout << "Ket qua S3 (de quy): " << S3_recursive(n) << endl;
    cout << "Ket qua S3 (khu de quy): " << S3_iterative(n) << endl;
    
    cout << "Ket qua S4 (de quy): " << S4_recursive(n) << endl;
    cout << "Ket qua S4 (khu de quy): " << S4_iterative(n) << endl;

    return 0;
}

