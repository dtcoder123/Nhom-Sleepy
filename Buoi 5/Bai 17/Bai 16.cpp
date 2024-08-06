#include <iostream>

using namespace std;

// Hàm d? quy tính giá tr? c?a X(n)
int x_recursive(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return x_recursive(n - 1) + (n - 1) * x_recursive(n - 2);
}

int main() {
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;

    if (n < 1) {
        cout << "Gia tri n phai la so nguyen duong." << endl;
        return 1;
    }

    // Tính giá tr? c?a X(n) b?ng phuong pháp d? quy
    int result = x_recursive(n);
    cout << "Gia tri X(" << n << ") = " << result << endl;

    return 0;
}

