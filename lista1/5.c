#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("A média desses valores são: %.1lf\n", ((a * 2) + (b * 3) + (c * 5)) / 10.0);
    }
    return 0;
}