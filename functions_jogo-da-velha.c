#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar_tabuleiro(char tab[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tab[i][j] = ' ';
}

void exibir_tabuleiro(char tab[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", tab[i][0], tab[i][1], tab[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int jogada_valida(char tab[3][3], int l, int c) {
    if (l < 0 || l > 2 || c < 0 || c > 2) return 0;
    if (tab[l][c] != ' ') return 0;
    return 1;
}

void obter_jogada_computador(char tab[3][3], int *l, int *c) {
    do {
        *l = rand() % 3;
        *c = rand() % 3;
    } while (!jogada_valida(tab, *l, *c));
}

int verificar_vencedor(char tab[3][3], char j) {
    for (int i = 0; i < 3; i++) {
        if (tab[i][0] == j && tab[i][1] == j && tab[i][2] == j) return 1;
        if (tab[0][i] == j && tab[1][i] == j && tab[2][i] == j) return 1;
    }
    if (tab[0][0] == j && tab[1][1] == j && tab[2][2] == j) return 1;
    if (tab[0][2] == j && tab[1][1] == j && tab[2][0] == j) return 1;
    return 0;
}

int tabuleiro_cheio(char tab[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tab[i][j] == ' ') return 0;
    return 1;
}
