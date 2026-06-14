#include <stdio.h>

int fact (int n){
    if (n == 1) return 1;
    else {
        return n * fact (n-1);
    }
}
int somatorio_e_rec (int n){
    if (n == 0 || n == 1) return 1;
    else{
        return (1 / fact (n) ) + somatorio_e_rec (n-1);
    }
}
int somatorio_e_it (int n){
    int soma = 0;
    for (int i = 0; i <= n; i++){
        soma += 1 / fact(n);
    }
}
int main(){
    printf("Escolha um número qualquer");
    int n;
    scanf ("%d", &n);
    printf("Somatório de e recursivo:%d\n", somatorio_e_rec (n) );
    printf("Somatório de e iterativo: %d\n", somatorio_e_it (n));
    return 0;
}