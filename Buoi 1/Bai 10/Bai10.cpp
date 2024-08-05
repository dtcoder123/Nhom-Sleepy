#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
void printChars(const char *st) {
    while (*st != '\0') {
        cout << *st << ' ';
        st++;
    }
    cout << endl;
}

void toUpperCase(char *st) {
    while (*st != '\0') {
        *st = toupper((unsigned char) *st);
        st++;
    }
}

void capitalizeWords(char *st) {
    bool newWord = true;
    while (*st != '\0') {
        if (isspace((unsigned char) *st)) {
            newWord = true;
        } else if (newWord) {
            *st = toupper((unsigned char) *st);
            newWord = false;
        }
        st++;
    }
}
int main(){
	char st[100];
    cout << "nhap vao chuoi: ";
    cin.getline(st, sizeof(st));
    cout << "cac ky tu trong chuoi la: ";
    printChars(st);
    toUpperCase(st);
    cout << "chuoi sau khi chuyen sang chu hoa: " << st << endl;
    strcpy(st, " ");
	capitalizeWords(st);
	return 0;
}
