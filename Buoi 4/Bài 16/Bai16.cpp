#include <stdio.h>

#define MAX 100 


int memo[MAX];


void initMemo() {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1; 
    }
}


int Y_n_simple(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return Y_n_simple(n - 1) + 2 * Y_n_simple(n - 2) + 3 * Y_n_simple(n - 3);
}


int Y_n_memo(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    
    if (memo[n] != -1) return memo[n];
    
    memo[n] = Y_n_memo(n - 1) + 2 * Y_n_memo(n - 2) + 3 * Y_n_memo(n - 3);
    return memo[n];
}

int main() {
    int n;
    int choice;
    
    printf("Nhap n: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("n phai lon hon hoac bang 1.\n");
        return 1;
    }
    
    printf("Chon phuong phap tinh (1: De quy don gian, 2: De quy voi memoization): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Y_%d (De quy don gian) = %d\n", n, Y_n_simple(n));
            break;
        case 2:
            initMemo();
            printf("Y_%d (De quy voi memoization) = %d\n", n, Y_n_memo(n));
            break;
        default:
            printf("Lua chon khong hop le.\n");
            return 1;
    }
    
    return 0;
}

