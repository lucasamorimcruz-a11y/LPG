#include <stdio.h>

void max_vetor (float vet[], int tam, float *pMax, int *pIndice){
    *pMax = vet[0];
    for (int i = 1; i < tam; i++){
        if (vet[i] > *pMax)
         *pMax = vet[i];
         *pIndice = i;
    }
    return;
}

int main(){
    int tam, pIndice;
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &tam);
    float vet[tam], pMax;
    printf("Insira os valores do vetor\n");
    for (int i = 0; i < tam; i++){
        scanf("%f", &vet[i]);
    }
    max_vetor (vet, tam, &pMax, &pIndice);
    printf("O maior valor do vetor é %.3f e o index dele é %d\n", pMax, pIndice);
    return 0;
}