#include <complex>
#include <iostream>
#include <vector>

using namespace std;
typedef complex<double> complejo;
typedef vector<complejo> complejoArreglo;
const double PI = acos(-1);

complejoArreglo Recursive_FFT(complejoArreglo a)
{
    int n = a.size();
    if (n == 1) {
        return a;
    }
    complejo W_n = exp((complejo(0, 2 * PI) / complejo(n, 0)));
    complejo W = complejo(1, 0);
    complejoArreglo a_0, a_1;
    for (int i = 0; i < n; i += 2) {
        a_0.push_back(a[i]);
    }
    for (int i = 1; i < n; i += 2) {
        a_1.push_back(a[i]);
    }

    complejoArreglo y_0, y_1, y(n);
    y_0 = Recursive_FFT(a_0);
    y_1 = Recursive_FFT(a_1);

    for (int k = 0; k <= (n / 2) - 1; k++) {
        y[k] = y_0[k] + (W * y_1[k]);
        y[k + (n / 2)] = y_0[k] - (W * y_1[k]);
        W *= W_n;
    }
    return y;
}

int main(void)
{
    int n, aux;
    cin >> n;
    complejoArreglo arreglo(n), FFT(n);
    for (int i = 0; i < n; i++) {
        cin >> aux;
        arreglo[i] = complejo(aux, 0);
    }
    FFT = Recursive_FFT(arreglo);
    for (int i = 0; i < n; i++) {
        cout << FFT[i] << ' ';
    }
    cout << endl;
    return 0;
}