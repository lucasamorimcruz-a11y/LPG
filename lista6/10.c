#include <stdio.h>

void inverse (char str[]){
    int size = 0 ;
    while (str[size] != '\0')
    {
        size++;
    }
    int j = size - 1;
    for (int i = 0; i < (size / 2); i++){
        char curr = str[i];
        str[i] = str[j];
        str[j] = curr;
        j--;
    }
    return;
}

int main (){
    char str[100];
    scanf("%s", str);
    inverse(str);
    printf("%s\n", str);
    return 0;
}