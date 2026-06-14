#include <stdio.h>

int main (){
    char s[1000];
    scanf("%s", s);
    int i= 0;
    int ok = 1;
    while (s[i] != '\0'){
        if (s[i] >= '0' && s[i] <= '9') {
            ok = 1;
            break;
        }
        i++;
    }
    if (ok){
        printf("Contém\n");
    }
    else{
        printf("Não contém\n");
    }

}