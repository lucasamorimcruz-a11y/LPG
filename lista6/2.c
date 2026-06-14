#include <stdio.h>

int main (){
    char s[100]; 
    printf("Entre uma string s\n");
    scanf("%s", s);
    getchar();
    char c;
    printf("Qual caractere você quer verificar?\n");
    scanf("%c", &c);
    int index = 0;
    int counter = 0;
    int ok = 0;
    while (s[index] != '\0'){
        if (c == s[index]){
            ok = 1;
            counter++;
        }
        index++;
    }
    if (ok){
        printf("Contém %d vezes!\n", counter);
    }
    else{
        printf("Não contém!\n");
    }
    return 0;
}
