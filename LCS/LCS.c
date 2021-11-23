#include <stdio.h>
#include <stdlib.h>
int lcs(char *cadena1, char *cadena2, int longitud1, int longitud2)
{
    if (longitud1 == 0 || longitud2 == 0)
        return 0;
    if (cadena1[longitud1 - 1] == cadena2[longitud2 - 1])
        return 1 + lcs(cadena1, cadena2, longitud1 - 1, longitud2 - 1);
    else
        return maximo(lcs(cadena1, cadena2, longitud1, longitud2 - 1), lcs(cadena1, cadena2, longitud1 - 1, longitud2));
}

int maximo(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int longitud1, longitud2;
    scanf("%d", &longitud1);
    char *cadena1 = (char *)malloc(longitud1 * sizeof(char));
    scanf("%d", &longitud2);
    char *cadena2 = (char *)malloc(longitud2 * sizeof(char));
    printf("Longitud del LCS %d", lcs(cadena1, cadena2, longitud1, longitud2));

    return 0;
}