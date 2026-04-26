#include <stdio.h>


void calcula_hora (int totalMinutos, int*ph, int*pm){
    *ph = totalMinutos / 60;
    *pm = totalMinutos % 60;
    return;
}
int main(){
    int totalMinutos, ph, pm;
    printf("Qual o total de minutos que temos?\n");
    scanf("%d", &totalMinutos);
    calcula_hora (totalMinutos, &ph, &pm);
    printf("O horário é: %dh e %dm", ph, pm);
    return 0;
}