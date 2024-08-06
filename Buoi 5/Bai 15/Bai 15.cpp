#include <iostream>
#include <vector>

using namespace std;

// Hàm tính giá tr? c?a A(n) s? d?ng d? quy
int a_recursive(int n, vector<int> &a) {
    if (n == 1) {
        return 1; // Co s? c?a d? quy: A1 = 1
    }
    
    // Tính t?ng c?a các ph?n t? t? A1 d?n A(n-1)
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += a[i];
    }

    // Tính giá tr? c?a A(n)
    a[n] = n * sum;
    return a[n];
}

// Hàm tính giá tr? c?a A(n) v?i vi?c tính toán d? quy
int compute_a(int n, vector<int> &a) {
    // Ð?t giá tr? m?c d?nh là -1 (chua tính toán)
    if (a[n] != -1) {
        return a[n];
    }
    if (n == 1) {
        a[n] = 1;
        return a[n];
    }

    // Tính giá tr? c?a A(n) d? quy
    a_recursive(n, a);
    return a[n];
}

int main() {
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;

    if (n < 1) {
        cout << "Gia tri n phai la so nguyen duong." << endl;
        return 1;
    }

    vector<int> a(n + 1, -1); // Vector d? luu tr? giá tr? c?a dãy A

    // Tính giá tr? c?a A(n) d? quy
    int result = compute_a(n, a);
    cout << "Gia tri A(" << n << ") = " << result << endl;

    return 0;
}

