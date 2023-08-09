#include <iostream>

using namespace std;

int hitungFaktorial()
{
    int faktorial = 1;
    for (int i = 5; i >= 1; --i)
    {
        faktorial = faktorial * i;
    }
    return faktorial;
}

int main()
{
    cout << "Penyelesaian Function/Prosedur Tanpa Parameter dengan Looping: " << hitungFaktorial() << endl;
    return 0;
}