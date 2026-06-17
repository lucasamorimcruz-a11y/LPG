#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

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

/* tabuleiro char removed — matriz + escolhido are sufficient */
int matriz[TAM][TAM];
int escolhido[TAM][TAM];
int contador_de_players = 0;
jogador_t *tabela_com_ranking = NULL;

/* forward declarations */
int gerar_minas(dificuldade_t dificuldade_escolhida);
dificuldade_t escolha_dificuldade();
void calcular_pontuacao(jogador_t *jogador, dificuldade_t dificuldade);
void get_input(int *escolha_de_linha, int *escolha_de_coluna, int *reiniciar, int *desistir);
void criar_tabuleiro();
void gerar_tabuleiro(dificuldade_t dificuldade);
void imprimir_tabuleiro();
void calcular_minas();
void imprimir_tutorial();
void imprimir_comandos();
void imprimir_ranking();
void inicializar_jogador(jogador_t *jogador);
void imprimir_menu(dificuldade_t *dificuldade);
void loop(dificuldade_t dificuldade);
void gerar_ranking(jogador_t *jogador);
void reiniciar_partida(jogador_t *jogador, dificuldade_t dificuldade);
void limpar_nome(jogador_t *jogador);
void limpar_tela();
int verificar_vitoria();

/* ------------------------------------------------------------------ */
int main()
{
    srand((unsigned)time(NULL));
    dificuldade_t dificuldade = escolha_dificuldade();
    imprimir_menu(&dificuldade);
    return 0;
}

/* ------------------------------------------------------------------ */
int gerar_minas(dificuldade_t dificuldade_escolhida)
{
    if (dificuldade_escolhida == FACIL)  return 5;
    if (dificuldade_escolhida == MEDIO)  return 8;
    return 10;
}

/* ------------------------------------------------------------------ */
dificuldade_t escolha_dificuldade()
{
    int n;
    printf("Escolha uma das opções de dificuldade\n");
    printf("1 - FÁCIL\n");
    printf("2 - MÉDIO\n");
    printf("3 - DIFÍCIL\n");
    scanf("%d", &n);
    while (n < 1 || n > 3)
    {
        printf("Opção inválida. Tente novamente: ");
        scanf("%d", &n);
    }
    limpar_tela();
    return (dificuldade_t)(n - 1);
}

/* ------------------------------------------------------------------ */
void calcular_pontuacao(jogador_t *jogador, dificuldade_t dificuldade)
{
    int mult;
    if (dificuldade == FACIL)       mult = 1;
    else if (dificuldade == MEDIO)  mult = 2;
    else                            mult = 3;

    int ok = 0;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (escolhido[i][j] == 1 && matriz[i][j] != -1)
                ok++;

    int pontos = ok * 100 * mult;
    int penalidade = jogador->tempo / 3;
    jogador->pontos = pontos - penalidade;
    if (jogador->pontos < 0)
        jogador->pontos = 0;
}

/* ------------------------------------------------------------------ */
/*
 * Reads a line from stdin and parses it.
 * Sets *reiniciar=1 if user typed 'R'/'r', *desistir=1 if 'Q'/'q'.
 * Otherwise fills *linha and *coluna (0-based).
 */
void get_input(int *linha, int *coluna, int *reiniciar, int *desistir)
{
    *reiniciar = 0;
    *desistir  = 0;

    char buf[64];
    /* consume any leftover newline */
    int c;
    while ((c = getchar()) == '\n' || c == ' ');
    ungetc(c, stdin);

    if (!fgets(buf, sizeof(buf), stdin)) return;

    /* strip trailing newline */
    buf[strcspn(buf, "\n")] = '\0';

    if (buf[0] == 'R' || buf[0] == 'r') { *reiniciar = 1; return; }
    if (buf[0] == 'Q' || buf[0] == 'q') { *desistir  = 1; return; }

    int l = -1, col = -1;
    printf("Insira a linha (1 a %d): ", TAM);
    fflush(stdout);
    /* try to parse two numbers from the buffer first */
    if (sscanf(buf, "%d %d", &l, &col) == 2)
    {
        /* user typed both on one line */
    }
    else if (sscanf(buf, "%d", &l) == 1)
    {
        /* need the column still */
        printf("Insira a coluna (1 a %d): ", TAM);
        fflush(stdout);
        scanf("%d", &col);
    }
    else
    {
        printf("Entrada inválida.\n");
        return;
    }

    while (l < 1 || l > TAM)
    {
        printf("Linha fora do alcance. Insira novamente (1 a %d): ", TAM);
        scanf("%d", &l);
    }
    while (col < 1 || col > TAM)
    {
        printf("Coluna fora do alcance. Insira novamente (1 a %d): ", TAM);
        scanf("%d", &col);
    }

    *linha  = l - 1;
    *coluna = col - 1;
}

/* ------------------------------------------------------------------ */
void criar_tabuleiro()
{
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
        {
            escolhido[i][j] = 0;
            matriz[i][j]    = 0;
        }
}

