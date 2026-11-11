#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Struktur untuk menyimpan data produk
struct Produk {
    string nama;
    double hargaSatuan;
    int jumlahTerjual;
    double pendapatan;
};

int main() {
    int jumlahProduk;

    // Input jumlah produk
    cout << "Masukkan jumlah produk: ";
    cin >> jumlahProduk;

    // 4. Tangani kasus jika jumlah produk yang dimasukkan adalah 0 atau negatif
    if (jumlahProduk <= 0) {
        cout << "\nError: Jumlah produk harus lebih besar dari 0!" << endl;
        return 1; // Keluar program dengan status error
    }

    // 1. Gunakan array dinamis untuk menyimpan data produk
    Produk* daftarProduk = new Produk[jumlahProduk];

    cout << "\nMasukkan data produk (nama produk, harga satuan, jumlah terjual):\n";
    for (int i = 0; i < jumlahProduk; i++) {
        cout << "\nProduk " << (i + 1) << ":\n";
        cout << "  Nama produk   : ";
        cin >> (daftarProduk + i)->nama;
        cout << "  Harga satuan  : ";
        cin >> (daftarProduk + i)->hargaSatuan;
        cout << "  Jumlah terjual: ";
        cin >> (daftarProduk + i)->jumlahTerjual;

        // Hitung pendapatan per produk (harga satuan * jumlah terjual)
        (daftarProduk + i)->pendapatan = (daftarProduk + i)->hargaSatuan * (daftarProduk + i)->jumlahTerjual;
    }

    // 2. Hitung total pendapatan dan rata-rata pendapatan per produk
    double totalPendapatan = 0;
    int indexTertinggi = 0;

    for (int i = 0; i < jumlahProduk; i++) {
        totalPendapatan += (daftarProduk + i)->pendapatan;

        // 3. Cari produk dengan pendapatan tertinggi
        if ((daftarProduk + i)->pendapatan > (daftarProduk + indexTertinggi)->pendapatan) {
            indexTertinggi = i;
        }
    }

    double rataRataPendapatan = totalPendapatan / jumlahProduk;

    // Menampilkan Output
    cout << "\n----------------------------------------\n";
    cout << "Output:\n";
    cout << fixed << setprecision(0);
    cout << "Total pendapatan: Rp " << totalPendapatan << endl;
    cout << "Rata-rata pendapatan per produk: Rp " << rataRataPendapatan << endl;
    
    // 3. Tampilkan produk dengan pendapatan tertinggi
    cout << "Produk dengan pendapatan tertinggi: \"" << (daftarProduk + indexTertinggi)->nama 
         << "\" (Rp " << (daftarProduk + indexTertinggi)->pendapatan << ")" << endl;

    // Dealokasi memori dinamis untuk mencegah memory leak
    delete[] daftarProduk;

    return 0;
}