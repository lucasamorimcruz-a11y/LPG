#include <stdio.h>

void inc_dec (int *a, int *b){
    *a++;
    *b--;
    return;
}

int main(){
    int a,b;
    printf("Insira dois números\n");
    scanf("%d%d", &a, &b);
    inc_dec (&a, &b);
    printf("%d e %d \n", a, b);
    return 0;
}
