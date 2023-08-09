#include <iostream>
#include <string>

using namespace std;

struct Nama
{
    char namadepan[10];
    char namabelakang[10];
    char namatengah[10];
    char namaPanggilan[10];
};

struct TempatTanggalLahir
{
    string tempat;
    string hari;
    string bulan;
    string tahun;
};

struct Alamat
{
    string alamatKTP;
    string jalan;
    string rt;
    string rw;
    string desa;
    string kec;
    string kota;
    string provinsi;
    string noRumah;
};

int main()
{
    Nama pemilikKTP;
    TempatTanggalLahir lahir;
    string golonganDarah;
    string jenisKelamin;
    string pekerjaan;
    Alamat alamate;

    cout << "Masukan Nama" << endl;

    cout << " - Depan Pemilik KTP    : ";
    cin >> pemilikKTP.namadepan;

    cout << " - Belakang Pemilik KTP : ";
    cin >> pemilikKTP.namabelakang;

    system("cls");

    cout << "Masukan Tempat Tanggal Lahir" << endl;

    cout << " - Tempat Lahir          : ";
    cin >> lahir.tempat;

    cout << " - Tanggal Lahir " << endl;

    cout << "   - hari (misal: 01)    : ";
    cin >> lahir.hari;

    cout << "   - bulan (misal: 05)   : ";
    cin >> lahir.bulan;

    cout << "   - tahun (misal: 1999) : ";
    cin >> lahir.tahun;

    system("cls");

    cout << "Golongan darah : ";
    cin >> golonganDarah;

    cout << "Jenis Kelamin  : ";
    cin.ignore(); // Menghapus newline yang tertinggal
    getline(cin, jenisKelamin);

    cout << "Pekerjaan      : ";
    getline(cin, pekerjaan);

    system("cls");

    cout << "Masukan Alamat" << endl;
    cout << " - Jalan          : ";
    getline(cin, alamate.jalan);

    cout << " - RT (misal: 05) : ";
    cin >> alamate.rt;

    cout << " - RW (misal: 03) : ";
    cin >> alamate.rw;

    cout << " - Desa           : ";
    getline(cin, alamate.desa);

    cout << " - Kecamatan      : ";
    getline(cin, alamate.kec);

    cout << " - Kota           : ";
    getline(cin, alamate.kota);

    cout << " - Provinsi       : ";
    getline(cin, alamate.provinsi);

    // Membersihkan terminal pada Windows
    system("cls");

    // Menampilkan data yang dimasukkan
    cout << "===================================================================" << endl;
    cout << "=                INDONESIA                 DRIVING LECENSIE       =" << endl;
    cout << "=          SURAT IJIN MENGEMUDI                    C              =" << endl;
    cout << "===================================================================" << endl;
    cout << " 1. " << pemilikKTP.namadepan << " " << pemilikKTP.namabelakang << endl;
    cout << " 2. " << lahir.tempat << ", " << lahir.hari << "-" << lahir.bulan << "-" << lahir.tahun << endl;
    cout << " 3. " << golonganDarah << " - " << jenisKelamin << endl;
    cout << " 4. Jl. " << alamate.jalan << endl;
    cout << "    RT " << alamate.rt << "/" << alamate.rw << " " << alamate.desa << " " << alamate.kec << endl;
    cout << "    KOTA " << alamate.kota << endl;
    cout << " 5. " << pekerjaan << endl;
    cout << " 6. " << alamate.provinsi << endl;
    cout << "===================================================================" << endl;

    return 0;
}
