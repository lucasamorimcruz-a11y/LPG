#include <stdio.h>
#define PI 3.14

void calcula_circulo (float raio, float *pPerimetro, float *pArea){
    *pPerimetro = 2 * PI * raio;
    *pArea = PI * (raio * raio);
    return;
}

int main (){
    float raio, pPerimetro, pArea;
    printf("Insira o valor do raio\n");
    scanf("%f", &raio);
    calcula_circulo (raio, &pPerimetro, &pArea);
    printf("O valor do perímetro desse círculo é: %.2f\n", pPerimetro);
    printf("O valor da área desse círculo é de: %.2f\n", pArea);
    return 0;
}