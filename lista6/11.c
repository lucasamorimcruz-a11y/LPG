#include <stdio.h>


void remove(char s[], char c) {
    int i, j = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j] = s[i];
            j++;
        }
    }

    s[j] = '\0'; 
}

int main() {
    char s[100];
    scanf("%s\n", s);
    char c;
    scanf ("%c", c);
    remove(s, c);
    printf("%s\n", s);
    return 0;
}