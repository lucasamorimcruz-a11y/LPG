#include <stdio.h>

int main (){
    char s [100];
    scanf("%s\n", s);
    int size = 0;
    while (s[size] != '\0'){
        size++;
    }
    for (int i = 0; i < size; i++){
        if (s[i] >= '0' && s[i] <= '9'){
            s[i] = s[i] - '0';
        }   
    }
    printf("%s", s);
    return 0;
}