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
int kth_primes (int k, int n){
    int number = k + 1;
    while (n > 0){
        if (is_prime(number)) {
            printf("%d\n", number);            
            n--;
            number++;
        }
    }
    return 0;
}

int main(){
    int n, k;
    printf("Insira n e k\n");
    scanf("%d%d", &n, &k);
    kth_primes(k,n);
    return 0;
}