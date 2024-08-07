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
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void tinhTongTungDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
        printf("Tong dong %d: %d\n", i, tong);
    }
}

void xuatPhanTuLonNhatTungCot(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Phan tu lon nhat cot %d: %d\n", j, max);
    }
}

void xuatPhanTuDuongBien(int a[MAX][MAX], int m, int n) {
    printf("Phan tu duong bien:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", a[0][j]);
    }
    for (int i = 1; i < m - 1; i++) {
        printf("%d ", a[i][0]);
        printf("%d ", a[i][n-1]);
    }
    for (int j = 0; j < n; j++) {
        printf("%d ", a[m-1][j]);
    }
    printf("\n");
}

int laCucDai(int a[MAX][MAX], int m, int n, int i, int j) {
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++) {
        int ni = i + x[k];
        int nj = j + y[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[i][j] <= a[ni][nj]) {
            return 0;
        }
    }
    return 1;
}

void xuatCucDai(int a[MAX][MAX], int m, int n) {
    printf("Cac phan tu cuc dai:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laCucDai(a, m, n, i, j)) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

int laHoangHau(int a[MAX][MAX], int m, int n, int i, int j) {
    for (int k = 0; k < m; k++) {
        if (a[k][j] > a[i][j]) {
            return 0;
        }
    }
    for (int k = 0; k < n; k++) {
        if (a[i][k] > a[i][j]) {
            return 0;
        }
    }
    return 1;
}

void xuatHoangHau(int a[MAX][MAX], int m, int n) {
    printf("Cac phan tu hoang hau:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laHoangHau(a, m, n, i, j)) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

int laDiemYenNgua(int a[MAX][MAX], int m, int n, int i, int j) {
    int maxDong = a[i][j];
    for (int k = 0; k < n; k++) {
        if (a[i][k] > maxDong) {
            maxDong = a[i][k];
        }
    }
    int minCot = a[i][j];
    for (int k = 0; k < m; k++) {
        if (a[k][j] < minCot) {
            minCot = a[k][j];
        }
    }
    return (a[i][j] == maxDong) && (a[i][j] == minCot);
}

void xuatDiemYenNgua(int a[MAX][MAX], int m, int n) {
    printf("Cac phan tu diem yen ngua:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laDiemYenNgua(a, m, n, i, j)) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

void xuatDongToanSoChan(int a[MAX][MAX], int m, int n) {
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
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

void sapXepTangDanTungDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

int main() {
    int m, n;
    int a[MAX][MAX];

    printf("Nhap so dong: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);

    taoMaTran(a, m, n, 0, 100);
    printf("Ma tran ngau nhien:\n");
    xuatMaTran(a, m, n);

    printf("\nTong gia tri tung dong:\n");
    tinhTongTungDong(a, m, n);

    printf("\nPhan tu lon nhat tung cot:\n");
    xuatPhanTuLonNhatTungCot(a, m, n);

    printf("\nCac phan tu thuoc duong bien:\n");
    xuatPhanTuDuongBien(a, m, n);

    printf("\nCac phan tu cuc dai:\n");
    xuatCucDai(a, m, n);

    printf("\nCac phan tu hoang hau:\n");
    xuatHoangHau(a, m, n);

    printf("\nCac phan tu diem yen ngua:\n");
    xuatDiemYenNgua(a, m, n);

    printf("\nCac dong chi chua so chan:\n");
    xuatDongToanSoChan(a, m, n);

    sapXepTangDanTungDong(a, m, n);
    printf("\nMa tran sau khi sap xep tang dan tung dong:\n");
    xuatMaTran(a, m, n);

    return 0;
}

