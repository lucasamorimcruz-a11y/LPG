#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        int x, y;
        int sum = 0;
        scanf("%i%i", &x, &y);
        int ini = x < y ? x : y;
        int fin = x > y ? x : y;
        for (int i = ini + 1; i < fin; i++)
        {
            if (i % 2 != 0)
            {
                sum += i;
            }
        }
        printf("%i\n", sum);
    }
}