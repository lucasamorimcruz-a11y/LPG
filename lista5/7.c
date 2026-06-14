#include <stdio.h>

void min_matriz (float mat[3][4], float *pMin, int *pI, int *pJ){
    *pMin = mat[0][0];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (mat[i][j] < *pMin) {
                *pMin = mat[i][j];
                *pI = i;
                *pJ = j;

            }
        }
    }
}

int main(){
    float mat[3][4], pMin;
    int pI, pJ;
    printf("Insira os valores na matrix 3x4\n");
    for (int i = 0; i < 3; i++){
            for (int j = 0; j < 4; j++){
                scanf("%f", &mat[i][j]);
        }
    }
    min_matriz (mat, &pMin, &pI, &pJ);
    printf("O valor mínimo da matriz é %.2f e está localizado no índice %dx%d da matriz \n", pMin, pI, pJ);
    return 0;
}