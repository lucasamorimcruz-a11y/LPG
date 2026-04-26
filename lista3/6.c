#include <stdio.h>

int fibo (int n){
    int prim = 1;
    int seg = 1;
    int soma = 0;
    for (int i = 2; i < n; i++){
        soma = prim + seg;
        seg = prim;
        prim = soma;
        printf("%d\n", soma);
    }
    return 0;
}

int main(){
    int n; 
    printf("Digite número:\n");
    scanf("%d", &n);
    fibo (n);
    return 0;
}