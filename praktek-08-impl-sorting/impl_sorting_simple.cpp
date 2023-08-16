#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int n = 10;
int jml;

struct Nama
{
    string namadepan;
    string namabelakang;
    string namatengah;
    string namaPanggilan;
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

struct Sim
{
    Nama pemilikKTP;
    TempatTanggalLahir lahir;
    string golonganDarah;
    string jenisKelamin;
    string pekerjaan;
    Alamat alamat;
};

Sim dataSim[n];

void tukar(int a, int b)
{
    Sim temp;
    temp = dataSim[b];
    dataSim[b] = dataSim[a];
    dataSim[a] = temp;
}

void bubbleSort()
{
    for (int i = 1; i < jml; i++)
    {
        for (int j = 0; j < jml - i; j++)
        {
            if (dataSim[j].pemilikKTP.namadepan > dataSim[j + 1].pemilikKTP.namadepan)
            {
                tukar(j, j + 1);
            }
        }
    }
}

void cetakData()
{
    cout << setfill('=') << setw(80) << "=" << endl;
    cout << setfill(' ') << left << setw(5) << "No";
    cout << setw(20) << "Nama Lengkap";
    cout << setw(20) << "Tempat Lahir";
    cout << setw(15) << "Tgl Lahir";
    cout << setw(15) << "Gol. Darah";
    cout << setw(15) << "Jenis Kelamin";
    cout << setw(15) << "Pekerjaan";
    cout << setw(20) << "Alamat";
    cout << setw(10) << "No Rumah" << endl;
    cout << setfill('=') << setw(80) << "=" << endl;

    for (int i = 0; i < jml; i++)
    {
        cout << setfill(' ') << left << setw(5) << (i + 1);
        cout << setw(20) << dataSim[i].pemilikKTP.namadepan + " " + dataSim[i].pemilikKTP.namabelakang;
        cout << setw(20) << dataSim[i].lahir.tempat;
        cout << setw(5) << dataSim[i].lahir.hari << " " << dataSim[i].lahir.bulan << " " << dataSim[i].lahir.tahun;
        cout << setw(15) << dataSim[i].golonganDarah;
        cout << setw(15) << dataSim[i].jenisKelamin;
        cout << setw(15) << dataSim[i].pekerjaan;
        cout << setw(20) << dataSim[i].alamat.alamatKTP + ", " + dataSim[i].alamat.kota;
        cout << setw(10) << dataSim[i].alamat.noRumah << endl;
    }
    cout << setfill('=') << setw(80) << "=" << endl;
}

int main()
{
    cout << "===PROGRAM BUBBLE SORT===" << endl;
    // Tampilkan data awal....................
    jml = 0;
    while (jml < n)
    {
        system("cls");
        cout << "\n\nMasukkan data index [" << jml << "] : \n";
        cout << "Nama Depan   : ";
        cin >> dataSim[jml].pemilikKTP.namadepan;
        cout << "Nama Belakang: ";
        cin >> dataSim[jml].pemilikKTP.namabelakang;
        cin.ignore();
        cout << "Tempat Lahir : ";
        getline(cin, dataSim[jml].lahir.tempat);
        cout << "Hari Lahir   : ";
        getline(cin, dataSim[jml].lahir.hari);
        cout << "Bulan Lahir  : ";
        getline(cin, dataSim[jml].lahir.bulan);
        cout << "Tahun Lahir  : ";
        getline(cin, dataSim[jml].lahir.tahun);
        cout << "Golongan Darah: ";
        getline(cin, dataSim[jml].golonganDarah);
        cout << "Jenis Kelamin : ";
        getline(cin, dataSim[jml].jenisKelamin);
        cout << "Pekerjaan     : ";
        getline(cin, dataSim[jml].pekerjaan);
        cout << "Alamat KTP    : ";
        getline(cin, dataSim[jml].alamat.alamatKTP);
        cout << "Jalan         : ";
        getline(cin, dataSim[jml].alamat.jalan);
        cout << "RT            : ";
        getline(cin, dataSim[jml].alamat.rt);
        cout << "RW            : ";
        getline(cin, dataSim[jml].alamat.rw);
        cout << "Desa          : ";
        getline(cin, dataSim[jml].alamat.desa);
        cout << "Kecamatan     : ";
        getline(cin, dataSim[jml].alamat.kec);
        cout << "Kota          : ";
        getline(cin, dataSim[jml].alamat.kota);
        cout << "Provinsi      : ";
        getline(cin, dataSim[jml].alamat.provinsi);
        cout << "No Rumah      : ";
        getline(cin, dataSim[jml].alamat.noRumah);
        jml++;
        cout << "\nTambah data lagi [y/t] : ";
        char lagi;
        cin >> lagi;
        cin.ignore(); // Mengabaikan newline di buffer setelah membaca karakter 'lagi'
        if (lagi == 't' || lagi == 'T')
        {
            break;
        }
    }

    // Tampilkan data.........................
    system("cls");
    cout << "\n\nData awal : " << endl;
    cetakData();

    // Proses pengurutan data.................
    bubbleSort();

    // Tampilkan data setelah diurutkan.......
    cout << "\n\nData setelah di urutkan (sort) : " << endl;
    cetakData();
    cout << "\n\nSorting Selesai";
    return 0;
}
