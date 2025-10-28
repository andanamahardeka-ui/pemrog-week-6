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
struct Karyawan karyawan[100];


int tampilkanData();
int tambahKaryawan();
int editKaryawan();
int hapusKaryawan();

int main(){
    //Tampilkan opsi
    while(true){
        int opsi1;
        cout<<"\n\n";
        cout<<"(1) Tampilkan semua data karyawan"<<endl;
        cout<<"(2) Tambahkan karyawan baru"<<endl;
        cout<<"(3) Edit data karyawan berdasarkan NIK"<<endl;
        cout<<"(4) Hapus karyawan berdasarkan NIK"<<endl;
        cin>>opsi1;

        switch(opsi1)
        {
            case 1: tampilkanData(); break;
            case 2: tambahKaryawan(); break;
            case 3: editKaryawan(); break;
            case 4: hapusKaryawan(); break;
        }
    }


    return 0;
}

int tampilkanData(){
    int count = 0;
    string line;
   
    ifstream inputFile("karyawan.txt");
    if(!inputFile){
        cout<<"File tidak bisa dibuka"<<endl;
        return 0;
    }

    while (getline(inputFile, line) && count < 100) {
        stringstream ss(line);
        ss >> karyawan[count].nama >> karyawan[count].umur >> karyawan[count].nik>> karyawan[count].jabatan;
        count++;


    }

    cout<<"\n";
    for (int i = 0; i<count; i++){
        cout << "Nama: " << karyawan[i].nama << endl;
        cout << "Umur: " << karyawan[i].umur << endl;
        cout << "NIK: " << karyawan[i].nik << endl;
        cout << "Jabatan: " << karyawan[i].jabatan << endl;
        cout << "-------------------\n";
    }

    return 0;
}

int tambahKaryawan(){
    int jumlahDiinput;
    cout<<"-------------------\n";
    cout<<"Jumlah karyawan yang ingin di input: ";
    cin>> jumlahDiinput;
    cin.ignore();

    ofstream fileOutput("karyawan.txt", ios::app);
    for(int i = 0; i<jumlahDiinput; i++){
        cout<<"\nMahasiswa ke-"<<i+1<<endl;
        cout<<"Nama: ";
        getline(cin, karyawan[i].nama);
        cout<<"Umur: ";
        cin>>karyawan[i].umur;
        cout<<"NIK:";
        cin>>karyawan[i].nik;
        cout<<"Jabatan: ";
        cin>>karyawan[i].jabatan;

        fileOutput<<karyawan[i].nama<< " ";
        fileOutput<<karyawan[i].umur<< " ";
        fileOutput<<karyawan[i].nik<< " ";
        fileOutput<<karyawan[i].jabatan<< " ";
        fileOutput<<"\n";
    }
    cout<<"Berhasil ditambahkan!"<<endl;
    fileOutput.close();
    return 0;
}
int editKaryawan(){
    int count = 0;
    int opsi2;
    int letakIndex;
    string editNik;
    string line;
    string namaBaru;
    int umurBaru;
    string nikBaru;
    string jabatanBaru;
    bool nikDitemukan = false;
   
    cout<<"Masukkan NIK karyawan yang ingin diedit: ";
    cin>>editNik;


    ifstream inputFile("karyawan.txt");


    while(getline(inputFile, line)){
        stringstream ss(line);
        ss >> karyawan[count].nama >> karyawan[count].umur >> karyawan[count].nik>> karyawan[count].jabatan;
        if(editNik == karyawan[count].nik){
            cout<<"-------------------\n";
            cout<<"Data karyawan yang ingin diedit:"<<endl;
            cout << "Nama: " << karyawan[count].nama << endl;
            cout << "Umur: " << karyawan[count].umur << endl;
            cout << "NIK: " << karyawan[count].nik << endl;
            cout << "Jabatan: " << karyawan[count].jabatan << endl;
            letakIndex = count;
            nikDitemukan = true;
        }
        count++;
    }
    inputFile.close();


    if(!nikDitemukan){
        cout<<"NIK tidak ditemukan!!"<<endl;
        return 0;
    }


    cout<<"\nPilih properti yang ingin diedit: "<<endl;
    cout<<"(1) Nama \n(2) Umur \n(3) NIK \n(4) Jabatan \n(5) Kembali "<<endl;
    cin>>opsi2;


    switch(opsi2){
        case 1: cout<<"Nama baru: "; cin>>namaBaru; karyawan[letakIndex].nama = namaBaru; break;
        case 2: cout<<"Ganti umur menjadi: "; cin>>umurBaru; karyawan[letakIndex].umur = umurBaru; break;
        case 3: cout<<"Ganti NIK menjadi: "; cin>>nikBaru; karyawan[letakIndex].nik = nikBaru; break;
        case 4: cout<<"Ganti jabatan menjadi: "; cin>>jabatanBaru; karyawan[letakIndex].jabatan = jabatanBaru; break;
        case 5: return 0;
        default: cout<<"Opsi tidak valid!";
    }
   
    ofstream outputFile("karyawan.txt");
    for(int i = 0; i < count; i++){  
        outputFile << karyawan[i].nama << " ";
        outputFile << karyawan[i].umur << " ";
        outputFile << karyawan[i].nik << " ";
        outputFile << karyawan[i].jabatan << "\n";
    }
    outputFile.close();
    cout<<"Suksessss!!"<<endl;
    return 0;
}

int hapusKaryawan(){
    int count = 0;
    char opsi3;
    int letakIndex;
    string hapusNik;
    string line;
    bool nikDitemukan = false;


    cout<<"Masukkan NIK karyawan yang ingin dihapus: ";
    cin>>hapusNik;


    ifstream inputFile("karyawan.txt");


    while(getline(inputFile, line)){
        stringstream ss(line);
        ss >> karyawan[count].nama >> karyawan[count].umur >> karyawan[count].nik>> karyawan[count].jabatan;
        if(hapusNik == karyawan[count].nik){
            cout<<"-------------------\n";
            cout<<"Data karyawan yang akan dihapus:"<<endl;
            cout << "Nama: " << karyawan[count].nama << endl;
            cout << "Umur: " << karyawan[count].umur << endl;
            cout << "NIK: " << karyawan[count].nik << endl;
            cout << "Jabatan: " << karyawan[count].jabatan << endl;
            letakIndex = count;
            nikDitemukan = true;
        }
        count++;
    }
    inputFile.close();


    if(!nikDitemukan){
        cout<<"NIK tidak ditemukan!!"<<endl;
        return 0;
    }

    cout<<"Apakah anda yakin ingin menghapus? (y/n)"<<endl;
    cin>>opsi3;
    if(opsi3 == 'y' || opsi3 == 'Y'){
        ofstream outputFile("karyawan.txt");


        for(int i = 0; i < count; i++){
            if(karyawan[i].nik != hapusNik){
                outputFile << karyawan[i].nama << " ";
                outputFile << karyawan[i].umur << " ";
                outputFile << karyawan[i].nik << " ";
                outputFile << karyawan[i].jabatan << "\n";
            }
        }
    cout<<"Berhasil dihapus:))"<<endl;
    }else if(opsi3 == 'n' || opsi3 == 'N'){    
       return 0;
    }

    return 0;
}
