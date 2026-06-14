#include <stdio.h>

int soma_especial (int n, int k, int x){
    int it = x;
    int soma = 0;
    while (n--){
        if (it % k == 0) soma += it;
        it++;
    }   
    return soma;
}

int main(){
    int n, k, x;
    printf("Insira três números\n");
    scanf("%d%d%d", &n, &k, &x);
    printf("A somatória resulta em : %d", soma_especial(n,k,x));
    return 0;

}