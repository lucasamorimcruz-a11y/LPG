#include <stdlib.h>
#include <stdio.h>

float *clone (float v[], int n){
    float *nv = malloc (sizeof(float ) * n);
    for (int i = 0; i < n; i++){
        nv[i] = v[i];
    }
    return nv;
}
int main(){
    float v[] =  {1,2,34,4,5};
    int n = 5;
    float *vetor = clone(v,n);
    for (int i = 0; i < n; i++){
        printf("%f\n", vetor[i]);
    }
    return 0;
}