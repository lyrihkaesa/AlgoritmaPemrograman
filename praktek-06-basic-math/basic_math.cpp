#include <iostream>

using namespace std;

// Basic Variable
int variabelA = 8;
int variabelB = 5;

// Penyelesaian Konvensional Tanpa Looping
int penjumlahanKonvensional = 8 + 5;
int penguranganKonvensional = 8 - 5;
int perkalianKonvensional = 8 * 5;

// Penyelesaian Konvensional dengan Looping
int penjumlahanLooping(int a, int b)
{
    int hasil = a;
    for (int i = 0; i < b; ++i)
    {
        hasil += 1;
    }
    return hasil;
}

int penguranganLooping(int a, int b)
{
    int hasil = a;
    for (int i = 0; i < b; ++i)
    {
        hasil -= 1;
    }
    return hasil;
}

int perkalianLooping(int a, int b)
{
    int hasil = 0;
    for (int i = 0; i < b; ++i)
    {
        hasil += a;
    }
    return hasil;
}

// Penyelesaian Function/Prosedur Tanpa Parameter dengan Looping
int hitungPenjumlahan()
{
    int hasil = variabelA;
    for (int i = 0; i < variabelB; ++i)
    {
        hasil += 1;
    }
    return hasil;
}

int hitungPengurangan()
{
    int hasil = variabelA;
    for (int i = 0; i < variabelB; ++i)
    {
        hasil -= 1;
    }
    return hasil;
}

int hitungPerkalian()
{
    int hasil = 0;
    for (int i = 0; i < variabelB; ++i)
    {
        hasil += variabelA;
    }
    return hasil;
}

// Penyelesaian Function dengan Parameter dengan Looping
int hitungPenjumlahan(int a, int b)
{
    int hasil = a;
    for (int i = 0; i < b; ++i)
    {
        hasil += 1;
    }
    return hasil;
}

int hitungPengurangan(int a, int b)
{
    int hasil = a;
    for (int i = 0; i < b; ++i)
    {
        hasil -= 1;
    }
    return hasil;
}

int hitungPerkalian(int a, int b)
{
    int hasil = 0;
    for (int i = 0; i < b; ++i)
    {
        hasil += a;
    }
    return hasil;
}

// Penyelesaian Function Rekursif
int hitungPenjumlahanRekursif(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return hitungPenjumlahanRekursif(a + 1, b - 1);
    }
}

int hitungPenguranganRekursif(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return hitungPenguranganRekursif(a - 1, b - 1);
    }
}

int hitungPerkalianRekursif(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    else
    {
        return a + hitungPerkalianRekursif(a, b - 1);
    }
}

int main()
{
    cout << "Penjumlahan Konvensional: " << penjumlahanKonvensional << endl;
    cout << "Pengurangan Konvensional: " << penguranganKonvensional << endl;
    cout << "Perkalian Konvensional: " << perkalianKonvensional << endl;
    cout << "====================" << endl;

    cout << "Penjumlahan dengan Looping: " << penjumlahanLooping(8, 5) << endl;
    cout << "Pengurangan dengan Looping: " << penguranganLooping(8, 5) << endl;
    cout << "Perkalian dengan Looping: " << perkalianLooping(8, 5) << endl;
    cout << "====================" << endl;

    cout << "Penjumlahan Tanpa Parameter dengan Looping: " << hitungPenjumlahan() << endl;
    cout << "Pengurangan Tanpa Parameter dengan Looping: " << hitungPengurangan() << endl;
    cout << "Perkalian Tanpa Parameter dengan Looping: " << hitungPerkalian() << endl;
    cout << "====================" << endl;

    cout << "Penjumlahan dengan Parameter dan Looping: " << hitungPenjumlahan(8, 5) << endl;
    cout << "Pengurangan dengan Parameter dan Looping: " << hitungPengurangan(8, 5) << endl;
    cout << "Perkalian dengan Parameter dan Looping: " << hitungPerkalian(8, 5) << endl;
    cout << "====================" << endl;

    cout << "Penjumlahan Rekursif: " << hitungPenjumlahanRekursif(8, 5) << endl;
    cout << "Pengurangan Rekursif: " << hitungPenguranganRekursif(8, 5) << endl;
    cout << "Perkalian Rekursif: " << hitungPerkalianRekursif(8, 5) << endl;

    return 0;
}
