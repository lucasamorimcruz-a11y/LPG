#include <stdio.h>

int fibo (int n){
    int prim = 1;
    int seg = 1;
    for (int i = 1; i <= n; i++){
        printf("%d\n", prim);
        int soma = prim + seg;
        prim = seg;
        seg = soma;
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