#include <stdio.h>

int tipo_triangulo(float x, float y, float z){
    if (x == y && x == z) return 1;
    else if (x == y && x != z) return 2;
    else if (x != y && x != z && y != z) return 3;
    else{
        return 0;
    }
}

int main(){
    printf("Insira três números - os lados do triângulo\n");
    float a,b,c;
    scanf("%f%f%f", &a, &b, &c);
    int res = tipo_triangulo(a,b,c);
    if (res == 0){
        printf("Não forma um triângulo\n");
    }
    else if (res == 1){
        printf("É um triângulo equilátero\n");
    }
    else if (res == 2){
        printf("É um triângulo isósceles\n");
    }
    else{
        printf("É um triângulo escaleno\n");
    }
    return 0;
}