#include <stdio.h>

void busca_todos (int v[], int n, int chave, int indices[]){
    int counter = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == chave){
            indices[counter] = i;
            counter++;
        }
    }
    for (int i = counter; i < n; i++){
        indices[i] = -1;
    }
}
int main(){
    int n, chave;
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &n);
    int v[n], indices[n];
    printf("Qual o número que queremos encontrar?\n");
    scanf("%d", &chave);
    printf("Insira os números que estão dentro do vetor\n");
    for (int i = 0; i < n; i++){
            scanf("%d", &v[i]);
    }
    printf("{");
    busca_todos (v, n, chave, indices);
    for (int i = 0; i < n; i++){
        printf ("%d, ", indices[i]);

    }
    printf("}\n");
    return 0;
}