#include <iostream>
#include <iomanip>

using namespace std;

// Fungsi rekursif untuk menghitung diskon dan total harga setelah diskon
// Mengembalikan total harga akhir secara rekursif
double hitungDiskonRekursif(double* harga, int n, int index = 0) {
    // Base case: jika sudah mencapai akhir array, kembalikan 0
    if (index >= n) {
        return 0;
    }

    double h = *(harga + index);
    double diskonPersen = 0;

    // 3. Seleksi kondisi untuk menentukan diskon berdasarkan harga barang
    if (h > 500000) {
        diskonPersen = 0.10; // Diskon 10% untuk harga di atas Rp500.000
    } else if (h > 200000) {
        diskonPersen = 0.05; // Diskon 5% untuk harga di atas Rp200.000 s.d Rp500.000
    } else {
        diskonPersen = 0.0;  // Tidak ada diskon
    }

    // 4. Menampilkan informasi diskon untuk setiap barang
    cout << "Diskon untuk barang " << (index + 1) << ": ";
    if (diskonPersen > 0) {
        cout << (int)(diskonPersen * 100) << "%" << endl;
    } else {
        cout << "Tidak ada diskon" << endl;
    }

    // Hitung harga setelah diskon untuk barang saat ini
    double hargaSetelahDiskon = h - (h * diskonPersen);

    // Rekurens: tambahkan dengan hasil dari barang berikutnya
    return hargaSetelahDiskon + hitungDiskonRekursif(harga, n, index + 1);
}

int main() {
    int jumlahBarang;

    // Input jumlah barang
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang;

    // 1. Alokasi array dinamis untuk menyimpan harga barang
    double* daftarHarga = new double[jumlahBarang];

    // Input harga masing-masing barang menggunakan pointer aritmatika
    for (int i = 0; i < jumlahBarang; i++) {
        cout << "Masukkan harga barang " << (i + 1) << ": ";
        cin >> *(daftarHarga + i);
    }

    cout << endl;

    // 2 & 4. Memanggil fungsi rekursif untuk memproses diskon dan mendapatkan total harga
    double totalHargaSetelahDiskon = hitungDiskonRekursif(daftarHarga, jumlahBarang);

    // Tampilkan total harga setelah diskon
    cout << "\nTotal harga setelah diskon: " << fixed << setprecision(0) << totalHargaSetelahDiskon << endl;

    // Dealokasi memori dinamis untuk mencegah memory leak
    delete[] daftarHarga;

    return 0;
}