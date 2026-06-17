#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l1, c1, l2, c2;

    printf("Linhas e colunas da matriz A:\n");
    scanf("%i %i", &l1, &c1);

    printf("Linhas e colunas da matriz B:\n");
    scanf("%i %i", &l2, &c2);

    if(c1 != l2)
    {
        printf("Multiplicacao impossivel\n");
        return 0;
    }

    int **A = malloc(sizeof(int*) * l1);

    for(int i = 0; i < l1; i++)
    {
        A[i] = malloc(sizeof(int) * c1);
    }

    int **B = malloc(sizeof(int*) * l2);

    for(int i = 0; i < l2; i++)
    {
        B[i] = malloc(sizeof(int) * c2);
    }

    int **C = malloc(sizeof(int*) * l1);

    for(int i = 0; i < l1; i++)
    {
        C[i] = malloc(sizeof(int) * c2);
    }

    printf("Digite a matriz A:\n");

    for(int i = 0; i < l1; i++)
    {
        for(int j = 0; j < c1; j++)
        {
            scanf("%i", &A[i][j]);
        }
    }

    printf("Digite a matriz B:\n");

    for(int i = 0; i < l2; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            scanf("%i", &B[i][j]);
        }
    }

    for(int i = 0; i < l1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for(int k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Matriz resultado:\n");

    for(int i = 0; i < l1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            printf("%i ", C[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < l1; i++) free(A[i]);
    for(int i = 0; i < l2; i++) free(B[i]);
    for(int i = 0; i < l1; i++) free(C[i]);

    free(A);
    free(B);
    free(C);

    return 0;
}