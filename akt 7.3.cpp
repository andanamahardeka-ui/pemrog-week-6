#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Karyawan {
string nama;
int umur;
string nik;
string jabatan;
};

int main() {
const int jumlahKaryawan = 1000;
Karyawan kry[jumlahKaryawan];
int count = 0;
ifstream inputFile("karyawan.txt");
if (!inputFile) {
cerr << "Tidak dapat membuka file!" << endl;
return 1;
}
string line;
while (getline(inputFile, line) && count < jumlahKaryawan) {
stringstream ss(line);
ss >> kry[count].nama >> kry[count].umur >> kry[count].nik >> kry[count].jabatan;
count++;
}
inputFile.close();
cout << "Data Karyawan:" << endl;
for (int i = 0; i < count; i++) {
cout << "Karyawan " << i + 1 << ":" << endl;
cout << "Nama: " << kry[i].nama << endl;
cout << "Umur: " << kry[i].umur << endl;
cout << "NIK: " << kry[i].nik << endl;
cout << "Jabatan: " << kry[i].jabatan << endl;
cout << endl; // Baris kosong untuk pemisah
}


int x = 0;
string nama;
int umur;
string nik;
string jabatan;
cout << "Menu: " << endl;
cout << "1. Tambah data karyawan" << endl;
cout << "2. Edit data karyawan" << endl;
cout << "3. Hapus data karyawan" << endl;

cout << "Pilih menu: " << endl;
cin >> x;
switch(x){
	case 1:
		cout << "Masukkan nama: " << endl;
		cin >> nama;
		cout << "Masukkan umur: " << endl;
		cin >> umur;
		cout << "Masukkan nik: " << endl;
		cin >> nik;
		cout << "Masukkan jabatan: " << endl;
		cin >> jabatan;
		cout << "Data yang baru: " << endl;
		cout << "Nama: " << 
}


return 0;
}
