#include <stdio.h>
#include <stdlib.h>

char *repetidor(char *s, int n) {
    int cnt = 0;
    while (s[cnt] != '\0') {
        cnt++;
    }
    int total = cnt;
    int size = total * n;
    char *string = malloc(sizeof(char) * (size + 1));
    if (!string) return NULL;
    int j = 0;
    for (int i = 0; i < size; i++) {
        string[i] = s[j];
        j++;

        if (j == total) {
            j = 0;
        }
    }
    string[size] = '\0';
    return string;
}

int main() {
    char *s = "olaola";
    int n = 3;
    char *string = repetidor(s, n);
    printf("%s\n", string);
    free(string);
    return 0;
}