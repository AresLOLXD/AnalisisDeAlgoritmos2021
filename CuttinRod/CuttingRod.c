#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int cutRod(int *p, int n)
{
    int i, aux;
    if (n == 0)
        return 0;
    int q = INT_MIN;
    for (i = 1; i <= n; i++)
    {
        aux = (p[i] + cutRod(p, n - i));
        if (aux > q)
        {
            q = aux;
        }
    }
    return q;
}

int main(void)
{
    int *p;
    int n, i;
    scanf("%d", &n);
    p = (int *)malloc(100 * sizeof(int));
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("La respuesta es: %d", cutRod(p, n));
    return 0;
}