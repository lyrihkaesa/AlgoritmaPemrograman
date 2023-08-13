#include <iostream>

using namespace std;

// Menampilkan array dari [10, 20, 30] menjadi "10, 20, 30 \n"
void tampilkanArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

// Implementasi manual swap: digunakan untuk menukar nilai dari dua variabel.
// Menggunakan int &a dan int &b adalah parameter fungsi yang menerima referensi atau alamat dari variabel a dan b.
// Sehingga, saat a dan b ditukar nilai dalam fungsi,
// perubahan juga akan terlihat di luar fungsi karena kita bekerja dengan alamat atau referensi variabel, bukan nilai copy dari variabel.
void manualSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                manualSwap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort (Min Sort)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            manualSwap(arr[i], arr[minIndex]);
        }
    }
}

int main()
{
    const int n = 5; // Jumlah bilangan
    int arrayBubble[n] = {10, 40, 33, 24, 4};

    cout << "Bilangan sebelum Bubble Sort: ";
    tampilkanArray(arrayBubble, n);

    bubbleSort(arrayBubble, n);
    cout << "Bilangan setelah Bubble Sort: ";
    tampilkanArray(arrayBubble, n);

    cout << "=============================================================" << endl;
    int arrMinSort[n] = {10, 40, 33, 24, 4};

    cout << "Bilangan sebelum Selection Sort (Min Sort): ";
    tampilkanArray(arrMinSort, n);

    selectionSort(arrMinSort, n);
    cout << "Bilangan setelah Selection Sort (Min Sort): ";
    tampilkanArray(arrMinSort, n);

    return 0;
}
