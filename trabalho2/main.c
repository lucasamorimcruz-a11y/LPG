#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char pais[50];
    char grupo;
    int jogos;
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
} Selecao;

int pontos(Selecao s)
{
    return s.vitorias * 3 + s.empates;
}

void limpar_tela()
{
    printf("\e[1J\e[H");
    fflush(stdout);
}

void imprimir_selecao(Selecao s)
{
    printf("País: %s\n", s.pais);
    printf("Grupo: %c\n", s.grupo);
    printf("Jogos: %d\n", s.jogos);
    printf("Vitórias: %d\n", s.vitorias);
    printf("Empates: %d\n", s.empates);
    printf("Derrotas: %d\n", s.derrotas);
    printf("Gols marcados: %d\n", s.gols_marcados);
    printf("Gols sofridos: %d\n", s.gols_sofridos);
    printf("-----------------\n");
}

void cadastrar_selecao()
{
    FILE *arquivo = fopen("copa.txt", "a");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Selecao s;
    getchar();
    printf("Insira o nome do país:\n");
    fgets(s.pais, sizeof(s.pais), stdin);
    s.pais[strcspn(s.pais, "\r\n")] = '\0';
    printf("Insira o grupo (A - H):\n");
    scanf(" %c", &s.grupo);
    s.grupo = toupper(s.grupo);
    if (s.grupo < 'A' || s.grupo > 'H')
    {
        printf("Grupo inválido\n");
        fclose(arquivo);
        return;
    }
    printf("Jogos: ");
    scanf("%d", &s.jogos);
    printf("Vitórias: ");
    scanf("%d", &s.vitorias);
    printf("Empates: ");
    scanf("%d", &s.empates);
    printf("Derrotas: ");
    scanf("%d", &s.derrotas);
    if (s.vitorias + s.empates + s.derrotas != s.jogos)
    {
        printf("Dados inválidos\n");
        fclose(arquivo);
        return;
    }
    printf("Gols marcados: ");
    scanf("%d", &s.gols_marcados);
    printf("Gols sofridos: ");
    scanf("%d", &s.gols_sofridos);
    fprintf(arquivo, "%s;%c;%d;%d;%d;%d;%d;%d;\n", s.pais, s.grupo, s.jogos, s.vitorias, s.empates, s.derrotas, s.gols_marcados, s.gols_sofridos);
    fclose(arquivo);
    printf("Seleção cadastrada!\n");
}

void listar_selecoes()
{
    FILE *arquivo = fopen("copa.txt", "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Selecao s;
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%49[^;];%c;%d;%d;%d;%d;%d;%d;", s.pais, &s.grupo, &s.jogos, &s.vitorias, &s.empates, &s.derrotas, &s.gols_marcados, &s.gols_sofridos) == 8)
        {
            imprimir_selecao(s);
        }
    }
    fclose(arquivo);
}

void buscar_selecao(char *nome)
{
    FILE *arquivo = fopen("copa.txt", "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Selecao s;
    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%49[^;];%c;%d;%d;%d;%d;%d;%d;", s.pais, &s.grupo, &s.jogos, &s.vitorias, &s.empates, &s.derrotas, &s.gols_marcados, &s.gols_sofridos) == 8)
        {
            if (strcmp(s.pais, nome) == 0)
            {
                imprimir_selecao(s);
                fclose(arquivo);
                return;
            }
        }
    }
    printf("Seleção não encontrada.\n");
    fclose(arquivo);
}
void mostrar_classificacao()
{
    FILE *arquivo = fopen("copa.txt", "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Selecao lista[48];
    int total = 0;
    char linha[256];
    while (total < 48 && fgets(linha, sizeof(linha), arquivo))
    {
        Selecao s;
        if (sscanf(linha, "%49[^;];%c;%d;%d;%d;%d;%d;%d;", s.pais, &s.grupo, &s.jogos, &s.vitorias, &s.empates, &s.derrotas, &s.gols_marcados, &s.gols_sofridos) == 8)
        {
            lista[total++] = s;
        }
    }
    fclose(arquivo);
    if (total == 0)
    {
        printf("Nenhuma seleção cadastrada.\n");
        return;
    }
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (pontos(lista[j]) < pontos(lista[j + 1]))
            {
                Selecao tmp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tmp;
            }
        }
    }
    printf("=== CLASSIFICAÇÃO ===\n");
    for (int i = 0; i < total; i++)
    {
        printf("%dº - %s | %d pts\n", i + 1, lista[i].pais, pontos(lista[i]));
    }
}

int main()
{
    int c;
    do
    {
        printf("\n1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Classificação\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            limpar_tela();
            cadastrar_selecao();
            break;
        case 2:
            limpar_tela();
            listar_selecoes();
            break;
        case 3:
        {
            char buffer[50];
            getchar();
            limpar_tela();
            printf("Digite o país:\n");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            buscar_selecao(buffer);
            break;
        }
        case 4:
            limpar_tela();
            mostrar_classificacao();
            break;
        }
    } while (c != 5);
    return 0;
}