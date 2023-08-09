#include <iostream>

using namespace std;

int hitungFaktorial(int faktorialParameter)
{
    int faktorial = 1;
    for (int i = faktorialParameter; i >= 1; --i)
    {
        faktorial = faktorial * i;
    }
    return faktorial;
}

int main()
{
    cout << "Penyelesaian Function dengan Parameter dengan Looping: " << hitungFaktorial(5) << endl;
    return 0;
}