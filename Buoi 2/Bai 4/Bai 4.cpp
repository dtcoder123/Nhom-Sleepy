#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>

using namespace std;

#define MAX 50

struct MixedNumber {
    int integerPart;
    int numerator;
    int denominator;
};

// H�m chu?n h�a ph�n s?
void normalizeFraction(int &numerator, int &denominator) {
    if (denominator == 0) {
        cout << "Error: Division by zero!" << endl;
        exit(1);
    }
    int gcd = 1;
    int minVal = min(abs(numerator), abs(denominator));
    for (int i = 2; i <= minVal; ++i) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }
    numerator /= gcd;
    denominator /= gcd;
}

// H�m chu?n h�a h?n s?
void normalizeMixedNumber(MixedNumber &mn) {
    if (mn.denominator == 0) {
        cout << "Error: Division by zero!" << endl;
        exit(1);
    }
    if (mn.numerator < 0 && mn.integerPart > 0) {
        mn.integerPart--;
        mn.numerator += mn.denominator;
    }
    if (mn.numerator >= mn.denominator) {
        mn.integerPart += mn.numerator / mn.denominator;
        mn.numerator = mn.numerator % mn.denominator;
    }
    normalizeFraction(mn.numerator, mn.denominator);
}

// H�m ki?m tra s? nguy�n t?
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// 1. T�m h?n s? x trong m?ng b b?ng t�m ki?m tuy?n t�nh
bool linearSearch(MixedNumber b[], int size, MixedNumber x) {
    for (int i = 0; i < size; ++i) {
        if (b[i].integerPart == x.integerPart &&
            b[i].numerator == x.numerator &&
            b[i].denominator == x.denominator) {
            return true;
        }
    }
    return false;
}

// 2. S?p x?p b sao cho c�c ph?n t? c� ph?n nguy�n ch?n l�n d?u, ph?n t? c� ph?n nguy�n l? ? cu?i m?ng
void sortByIntegerPart(MixedNumber b[], int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        while (left < right && b[left].integerPart % 2 == 0) ++left;
        while (left < right && b[right].integerPart % 2 != 0) --right;
        if (left < right) {
            swap(b[left], b[right]);
        }
    }
}

