#include <stdio.h>

int main (){
    char s[1000];
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
        i++;
    }
    printf("%s", s);
    return 0;
}