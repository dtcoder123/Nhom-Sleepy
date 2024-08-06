#include <iostream>
#include <cmath>

using namespace std;

// Hàm d? quy tính s? ti?n sau m nam
double calculateAmount(double principal, double interestRate, int years) {
    if (years == 0) {
        return principal;
    }
    return calculateAmount(principal * (1 + interestRate / 100), interestRate, years - 1);
}

int main() {
    double principal;
    double interestRate;
    int years;

    cout << "Nhap so von ban dau (trieu dong): ";
    cin >> principal;
    cout << "Nhap lai suat hang nam (theo phan tram): ";
    cin >> interestRate;
    cout << "Nhap so nam: ";
    cin >> years;

    double amount = calculateAmount(principal, interestRate, years);
    cout << "So tien sau " << years << " nam la: " << amount << " trieu dong" << endl;

    return 0;
}

