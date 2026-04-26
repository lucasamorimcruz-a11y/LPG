#include <stdio.h>

int is_prime (int n){
    int counter = 1;
    for(int i = 2; i < n; i++){
        if (n % i == 0) counter++;
    }
    if (counter > 2) return 0;
    return 1;
}
int kth_primes (int k, int n){
    int number = k;
    int ok = 0;
    while (n != 0){
        if (is_prime(number)) {
            printf("%d\n", number);            
            n--;
            number++;
        }
    }
}

int main(){
    int n, k;
    printf("Insira n e k\n");
    scanf("%d%d", &n, &k);
    kth_primes(k,n);
    return 0;
}