#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Struktur untuk menyimpan data proyek
struct Proyek {
    string nama;
    double anggaran;
    int pekerja;
};

// Fungsi untuk menampilkan daftar proyek
void tampilkanDaftarProyek(Proyek* arr, int ukuran) {
    if (ukuran <= 0) {
        cout << "(Tidak ada proyek dalam daftar)\n";
        return;
    }
    for (int i = 0; i < ukuran; i++) {
        cout << "Proyek " << (i + 1) << ": \"" << (arr + i)->nama 
             << "\", Anggaran: Rp " << fixed << setprecision(0) << (arr + i)->anggaran 
             << ", Pekerja: " << (arr + i)->pekerja << endl;
    }
}

int main() {
    int jumlahProyek;

    // Input jumlah proyek awal
    cout << "Masukkan jumlah proyek: ";
    cin >> jumlahProyek;

    // 4. Tangani kasus jika jumlah proyek 0 atau negatif
    if (jumlahProyek <= 0) {
        cout << "\nError: Jumlah proyek tidak valid (harus lebih dari 0)!" << endl;
        return 1;
    }

    // 1. Alokasi array dinamis untuk menyimpan data proyek
    Proyek* daftarProyek = new Proyek[jumlahProyek];

    cout << "\nMasukkan data proyek:\n";
    for (int i = 0; i < jumlahProyek; i++) {
        cout << "Proyek " << (i + 1) << ":\n";
        cout << "  Nama Proyek : ";
        cin >> ws; // Membersihkan whitespace sebelum input string
        getline(cin, (daftarProyek + i)->nama);
        cout << "  Anggaran    : Rp ";
        cin >> (daftarProyek + i)->anggaran;
        cout << "  Pekerja     : ";
        cin >> (daftarProyek + i)->pekerja;

        // 4. Tangani kasus jika anggaran atau jumlah pekerja negatif
        if ((daftarProyek + i)->anggaran < 0 || (daftarProyek + i)->pekerja < 0) {
            cout << "\nError: Anggaran dan jumlah pekerja tidak boleh bernilai negatif!\n";
            delete[] daftarProyek;
            return 1;
        }
    }

    // Operasi Tambah Proyek Baru
    cout << "\n--- Operasi Tambah Proyek ---\n";
    string namaBaru;
    double anggaranBaru;
    int pekerjaBaru;

    cout << "Proyek: \"";
    cin >> ws;
    getline(cin, namaBaru);
    cout << "Anggaran: Rp ";
    cin >> anggaranBaru;
    cout << "Pekerja: ";
    cin >> pekerjaBaru;

    if (anggaranBaru < 0 || pekerjaBaru < 0) {
        cout << "\nError: Anggaran dan jumlah pekerja baru tidak boleh negatif!\n";
        delete[] daftarProyek;
        return 1;
    }

    // 2. Alokasi ulang array dinamis dengan ukuran lebih besar (+1)
    int ukuranBaru = jumlahProyek + 1;
    Proyek* tempProyek = new Proyek[ukuranBaru];

    // Salin data lama ke array sementara
    for (int i = 0; i < jumlahProyek; i++) {
        *(tempProyek + i) = *(daftarProyek + i);
    }

    // Tambahkan data baru di indeks terakhir
    (tempProyek + jumlahProyek)->nama = namaBaru;
    (tempProyek + jumlahProyek)->anggaran = anggaranBaru;
    (tempProyek + jumlahProyek)->pekerja = pekerjaBaru;

    // Hapus memori lama dan arahkan pointer ke array baru
    delete[] daftarProyek;
    daftarProyek = tempProyek;
    jumlahProyek = ukuranBaru;

    // Tampilkan hasil setelah penambahan
    cout << "\nDaftar proyek setelah penambahan:\n";
    tampilkanDaftarProyek(daftarProyek, jumlahProyek);

    // Operasi Hapus Proyek Tertentu
    cout << "\n--- Operasi Hapus Proyek ---\n";
    int indeksHapus;
    cout << "Indeks proyek yang dihapus (1 s.d " << jumlahProyek << "): ";
    cin >> indeksHapus;

    // 4. Tangani kasus indeks proyek tidak valid saat menghapus
    if (indeksHapus < 1 || indeksHapus > jumlahProyek) {
        cout << "\nError: Indeks proyek yang dimasukkan tidak valid!\n";
        delete[] daftarProyek;
        return 1;
    }

    // Konversi indeks ke format 0-based
    int targetIndex = indeksHapus - 1;

    // 2. Alokasi ulang array dinamis dengan ukuran lebih kecil (-1)
    ukuranBaru = jumlahProyek - 1;
    tempProyek = (ukuranBaru > 0) ? new Proyek[ukuranBaru] : nullptr;

    int k = 0;
    for (int i = 0; i < jumlahProyek; i++) {
        if (i == targetIndex) continue; // Lewati elemen yang akan dihapus
        *(tempProyek + k) = *(daftarProyek + i);
        k++;
    }

    delete[] daftarProyek;
    daftarProyek = tempProyek;
    jumlahProyek = ukuranBaru;

    // Tampilkan hasil setelah penghapusan
    cout << "\nDaftar proyek setelah penghapusan:\n";
    tampilkanDaftarProyek(daftarProyek, jumlahProyek);

    // 3. Hitung total anggaran, rata-rata pekerja, dan proyek dengan anggaran terbesar
    if (jumlahProyek > 0) {
        double totalAnggaran = 0;
        int totalPekerja = 0;
        int indexTerbesar = 0;

        for (int i = 0; i < jumlahProyek; i++) {
            totalAnggaran += (daftarProyek + i)->anggaran;
            totalPekerja += (daftarProyek + i)->pekerja;

            if ((daftarProyek + i)->anggaran > (daftarProyek + indexTerbesar)->anggaran) {
                indexTerbesar = i;
            }
        }

        double rataRataPekerja = (double)totalPekerja / jumlahProyek;

        cout << "\nOutput Analisis:\n";
        cout << "Total anggaran seluruh proyek: Rp " << totalAnggaran << endl;
        cout << "Rata-rata jumlah pekerja per proyek: " << fixed << setprecision(2) << rataRataPekerja << endl;
        cout << "Proyek dengan anggaran terbesar: \"" << (daftarProyek + indexTerbesar)->nama 
             << "\" (Rp " << (daftarProyek + indexTerbesar)->anggaran << ")" << endl;
    } else {
        cout << "\n(Tidak ada data tersisa untuk dianalisis)\n";
    }

    // Dealokasi akhir memori heap
    if (daftarProyek != nullptr) {
        delete[] daftarProyek;
    }

    return 0;
}