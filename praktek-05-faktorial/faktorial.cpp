#include <iostream>

using namespace std;

// Penyelesaian Konvensional Tanpa Looping
int faktorialKonvensional()
{
    return 5 * 4 * 3 * 2 * 1;
}

// Penyelesaian Konvensional dengan Looping
int faktorialLooping()
{
    int faktorial = 1;
    for (int i = 5; i >= 1; --i)
    {
        faktorial *= i;
    }
    return faktorial;
}

// Penyelesaian Function/Prosedur Tanpa Parameter dengan Looping
int hitungFaktorial()
{
    int faktorial = 1;
    for (int i = 5; i >= 1; --i)
    {
        faktorial *= i;
    }
    return faktorial;
}

// Penyelesaian Function dengan Parameter dengan Looping
int hitungFaktorial(int n)
{
    int faktorial = 1;
    for (int i = n; i >= 1; --i)
    {
        faktorial *= i;
    }
    return faktorial;
}

// Penyelesaian Function Rekursif
int hitungFaktorialRekursif(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * hitungFaktorialRekursif(n - 1);
    }
}

int main()
{
    cout << "Penyelesaian Konvensional Tanpa Looping: " << faktorialKonvensional() << endl;
    cout << "Penyelesaian Konvensional dengan Looping: " << faktorialLooping() << endl;
    cout << "Penyelesaian Function/Prosedur Tanpa Parameter dengan Looping: " << hitungFaktorial() << endl;
    cout << "Penyelesaian Function dengan Parameter dengan Looping: " << hitungFaktorial(5) << endl;
    cout << "Penyelesaian Function Rekursif: " << hitungFaktorialRekursif(5) << endl;

    return 0;
}
