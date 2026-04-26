#include <stdio.h>

int main()
{
    int hora_inicial, hora_final;
    scanf("%i %i", &hora_inicial, &hora_final);
    if (hora_inicial == hora_final)
    {
        printf("O jogo durou 24h\n");
    }
    else if (hora_inicial < hora_final){
        printf("O jogo durou %i\n", hora_final - hora_inicial);
    }
    else {
        printf("O jogo durou %i\n", (24 - hora_inicial + hora_final));
    }
    return 0;
}