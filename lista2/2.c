#include <stdio.h>


int main()
{
    int k;
    scanf("%i", &k);
    double sum = 0;
    for (int i = 1; i <= k; i++)
    {
        double curr = 0;
        if (i % 2 == 0){
            curr = 1.0 / i;
        }
        else{
            curr = -1.0 / i;
        }
        printf("%.1lf", curr);
        sum+= curr;
    }
    printf("Soma: %i\n", sum);
    return 0;
}