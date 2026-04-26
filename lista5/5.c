#include <stdio.h>

void max_min (int vet[], int tam, int *pMin, int *pMax){
    *pMin = vet[0];
    *pMax = vet[0];
    for (int i = 1; i < tam; i++){
        if (vet[i] < *pMin) *pMin = vet[i];
        if (vet[i] > *pMax) *pMax = vet[i];
    }
    return;
}

int main(){
    int tam, pMin, pMax;
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &tam);
    int vet[tam];
    printf ("Insira os valores do vetor\n");
    for (int i =0 ; i < tam; i++){
        scanf("%d", &vet[i]);
    }
    printf("O valor máximo do vetor é %d e o mínimo é %d", pMax, pMin);
    return 0;

}