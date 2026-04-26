#include <stdio.h>

int soma_impares (int x, int y){
    int soma = 0;
    if (x > y){
        for (int i = y; i < x; i++){
            if (i % 2 != 0) soma+= i;
        }
    }
    else{
        for (int i = x; i < y; i++){
            if (i % 2 != 0) soma+= i;
        }
    }
    return soma;
}

int main(){
    printf("Escolha dois números para ser calculado a soma");
    int a, b;
    scanf("%d%d", &a, &b);
    printf("A soma de ímpares entre os dois números é de: %d", soma_impares(a,b));
    return 0;
}