#include <iostream>
#include <vector>

using namespace std;

// Hàm d? quy tính giá tr? c?a x(n)
int x_recursive(int n, vector<int> &x) {
    if (n == 0) return 1;
    if (n == 1) return 2;

    if (x[n] != -1) return x[n];

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += x_recursive(i, x);
    }

    x[n] = n * x_recursive(0, x) + (n - 1) * x_recursive(1, x) + sum;
    return x[n];
}

// Hàm d? quy tính giá tr? c?a A(n)
int a_recursive(int n, vector<int> &A) {
    if (n == 1) return 1;

    if (A[n] != -1) return A[n];

    int result;
    if (n % 2 == 0) {  // N?u n là s? ch?n
        int k = n / 2;
        result = k + a_recursive(k, A) + 2;
    } else {  // N?u n là s? l?
        int k = (n - 1) / 2;
        result = k * k + a_recursive(k, A) * a_recursive(k + 1, A) + 1;
    }

    A[n] = result;
    return result;
}

int main() {
    int n;

    // Tính dãy x_n
    cout << "Nhap gia tri n cho x_n: ";
    cin >> n;

    if (n < 0) {
        cout << "Gia tri n phai la so nguyen duong." << endl;
        return 1;
    }

    vector<int> x(n + 1, -1);
    int result_x = x_recursive(n, x);
    cout << "Gia tri x(" << n << ") = " << result_x << endl;

    // Tính dãy A_n
    cout << "Nhap gia tri n cho A_n: ";
    cin >> n;

    if (n < 1) {
        cout << "Gia tri n phai la so nguyen duong va n >= 1." << endl;
        return 1;
    }

    vector<int> A(n + 1, -1);
    int result_a = a_recursive(n, A);
    cout << "Gia tri A(" << n << ") = " << result_a << endl;

    return 0;
}

