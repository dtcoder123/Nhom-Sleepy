#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
void xuatSoCucTieu(int *k, int n) {
    if (n <= 1) {
        cout << "Khong co so cuc tieu trong mang vi mang co it hon 2 phan tu." << endl;
        return;
    }

    cout << "Cac so cuc tieu trong mang la: ";
    for (int i = 1; i < n - 1; i++) {
        if (k[i] < k[i - 1] && k[i] < k[i + 1]) {
            cout << k[i] << " ";
        }
    }
    if (k[0] < k[1]) {
        cout << k[0] << " ";
    }
    if (k[n - 1] < k[n - 2]) {
        cout << k[n - 1] << " ";
    }
    cout << endl;
}

void xoaPhanTuTaiViTri(int *&arr, int &n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    arr = (int *)realloc(arr, n * sizeof(int));
}

void themPhanTuTaiViTri(int *&arr, int &n, int x, int k) {
    if (k < 0 || k > n) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    arr = (int *)realloc(arr, (n + 1) * sizeof(int));
    for (int i = n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    n++;
}

void chuyenChanLe(int *arr, int n) {
    int *temp = new int[n];
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}
bool kiemTraChanLeXenKe(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 == 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

void NhapMang(int *&arr, int &n) {
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    arr = new int[n];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i << ": ";
        cin >> arr[i];
    }
}

void XuatMang(int *arr, int n) {
    cout << "Cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
	 int *arr, n;
    NhapMang(arr, n);

    XuatMang(arr, n);

    xuatSoCucTieu(arr, n);

    int viTriXoa;
    cout << "Nhap vi tri can xoa: ";
    cin >> viTriXoa;
    xoaPhanTuTaiViTri(arr, n, viTriXoa);
    XuatMang(arr, n);

    int x, viTriThem;
    cout << "Nhap gia tri can them: ";
    cin >> x;
    cout << "Nhap vi tri can them: ";
    cin >> viTriThem;
    themPhanTuTaiViTri(arr, n, x, viTriThem);
    XuatMang(arr, n);
    chuyenChanLe(arr, n);
    cout << "Mang sau khi chuyen so chan len dau va so le xuong cuoi: ";
    XuatMang(arr, n);

    if (kiemTraChanLeXenKe(arr, n)) {
        cout << "Mang co chua chan le xen ke." << endl;
    } else {
        cout << "Mang khong chua chan le xen ke." << endl;
    }
    delete[] arr;
    return 0;
}
