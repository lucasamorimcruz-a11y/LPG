#include <stdio.h>
#include <stdlib.h>

int main (){
    int n; 
    printf("Escolha o tamanho do vetor V\n");
    scanf("%d", &n);   
    int *v = malloc (sizeof( int ) * n);
    printf("Insira os %i valores\n", n);
    int vpq = 0, vnq = 0;
    for (int i = 0; i < n; i++){
        scanf("%i", &v[i]);
        if (v[i] > 0) vpq++;
        else{
            vnq++;
        }
    }
    int *vp = malloc (sizeof (int) * vpq);
    int *vn = malloc (sizeof (int ) * vnq);
    int vpc = 0, vnc = 0;
    for (int i = 0; i < n; i++){
        if (v[i] > 0){
            vp[vpq] = v[i];
            vpq++;
        }
        else{
            vn[vnc] = v[i];
            vnc++;
        }
    }
    for (int i = 0; i < vpq; i++){
        printf("%i\n", vp[i]);
    }
    for (int i = 0; i < vnq; i++){
        printf("%i\n", vn[i]);
    }
    return 0;
}