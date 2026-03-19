#include <stdio.h>

int main()
{
    double x, n;
    scanf("%lf%lf", &x, &n);
    double sum = 1.0; 
    double term = 1.0;
    for (int i = 1; i <= n; i++)
    {
        term *= x / (double )(i);
        sum += term;
    }
    printf("%.1lf", sum);
}