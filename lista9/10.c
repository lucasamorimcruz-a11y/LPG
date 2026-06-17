#include <stdio.h>
#include <stdlib.h>

int *diagonal_secundaria(int **matriz, int ordem)
{
    int *v = malloc(sizeof(int) * ordem);

    for (int i = 0; i < ordem; i++)
    {
        v[i] = matriz[i][ordem - 1 - i];
    }

    return v;
}

int main()
{
    int ordem;

    printf("Informe a ordem da matriz:\n");
    scanf("%i", &ordem);

    int **matriz = malloc(sizeof(int *) * ordem);

    for (int i = 0; i < ordem; i++)
    {
        matriz[i] = malloc(sizeof(int) * ordem);
    }

    printf("Digite os elementos da matriz:\n");

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            scanf("%i", &matriz[i][j]);
        }
    }

    int *v = diagonal_secundaria(matriz, ordem);

    printf("Diagonal secundaria:\n");

    for (int i = 0; i < ordem; i++)
    {
        printf("%i ", v[i]);
    }

    printf("\n");

    free(v);

    for (int i = 0; i < ordem; i++)
    {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}