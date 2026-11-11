#include <iostream>
#include <iomanip>


using namespace std;


// Fungsi rekursif untuk menghitung total jumlah nilai mahasiswa
int hitungTotalRekursif(int arr[], int n) {
    // Basis rekursi: jika n sudah 0, kembalikan 0
    if (n <= 0) {
        return 0;
    }
    // Rekurens: elemen terakhir ditambah hasil rekursi untuk sisa elemen di bawahnya
    return arr[n - 1] + hitungTotalRekursif(arr, n - 1);
}


int main() {
    int n;
   
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;


    // Menangani kasus jika jumlah mahasiswa adalah 0 atau negatif
    if (n <= 0) {
        cout << "Jumlah mahasiswa tidak boleh 0 atau kurang dari 0." << endl;
        return 0;
    }


    // 1. Menggunakan array dinamis untuk menyimpan nilai mahasiswa
    int* nilai = new int[n];


    cout << "Masukkan nilai mahasiswa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << (i + 1) << ": ";
        cin >> nilai[i];
    }


    // 3. Mencari nilai terbesar dan terkecil dari array
    int nilaiTerbesar = nilai[0];
    int nilaiTerkecil = nilai[0];


    for (int i = 1; i < n; i++) {
        if (nilai[i] > nilaiTerbesar) {
            nilaiTerbesar = nilai[i];
        }
        if (nilai[i] < nilaiTerkecil) {
            nilaiTerkecil = nilai[i];
        }
    }


    // 2. Menggunakan fungsi rekursif untuk menghitung rata-rata
    double totalNilai = hitungTotalRekursif(nilai, n);
    double rataRata = totalNilai / n;


    // Menampilkan output sesuai format studi kasus
    cout << "\nOutput:\n";
    cout << "Nilai terbesar: " << nilaiTerbesar << endl;
    cout << "Nilai terkecil: " << nilaiTerkecil << endl;
    cout << "Rata-rata nilai: " << fixed << setprecision(0) << rataRata << endl;


    // Dealokasi memori array dinamis untuk mencegah memory leak
    delete[] nilai;


    return 0;
}