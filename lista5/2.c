#include <stdio.h>

void troca_valor (float *x, float *y){
    float temp = *x;
    *x = *y;
    *y = temp;
    return;
}

int main (){
    float a, b;
    printf("Insira dois números, A e B:\n");
    scanf("%f %f", &a, &b);
    troca_valor (&a, &b);
    printf("A = %2.f e B = %.2f\n", a, b);
    return 0;    
}