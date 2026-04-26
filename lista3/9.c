#include <stdio.h>

int serie_harmonica_rec (int n){
    if (n == 1) return 1;
    else{
        return (1 / n) + serie_harmonica_rec (n - 1);
    }
}
int serie_harmonica_it (int n){
    int soma = 1;
    for (int i = 2; i<= n;i++){
        soma += 1/ i;
    }
    return soma;
}

int main(){
    printf("Escolha um número qualquer\n");
    int n;
    scanf("%d", &n);
    printf("Série harmonica recursiva:%d\n", serie_harmonica_rec(n));
    printf("Série harmonica iterativa:%d\n", serie_harmonica_it(n));
    return 0;
}