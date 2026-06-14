#include <stdio.h>

int max(int a, int b, int c){
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else{
        return c;
    }
}

int main(){
    int a,b,c;
    printf("Escolha três valores\n");
    scanf("%d%d%d", &a,&b,&c);
    printf("O maior valor entre eles são: %d\n", max(a,b,c));
    return 0;
}
