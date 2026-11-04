#include <iostream>
using namespace std;

void copyString(char *src, char *dest) {
    while (*src) {
        *dest = *src; // Diperbaiki dari *dest = src; menjadi *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; // Menambahkan karakter null di akhir string
}

int main() {
    char src[] = "Hello";
    char dest[10];
    copyString(src, dest);
    cout << "Hasil copy string: " << dest << endl;
    return 0;
}