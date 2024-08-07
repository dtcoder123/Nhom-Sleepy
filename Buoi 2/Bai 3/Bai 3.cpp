#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

#define MAX 50

// Hàm ki?m tra s? nguyên t?
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// 1. Li?t kê các s? nguyên t? nh? hon n
void listPrimes(int n) {
    bool found = false;
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co so nguyen to nho hon " << n << endl;
    }
    cout << endl;
}

// 2. Tính t?ng các ph?n t? có ch? s? d?u là ch? s? l?
int firstDigit(int num) {
    while (num >= 10) num /= 10;
    return num;
}

int sumOddFirstDigit(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (firstDigit(arr[i]) % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// 3. Li?t kê s? l?n xu?t hi?n c?a các ph?n t? trong m?ng
void countOccurrences(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        int count = 1;
        if (arr[i] == INT_MIN) continue; // Ðánh d?u ph?n t? dã du?c d?m
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] == arr[i]) {
                count++;
                arr[j] = INT_MIN; // Ðánh d?u ph?n t? dã du?c d?m
            }
        }
        cout << "Phan tu " << arr[i] << " xuat hien " << count << " lan" << endl;
    }
}

// 4. S?p x?p m?ng: s? ch?n tang d?n, s? l? gi?m d?n
void sortEvenOdd(int arr[], int size) {
    // S?p x?p s? ch?n tang d?n
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    // S?p x?p s? l? gi?m d?n
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] % 2 != 0 && arr[j] % 2 != 0 && arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// 5. Tìm dãy con gi?m dài nh?t trong m?ng
int longestDecreasingSubsequence(int arr[], int size) {
    int maxLength = 0;
    for (int i = 0; i < size; ++i) {
        int length = 1;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[j - 1]) {
                length++;
            } else {
                break;
            }
        }
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}

// 6. Tìm s? nh? th? 2 trong m?ng
int secondSmallest(int arr[], int size) {
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }
    return (secondSmallest == INT_MAX) ? -1 : secondSmallest;
}

// 7. Tìm các ph?n t? có ch?a các ch? s? c?a x
bool containsDigits(int num, int x) {
    bool digits[10] = {false};
    while (x > 0) {
        digits[x % 10] = true;
        x /= 10;
    }
    while (num > 0) {
        if (digits[num % 10]) {
            return true;
        }
        num /= 10;
    }
    return false;
}

void findElementsContainingDigits(int arr[], int size, int x) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (containsDigits(arr[i], x)) {
            cout << arr[i] << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay phan tu nao chua cac chu so cua " << x << endl;
    }
    cout << endl;
}

// 8. S?p x?p m?ng sao cho các ph?n t? ch?n tang d?n, các ph?n t? l? gi? nguyên v? trí
void sortEvenKeepOdd(int arr[], int size) {
    int temp[MAX];
    int index = 0;
    // Sao chép s? ch?n vào m?ng t?m
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            temp[index++] = arr[i];
        }
    }
    // S?p x?p s? ch?n tang d?n
    for (int i = 0; i < index - 1; ++i) {
        for (int j = i + 1; j < index; ++j) {
            if (temp[i] > temp[j]) {
                swap(temp[i], temp[j]);
            }
        }
    }
    // Ghi l?i vào m?ng g?c
    index = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            arr[i] = temp[index++];
        }
    }
}

// 9. S?p x?p m?ng: s? l? ? d?u m?ng, s? ch?n ? cu?i m?ng
void sortOddEven(int arr[], int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        while (left < right && arr[left] % 2 != 0) ++left;
        while (left < right && arr[right] % 2 == 0) --right;
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
}

int main() {
    int a[MAX];
    int n;

    // Nh?p và t?o m?ng ng?u nhiên
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    if (n > MAX) n = MAX;

    cout << "Nhap cac phan tu trong mang:" << endl;
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;  // Gi? s? s? ng?u nhiên t? 0 d?n 99
    }

    // Hi?n th? m?ng
    cout << "Mang:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Các bài toán
    int x;
    
    // 1. Li?t kê s? nguyên t? nh? hon n
    cout << "Nhap gia tri n de liet ke so nguyen to: ";
    cin >> n;
    listPrimes(n);

    // 2. Tính t?ng các ph?n t? có ch? s? d?u là ch? s? l?
    cout << "Tong cac phan tu co chu so dau la chu so le: " << sumOddFirstDigit(a, n) << endl;

    // 3. Li?t kê s? l?n xu?t hi?n c?a các ph?n t?
    cout << "So lan xuat hien cua cac phan tu:" << endl;
    countOccurrences(a, n);

    // 4. S?p x?p m?ng: s? ch?n tang d?n, s? l? gi?m d?n
    sortEvenOdd(a, n);
    cout << "Mang sau khi sap xep: so chan tang dan, so le giam dan:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 5. Tìm dãy con gi?m dài nh?t trong m?ng
    cout << "Dai nhat cua day con giam la: " << longestDecreasingSubsequence(a, n) << endl;

    // 6. Tìm s? nh? th? 2 trong m?ng
    int secondSmall = secondSmallest(a, n);
    if (secondSmall == -1) {
        cout << "Khong co so nho thu hai trong mang" << endl;
    } else {
        cout << "So nho thu hai trong mang la: " << secondSmall << endl;
    }

    // 7. Tìm các ph?n t? có ch?a các ch? s? c?a x
    cout << "Nhap so x co 2 chu so: ";
    cin >> x;
    findElementsContainingDigits(a, n, x);

    // 8. S?p x?p m?ng sao cho các ph?n t? ch?n tang d?n, các ph?n t? l? gi? nguyên v? trí
    sortEvenKeepOdd(a, n);
    cout << "Mang sau khi sap xep: so chan tang dan, so le giu nguyen vi tri:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 9. S?p x?p m?ng: s? l? ? d?u m?ng, s? ch?n ? cu?i m?ng
    sortOddEven(a, n);
    cout << "Mang sau khi sap xep: so le o dau, so chan o cuoi:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

