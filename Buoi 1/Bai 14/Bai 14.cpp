#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
int tinhNamNghiHuu(int namSinh, int thangSinh, char gioiTinh) {
    if (gioiTinh == 'M' || gioiTinh == 'm') {  // Nam
        if (namSinh < 1961) return 2021 + (60 - (2021 - namSinh));
        if (namSinh == 1961 && thangSinh >= 1 && thangSinh <= 9) return 2021;
        if (namSinh == 1961 && thangSinh > 9) return 2022;
        if (namSinh == 1962 && thangSinh >= 1 && thangSinh <= 6) return 2022;
        if (namSinh == 1962 && thangSinh > 6) return 2023;
        if (namSinh == 1963 && thangSinh >= 1 && thangSinh <= 3) return 2023;
        if (namSinh == 1963 && thangSinh > 3) return 2024;
        if (namSinh == 1964 && thangSinh >= 1 && thangSinh <= 9) return 2025;
        if (namSinh == 1964 && thangSinh > 9) return 2026;
        if (namSinh == 1965 && thangSinh >= 1 && thangSinh <= 6) return 2026;
        if (namSinh == 1965 && thangSinh > 6) return 2027;
        if (namSinh == 1966 && thangSinh >= 1 && thangSinh <= 3) return 2027;
        if (namSinh == 1966 && thangSinh > 3) return 2028;
        if (namSinh >= 1967) return 2028 + (62 - (1967 - namSinh));
    } else if (gioiTinh == 'F' || gioiTinh == 'f') {  // Nu
        if (namSinh < 1966) return 2021 + (55 - (2021 - namSinh));
        if (namSinh == 1966 && thangSinh >= 1 && thangSinh <= 8) return 2021;
        if (namSinh == 1966 && thangSinh > 8) return 2022;
        if (namSinh == 1967 && thangSinh >= 1 && thangSinh <= 4) return 2022;
        if (namSinh == 1967 && thangSinh > 4) return 2023;
        if (namSinh == 1968 && thangSinh >= 1 && thangSinh <= 8) return 2024;
        if (namSinh == 1968 && thangSinh > 8) return 2025;
        if (namSinh == 1969 && thangSinh >= 1 && thangSinh <= 5) return 2025;
        if (namSinh == 1969 && thangSinh > 5) return 2026;
        if (namSinh == 1970 && thangSinh >= 1 && thangSinh <= 8) return 2027;
        if (namSinh == 1970 && thangSinh > 8) return 2028;
        if (namSinh >= 1971) return 2028 + (60 - (1971 - namSinh));
    }
    return -1;  // Invalid case
}

int main() {
    char hovaten[30];
    char gioitinh;
    int ngaysinh, thangsinh, namsinh;

    cout << "Nhap ho va ten: ";
    cin.ignore();
    cin.getline(hovaten, 30);

    cout << "Nhap gioi tinh (M/F): ";
    cin >> gioitinh;

    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> ngaysinh >> thangsinh >> namsinh;

    int namNghiHuu = tinhNamNghiHuu(namsinh, thangsinh, gioitinh);
    if (namNghiHuu != -1) {
        cout << "Nam nghi huu cua " << hovaten << " la: " << namNghiHuu << endl;
    } else {
        cout << "Thong tin sinh nhat hoac gioi tinh khong hop le." << endl;
    }

    return 0;
}

