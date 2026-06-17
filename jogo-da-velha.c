#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions_jogo-da-velha.c"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char tab[3][3];
    char h_char = ' ', c_char = ' ';
    int is_auto = 0, turno = 1;

    // Definição do caractere
    if (argc > 1 && (argv[1][0] == 'X' || argv[1][0] == 'O')) {
        h_char = argv[1][0];
    } else {
        while (h_char != 'X' && h_char != 'O') {
            printf("Escolha seu caractere (X ou O): ");
            scanf(" %c", &h_char);
        }
    }
    c_char = (h_char == 'X') ? 'O' : 'X';

    // Verificação do modo auto
    if (argc > 2 && strcmp(argv[2], "auto") == 0) {
        is_auto = 1;
    }

    inicializar_tabuleiro(tab);

    while (1) {
        int l, c;
        if (turno == 1) {
            if (is_auto) {
                obter_jogada_computador(tab, &l, &c);
            } else {
                do {
                    printf("Jogador 1 (%c) - Informe linha (1-3) e coluna (1-3): ", h_char);
                    scanf("%d %d", &l, &c);
                    l--; c--; // Ajuste para índice 0
                } while (!jogada_valida(tab, l, c));
            }
            tab[l][c] = h_char;
            exibir_tabuleiro(tab);
            if (verificar_vencedor(tab, h_char)) { printf("O jogador 1 ganhou\n"); break; }
        } else {
            obter_jogada_computador(tab, &l, &c);
            tab[l][c] = c_char;
            printf("Computador jogou:\n");
            exibir_tabuleiro(tab);
            if (verificar_vencedor(tab, c_char)) { printf("O jogador 2 ganhou\n"); break; }
        }

        if (tabuleiro_cheio(tab)) { printf("O jogo terminou sem vencedores\n"); break; }
        turno = (turno == 1) ? 2 : 1;
    }

    printf("Criado por Miguel de Mello Gomes\n");
    return 0;
}
