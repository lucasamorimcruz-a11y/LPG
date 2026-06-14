#include <stdio.h>


int compara (char str1[], char str2[]){
    
    size_t counter = 0;
    size_t str1_size = 0;
    size_t str2_size = 0; 
    int ok = 1;
    while (str1[counter] != '\0'){
        counter++;
    }
    str1_size = counter;
    counter = 0;
    while (str2[counter] != '\0'){
        counter++;
    }
    str2_size = counter;
    counter = 0;
    if (str1_size != str2_size){
        ok = 0;
    }
    else{
        while (str1[counter] != '\0' && str2[counter] != '\0'){
            if (str1[counter] != str2[counter]){
                ok = 0;
            }
            counter++;
        }
    }
    return ok;
}

int main(){
    char str1[] = "olá";
    char str2[] = "olác";
    if (compara(str1, str2)){
        printf("É equivalente\n");
    }
    else{
        printf("Não é equivalente\n");
    }
}
