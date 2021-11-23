#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vectorInt;
vectorInt profundidades;
vectorInt arreglo;

void calcularProfundidad(vectorInt indices, int profundidad)
{
    int n = indices.size();
    if (n == 0)
        return;
    int indiceDelIndiceDelMayor = n - 1;
    for (int i = indiceDelIndiceDelMayor; i >= 0; i--)
    {
        if (arreglo[indices[i]] > arreglo[indices[indiceDelIndiceDelMayor]])
        {
            indiceDelIndiceDelMayor = i;
        }
    }
    profundidades[indices[indiceDelIndiceDelMayor]] = profundidad;
    vectorInt izq, der;
    for (int i = 0; i < indiceDelIndiceDelMayor; i++)
    {
        izq.push_back(indices[i]);
    }
    for (int i = indiceDelIndiceDelMayor + 1; i < n; i++)
    {
        der.push_back(indices[i]);
    }
    calcularProfundidad(izq, profundidad + 1);
    calcularProfundidad(der, profundidad + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;

    vectorInt indices;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arreglo = vectorInt(n);
        profundidades = vectorInt(n, 0);
        indices = vectorInt(n, 0);
        for (int j = 0; j < n; j++)
        {
            cin >> arreglo[j];
            indices[j] = j;
        }
        calcularProfundidad(indices, 0);
        for (int j = 0; j < n; j++)
        {
            cout << profundidades[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}