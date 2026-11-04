#include <iostream>
using namespace std;

void doubleValues(int arr[], int *size) {
    for (int i = 0; i < *size; i++) {
        *(arr + i) *= 2; // Diperbaiki agar nilai hasil kali disimpan kembali ke array
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    doubleValues(arr, &size);
    cout << "Array setelah nilai digandakan: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}