/* ------------------------------------------------------------------ */
void gerar_tabuleiro(dificuldade_t dificuldade)
{
    int quantidade = gerar_minas(dificuldade);
    while (quantidade > 0)
    {
        int linha = rand() % TAM;
        int col   = rand() % TAM;
        if (matriz[linha][col] != -1)
        {
            matriz[linha][col] = -1;
            quantidade--;
        }
    }
}

/* ------------------------------------------------------------------ */
void imprimir_tabuleiro()
{
    /* column header */
    printf("   ");
    for (int j = 0; j < TAM; j++) printf("%2d", j + 1);
    printf("\n");

    for (int i = 0; i < TAM; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++)
        {
            if (escolhido[i][j] == 0)
                printf(" #");
            else if (matriz[i][j] == -1)
                printf(" *");   /* revealed mine (game over display) */
            else
                printf("%2d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n[Digite LINHA COLUNA  |  R = reiniciar  |  Q = desistir]\n");
}

/* ------------------------------------------------------------------ */
void inicializar_jogador(jogador_t *jogador)
{
    printf("Qual o nome do jogador? ");
    fflush(stdout);
    /* consume leftover newline if any */
    int c;
    while ((c = getchar()) == '\n');
    ungetc(c, stdin);
    scanf("%24s", jogador->nome);
    jogador->pontos = 0;
    jogador->tempo  = 0;
}

/* ------------------------------------------------------------------ */
void calcular_minas()
{
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
        {
            if (matriz[i][j] == -1) continue;
            int minas = 0;
            for (int a = -1; a <= 1; a++)
                for (int b = -1; b <= 1; b++)
                {
                    int ni = i + a, nj = j + b;
                    if (ni >= 0 && ni < TAM && nj >= 0 && nj < TAM && matriz[ni][nj] == -1)
                        minas++;
                }
            matriz[i][j] = minas;
        }
}

/* ------------------------------------------------------------------ */
void imprimir_tutorial()
{
    limpar_tela();
    printf("=== TUTORIAL ===\n\n");
    printf("Campo Minado é um jogo em que você deve descobrir todas as casas\n");
    printf("do tabuleiro SEM revelar nenhuma mina.\n\n");
    printf("Cada número revelado indica quantas minas existem nas casas\n");
    printf("adjacentes (incluindo diagonais). Use essa informação para\n");
    printf("deduzir onde estão as minas e evitá-las.\n\n");
    printf("  # = casa não revelada\n");
    printf("  0 = nenhuma mina adjacente\n");
    printf("  * = MINA (fim de jogo)\n\n");
    printf("Dificuldades:\n");
    printf("  FÁCIL   - 5 minas\n");
    printf("  MÉDIO   - 8 minas\n");
    printf("  DIFÍCIL - 10 minas\n\n");
    printf("Pressione ENTER para voltar ao menu...");
    fflush(stdout);
    while (getchar() != '\n');
    getchar();
}

/* ------------------------------------------------------------------ */
void imprimir_comandos()
{
    limpar_tela();
    printf("=== COMANDOS ===\n\n");
    printf("  LINHA COLUNA  - Digite o número da linha e da coluna separados por espaço\n");
    printf("                  para revelar aquela casa. Ex: 3 5\n");
    printf("  R             - Reinicia o jogo sem salvar pontuação\n");
    printf("  Q             - Desiste e salva a pontuação atual no ranking\n\n");
    printf("Pressione ENTER para voltar ao menu...");
    fflush(stdout);
    while (getchar() != '\n');
    getchar();
}

/* ------------------------------------------------------------------ */
void imprimir_ranking()
{
    limpar_tela();
    FILE *fp = fopen("Ranking_Oficial.txt", "r");
    if (!fp)
    {
        printf("Nenhum ranking disponível ainda.\n");
    }
    else
    {
        printf("=== RANKING ===\n\n");
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp))
            printf("%s", buffer);
        fclose(fp);
    }
    printf("\nPressione ENTER para voltar ao menu...");
    fflush(stdout);
    while (getchar() != '\n');
    getchar();
}

/* ------------------------------------------------------------------ */
/*
 * The menu is shown repeatedly until the user picks "Sair" or starts a game.
 * dificuldade is passed as pointer so it can be reused across sessions.
 */
void imprimir_menu(dificuldade_t *dificuldade)
{
    while (1)
    {
        limpar_tela();
        printf(" ======== CAMPO MINADO ======== \n");
        printf("Escolha uma das seguintes opções\n");
        printf("1 - Começar jogo\n");
        printf("2 - Tutorial\n");
        printf("3 - Comandos\n");
        printf("4 - Rankings\n");
        printf("5 - Alterar dificuldade\n");
        printf("6 - Sair\n");
        printf("> ");
        fflush(stdout);

        int op;
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            criar_tabuleiro();
            gerar_tabuleiro(*dificuldade);
            calcular_minas();
            loop(*dificuldade);
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
            limpar_tela();
            *dificuldade = escolha_dificuldade();
            printf("Dificuldade alterada!\n");
            break;
        case 6:
            printf("Até logo!\n");
            free(tabela_com_ranking);
            return;
        default:
            printf("Opção inválida.\n");
        }
    }
}

