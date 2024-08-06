#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTran(int a[MAX][MAX], int m, int n, int min, int max) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void xuatCotToanSoLe(int a[MAX][MAX], int m, int n) {
    printf("Cac cot chi chua so le:\n");
    for (int j = 0; j < n; j++) {
        int toanLe = 1;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                toanLe = 0;
                break;
            }
        }
        if (toanLe) {
            printf("Cot %d: ", j);
            for (int i = 0; i < m; i++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

int timMaxBien(int a[MAX][MAX], int m, int n) {
    int maxBien = a[0][0];
    for (int j = 0; j < n; j++) {
        if (a[0][j] > maxBien) maxBien = a[0][j];
        if (a[m-1][j] > maxBien) maxBien = a[m-1][j];
    }
    for (int i = 1; i < m-1; i++) {
        if (a[i][0] > maxBien) maxBien = a[i][0];
        if (a[i][n-1] > maxBien) maxBien = a[i][n-1];
    }
    return maxBien;
}

int demSo2(int n) {
    while (n > 0) {
        if (n % 10 == 2) return 1;
        n /= 10;
    }
    return 0;
}

int demSoChuSo2(int a[MAX][MAX], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (demSo2(a[i][j])) {
                dem++;
            }
        }
    }
    return dem;
}

int laCucTieu(int a[MAX][MAX], int m, int n, int i, int j) {
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++) {
        int ni = i + x[k];
        int nj = j + y[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[i][j] >= a[ni][nj]) {
            return 0;
        }
    }
    return 1;
}

void xuatCucTieu(int a[MAX][MAX], int m, int n) {
    printf("Cac phan tu cuc tieu:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laCucTieu(a, m, n, i, j)) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

void sapXepDongTangGiam(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

void sapXepCotTangGiam(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

int kiemTraZicZac(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] <= a[i][j + 1] || a[i][j] <= a[i + 1][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void lietKeDongToanSoChan(int a[MAX][MAX], int m, int n) {
    printf("Cac dong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        int toanChan = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                toanChan = 0;
                break;
            }
        }
        if (toanChan) {
            printf("Dong %d\n", i);
        }
    }
}

void lietKeDongGiamDan(int a[MAX][MAX], int m, int n) {
    printf("Cac dong chua gia tri giam dan:\n");
    for (int i = 0; i < m; i++) {
        int giamDan = 1;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) {
                giamDan = 0;
                break;
            }
        }
        if (giamDan) {
            printf("Dong %d\n", i);
        }
    }
}

int timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int maxCount = 0;
    int maxValue = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < n; l++) {
                    if (a[i][j] == a[k][l]) {
                        count++;
                    }
                }
            }
            if (count > maxCount) {
                maxCount = count;
                maxValue = a[i][j];
            }
        }
    }
    return maxValue;
}

void lietKeChuSoXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int count[10] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp = a[i][j];
            while (temp > 0) {
                count[temp % 10]++;
                temp /= 10;
            }
        }
    }
    int maxCount = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }
    printf("Cac chu so xuat hien nhieu nhat:\n");
    for (int i = 0; i < 10; i++) {
        if (count[i] == maxCount) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void lietKeCotTongNhoNhat(int a[MAX][MAX], int m, int n) {
    int minSum = 0;
    for (int i = 0; i < m; i++) {
        minSum += a[i][0];
    }
    for (int j = 1; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }
    printf("Cac cot co tong nho nhat:\n");
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum == minSum) {
            printf("Cot %d\n", j);
        }
    }
}

void hoanViHaiCot(int a[MAX][MAX], int m, int n, int i, int j) {
    for (int k = 0; k < m; k++) {
        int temp = a[k][i];
        a[k][i] = a[k][j];
        a[k][j] = temp;
    }
}

void hoanViHaiDong(int a[MAX][MAX], int m, int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        int temp = a[i][k];
        a[i][k] = a[j][k];
        a[j][k] = temp;
    }
}

int main() {
    int m, n;
    int a[MAX][MAX];

    printf("Nhap so dong m: ");
    scanf("%d", &m);
    printf("Nhap so cot n: ");
    scanf("%d", &n);

    taoMaTran(a, m, n, 0, 20);
    printf("Ma tran:\n");
    xuatMaTran(a, m, n);

    printf("\nCac cot chi chua so le:\n");
    xuatCotToanSoLe(a, m, n);

    printf("\nPhan tu lon nhat tren bien: %d\n", timMaxBien(a, m, n));

    printf("\nSo phan tu co chu so 2: %d\n", demSoChuSo2(a, m, n));

    printf("\nCac phan tu cuc tieu:\n");
    xuatCucTieu(a, m, n);

    printf("\nSap xep cac dong tang/giam dan:\n");
    sapXepDongTangGiam(a, m, n);
    xuatMaTran(a, m, n);

    printf("\nSap xep cac cot tang/giam dan:\n");
    sapXepCotTangGiam(a, m, n);
    xuatMaTran(a, m, n);

    printf("\nKiem tra ma tran giam dan theo zic zac: %s\n", kiemTraZicZac(a, m, n) ? "Co" : "Khong");

    printf("\nCac dong chi chua so chan:\n");
    lietKeDongToanSoChan(a, m, n);

    printf("\nCac dong chua gia tri giam dan:\n");
    lietKeDongGiamDan(a, m, n);

    printf("\nGia tri xuat hien nhieu nhat: %d\n", timGiaTriXuatHienNhieuNhat(a, m, n));

    printf("\nCac chu so xuat hien nhieu nhat:\n");
    lietKeChuSoXuatHienNhieuNhat(a, m, n);

    printf("\nCac cot co tong nho nhat:\n");
    lietKeCotTongNhoNhat(a, m, n);

    printf("\nHoan vi cot 1 va 2:\n");
    hoanViHaiCot(a, m, n, 1, 2);
    xuatMaTran(a, m, n);

    printf("\nHoan vi dong 1 va 2:\n");
    hoanViHaiDong(a, m, n, 1, 2);
    xuatMaTran(a, m, n);

    return 0;
}

