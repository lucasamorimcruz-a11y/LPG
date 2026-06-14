#include <stdio.h>

int main (){
    char s[1000];
    scanf("%s", s);
    int size = 0;
    while (s[size] != '\0'){
        size++;
    }  
    int j = size - 1;
    int i = 0;
    int ok = 1;
    while (i < j){
        if (s[i] != s[j]){
            ok = 0;
            break;
        }
        j--;
        i++;
    }
    if (ok) {
        printf("É palíndromo\n");
    }
    else{
        printf("Não é palíndromo\n");
    }
}
