#include <stdio.h>

void trim(char str[]){
    int inicio = 0;
    while (str[inicio] == ' '){
        inicio++;
    }
    int size = 0;
    while (str[size] != '\0'){
        size++;
    }
    int fim = size - 1;
    while (fim >= inicio && str[fim] == ' '){
        fim--;
    }
    int j = 0;
    for (int i = inicio; i <= fim; i++){
        str[j] = str[i];
        j++;
    }
    str[j] = '\0';
}

int main (){
    char str[100];
    fgets(str, 100, stdin);
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == '\n'){
            str[i] = '\0';
            break;
        }
        i++;
    }
    trim(str);
    printf("%s\n", str);
    return 0;
}