#include <iostream>

using namespace std;

int hitungFaktorialRekursif(int faktorialParameter)
{
    if (faktorialParameter == 0 || faktorialParameter == 1)
    {
        return 1;
    }
    else
    {
        return faktorialParameter * hitungFaktorialRekursif(faktorialParameter - 1);
    }
}

int main()
{
    cout << "Penyelesaian Function Rekursif: " << hitungFaktorialRekursif(5) << endl;
    return 0;
}