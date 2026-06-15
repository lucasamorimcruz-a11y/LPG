#include <stdio.h>

int main() {
    double valores[10];
    double *ponteiros[10];
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%lf", &valores[i]);
        ponteiros[i] = &valores[i];
    }
    printf("\nValores digitados:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", *ponteiros[i]);
    }
    return 0;
}