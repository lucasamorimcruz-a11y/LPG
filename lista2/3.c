#include <stdio.h>
#include <stdbool.h>

void calculate_gregory_leibniz()
{
    int x;
    scanf("%i", &x);
    double counter = 1;
    bool flip = true;
    double sum = 0;
    for (int i = 1; i <= x; i++)
    {
        if (flip)
        {
            sum += (4.0 / counter);
        }
        else
        {
            sum += (-4.0 / counter);
        }
        counter += 2;
        flip = !flip;
    }
    printf("Valor aproximado de PI é : %.5lf\n", sum);
}
void calculate_nilakantha_series()
{
    int x;
    scanf("%i", &x);
    bool flip = true;
    double sum = 3;
    for (int i = 1; i <= x; i++)
    {
        double n = 2.0 + (i - 1) * 2;
        if (flip)
        {
            sum += (4.0) / (n * (n+1) * (n+2));
        }
        else
        {
            sum += (-4.0) / (n * (n+1) * (n+2));
        }
        flip = !flip;
    }
    printf("Valor aproximado de PI é : %.5lf\n", sum);
}

int main(){
    calculate_gregory_leibniz();
    calculate_nilakantha_series();
    return 0;
}