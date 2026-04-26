#include <stdio.h>

int compara (float a[], float b[], int n){
    int ok = 1;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            ok = 0;
        }
    }
    return ok;

}
int main(){
    float a[] = {1,2,3,4,5};
    float b[] = {1,3,4,5,6};
    if (compara(a,b,5)){
        printf("Sim\n");
    }
    else{
        printf("Nao\n");
    }
}