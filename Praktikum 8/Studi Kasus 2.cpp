#include <iostream>
#include <iomanip>

using namespace std;

// Fungsi untuk mengalokasikan memori dinamis untuk matriks (2D array menggunakan pointer ke pointer)
int** alokasiMatriks(int baris, int kolom) {
    int** matriks = new int*[baris];
    for (int i = 0; i < baris; i++) {
        matriks[i] = new int[kolom](); // Diinisialisasi dengan 0
    }
    return matriks;
}

// Fungsi untuk membebaskan memori dinamis matriks
void dealokasiMatriks(int** matriks, int baris) {
    for (int i = 0; i < baris; i++) {
        delete[] matriks[i];
    }
    delete[] matriks;
}

int main() {
    int barisA, kolomA, barisB, kolomB;

    // Input ukuran Matriks A
    cout << "Masukkan jumlah baris dan kolom Matriks A: ";
    cin >> barisA >> kolomA;

    // Input ukuran Matriks B
    cout << "Masukkan jumlah baris dan kolom Matriks B: ";
    cin >> barisB >> kolomB;

    // 3 & 4. Validasi apakah matriks dapat dikalikan (Kolom A harus sama dengan Baris B)
    if (kolomA != barisB) {
        cout << "\nError: Perkalian tidak dapat dilakukan!" << endl;
        cout << "Jumlah kolom Matriks A (" << kolomA << ") harus sama dengan jumlah baris Matriks B (" << barisB << ")." << endl;
        return 1; // Keluar program dengan status error
    }

    // 1. Alokasi array dinamis 2D untuk Matriks A, Matriks B, dan Matriks Hasil
    int** matriksA = alokasiMatriks(barisA, kolomA);
    int** matriksB = alokasiMatriks(barisB, kolomB);
    int** hasil = alokasiMatriks(barisA, kolomB);

    // Input elemen Matriks A
    cout << "\nMasukkan elemen Matriks A (" << barisA << "x" << kolomA << "):\n";
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> *(*(matriksA + i) + j); // Menggunakan pointer aritmatika
        }
    }

    // Input elemen Matriks B
    cout << "\nMasukkan elemen Matriks B (" << barisB << "x" << kolomB << "):\n";
    for (int i = 0; i < barisB; i++) {
        for (int j = 0; j < kolomB; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> *(*(matriksB + i) + j); // Menggunakan pointer aritmatika
        }
    }

    // Proses Perkalian Matriks menggunakan Pointer
    // hasil[i][j] = sum(matriksA[i][k] * matriksB[k][j])
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            *(*(hasil + i) + j) = 0; // Inisialisasi elemen hasil dengan 0
            for (int k = 0; k < kolomA; k++) {
                *(*(hasil + i) + j) += (*(*(matriksA + i) + k)) * (*(*(matriksB + k) + j));
            }
        }
    }

    // 2. Tampilkan hasil perkalian dua matriks dengan menggunakan pointer
    cout << "\nHasil perkalian Matriks A dan B:\n";
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            cout << setw(6) << *(*(hasil + i) + j) << " ";
        }
        cout << endl;
    }

    // Dealokasi memori untuk mencegah kebocoran memori (memory leak)
    dealokasiMatriks(matriksA, barisA);
    dealokasiMatriks(matriksB, barisB);
    dealokasiMatriks(hasil, barisA);

    return 0;
}