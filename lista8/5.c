#include <stdlib.h>
#include <stdio.h>


int existe(int *vetor, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) return 1;
    }
    return 0;
}

int *uniao (int *v1, int n1, int *v2, int n2, int *p3){
    int *res = (int *)malloc((n1 + n2) * sizeof(int));
    int contador = 0;
    for (int i = 0; i < n1; i++) {
        if (!existe(res, contador, v1[i])) {
            res[contador++] = v1[i];
        }
    }
    for (int i = 0; i < n2; i++) {
        if (!existe(res, contador, v2[i])) {
            res[contador++] = v2[i];
        }
    }
    res = (int *)realloc(res, contador * sizeof(int));
    *p3 = contador;
    return res;
}
int main(){
    int n1; 
    printf("Escolha o tamanho do vetor V1\n");
    scanf("%d", &n1);
    int *v1 = malloc (sizeof (int) * n1);
    printf("Insira os elementos do vetor V1\n");
    for (int i = 0; i < n1; i++){
        scanf("%i", v1[i]);
    }
    int n2; 
    printf("Escolha o tamanho do vetor V2\n");
    scanf("%d", &n2);  
    int *v2 = malloc (sizeof (int) * n2);
    printf("Insira os elementos do vetor V2\n");
    for (int i = 0; i < n2; i++){
        scanf("%i", v2[i]);
    } 
    int n3;
    int *res = uniao(v1, n1, v2, n2, n3);
    for (int i = 0; i < n3; i++) {
        printf("%d ", res[i]);
    }
    free(res);
}