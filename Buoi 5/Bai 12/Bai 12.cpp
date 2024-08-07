#include <iostream>
#include <vector>

using namespace std;

// Hàm tính x_n và y_n d? quy
void compute_sequences_recursive(int n, int &x_n, int &y_n, vector<int> &x, vector<int> &y) {
    if (n == 0) {
        x_n = 1;
        y_n = 0;
        return;
    }
    if (x[n] == -1 || y[n] == -1) { // N?u chua tính toán
        compute_sequences_recursive(n - 1, x[n - 1], y[n - 1], x, y);
        x[n] = x[n - 1] + y[n - 1];
        y[n] = 3 * x[n - 1] + 2 * y[n - 1];
    }
    x_n = x[n];
    y_n = y[n];
}

// Hàm tính x_n và y_n d? quy
void compute_sequences_recursive(int n, int &x_n, int &y_n) {
    if (n == 0) {
        x_n = 1;
        y_n = 0;
        return;
    }
    int x_prev, y_prev;
    compute_sequences_recursive(n - 1, x_prev, y_prev);
    x_n = x_prev + y_prev;
    y_n = 3 * x_prev + 2 * y_prev;
}
void compute_sequences_iterative(int n, int &x_n, int &y_n) {
    if (n == 0) {
        x_n = 1;
        y_n = 0;
        return;
    }

    vector<int> x(n + 1, 0);
    vector<int> y(n + 1, 0);

    x[0] = 1;
    y[0] = 0;

    for (int i = 1; i <= n; ++i) {
        x[i] = x[i - 1] + y[i - 1];
        y[i] = 3 * x[i - 1] + 2 * y[i - 1];
    }

    x_n = x[n];
    y_n = y[n];
}
int main() {
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;

    if (n < 0) {
        cout << "Gia tri n phai la so nguyen duong." << endl;
        return 1;
    }

    int x_n_recursive, y_n_recursive;
    compute_sequences_recursive(n, x_n_recursive, y_n_recursive);
    cout << "x_n (de quy): " << x_n_recursive << endl;
    cout << "y_n (de quy): " << y_n_recursive << endl;

    int x_n_iterative, y_n_iterative;
    compute_sequences_iterative(n, x_n_iterative, y_n_iterative);
    cout << "x_n (khu de quy): " << x_n_iterative << endl;
    cout << "y_n (khu de quy): " << y_n_iterative << endl;

    return 0;
}

