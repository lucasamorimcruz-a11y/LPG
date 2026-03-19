#include <stdio.h>

int fact (int num){
    if (num == 1) return 1;
    else return num * fact (num - 1 );
}

int main(){
    int n; 
    scanf( "%i", &n);
    double e = 0;
    for (int i = 0; i < n; i++){
        e += 1.0 / (double) (fact(i));
    }
    printf ("%.5lf", e);
}