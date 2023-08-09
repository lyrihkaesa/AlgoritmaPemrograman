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

struct Alamat
{
    string AlamatLkp;
    string Jalan;
    string Desa;
    string Kec;
    string Kota;
    string Prop;
    string NoRuman;
};

int main()
{
    Nama pemilikKTP;
    Alamat alamate;

    cout << "Masukan Nama" << endl;
    cout << " - Depan Pemilik KTP    : ";
    cin >> pemilikKTP.namadepan;

    cout << " - Belakang Pemilik KTP : ";
    cin >> pemilikKTP.namabelakang;

    cout << "Masukan Alamat" << endl;
    cout << " - Jalan    : ";
    cin.ignore(); // Menghapus newline yang tertinggal
    getline(cin, alamate.Jalan);

    cout << " - Provinsi : ";
    getline(cin, alamate.Prop);

    // Membersihkan terminal pada Windows
    system("cls");

    // Menampilkan data yang dimasukkan
    cout << "=================================" << endl;
    cout << "Nama Pemilik KTP : " << pemilikKTP.namadepan << " " << pemilikKTP.namabelakang << endl;
    cout << "Alamat Jalan     : " << alamate.Jalan << endl;
    cout << "Alamat Propinsi  : " << alamate.Prop << endl;
    cout << "=================================" << endl;

    return 0;
}
