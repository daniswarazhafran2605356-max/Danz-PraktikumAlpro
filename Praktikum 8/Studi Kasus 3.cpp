#include <iostream>
#include <iomanip>

using namespace std;

// Fungsi untuk mengalokasikan memori dinamis untuk matriks (2D array menggunakan pointer ke pointer)
int** alokasiMatriks(int baris, int kolom) {
    int** matriks = new int*[baris];
    for (int i = 0; i < baris; i++) {
        matriks[i] = new int[kolom]();
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

// 3. Fungsi rekursif untuk menampilkan matriks baris per baris
void tampilkanRekursif(int** matriks, int baris, int kolom, int i = 0, int j = 0) {
    // Base case: jika baris sudah habis, hentikan rekursi
    if (i >= baris) return;

    // Cetak elemen pada kolom saat ini dengan format lebar tetap
    cout << setw(6) << *(*(matriks + i) + j) << " ";

    // Jika sudah mencapai kolom terakhir, pindah ke baris berikutnya
    if (j + 1 >= kolom) {
        cout << endl;
        tampilkanRekursif(matriks, baris, kolom, i + 1, 0);
    } else {
        // Lanjutkan ke kolom berikutnya di baris yang sama
        tampilkanRekursif(matriks, baris, kolom, i, j + 1);
    }
}

int main() {
    int baris, kolom;

    // Input ukuran Matriks
    cout << "Masukkan jumlah baris matriks: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom matriks: ";
    cin >> kolom;

    // 1. Alokasi array dinamis 2D untuk Matriks Asli dan Matriks Transpose
    int** matriksAsli = alokasiMatriks(baris, kolom);
    // Untuk transpose, ukuran baris dan kolom ditukar (kolom x baris)
    int** matriksTranspose = alokasiMatriks(kolom, baris);

    // Input elemen Matriks Asli
    cout << "\nMasukkan elemen Matriks (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Matriks[" << i << "][" << j << "] = ";
            cin >> *(*(matriksAsli + i) + j);
        }
    }

    // Proses Transpose Matriks (baris ditukar dengan kolom)
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            *(*(matriksTranspose + j) + i) = *(*(matriksAsli + i) + j);
        }
    }

    // 2. Tampilkan matriks asli dan matriks hasil transpose menggunakan fungsi rekursif
    cout << "\nMatriks asli:\n";
    tampilkanRekursif(matriksAsli, baris, kolom);

    cout << "\nMatriks transpose:\n";
    tampilkanRekursif(matriksTranspose, kolom, baris);

    // Dealokasi memori untuk mencegah memory leak
    dealokasiMatriks(matriksAsli, baris);
    dealokasiMatriks(matriksTranspose, kolom);

    return 0;
}