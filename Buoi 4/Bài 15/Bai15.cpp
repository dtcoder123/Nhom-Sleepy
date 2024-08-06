#include <stdio.h>


void calculateSequence(int n) {
   
    long long A[n];
  
    A[0] = 1;

   
    for (int i = 1; i < n; i++) {
        A[i] = (i + 1) * 0; 
        for (int j = 0; j < i; j++) {
            A[i] += A[j];
        }
   
        A[i] *= (i + 1);
    }


    printf("Day so A_n:\n");
    for (int i = 0; i < n; i++) {
        printf("A[%d] = %lld\n", i + 1, A[i]);
    }
}

int main() {
    int n;


    printf("Nhap so luong phan tu cua day: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("So luong phan tu phai lon hon hoac bang 1.\n");
        return 1;
    }


    calculateSequence(n);

    return 0;
}

