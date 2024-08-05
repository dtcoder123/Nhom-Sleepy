#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
void Bai9(float *pa, float *pb) {
    float tong = *pa + *pb;
    float hieu = *pa - *pb;
    float tich = *pa * *pb;
    float thuong = *pa / *pb;

    float *pTong = &tong;
    float *pHieu = &hieu;
    float *pTich = &tich;
    float *pThuong = &thuong;

    cout << "\nTong cua a va b: " << tong;
    cout << "\nDia chi cua tong: " << static_cast<void*>(pTong);

    cout << "\nHieu cua a va b: " << hieu;
    cout << "\nDia chi cua hieu: " << static_cast<void*>(pHieu);

    cout << "\nTich cua a va b: " << tich;
    cout << "\nDia chi cua tich: " << static_cast<void*>(pTich);

    cout << "\nThuong cua a va b: " << thuong;
    cout << "\nDia chi cua thuong: " << static_cast<void*>(pThuong);
}

void Bai3() {
    float a = 5.7, b = 4.8;
    float *pa = &a;
    float *pb = &b;

    cout << "\nDia chi cua a: " << static_cast<void*>(pa);
    cout << "\nDia chi cua b: " << static_cast<void*>(pb);
    Bai9(pa, pb);
}
int main(){
	float a,b;
	Bai3();
	return 0;
}
