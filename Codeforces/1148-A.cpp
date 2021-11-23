#include <iostream>
using namespace std;
typedef long long int largo;
int main(void)
{
    largo suma = 0L;
    largo a, b, c;
    cin >> a >> b >> c;
    suma += c * 2L;
    if (a != b)
        suma += (min(a, b) * 2) + 1;
    else
        suma += a * 2;
    cout << suma;
    return 0;
}