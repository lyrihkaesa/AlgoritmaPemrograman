#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

const int maxBuku = 100;

struct Buku
{
    string judul;
    string penulis;
    int tahun;
    bool dipinjam;
    string tanggalPinjam;
    string tanggalBalik;

    int hitungLamaPinjam()
    {
        struct tm tmPinjam = {};
        struct tm tmBalik = {};

        stringstream ssPinjam(tanggalPinjam);
        ssPinjam >> get_time(&tmPinjam, "%d/%m/%Y");

        stringstream ssBalik(tanggalBalik);
        ssBalik >> get_time(&tmBalik, "%d/%m/%Y");

        time_t timePinjam = mktime(&tmPinjam);
        time_t timeBalik = mktime(&tmBalik);

        int lamaPinjam = (timeBalik - timePinjam) / (60 * 60 * 24);
        return lamaPinjam;
    }
};

void pinjamBuku(Buku koleksiBuku[], int jmlBuku)
{
    cout << "Masukkan judul buku yang ingin dipinjam: ";
    string judulPinjam;
    getline(cin, judulPinjam);

    bool ditemukan = false;
    for (int i = 0; i < jmlBuku; i++)
    {
        if (koleksiBuku[i].judul == judulPinjam && !koleksiBuku[i].dipinjam)
        {
            koleksiBuku[i].dipinjam = true;

            cout << "Masukkan tanggal pinjam (dd/mm/yyyy) atau tekan 'Enter' untuk hari ini: ";
            string tanggalPinjamInput;
            getline(cin, tanggalPinjamInput);

            if (tanggalPinjamInput.empty())
            {
                time_t now = time(0);
                tm *tmNow = localtime(&now);
                char buffer[11];
                strftime(buffer, sizeof(buffer), "%d/%m/%Y", tmNow);
                koleksiBuku[i].tanggalPinjam = buffer;
            }
            else
            {
                koleksiBuku[i].tanggalPinjam = tanggalPinjamInput;
            }

            cout << "Apakah Anda ingin meminjam buku selama beberapa hari atau sampai tanggal tertentu?" << endl;
            cout << "[1] Berapa Hari" << endl;
            cout << "[2] Tanggal Balik" << endl;
            cout << "Pilihan: ";
            char pilihan;
            cin >> pilihan;
            cin.ignore();

            if (pilihan == '1')
            {
                int lamaPinjam;
                cout << "Berapa hari Anda ingin meminjam buku: ";
                cin >> lamaPinjam;
                cin.ignore();

                struct tm tmPinjam = {};
                stringstream ss(koleksiBuku[i].tanggalPinjam);
                ss >> get_time(&tmPinjam, "%d/%m/%Y");
                time_t timePinjam = mktime(&tmPinjam);

                time_t timeBalik = timePinjam + (lamaPinjam * 24 * 60 * 60); // lamaPinjam hari
                tm *tmBalik = localtime(&timeBalik);
                char buffer[11];
                strftime(buffer, sizeof(buffer), "%d/%m/%Y", tmBalik);
                koleksiBuku[i].tanggalBalik = buffer;
            }
            else if (pilihan == '2')
            {
                cout << "Masukkan tanggal balik (dd/mm/yyyy): ";
                getline(cin, koleksiBuku[i].tanggalBalik);
            }
            else
            {
                cout << "Pilihan tidak valid. Buku tidak dipinjam." << endl;
                koleksiBuku[i].dipinjam = false;
            }

            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "Buku tidak ditemukan atau sudah dipinjam." << endl;
    }
}

void kembalikanBuku(Buku koleksiBuku[], int jmlBuku)
{
    cout << "Masukkan judul buku yang ingin dikembalikan: ";
    string judulKembali;
    getline(cin, judulKembali);

    bool ditemukan = false;
    for (int i = 0; i < jmlBuku; i++)
    {
        if (koleksiBuku[i].judul == judulKembali && koleksiBuku[i].dipinjam)
        {
            koleksiBuku[i].dipinjam = false;
            cout << "Buku '" << koleksiBuku[i].judul << "' berhasil dikembalikan." << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "Buku tidak ditemukan atau belum dipinjam." << endl;
    }
}

void headerKoleksiBuku()
{
    cout << "=======================================================================================================================" << endl;
    cout << "                                                 Koleksi Buku Tersedia                                                 " << endl;
    cout << "=======================================================================================================================" << endl;
    cout << left << setw(3) << "No" << setw(25) << "Judul Buku" << setw(20) << "Penulis" << setw(6) << "Tahun" << setw(10) << "Status" << setw(15) << "Tanggal Pinjam" << setw(15) << "Tanggal Balik" << setw(15) << "Lama (Hari)" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
}

void rowBuku(Buku buku, int i)
{
    cout << left << setw(3) << (i + 1);
    cout << setw(25) << buku.judul;
    cout << setw(20) << buku.penulis;
    cout << setw(6) << buku.tahun;
    if (buku.dipinjam)
    {
        cout << setw(10) << "Dipinjam";
        cout << setw(15) << buku.tanggalPinjam;
        cout << setw(15) << buku.tanggalBalik;
        cout << setw(15) << buku.hitungLamaPinjam();
    }
    else
    {
        cout << setw(10) << "Tersedia";
        cout << setw(15) << "-";
        cout << setw(15) << "-";
        cout << setw(15) << "-";
    }
    cout << endl;
}

void tampilkanKoleksiBuku(Buku koleksiBuku[], int jmlBuku)
{
    headerKoleksiBuku();

    for (int i = 0; i < jmlBuku; i++)
    {
        rowBuku(koleksiBuku[i], i);
    }

    cout << "=======================================================================================================================" << endl;
}

void urutkanBerdasarkanJudul(Buku koleksiBuku[], int jmlBuku)
{
    sort(koleksiBuku, koleksiBuku + jmlBuku, [](const Buku &a, const Buku &b)
         { return a.judul < b.judul; });

    cout << "Koleksi buku berhasil diurutkan berdasarkan judul." << endl;
}

void cariBuku(Buku koleksiBuku[], int jmlBuku)
{
    cout << "Masukkan judul buku yang ingin dicari: ";
    string judulCari;
    getline(cin, judulCari);

    headerKoleksiBuku();

    bool ditemukan = false;
    for (int i = 0; i < jmlBuku; i++)
    {
        if (koleksiBuku[i].judul.find(judulCari) != string::npos)
        {
            rowBuku(koleksiBuku[i], i);
            ditemukan = true;
        }
    }

    if (!ditemukan)
    {
        cout << "Buku tidak ditemukan." << endl;
    }

    cout << "=======================================================================================================================" << endl;
}

void tambahBuku(Buku koleksiBuku[], int &jmlBuku)
{
    if (jmlBuku < maxBuku)
    {
        cout << "Masukkan judul buku                 : ";
        getline(cin, koleksiBuku[jmlBuku].judul);
        cout << "Masukkan penulis buku               : ";
        getline(cin, koleksiBuku[jmlBuku].penulis);
        cout << "Masukkan tahun terbit (Misal: 2018) : ";
        cin >> koleksiBuku[jmlBuku].tahun;
        koleksiBuku[jmlBuku].dipinjam = false;
        koleksiBuku[jmlBuku].tanggalPinjam = "";
        koleksiBuku[jmlBuku].tanggalBalik = "";
        jmlBuku++;
        cin.ignore(); // Membersihkan newline character dari buffer
        cout << "Buku berhasil ditambahkan." << endl;
    }
    else
    {
        cout << "Koleksi buku sudah penuh." << endl;
    }
}

int main()
{
    Buku koleksiBuku[maxBuku];
    int jmlBuku = 5;

    // Inisialisasi data buku
    koleksiBuku[0] = {"Judul D", "Penulis A", 2021, false, "", ""};
    koleksiBuku[1] = {"Judul A", "Penulis B", 2022, false, "", ""};
    koleksiBuku[2] = {"Judul H", "Penulis C", 2020, false, "", ""};
    koleksiBuku[3] = {"Judul G", "Penulis D", 2023, false, "", ""};
    koleksiBuku[4] = {"Judul E", "Penulis E", 2019, false, "", ""};

    char pilihan;
    do
    {
        system("cls");
        tampilkanKoleksiBuku(koleksiBuku, jmlBuku);

        cout << endl
             << "Menu:" << endl;
        cout << "[1] Pinjam Buku" << endl;
        cout << "[2] Kembalikan Buku" << endl;
        cout << "[3] Urutkan Buku Berdasarkan Judul" << endl;
        cout << "[4] Cari Buku" << endl;
        cout << "[5] Tambah Buku" << endl;
        cout << "[0] Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case '1':
            system("cls");
            tampilkanKoleksiBuku(koleksiBuku, jmlBuku);
            cout << endl;
            pinjamBuku(koleksiBuku, jmlBuku);
            break;
        case '2':
            system("cls");
            tampilkanKoleksiBuku(koleksiBuku, jmlBuku);
            cout << endl;
            kembalikanBuku(koleksiBuku, jmlBuku);
            break;
        case '3':
            urutkanBerdasarkanJudul(koleksiBuku, jmlBuku);
            break;
        case '4':
            system("cls");
            cariBuku(koleksiBuku, jmlBuku);
            break;
        case '5':
            system("cls");
            tambahBuku(koleksiBuku, jmlBuku);
            break;
        case '0':
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan masukkan pilihan yang benar." << endl;
        }
        cout << "Enter untul memprosess...";
        cin.get();
    } while (pilihan != '0');

    return 0;
}
