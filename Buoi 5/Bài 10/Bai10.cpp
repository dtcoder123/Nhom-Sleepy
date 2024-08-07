#include <stdio.h>


int timKiemNhiPhan(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;


        if (arr[mid] == x) {
            return mid;
        }

  
        if (arr[mid] > x) {
            return timKiemNhiPhan(arr, left, mid - 1, x);
        }

      
        return timKiemNhiPhan(arr, mid + 1, right, x);
    }

   
    return -1;
}

int main() {
    int n, x;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu da sap xep cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    int result = timKiemNhiPhan(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Phan tu %d duoc tim thay tai chi so %d\n", x, result);
    } else {
        printf("Phan tu %d khong co trong mang\n", x);
    }

    return 0;
}

