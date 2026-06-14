#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 1000
#define TAM 8
enum dificuldade
{
    FACIL,
    MEDIO,
    DIFICIL
};
struct Jogador
{
    char nome[25];
    int pontos;
    int tempo;
};

typedef enum dificuldade dificuldade_t;
typedef struct Jogador jogador_t;

char tabuleiro[TAM][TAM];
int matriz[TAM][TAM];
int escolhido[TAM][TAM];
int contador_de_players = 0;
jogador_t *tabela_com_ranking = NULL;

int gerar_minas(dificuldade_t dificuldade_escolhida);
dificuldade_t escolha_dificuldade();
void calcular_pontuacao(jogador_t *jogador, dificuldade_t dificuldade);
void contador_de_jogadas();
void get_input(int *escolha_de_linha, int *escolha_de_coluna);
void criar_tabuleiro();
void gerar_tabuleiro(dificuldade_t dificuldade);
void imprimir_tabuleiro();
void calcular_minas();
void imprimir_tutorial();
void imprimir_comandos();
void imprimir_ranking();
void inicializar_jogador(jogador_t *jogador);
void imprimir_menu(dificuldade_t dificuldade);
void gerar_contagem();
void loop();
void gerar_ranking(jogador_t *jogador);
void reiniciar_partida(jogador_t *jogador);
void limpar_nome(jogador_t *jogador);
void limpar_tela();
int main()
{
    srand(time(NULL));
    time_t inicial, final;
    inicial = time(NULL);
    dificuldade_t dificuldade = escolha_dificuldade();
    imprimir_menu(dificuldade);
    criar_tabuleiro();
    gerar_tabuleiro(dificuldade);
    calcular_minas();
    loop();
    final = time(NULL);
    return 0;
}
int gerar_minas(dificuldade_t dificuldade_escolhida)
{
    int quantidade_de_minas;
    if (dificuldade_escolhida == FACIL)
    {
        quantidade_de_minas = 5;
    }
    else if (dificuldade_escolhida == MEDIO)
    {
        quantidade_de_minas = 8;
    }
    else
    {
        quantidade_de_minas = 10;
    }
    return quantidade_de_minas;
}
dificuldade_t escolha_dificuldade()
{
    int n;
    dificuldade_t dificuldade_escolhida;
    printf("Escolha uma das opções de dificuldade\n");
    printf("1 - FÁCIL\n");
    printf("2 - MÉDIO\n");
    printf("3 - DÍFICIL\n");
    scanf("%d", &n);
    while (n < 1 || n > 3)
    {
        printf("Opção inválida.\n");
        scanf("%d", &n);
    }
    limpar_tela();
    return (dificuldade_t)(n - 1);
}
void calcular_pontuacao(jogador_t *jogador, dificuldade_t dificuldade)
{
    int tempo_gasto = jogador->tempo;
    int mult;
    int ok = 0;
    if (dificuldade == FACIL)
        mult = 1;
    else if (dificuldade == MEDIO)
        mult = 2;
    else
    {
        mult = 3;
    }
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (escolhido[i][j] == 1 && matriz[i][j] != -1)
            {
                ok++;
            }
        }
    }
    int pontos = ok * 100 * mult;
    int tempo = tempo_gasto / 3;
    jogador->pontos = pontos - tempo;
    if (jogador->pontos < 0)
    {
        jogador->pontos = 0;
    }
    return;
}
void get_input(int *escolha_de_linha, int *escolha_de_coluna)
{
    printf("Insira qual a linha que você tem interesse em verificar. (Insira número de 1 a %i) \n", TAM);
    scanf("%d", escolha_de_linha);
    while (*escolha_de_linha > TAM || *escolha_de_linha < 1)
    {
        printf("Número fora do alcance do tabuleiro. Insira novamente\n");
        scanf("%d", escolha_de_linha);
    }
    (*escolha_de_linha)--;
    printf("Insira qual a coluna que você tem interesse em verificar. (Insira número de 1 a %i) \n", TAM);
    scanf("%d", escolha_de_coluna);
    while (*escolha_de_coluna > TAM || *escolha_de_coluna < 1)
    {
        printf("Número fora do alcance do tabuleiro. Insira novamente\n");
        scanf("%d", escolha_de_coluna);
    }
    (*escolha_de_coluna)--;
    return;
}
void criar_tabuleiro()
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            escolhido[i][j] = 0;
            matriz[i][j] = 0;
        }
    }
}
void gerar_tabuleiro(dificuldade_t dificuldade)
{
    int quantidade_de_minas = gerar_minas(dificuldade);
    while (quantidade_de_minas > 0)
    {
        int linha = rand() % TAM;
        int col = rand() % TAM;
        if (matriz[linha][col] != -1)
        {
            matriz[linha][col] = -1;
            quantidade_de_minas--;
        }
    }
}
void imprimir_tabuleiro()
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (escolhido[i][j] == 0)
            {
                printf("# ");
            }
            else
            {
                printf("%d ", matriz[i][j]);
            }
        }
        printf(" \n");
    }
    printf("Pressione R caso queira REINICIAR O JOGO");
}
void inicializar_jogador(jogador_t *jogador)
{
    printf("Qual o nome do jogador?\n");
    scanf("%s", jogador->nome);
    jogador->pontos = 0;
    jogador->tempo = 0;
    return;
}
void calcular_minas()
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (matriz[i][j] == -1)
                continue;
            int minas = 0;
            for (int a = -1; a <= 1; a++)
            {
                for (int b = -1; b <= 1; b++)
                {
                    int n1 = i + a;
                    int n2 = j + b;
                    if (n1 >= 0 && n1 < TAM && n2 >= 0 && n2 < TAM && matriz[n1][n2] == -1)
                        minas++;
                }
            }
            matriz[i][j] = minas;
        }
    }
}
void imprimir_tutorial()
{
    printf("Seja bem-vindo!\n");
}
void imprimir_comandos()
{
    printf(" ====== COMANDOS ======\n");
    printf("Q - Pressione Q para desistir do jogo");
    printf("R - Pressione R para reiniciar o jogo sem salvar os status atuais\n");
    printf("1 ~ 8 - Escolha um número de 1 a 8 para escolher qual coluna/linha você vai querer descobrir\n ");
    return;
}
void imprimir_ranking()
{
    FILE *pointeiro_pro_arquivo = fopen("Ranking_Oficial.txt", "r");
    char buffer[1024];
    if (!pointeiro_pro_arquivo)
    {
        perror("Erro ao abrir arquivo");
        return;
    }
    while (fgets(buffer, sizeof(buffer), pointeiro_pro_arquivo) != NULL)
    {
        printf("%s\n", buffer);
    }
    fclose(pointeiro_pro_arquivo);
    return;
}
void imprimir_menu(dificuldade_t dificuldade)
{
    printf(" ======== CAMPO MINADO ======== \n");
    printf("Escolha uma das seguintes opções\n");
    printf("1 - Começar jogo\n");
    printf("2 - Tutorial\n");
    printf("3 - Comandos\n");
    printf("4 - Rankings\n");
    printf("5 - Sair\n");
    int op;
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        loop();
        break;
    case 2:
        imprimir_tutorial();
        break;
    case 3:
        imprimir_comandos();
        break;
    case 4:
        imprimir_ranking();
        break;
    case 5:
        return;
    default:
        printf("Opção inválida.\n");
    }
}
void loop()
{
    jogador_t jogador;
    inicializar_jogador(&jogador);
    int linha, coluna;
    while (1)
    {
        get_input(&linha, &coluna);
        escolhido[linha][coluna] = 1;
        if (matriz[linha][coluna] == -1)
        {
            limpar_tela();
            printf(" == VOCÊ PERDEU == !\n");
            gerar_ranking(&jogador);
            break;
        }
    }
    return;
}
int compare(const void *a, const void *b)
{
    jogador_t *jogador_1 = (jogador_t *)a;
    jogador_t *jogador_2 = (jogador_t *)b;
    return (jogador_2->pontos - jogador_1->pontos);
}
void gerar_ranking(jogador_t *jogador)
{
    FILE *file = fopen("Ranking_Oficial.txt", "a");
    if (file == NULL)
    {
        perror("Erro ao criar/acessar arquivo");
        return;
    }
    contador_de_players++;
    tabela_com_ranking = realloc(tabela_com_ranking, contador_de_players * sizeof(jogador_t));
    if (tabela_com_ranking == NULL)
    {
        perror("Erro ao alocar\n");
        return;
    }
    tabela_com_ranking[contador_de_players - 1] = *jogador;
    qsort(tabela_com_ranking, contador_de_players, sizeof(jogador_t), compare);
    fclose(file);
    return;
}
void reiniciar_partida(jogador_t *jogador)
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            matriz[i][j] = 0;
            escolhido[i][j] = 0;
            tabuleiro[i][j] = 0;
        }
    }
    limpar_nome(jogador);
    jogador->pontos = 0;
    jogador->tempo = 0;
    limpar_tela();
    return;
}
void limpar_nome(jogador_t *jogador)
{
    jogador->nome[0] = '\0';
}
void limpar_tela()
{
    printf("\e[1J\e[H");
    fflush(stdout);
}