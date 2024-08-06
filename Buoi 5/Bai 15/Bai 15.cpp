#include <iostream>
#include <vector>

using namespace std;

// H�m t�nh gi� tr? c?a A(n) s? d?ng d? quy
int a_recursive(int n, vector<int> &a) {
    if (n == 1) {
        return 1; // Co s? c?a d? quy: A1 = 1
    }
    
    // T�nh t?ng c?a c�c ph?n t? t? A1 d?n A(n-1)
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += a[i];
    }

    // T�nh gi� tr? c?a A(n)
    a[n] = n * sum;
    return a[n];
}

// H�m t�nh gi� tr? c?a A(n) v?i vi?c t�nh to�n d? quy
int compute_a(int n, vector<int> &a) {
    // �?t gi� tr? m?c d?nh l� -1 (chua t�nh to�n)
    if (a[n] != -1) {
        return a[n];
    }
    if (n == 1) {
        a[n] = 1;
        return a[n];
    }

    // T�nh gi� tr? c?a A(n) d? quy
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

    vector<int> a(n + 1, -1); // Vector d? luu tr? gi� tr? c?a d�y A

    // T�nh gi� tr? c?a A(n) d? quy
    int result = compute_a(n, a);
    cout << "Gia tri A(" << n << ") = " << result << endl;

    return 0;
}

