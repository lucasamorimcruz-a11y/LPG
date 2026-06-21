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
void get_input(int *escolha_de_linha, int *escolha_de_coluna, int *reiniciar, int *desistir);
void limpa_entrada();
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
int main()
{
    srand(time(NULL));
    dificuldade_t dificuldade = escolha_dificuldade();
    imprimir_menu(&dificuldade);
    return 0;
}
int gerar_minas(dificuldade_t dificuldade_escolhida)
{
    if (dificuldade_escolhida == FACIL)
    {
        return 5;
    }
    else if (dificuldade_escolhida == MEDIO)
    {
        return 8;
    }
    else
    {
        return 10;
    }
}
dificuldade_t escolha_dificuldade()
{
    limpar_tela();
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
    dificuldade_escolhida = n - 1;
    limpar_tela();
    return dificuldade_escolhida;
}
void calcular_pontuacao(jogador_t *jogador, dificuldade_t dificuldade)
{
    int tempo_gasto = jogador->tempo;
    int mult;
    int ok = 0;
    if (dificuldade == FACIL)
    {
        mult = 1;
    }
    else if (dificuldade == MEDIO)
    {
        mult = 2;
    }
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
void limpa_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
void get_input(int *escolha_de_linha, int *escolha_de_coluna, int *reiniciar, int *desistir)
{
    char buffer[64];
    char *ptr;
    int valor;
    int resultado_scanf;
    *reiniciar = 0;
    *desistir = 0;

    while (1)
    {
        printf("Insira qual a linha que você tem interesse em verificar. (Insira número de 1 a %i) \n", TAM);
        resultado_scanf = scanf("%63s", buffer);
        if (resultado_scanf == EOF)
        {
            printf("Entrada encerrada. Saindo do jogo.\n");
            exit(0);
        }
        if (resultado_scanf != 1)
        {
            limpa_entrada();
            continue;
        }
        if (buffer[0] == 'R' || buffer[0] == 'r')
        {
            *reiniciar = 1;
            return;
        }
        if (buffer[0] == 'Q' || buffer[0] == 'q')
        {
            *desistir = 1;
            return;
        }
        valor = strtoi(buffer, &ptr, 10);
        if (*ptr != '\0' || valor < 1 || valor > TAM)
        {
            printf("Número fora do alcance do tabuleiro. Insira novamente\n");
            continue;
        }
        *escolha_de_linha = valor;
        break;
    }
    (*escolha_de_linha)--;
    while (1)
    {
        printf("Insira qual a coluna que você tem interesse em verificar. (Insira número de 1 a %i) \n", TAM);
        resultado_scanf = scanf("%63s", buffer);
        if (resultado_scanf == EOF)
        {
            printf("Entrada encerrada. Saindo do jogo.\n");
            exit(0);
        }
        if (resultado_scanf != 1)
        {
            limpa_entrada();
            continue;
        }
        valor = strtoi(buffer, &ptr, 10);
        if (*ptr != '\0' || valor < 1 || valor > TAM)
        {
            printf("Número fora do alcance do tabuleiro. Insira novamente\n");
            continue;
        }
        *escolha_de_coluna = (int)valor;
        break;
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
    printf("   ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%2d", i + 1);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%2d", i + 1);
        for (int j = 0; j < TAM; j++)
        {
            if (escolhido[i][j] == 0)
            {
                printf(" #");
            }
            else if (matriz[i][j] == -1)
            {
                printf(" *");
            }
            else
            {
                printf("%2d", matriz[i][j]);
            }
        }
        printf(" \n");
    }
    printf("\n Digite no formato '-> LINHA <- -> COLUNA <-' || [R para REINCIAR e Q para DESISTIR]\n");
    ;
}
void inicializar_jogador(jogador_t *jogador)
{
    printf("Qual o nome do jogador? (Primeiro nome somente)\n");
    scanf("%s", jogador->nome);
    fflush(stdout);
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
            {
                continue;
            }
            int minas = 0;
            for (int a = -1; a <= 1; a++)
            {
                for (int b = -1; b <= 1; b++)
                {
                    int n1 = i + a;
                    int n2 = j + b;
                    if (n1 >= 0 && n1 < TAM && n2 >= 0 && n2 < TAM && matriz[n1][n2] == -1)
                    {
                        minas++;
                    }
                }
            }
            matriz[i][j] = minas;
        }
    }
}
void getv()
{
    int c;
    do
    {
        c = getchar();
    } while (c != 'v' && c != 'V' && c != EOF);
}
void imprimir_tutorial()
{
    limpar_tela();
    printf(" ==== TUTORIAL ==== \n");
    printf(" # -> Casa ainda a ser revelada. Pode ser escolhida. \n");
    printf(" 0 -> Nenhuma mina adjacente.\n ");
    printf(" N (N sendo qualquer número) -> Quantidade de minas ao redor da casa.\n");
    printf(" * -> Mina. Fim de jogo.\n");
    printf("\n\n\n");
    printf(" == Dificuldades == \n");
    printf(" FÁCIL - 5 minas espalhadas pelo campo\n");
    printf(" MÉDIO - 8 minas espalhadas pelo campo\n");
    printf(" DÍFICIL - 10 minas espalhadas pelo campo\n");
    printf("\n\n\n");
    printf("Pressione 'V' para retornar ao menu principal\n");
    fflush(stdout);
    getv();
    limpar_tela();
    return;
}
void imprimir_comandos()
{
    limpar_tela();
    printf(" ====== COMANDOS ======\n");
    printf("  LINHA COLUNA  - Digite o número da linha e da coluna separados por espaço\n");
    printf("1 ~ 8 - Escolha um número de 1 a 8 para escolher qual coluna/linha você vai querer descobrir\n ");
    printf("Q - Pressione Q para desistir do jogo\n");
    printf("R - Pressione R para reiniciar o jogo sem salvar os status atuais\n");
    printf("\n\n\n");
    printf("Pressione 'V' para retornar ao menu principal\n");
    fflush(stdout);
    getv();
    limpar_tela();
    return;
}
void imprimir_ranking()
{
    limpar_tela();
    FILE *pointeiro_pro_arquivo = fopen("Ranking_Oficial.txt", "r");
    char buffer[1024];
    if (!pointeiro_pro_arquivo)
    {
        printf("Ainda não há ranking salvo.\n");
        printf("Pressione 'V' para retornar ao menu principal\n");
        fflush(stdout);
        getv();
        return;
    }
    while (fgets(buffer, sizeof(buffer), pointeiro_pro_arquivo) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(pointeiro_pro_arquivo);
    printf("\nPressione 'V' para retornar ao menu principal\n");
    fflush(stdout);
    getv();
    limpar_tela();
    return;
}
void imprimir_menu(dificuldade_t *dificuldade)
{
    while (1)
    {
        printf(" ======== CAMPO MINADO ======== \n");
        printf("Escolha uma das seguintes opções\n");
        printf("1 - Começar jogo\n");
        printf("2 - Tutorial\n");
        printf("3 - Comandos\n");
        printf("4 - Rankings\n");
        printf("5 - Mudar dificuldade\n");
        printf("6 - Sair\n");
        int op;
        if (scanf("%d", &op) != 1)
        {
            limpa_entrada();
            printf("Opção inválida.\n");
            continue;
        }
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
            printf("Dificuldade mudada\n");
            break;
        case 6:
            printf("Encerrando.\n");
            free(tabela_com_ranking);
            return;
        default:
            printf("Opção inválida.\n");
        }
    }
}
int verificar_vitoria()
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (matriz[i][j] != -1 && escolhido[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
void loop(dificuldade_t dificuldade)
{
    limpar_tela();
    jogador_t jogador;
    inicializar_jogador(&jogador);

    time_t comeco_jogo = time(NULL);
    while (1)
    {
        limpar_tela();
        imprimir_tabuleiro();
        int linha = 0, coluna = 0, reiniciar = 0, desistir = 0;
        get_input(&linha, &coluna, &reiniciar, &desistir);
        if (reiniciar)
        {
            reiniciar_partida(&jogador, dificuldade);
            comeco_jogo = time(NULL);
            continue;
        }
        if (desistir)
        {
            jogador.tempo = (int)(time(NULL) - comeco_jogo);
            calcular_pontuacao(&jogador, dificuldade);
            printf("\nVocê desistiu. Pontuação: %d\n", jogador.pontos);
            gerar_ranking(&jogador);
            printf("Pressione ENTER para voltar ao menu...");
            fflush(stdout);
            while (getchar() != '\n')
            {
            }
            limpar_tela();
            return;
        }

        if (escolhido[linha][coluna] == 1)
        {
            printf("Essa casa já foi revelada! Tente outra.\n");
            continue;
        }

        escolhido[linha][coluna] = 1;

        if (matriz[linha][coluna] == -1)
        {
            for (int i = 0; i < TAM; i++)
            {
                for (int j = 0; j < TAM; j++)
                {
                    if (matriz[i][j] == -1)
                    {
                        escolhido[i][j] = 1;
                    }
                }
            }
            limpar_tela();
            imprimir_tabuleiro();
            jogador.tempo = (int)(time(NULL) - comeco_jogo);
            calcular_pontuacao(&jogador, dificuldade);
            printf("\n== VOCÊ PERDEU! ==  Pontuação: %d\n", jogador.pontos);
            gerar_ranking(&jogador);
            printf("Pressione ENTER para voltar ao menu...");
            fflush(stdout);
            while (getchar() != '\n')
            {

            }
            limpar_tela();
            return;
        }

        if (verificar_vitoria())
        {
            limpar_tela();
            imprimir_tabuleiro();
            jogador.tempo = (int)(time(NULL) - comeco_jogo);
            calcular_pontuacao(&jogador, dificuldade);
            printf("\n== VOCÊ VENCEU! ==  Pontuação: %d\n", jogador.pontos);
            gerar_ranking(&jogador);
            printf("Pressione ENTER para voltar ao menu...");
            fflush(stdout);
            while (getchar() != '\n')
            {
            }
            limpar_tela();
            return;
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
    contador_de_players++;

    jogador_t *tempo = realloc(tabela_com_ranking, contador_de_players * sizeof(jogador_t));
    if (!tempo)
    {
        perror("Erro ao alocar.");
        return;
    }
    tabela_com_ranking = tempo;
    tabela_com_ranking[contador_de_players - 1] = *jogador;
    qsort(tabela_com_ranking, contador_de_players, sizeof(jogador_t), compare);
    FILE *file = fopen("Ranking_Oficial.txt", "w");
    if (!file)
    {
        perror("Erro ao abrir arquivo do ranking");
        return;
    }
    fprintf(file, "%-s %-s %-s %s\n", "POS", "NOME", "PONTOS", "TEMPO");
    fprintf(file, "----------------------------------------------------\n");
    for (int i = 0; i < contador_de_players; i++)
    {
        fprintf(file, "%-5d %-25s %-10d %-10d\n", i + 1, tabela_com_ranking[i].nome, tabela_com_ranking[i].pontos, tabela_com_ranking[i].tempo);
    }
    fclose(file);
    return;
}
void reiniciar_partida(jogador_t *jogador, dificuldade_t dificuldade)
{
    criar_tabuleiro();
    gerar_tabuleiro(dificuldade);
    calcular_minas();
    limpar_nome(jogador);
    jogador->tempo = 0;
    jogador->pontos = 0;
    limpar_tela();
    inicializar_jogador(jogador);
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