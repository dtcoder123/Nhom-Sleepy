#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTran(int a[MAX][MAX], int n);
void xuatMaTran(int a[MAX][MAX], int n);
void xuatDuongCheoChinh(int a[MAX][MAX], int n);
void xuatDuongCheoSongSong(int a[MAX][MAX], int n);
int timMaxTamGiacTren(int a[MAX][MAX], int n);
void sapXepZigZag(int a[MAX][MAX], int n);
void sapXepDuongCheoChinh(int a[MAX][MAX], int n);
void sapXepDuongCheoPhu(int a[MAX][MAX], int n, int tangDan);
void sapXepDong(int a[MAX][MAX], int n);
void sapXepCot(int a[MAX][MAX], int n);
void sapXepCacDuongCheo(int a[MAX][MAX], int n);
void diChuyenChanLe(int a[MAX][MAX], int n);
int kiemTraDoiXung(int a[MAX][MAX], int n);

int main() {
    int n;
    int a[MAX][MAX];

    printf("Nhap cap cua ma tran (n >= 5): ");
    scanf("%d", &n);

    if (n < 5) {
        printf("Cap cua ma tran phai lon hon hoac bang 5.\n");
        return 1;
    }

    srand(time(0));
    taoMaTran(a, n);
    printf("Ma tran ngau nhien:\n");
    xuatMaTran(a, n);

    printf("\nCac phan tu tren duong cheo chinh:\n");
    xuatDuongCheoChinh(a, n);

    printf("\nCac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
    xuatDuongCheoSongSong(a, n);

    int max = timMaxTamGiacTren(a, n);
    printf("\nPhan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", max);

    printf("\nMa tran sau khi sap xep zig-zag:\n");
    sapXepZigZag(a, n);
    xuatMaTran(a, n);

    printf("\nDuong cheo chinh sau khi sap xep tang dan:\n");
    sapXepDuongCheoChinh(a, n);
    xuatMaTran(a, n);

    printf("\nDuong cheo phu sau khi sap xep tang dan:\n");
    sapXepDuongCheoPhu(a, n, 1);
    xuatMaTran(a, n);

    printf("\nDuong cheo phu sau khi sap xep giam dan:\n");
    sapXepDuongCheoPhu(a, n, 0);
    xuatMaTran(a, n);

    printf("\nMa tran sau khi sap xep cac dong:\n");
    sapXepDong(a, n);
    xuatMaTran(a, n);

    printf("\nMa tran sau khi sap xep cac cot:\n");
    sapXepCot(a, n);
    xuatMaTran(a, n);

    printf("\nMa tran sau khi sap xep cac duong cheo chinh va song song voi no:\n");
    sapXepCacDuongCheo(a, n);
    xuatMaTran(a, n);

    printf("\nMa tran sau khi di chuyen cac phan tu chan len tren va le xuong duoi:\n");
    diChuyenChanLe(a, n);
    xuatMaTran(a, n);

    if (kiemTraDoiXung(a, n)) {
        printf("\nMa tran doi xung qua duong cheo chinh.\n");
    } else {
        printf("\nMa tran khong doi xung qua duong cheo chinh.\n");
    }

    return 0;
}

void taoMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;  
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void xuatDuongCheoChinh(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}

void xuatDuongCheoSongSong(int a[MAX][MAX], int n) {

    for (int k = 1; k < n; k++) {
        for (int i = 0, j = k; j < n; i++, j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    for (int k = 1; k < n; k++) {
        for (int i = k, j = 0; i < n; i++, j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int timMaxTamGiacTren(int a[MAX][MAX], int n) {
    int max = a[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

void sapXepZigZag(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int index = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[index++] = a[i][j];
        }
    }


    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (temp[i] > temp[j]) {
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }


    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[index++];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }
}

void sapXepDuongCheoChinh(int a[MAX][MAX], int n) {
    int temp[MAX];


    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }
}

void sapXepDuongCheoPhu(int a[MAX][MAX], int n, int tangDan) {
    int temp[MAX];


    for (int i = 0; i < n; i++) {
        temp[i] = a[i][n - 1 - i];
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && temp[i] > temp[j]) || (!tangDan && temp[i] < temp[j])) {
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        a[i][n - 1 - i] = temp[i];
    }
}

void sapXepDong(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
                    int tmp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = tmp;
                }
            }
        }
    }
}

void sapXepCot(int a[MAX][MAX], int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int tmp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = tmp;
                }
            }
        }
    }
}

void sapXepCacDuongCheo(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int index = 0;

   
    for (int k = 0; k < n; k++) {
        for (int i = 0, j = k; j < n; i++, j++) {
            temp[index++] = a[i][j];
        }
        for (int i = k, j = 0; i < n; i++, j++) {
            temp[index++] = a[i][j];
        }
    }


    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (temp[i] > temp[j]) {
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }


    index = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0, j = k; j < n; i++, j++) {
            a[i][j] = temp[index++];
        }
        for (int i = k, j = 0; i < n; i++, j++) {
            a[i][j] = temp[index++];
        }
    }
}

void diChuyenChanLe(int a[MAX][MAX], int n) {
    int chan[MAX * MAX], le[MAX * MAX];
    int indexChan = 0, indexLe = 0;

  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                chan[indexChan++] = a[i][j];
            } else {
                le[indexLe++] = a[i][j];
            }
        }
    }

  
    int index = 0;
    for (int i = 0; i < indexChan; i++) {
        a[index / n][index % n] = chan[i];
        index++;
    }
    for (int i = 0; i < indexLe; i++) {
        a[index / n][index % n] = le[i];
        index++;
    }
}

int kiemTraDoiXung(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] != a[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

