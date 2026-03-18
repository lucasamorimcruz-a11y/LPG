#include <stdio.h>

int main(){
    int k;
    scanf("%i", &k);
    double sum = 0;
    for (int i = 1; i <= k; i++){
        printf("1/%i\n", i);
        sum += 1/(double) i;
    }
    printf("Soma é: %lf", sum);
}