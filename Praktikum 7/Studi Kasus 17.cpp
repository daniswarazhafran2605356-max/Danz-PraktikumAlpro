#include <iostream>
using namespace std;

// Mengubah tipe pengembalian menjadi int biasa
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max; // Mengembalikan nilai max
}

int main() {
    int arr[] = {3, 5, 2, 9, 6};
    
    // Menampung hasil ke dalam variabel int biasa
    int maxVal = findMax(arr, 5);
    
    // Menampilkan langsung nilainya
    cout << "Nilai maksimum dalam array adalah: " << maxVal << endl;
    
    return 0;
}