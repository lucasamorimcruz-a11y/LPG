#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Quantos valores deseja informar?\n");
    scanf("%i", &n);

    int **p = malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        int valor;

        printf("Valor %i:\n", i + 1);
        scanf("%i", &valor);

        int qtd = 0;

        for (int j = 1; j <= valor; j++)
        {
            if (valor % j == 0)
            {
                qtd++;
            }
        }

        p[i] = malloc(sizeof(int) * (qtd + 1));

        p[i][0] = valor;

        int pos = 1;

        for (int j = 1; j <= valor; j++)
        {
            if (valor % j == 0)
            {
                p[i][pos] = j;
                pos++;
            }
        }
    }

    printf("\nResultado:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Valor %i -> ", p[i][0]);

        for (int j = 1;; j++)
        {
            if (p[i][0] % p[i][j] != 0)
            {
                break;
            }

            printf("%i ", p[i][j]);

            if (p[i][j] == p[i][0])
            {
                break;
            }
        }

        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(p[i]);
    }

    free(p);

    return 0;
}
