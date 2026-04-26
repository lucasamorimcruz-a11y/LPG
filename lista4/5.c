#include <stdio.h>

int busca_seq_rec (int v[], int n, int chave){
    if (n == 0) return 0;
    if (v[n] != chave){
        return busca_seq_rec (v, n-1, chave);
    }
    else{
        return n;
    }
}
int main(){
    int n, chave;
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &n);
    printf("Qual o número que quer achar?\n");
    scanf("%d", &chave);
    int v[n];
    printf("Preencha o vetor.\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int ans = busca_seq_rec(v,n,chave);
    if (ans == 0) printf("Não foi possível encontrar o número no vetor\n");
    else{
        printf("O número está no index %d\n", ans);
    }
    return 0;
}