#include <iostream>
using namespace std;

// Definisi struct Mahasiswa
struct Mahasiswa {
string nama;
int umur;
string nik; // NIK disimpan sebagai string
};

int main() {
const int jumlahMahasiswa = 3; // Jumlah mahasiswa
Mahasiswa mhs[jumlahMahasiswa]; // Array of struct Mahasiswa

// Mengisi data mahasiswa
for (int i = 0; i < jumlahMahasiswa; i++) {
cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
getline(cin, mhs[i].nama); // Menggunakan getline untuk menangkap nama yang mengandung spasi
cout << "Masukkan umur: ";
cin >> mhs[i].umur;
cin.ignore(); // Mengabaikan newline leftover dari cin
cout << "Masukkan NIK: ";

getline(cin, mhs[i].nik); // Menggunakan getline untuk menangkap NIK yang mengandung spasi
cout << endl; // Baris kosong untuk pemisah
}
// Menampilkan data mahasiswa
cout << "\nData Mahasiswa:" << endl;
for (int i = 0; i < jumlahMahasiswa; i++) {
cout << "Mahasiswa " << i + 1 << ":" << endl;
cout << "Nama: " << mhs[i].nama << endl;
cout << "Umur: " << mhs[i].umur << endl;
cout << "NIK: " << mhs[i].nik << endl;
cout << endl; // Baris kosong untuk pemisah
}
return 0;
}
