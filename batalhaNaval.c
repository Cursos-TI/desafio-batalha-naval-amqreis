#include <stdio.h>

#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%2d ", col);
    }
    #define TAMANHO_TABULEIRO 10
    printf("\n");

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d ", linha);
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%2d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 4;
    int linha_vertical = 5, coluna_vertical = 7;

    // Validação de limites
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio horizontal ultrapassa os limites.\n");
        return 1;
    }

    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio vertical ultrapassa os limites.\n");
        return 1;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == VALOR_NAVIO ||
            tabuleiro[linha_vertical + i][coluna_vertical] == VALOR_NAVIO) {
            printf("Erro: sobreposição detectada.\n");
            return 1;
        }
    }

    // Posiciona navio horizontal
    printf("Navio horizontal (linha %d):\n", linha_horizontal);
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = VALOR_NAVIO;
        printf(" -> Coordenada [%d][%d]\n", linha_horizontal, coluna_horizontal + i);
    }

    // Posiciona navio vertical
    printf("Navio vertical (coluna %d):\n", coluna_vertical);
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = VALOR_NAVIO;
        printf(" -> Coordenada [%d][%d]\n", linha_vertical + i, coluna_vertical);
    }

    // Exibe tabuleiro
    printf("\nTabuleiro com navios:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