// 3. T�m h?n s? x theo gi?i thu?t t�m ki?m nh? ph�n trong m?ng b d� du?c s?p x?p tang/gi?m
bool binarySearch(MixedNumber b[], int size, MixedNumber x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (b[mid].integerPart == x.integerPart &&
            b[mid].numerator == x.numerator &&
            b[mid].denominator == x.denominator) {
            return true;
        }
        if (b[mid].integerPart < x.integerPart ||
            (b[mid].integerPart == x.integerPart && b[mid].numerator < x.numerator) ||
            (b[mid].integerPart == x.integerPart && b[mid].numerator == x.numerator && b[mid].denominator < x.denominator)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

// 4. Chia m?ng b th�nh 2 m?ng s1 v� s2
void splitArray(MixedNumber b[], int size, MixedNumber s1[], MixedNumber s2[], int &size1, int &size2) {
    size1 = size2 = 0;
    for (int i = 0; i < size; ++i) {
        if (b[i].numerator == 0) {
            s1[size1++] = b[i];
        } else {
            s2[size2++] = b[i];
        }
    }
}

// 5. X�a ph?n t? th? k trong m?ng b
void deleteElement(MixedNumber b[], int &size, int k) {
    if (k < 0 || k >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    for (int i = k; i < size - 1; ++i) {
        b[i] = b[i + 1];
    }
    size--;
}

// 6. Th�m h?n s? x v�o m?ng b t?i v? tr� k
void insertElement(MixedNumber b[], int &size, MixedNumber x, int k) {
    if (k < 0 || k > size) {
        cout << "Invalid index!" << endl;
        return;
    }
    for (int i = size; i > k; --i) {
        b[i] = b[i - 1];
    }
    b[k] = x;
    size++;
}

// 7. T?o m?ng c ch?a c�c ph?n t? l� ph�n s? du?c d?i t? c�c ph?n t? h?n s? c?a m?ng b
void convertToFraction(MixedNumber b[], int size, float c[]) {
    for (int i = 0; i < size; ++i) {
        c[i] = b[i].integerPart + static_cast<float>(b[i].numerator) / b[i].denominator;
    }
}

// 8. T�nh t?ng c�c ph?n t? c?a m?ng b
float sumArray(MixedNumber b[], int size) {
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += b[i].integerPart + static_cast<float>(b[i].numerator) / b[i].denominator;
    }
    return sum;
}

// 9. T�m ph?n t? l?n nh?t/nh? nh?t c?a b
MixedNumber findMax(MixedNumber b[], int size) {
    MixedNumber max = b[0];
    for (int i = 1; i < size; ++i) {
        if (b[i].integerPart > max.integerPart ||
            (b[i].integerPart == max.integerPart && (b[i].numerator * max.denominator > max.numerator * b[i].denominator))) {
            max = b[i];
        }
    }
    return max;
}

MixedNumber findMin(MixedNumber b[], int size) {
    MixedNumber min = b[0];
    for (int i = 1; i < size; ++i) {
        if (b[i].integerPart < min.integerPart ||
            (b[i].integerPart == min.integerPart && (b[i].numerator * min.denominator < min.numerator * b[i].denominator))) {
            min = b[i];
        }
    }
    return min;
}

// 10. Xu?t v? tr� ph?n t? c� ph?n nguy�n ch?n c?a b
void printEvenIntegerParts(MixedNumber b[], int size) {
    for (int i = 0; i < size; ++i) {
        if (b[i].integerPart % 2 == 0) {
            cout << "Index of even integer part: " << i << endl;
        }
    }
}

// 11. Xu?t v? tr� c?a ph?n t? l?n nh?t/nh? nh?t c?a b
void printMaxMinIndices(MixedNumber b[], int size) {
    MixedNumber max = findMax(b, size);
    MixedNumber min = findMin(b, size);
    for (int i = 0; i < size; ++i) {
        if (b[i].integerPart == max.integerPart &&
            b[i].numerator == max.numerator &&
            b[i].denominator == max.denominator) {
            cout << "Index of maximum element: " << i << endl;
        }
        if (b[i].integerPart == min.integerPart &&
            b[i].numerator == min.numerator &&
            b[i].denominator == min.denominator) {
            cout << "Index of minimum element: " << i << endl;
        }
    }
}

int main() {
    MixedNumber b[MAX];
    int n;

    // Nh?p v� t?o m?ng h?n s? ng?u nhi�n
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    if (n > MAX) n = MAX;

    cout << "Nhap cac phan tu trong mang:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << " (format: integerPart numerator denominator): ";
        cin >> b[i].integerPart >> b[i].numerator >> b[i].denominator;
        normalizeMixedNumber(b[i]);
    }

    // Hi?n th? m?ng
    cout << "Mang:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i].integerPart << " " << b[i].numerator << "/" << b[i].denominator << " ";
    }
    cout << endl;

    // C�c b�i to�n
    MixedNumber x;
    int k, size1, size2;

    // 1. T�m h?n s? x trong m?ng b
    cout << "Nhap so x (format: integerPart numerator denominator) de tim trong mang: ";
    cin >> x.integerPart >> x.numerator >> x.denominator;
    normalizeMixedNumber(x);
    if (linearSearch(b, n, x)) {
        cout << "Tim thay so x trong mang" << endl;
    } else {
        cout << "Khong tim thay so x trong mang" << endl;
    }

    // 2. S?p x?p b sao cho c�c ph?n t? c� ph?n nguy�n ch?n l�n d?u, ph?n t? c� ph?n nguy�n l? ? cu?i m?ng
    sortByIntegerPart(b, n);
    cout << "Mang sau khi sap xep:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i].integerPart << " " << b[i].numerator << "/" << b[i].denominator << " ";
    }
    cout << endl;

    // 3. T�m h?n s? x theo gi?i thu?t t�m ki?m nh? ph�n trong m?ng b d� du?c s?p x?p
    cout << "Nhap so x (format: integerPart numerator denominator) de tim trong mang da sap xep: ";
    cin >> x.integerPart >> x.numerator >> x.denominator;
    normalizeMixedNumber(x);
    if (binarySearch(b, n, x)) {
        cout << "Tim thay so x trong mang" << endl;
    } else {
        cout << "Khong tim thay so x trong mang" << endl;
    }

    // 4. Chia m?ng b th�nh 2 m?ng s1 v� s2
    MixedNumber s1[MAX], s2[MAX];
    splitArray(b, n, s1, s2, size1, size2);
    cout << "Mang s1 (phan nguyen):" << endl;
    for (int i = 0; i < size1; ++i) {
        cout << s1[i].integerPart << " " << s1[i].numerator << "/" << s1[i].denominator << " ";
    }
    cout << endl;
    cout << "Mang s2 (phan so):" << endl;
    for (int i = 0; i < size2; ++i) {
        cout << s2[i].integerPart << " " << s2[i].numerator << "/" << s2[i].denominator << " ";
    }
    cout << endl;

    // 5. X�a ph?n t? th? k trong m?ng b
    cout << "Nhap vi tri k de xoa: ";
    cin >> k;
    deleteElement(b, n, k);
    cout << "Mang sau khi xoa phan tu thu " << k << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i].integerPart << " " << b[i].numerator << "/" << b[i].denominator << " ";
    }
    cout << endl;

    // 6. Th�m h?n s? x v�o m?ng b t?i v? tr� k
    cout << "Nhap so x (format: integerPart numerator denominator) va vi tri k de them vao mang: ";
    cin >> x.integerPart >> x.numerator >> x.denominator >> k;
    normalizeMixedNumber(x);
    insertElement(b, n, x, k);
    cout << "Mang sau khi them so x:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i].integerPart << " " << b[i].numerator << "/" << b[i].denominator << " ";
    }
    cout << endl;

    // 7. T?o m?ng c ch?a c�c ph?n t? l� ph�n s? du?c d?i t? c�c ph?n t? h?n s? c?a m?ng b
    float c[MAX];
    convertToFraction(b, n, c);
    cout << "Mang c (phan so):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;

    // 8. T�nh t?ng c�c ph?n t? c?a m?ng b
    cout << "Tong cac phan tu cua mang b: " << sumArray(b, n) << endl;

    // 9. T�m ph?n t? l?n nh?t/nh? nh?t c?a b
    MixedNumber max = findMax(b, n);
    MixedNumber min = findMin(b, n);
    cout << "Phan tu lon nhat:" << endl;
    cout << max.integerPart << " " << max.numerator << "/" << max.denominator << endl;
    cout << "Phan tu nho nhat:" << endl;
    cout << min.integerPart << " " << min.numerator << "/" << min.denominator << endl;

    // 10. Xu?t v? tr� ph?n t? c� ph?n nguy�n ch?n c?a b
    printEvenIntegerParts(b, n);

    // 11. Xu?t v? tr� c?a ph?n t? l?n nh?t/nh? nh?t c?a b
    printMaxMinIndices(b, n);

    return 0;
}

