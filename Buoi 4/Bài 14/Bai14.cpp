#include <stdio.h>


int U_recursive(int n) {
    if (n < 6) {
        return n;
    } else {
        return U_recursive(n-5) + U_recursive(n-4) + U_recursive(n-3) + U_recursive(n-2) + U_recursive(n-1);
    }
}


int U_dp(int n) {

    int dp[n+1];


    for (int i = 0; i < 6 && i <= n; i++) {
        dp[i] = i;
    }


    for (int i = 6; i <= n; i++) {
        dp[i] = dp[i-5] + dp[i-4] + dp[i-3] + dp[i-2] + dp[i-1];
    }

    return dp[n];
}

int main() {
    int n;
    int choice;


    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);


    if (n < 0) {
        printf("N phai la so nguyen duong.\n");
        return 1;
    }


    printf("Chen phuong phap tinh toan:\n");
    printf("1. Ðe quy\n");
    printf("2. Lap trinh dang\n");
    printf("Nhap lua chon cua ban (1 hoac 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
    
            printf("U(%d) = %d (Ðe quy)\n", n, U_recursive(n));
            break;
        case 2:

            printf("U(%d) = %d (Lap trinh dung)\n", n, U_dp(n));
            break;
        default:
            printf("Lua chon không hop le.\n");
            return 1;
    }

    return 0;
}

