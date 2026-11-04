#include <iostream>
using namespace std;

void fillArray(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) { // Diperbaiki dari i <= size menjadi i < size
        arr[i] = value;
    }
}

int main() {
    int arr[5];
    fillArray(arr, 5, 10);
    cout << "Array setelah diisi: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}