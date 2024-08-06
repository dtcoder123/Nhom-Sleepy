#include <iostream>

using namespace std;

// Hàm d? quy tính giá tr? ph?n t? th? n c?a c?p s? nhân
double geometric_sequence_recursive(int n, double a, double q) {
    if (n == 1) {
        return a;
    }
    return q * geometric_sequence_recursive(n - 1, a, q);
}
double geometric_sequence_iterative(int n, double a, double q) {
    double result = a;
    for (int i = 1; i < n; ++i) {
        result *= q;
    }
    return result;
}
int main() {
    int n;
    double a, q;

    cout << "Nhap gia tri n: ";
    cin >> n;
    cout << "Nhap gia tri a (hang dau): ";
    cin >> a;
    cout << "Nhap gia tri q (cong boi): ";
    cin >> q;

    if (n <= 0) {
        cout << "Gia tri n phai lon hon 0." << endl;
        return 1;
    }

    double result_recursive = geometric_sequence_recursive(n, a, q);
    double result_iterative = geometric_sequence_iterative(n, a, q);

    cout << "Gia tri phan tu thu " << n << " (de quy): " << result_recursive << endl;
    cout << "Gia tri phan tu thu " << n << " (khu de quy): " << result_iterative << endl;

    return 0;
}

