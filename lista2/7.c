#include <stdio.h>
#include <stdbool.h>

int fact(int num)
{
    if (num <= 1)
        return 1;
    else
        return num * fact(num - 1);
}

int main()
{
    double x;
    int n;

    scanf("%lf %i", &x, &n);

    double cos_x = 1.0;
    bool flip = true;

    for (int i = 1; i < n; i++)
    {
        int exp = 2 * i;
        double elev = 1;

        for (int j = 0; j < exp; j++)
        {
            elev *= x;
        }

        if (flip)
        {
            cos_x -= elev / fact(exp);
        }
        else
        {
            cos_x += elev / fact(exp);
        }
        flip = !flip;
    }

    printf("%.5lf\n", cos_x);
    return 0;
}