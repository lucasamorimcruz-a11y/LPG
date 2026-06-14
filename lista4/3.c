#include <stdio.h>

int is_prime (int n){
    if (n <= 1) return 0;
    int counter = 0;
    for(int i = 1; i <= n; i++){
        if (n % i == 0) counter++;
    }
    if (counter > 2) return 0;
    return 1;
}
int soma_primos(int v[], int n){
    int soma = 0;
    for (int i = 0; i < n; i++){
        if (is_prime (v[i])){
            soma += v[i];
        }
    }
    return soma;
}
int main(){
    int n;
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++){
        printf("Insira o número do index: %d\n", i);
        scanf("%d", &v[i]);
    }
    printf("O somatório dos números primos dentro da função é equivalente a:%d\n", soma_primos(v,n));
    return 0;
}