/* ------------------------------------------------------------------ */
/* Returns 1 if all non-mine cells have been revealed. */
int verificar_vitoria()
{
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (matriz[i][j] != -1 && escolhido[i][j] == 0)
                return 0;
    return 1;
}

/* ------------------------------------------------------------------ */
void loop(dificuldade_t dificuldade)
{
    jogador_t jogador;
    limpar_tela();
    inicializar_jogador(&jogador);

    time_t inicio = time(NULL);

    while (1)
    {
        limpar_tela();
        imprimir_tabuleiro();

        int linha = 0, coluna = 0, reiniciar = 0, desistir = 0;
        get_input(&linha, &coluna, &reiniciar, &desistir);

        if (reiniciar)
        {
            reiniciar_partida(&jogador, dificuldade);
            inicio = time(NULL);
            continue;
        }

        if (desistir)
        {
            jogador.tempo = (int)difftime(time(NULL), inicio);
            calcular_pontuacao(&jogador, dificuldade);
            printf("\nVocê desistiu. Pontuação: %d\n", jogador.pontos);
            gerar_ranking(&jogador);
            printf("Pressione ENTER para voltar ao menu...");
            fflush(stdout);
            while (getchar() != '\n');
            getchar();
            return;
        }

        /* ignore already-revealed cells */
        if (escolhido[linha][coluna] == 1)
        {
            printf("Essa casa já foi revelada! Tente outra.\n");
            continue;
        }

        escolhido[linha][coluna] = 1;

        if (matriz[linha][coluna] == -1)
        {
            /* reveal all mines for the loss screen */
            for (int i = 0; i < TAM; i++)
                for (int j = 0; j < TAM; j++)
                    if (matriz[i][j] == -1)
                        escolhido[i][j] = 1;

            limpar_tela();
            imprimir_tabuleiro();
            jogador.tempo = (int)difftime(time(NULL), inicio);
            calcular_pontuacao(&jogador, dificuldade);
            printf("\n== VOCÊ PERDEU! ==  Pontuação: %d\n", jogador.pontos);
            gerar_ranking(&jogador);
            printf("Pressione ENTER para voltar ao menu...");
            fflush(stdout);
            while (getchar() != '\n');
            getchar();
            return;
        }

        if (verificar_vitoria())
        {
            limpar_tela();
            imprimir_tabuleiro();
            jogador.tempo = (int)difftime(time(NULL), inicio);
            calcular_pontuacao(&jogador, dificuldade);
            printf("\n== VOCÊ VENCEU! ==  Pontuação: %d\n", jogador.pontos);
            gerar_ranking(&jogador);
            printf("Pressione ENTER para voltar ao menu...");
            fflush(stdout);
            while (getchar() != '\n');
            getchar();
            return;
        }
    }
}

/* ------------------------------------------------------------------ */
int compare(const void *a, const void *b)
{
    const jogador_t *j1 = (const jogador_t *)a;
    const jogador_t *j2 = (const jogador_t *)b;
    return j2->pontos - j1->pontos;   /* descending */
}

/* ------------------------------------------------------------------ */
void gerar_ranking(jogador_t *jogador)
{
    contador_de_players++;
    jogador_t *tmp = realloc(tabela_com_ranking, contador_de_players * sizeof(jogador_t));
    if (!tmp)
    {
        perror("Erro ao alocar memória para ranking");
        return;
    }
    tabela_com_ranking = tmp;
    tabela_com_ranking[contador_de_players - 1] = *jogador;
    qsort(tabela_com_ranking, contador_de_players, sizeof(jogador_t), compare);

    /* rewrite the entire ranking file so it stays sorted */
    FILE *file = fopen("Ranking_Oficial.txt", "w");
    if (!file)
    {
        perror("Erro ao abrir arquivo de ranking");
        return;
    }
    fprintf(file, "%-5s %-25s %-10s %-10s\n", "POS", "NOME", "PONTOS", "TEMPO(s)");
    fprintf(file, "----------------------------------------------------\n");
    for (int i = 0; i < contador_de_players; i++)
        fprintf(file, "%-5d %-25s %-10d %-10d\n",
                i + 1,
                tabela_com_ranking[i].nome,
                tabela_com_ranking[i].pontos,
                tabela_com_ranking[i].tempo);
    fclose(file);
}

/* ------------------------------------------------------------------ */
void reiniciar_partida(jogador_t *jogador, dificuldade_t dificuldade)
{
    criar_tabuleiro();
    gerar_tabuleiro(dificuldade);
    calcular_minas();
    limpar_nome(jogador);
    jogador->pontos = 0;
    jogador->tempo  = 0;
    limpar_tela();
    inicializar_jogador(jogador);
}

/* ------------------------------------------------------------------ */
void limpar_nome(jogador_t *jogador)
{
    jogador->nome[0] = '\0';
}

/* ------------------------------------------------------------------ */
void limpar_tela()
{
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
    fflush(stdout);
#endif
}