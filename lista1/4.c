#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);
    int imp = 0, par = 0, pos = 0, neg = 0;
    while (n--)
    {
        int num;
        scanf("%i", &num);
        if (num % 2 == 0)
        {
            par++;
        }
        else
        {
            imp++;
        }
        if (num > 0)
        {
            pos++;
        }
        else if (num < 0)
        {
            neg++;
        }
    }
    printf("%i valor(es) par(es)\n", par);
    printf("%i valor(es) impar(es)\n", imp);
    printf("%i valor(es) positivo(s)\n", pos);
    printf("%i valor(es) negativo(s)\n", neg);
}