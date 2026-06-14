#include <stdio.h>

void concatena(char str1[], char str2[]) {
    int i = 0;
    int j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main() {
    char str1[100] = "olá, tudo bem?";
    char str2[] = "sim, e contigo?";
    concatena(str1, str2);
    printf("%s\n", str1);
    return 0;
}