#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Qual o tamanho do vetor?\n");
    scanf("%i", &n);
    float *v = malloc(sizeof(float) * n);
    printf("Insira os %i valores\n", n);
    float media = 0;
    for (int i = 0; i < n; i++){
        scanf("%i", &v[i]);
        media += v[i];
    }
    media /= n;
    int counter = 0;
    for (int i =0 ; i < n;i++){
        if (v[i] > media){
            counter++;
        }
    }
    float *vec = malloc (sizeof (float) * counter);
    counter = 0;
    for (int i =0 ; i < n;i++){
        if (v[i] > media){
            vec[counter] = v[i];
            counter++;
            printf("%.1f\n", vec[counter]);
        }
    }
    
}