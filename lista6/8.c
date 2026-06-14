#include <stdio.h>

int main (){
    char s[11];
    scanf("%s", s);

    int valido = 1;
    int size = 0;
    while (s[size] != '\0'){
        size++;
    }

    if (size != 10){
        valido = 0;
    }
    if (valido && (s[2] != '/' || s[5] != '/')){
        valido = 0;
    }
    for (int i = 0; i < 10 && valido; i++){
        if (i == 2 || i == 5){
            continue;
        }

        if (s[i] < '0' || s[i] > '9'){
            valido = 0;
        }
    }

    if (!valido){
        printf("Formato invalido\n");
        return 0;
    }

    int dia = (s[0] - '0') * 10 + (s[1] - '0');
    int mes = (s[3] - '0') * 10 + (s[4] - '0');
    int ano = (s[6] - '0') * 1000 +
              (s[7] - '0') * 100 +
              (s[8] - '0') * 10 +
              (s[9] - '0');

    printf("Dia: %d\n", dia);
    printf("Mes: %d\n", mes);
    printf("Ano: %d\n", ano);

    return 0;
}