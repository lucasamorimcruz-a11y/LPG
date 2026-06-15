#include <stdio.h>

void primeiro()
{
    char *pstr_e, dia_e[] = "os dias da semana são : seg, ter, quar, qui, sex, sab e dom";
    int i_e;
    pstr_e = dia_e;
    clrscr();
    while (*pstr_e)
    {
        putch(*pstr_e);
        pstr_e += 1;
    }
    getch();
}
void segundo()
{
    char str[] = "linguagem C", *px, *py, aux;
    px = py = str;
    for (; *py != '\0'; py++)
        ;
    py--;
    while (px < py)
    {
        aux = *px;
        *px = *py;
        *py = aux;
        px++;
        py--;
    }
    clrscr();
    puts(str);
    getch();
}

void terceiro()
{
    char *dias[] = {"Segunda", "Terça", "Quarta",
                    "Quinta", "Sexta", "Sabado",
                    "Domingo"};
    int i;
    clrscr();
    for (i = 0; i < 7; i++)
    {
        printf("\n dia da semana : % d \n", i + 1);
        while (*dias[i])
        {
            printf("% c", *dias[i]++);
        }
    }
    getch();
}

void quarto()
{
    char *dias[] = {"Segunda", "Terça", "Quarta",
                    "Quinta", "Sexta", "Sabado",
                    "Domingo"};
    int i;
    clrscr();
    for (i = 0; i < 7; i++)
    {
        printf("\n dia da semana : % d\n", i + 1);
        printf("\n%s", dias[i]);
    }
}

void quinto()
{
    int *p, i = 20;
    p = &i;
    printf("% i", sizeof(p));
    printf("% i", sizeof(*p));
}
