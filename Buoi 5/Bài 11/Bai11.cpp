#include <stdio.h>


int chiaQua(int m, int n) {
    if (n == 1 || m == 0) {
        return 1;
    }
    if (m < n) {
        return chiaQua(m, m);
    }
    return chiaQua(m, n - 1) + chiaQua(m - n, n);
}

int main() {
    int m, n;


    printf("Nhap so phan thuong m >= 2n: ");
    scanf("%d", &m);
    n = m / 2;
    printf("So cach chia %d phan thuong cho %d hoc sinh: %d\n", m, n, chiaQua(m, n));

 
    printf("Nhap so phan thuong m = n: ");
    scanf("%d", &m);
    n = m;
    printf("So cach chia %d phan thuong cho %d hoc sinh: %d\n", m, n, chiaQua(m, n));

 
    printf("Nhap so phan thuong m > 2n va moi hoc sinh deu co qua: ");
    scanf("%d", &m);
    n = (m / 2) + 1;
    printf("So cach chia %d phan thuong cho %d hoc sinh: %d\n", m, n, chiaQua(m, n));

    return 0;
}

