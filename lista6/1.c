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
    int ok = 0;
    while (s[index] != '\0'){
        if (c == s[index]){
            ok = 1;
            break;
        }
        index++;
    }
    if (ok){
        printf("Contém!\n");
    }
    else{
        printf("Não contém!\n");
    }
    return 0;
}
