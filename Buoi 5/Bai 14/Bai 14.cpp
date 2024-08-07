#include <iostream>
#include <vector>

using namespace std;

// H�m d? quy t�nh gi� tr? c?a U(n)
int u_recursive(int n, vector<int> &memo) {
    if (n < 6) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = u_recursive(n - 5, memo) + u_recursive(n - 4, memo) + u_recursive(n - 3, memo) + u_recursive(n - 2, memo) + u_recursive(n - 1, memo);
    return memo[n];
}

// H�m kh? d? quy t�nh gi� tr? c?a U(n)
int u_iterative(int n) {
    if (n < 6) {
        return n;
    }

    vector<int> u(n + 1, 0);

    // Kh?i t?o c�c gi� tr? co b?n cho n < 6
    for (int i = 0; i < 6; ++i) {
        u[i] = i;
    }

    // T�nh to�n gi� tr? c?a U(n) cho n >= 6
    for (int i = 6; i <= n; ++i) {
        u[i] = u[i - 5] + u[i - 4] + u[i - 3] + u[i - 2] + u[i - 1];
    }

    return u[n];
}

int main() {
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Gia tri n phai la so nguyen duong." << endl;
        return 1;
    }

    // Kh?i t?o vector memo d? luu tr? gi� tr? d� t�nh to�n cho phuong ph�p d? quy
    vector<int> memo(n + 1, -1);

    // T�nh gi� tr? c?a U(n) b?ng phuong ph�p d? quy
    int result_recursive = u_recursive(n, memo);
    cout << "Gia tri U(n) (de quy): " << result_recursive << endl;

    // T�nh gi� tr? c?a U(n) b?ng phuong ph�p kh? d? quy
    int result_iterative = u_iterative(n);
    cout << "Gia tri U(n) (khu de quy): " << result_iterative << endl;

    return 0;
}

