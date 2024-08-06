#include <iostream>
using namespace std;

// Hàm tìm ch? s? d?u tiên
int firstDigit(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

// Hàm tìm ch? s? d?o ngu?c
int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

// Hàm tìm ch? s? l?n nh?t
int maxDigit(int n) {
    int maxDigit = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        n /= 10;
    }
    return maxDigit;
}

// Hàm tìm ch? s? nh? nh?t
int minDigit(int n) {
    int minDigit = 9;
    while (n > 0) {
        int digit = n % 10;
        if (digit < minDigit) {
            minDigit = digit;
        }
        n /= 10;
    }
    return minDigit;
}

// Hàm ki?m tra toàn ch? s? l?
bool allOddDigits(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            return false;
        }
        n /= 10;
    }
    return true;
}

// Hàm ki?m tra toàn ch? s? ch?n
bool allEvenDigits(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 != 0) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    cout << "Chu so dau tien cua n la: " << firstDigit(n) << endl;
    cout << "Chu so dao nguoc cua n la: " << reverseNumber(n) << endl;
    cout << "Chu so lon nhat cua n la: " << maxDigit(n) << endl;
    cout << "Chu so nho nhat cua n la: " << minDigit(n) << endl;
    cout << "Toan bo chu so cua n la le: " << (allOddDigits(n) ? "Co" : "Khong") << endl;
    cout << "Toan bo chu so cua n la chan: " << (allEvenDigits(n) ? "Co" : "Khong") << endl;

    return 0;
}

