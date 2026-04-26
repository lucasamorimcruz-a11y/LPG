#include <stdio.h>

int soma_it (int n){
    int soma = 0;
    for (int i = 1; i <= n; i++){
        soma += i;
    }
    return soma;
}

int soma_rec (int n){
    if (n == 1) return 1;
    else {
        return n + soma_rec(n-1);
    }
}

int main (){
    int n;
    printf("Insira um número\n");
    scanf("%d", &n);
    printf("Soma recursiva:%d\n", soma_rec(n));
    printf("Soma iterativa:%d\n", soma_it(n));
    return 0;

}