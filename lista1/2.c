#include <stdio.h>

int main()
{
    double a, b, c, temp;
    scanf("%lf %lf %lf ", &a, &b, &c);
    if (a < b)
    {
        temp = b;
        a = b;
        b = temp;
    }
    if (a < c)
    {
        temp = c;
        a = c;
        c = temp;
    }
    if (b < c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    if (a >= b + c)
    {
        printf(" Não forma um triângulo.\n");
    }
    else
    {
        double pow_of_a = a * a;
        double pow_of_b = b * b;
        double pow_of_c = c * c;
        if (pow_of_a == pow_of_b + pow_of_c)
        {
            printf("Triângulo retângulo\n");
        }
        else if (pow_of_a > pow_of_b + pow_of_c)
        {
            printf("Triângulo obtusangulo\n");
        }
        else
        {
            printf("Triângulo acutangulo\n");
        }
        if (a == b && b == c)
        {
            printf(" Triângulo equilátero\n");
        }
        else if (a == b || a == c || b == c)
        {
            printf("triângulo isósceles");
        }
    }
    return 0;
}