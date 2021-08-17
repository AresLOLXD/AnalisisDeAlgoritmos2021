#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numerosAOrdenar[10000];
int arregloAuxiliar1[10000];
int arregloAuxiliar2[10000];
int cantidadDeNumerosAOrdenar;

void llenaNumeros()
{
    int i;
    if (cantidadDeNumerosAOrdenar < 0) {
        cantidadDeNumerosAOrdenar = 1;
    }
    srand(time(NULL));
    for (i = 0; i < cantidadDeNumerosAOrdenar; i++) {
        numerosAOrdenar[i] = rand();
    }
}

void mergeSort(int inicio, int fin)
{
    if (inicio != fin) {
        int i, j, k;
        int mitad = (inicio + fin) / 2;
        int tam1 = mitad - inicio + 1;
        int tam2 = fin - mitad;

        mergeSort(inicio, mitad);
        mergeSort(mitad + 1, fin);
        for (i = 0; i < tam1; i++) {
            arregloAuxiliar1[i] = numerosAOrdenar[inicio + i];
        }
        for (i = 0; i < tam2; i++) {
            arregloAuxiliar2[i] = numerosAOrdenar[mitad + 1 + i];
        }
        i = 0, j = 0, k = 0;
        while (i < tam1 && j < tam2) {
            if (arregloAuxiliar1[i] <= arregloAuxiliar2[j]) {
                numerosAOrdenar[k] = arregloAuxiliar1[i];
                i++;
            } else {
                numerosAOrdenar[k] = arregloAuxiliar2[j];
                j++;
            }
            k++;
        }

        while (i < tam1) {
            numerosAOrdenar[k] = arregloAuxiliar1[i];
            i++;
            k++;
        }
        while (j < tam2) {
            numerosAOrdenar[k] = arregloAuxiliar2[j];
            j++;
            k++;
        }
    }
}

void ordenaNumeros()
{
    mergeSort(0, cantidadDeNumerosAOrdenar - 1);
}

int main(void)
{
    printf("Ingresa la cantidad de numeros que quieres generar y ordenar (Numero entero positivo):\n");
    scanf("%d", &cantidadDeNumerosAOrdenar);
    llenaNumeros();
    ordenaNumeros();
    return 0;
}