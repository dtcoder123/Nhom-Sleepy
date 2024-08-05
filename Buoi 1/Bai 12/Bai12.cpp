#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    do {
        cout << "Nhap mau so (mau so phai khac 0): ";
        cin >> ps.mau;
        if (ps.mau == 0) {
            cout << "Mau so phai khac 0. Vui long nhap lai.\n";
        }
    } while (ps.mau == 0);
}

void xuatPhanSo(const PhanSo &ps) {
    cout << ps.tu << "/" << ps.mau << endl;
}

int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void rutGonPhanSo(PhanSo &ps) {
    int ucln = UCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
}

PhanSo timPhanSoNhoNhat(const PhanSo *arr, int n) {
    PhanSo min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (static_cast<double>(arr[i].tu) / arr[i].mau < static_cast<double>(min.tu) / min.mau) {
            min = arr[i];
        }
    }
    return min;
}

void xoaPhanTuTaiViTri(PhanSo *&arr, int &n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    arr = (PhanSo*) realloc(arr, n * sizeof(PhanSo));
}

void themPhanTuTaiViTri(PhanSo *&arr, int &n, PhanSo ps, int k) {
    if (k < 0 || k > n) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    arr = (PhanSo*) realloc(arr, (n + 1) * sizeof(PhanSo));
    for (int i = n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = ps;
    n++;
}

int main() {
    int n;
    PhanSo *arr;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    arr = new PhanSo[n];
    for (int i = 0; i < n; ++i) {
        nhapPhanSo(arr[i]);
    }

    PhanSo min = timPhanSoNhoNhat(arr, n);
    cout << "Phan so nho nhat la: ";
    xuatPhanSo(min);

    int k;
    cout << "Nhap vi tri can xoa: ";
    cin >> k;
    xoaPhanTuTaiViTri(arr, n, k);

    PhanSo ps;
    cout << "Nhap phan so can them:\n";
    nhapPhanSo(ps);
    cout << "Nhap vi tri can them: ";
    cin >> k;
    themPhanTuTaiViTri(arr, n, ps, k);

    cout << "Cac phan so trong mang:\n";
    for (int i = 0; i < n; ++i) {
        xuatPhanSo(arr[i]);
    }

    delete[] arr;
    return 0;
}
