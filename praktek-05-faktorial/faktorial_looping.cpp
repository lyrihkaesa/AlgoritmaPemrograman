#include <iostream>

using namespace std;

int main()
{
    int faktorial = 1;
    for (int i = 5; i >= 1; --i)
    {
        faktorial = faktorial * i;
    }
    cout << "Penyelesaian Konvensional dengan Looping: " << faktorial << endl;
    return 0;
}