#include <stdio.h>
#include <stdbool.h>

int fact(int num)
{
    if (num == 1)
        return 1;
    else
        return num * fact(num - 1);
}
int main()
{
    double x;
    int n;
    scanf("%lf %i", &x, &n);
    double sen_x = x;
    bool flip = true;
    for (int i = 1; i < n; i++)
    {
        double exp = 2 * i + 1;
        double elev = 1;
        for (int j = 0; j < exp; j++){
            elev *= x;
        }
        if (flip)
        {
            sen_x += -(elev) / fact(exp);
        }
        else
        {
            sen_x +=  elev / fact(exp);
        }
        flip = !flip;
    }
    printf("%.5lf", sen_x);
}
