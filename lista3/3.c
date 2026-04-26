#include <stdio.h>

int is_digit(char c){   
    if (c - '\0' <= 9 && c - '\0' >= 1){
        int num = c - '\0';
        printf("O número é %d\n", num);
        return 1;
    }
    return 0;
    
}
int main(){
    char c;
    printf("Entre um digito\n");
    scanf("%c", &c);
    if (is_digit(c)){
        printf("É um digito entre 1 a 9!\n");
    }    
    else{
        printf("Não é um digito entre 1 a 9\n");
    }
    return 0;

}