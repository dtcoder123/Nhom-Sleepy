#include <iostream>
using namespace std;

void NhapMang(int *&arr, int &n, const char *name) {
    cout << "Nhap so luong phan tu cua mang " << name << ": ";
    cin >> n;
    arr = new int[n];
    cout << "Nhap cac phan tu cua mang " << name << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i << ": ";
        cin >> arr[i];
    }
}

void XuatMang(int *arr, int n, const char *name) {
    cout << "Cac phan tu cua mang " << name << ":\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void chiaMang(int *a, int na, int *b, int nb) {
    if (na != nb) {
        cout << "Hai mang khong cung kich thuoc!" << endl;
        return;
    }

    cout << "Ket qua chia cac phan tu tuong ung cua mang a cho mang b:\n";
    for (int i = 0; i < na; ++i) {
        if (b[i] == 0) {
            cout << "Loi: Phan tu thu " << i << " cua mang b bang 0. Khong the chia.\n";
        } else {
            cout << "a[" << i << "] / b[" << i << "] = " << static_cast<double>(a[i]) / b[i] << endl;
        }
    }
}

int main() {
    int *a, *b;
    int na, nb;

    NhapMang(a, na, "a");
    NhapMang(b, nb, "b");

    XuatMang(a, na, "a");
    XuatMang(b, nb, "b");

    chiaMang(a, na, b, nb);

    delete[] a;
    delete[] b;

    return 0;
}
