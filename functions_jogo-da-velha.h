#ifndef FUNCTIONS_JOGO_DA_VELHA_H
#define FUNCTIONS_JOGO_DA_VELHA_H


void inicializar_tabuleiro(char tab[3][3]);

void exibir_tabuleiro(char tab[3][3]);

int jogada_valida(char tab[3][3], int l, int c);

void obter_jogada_computador(char tab[3][3], int *l, int *c);

int verificar_vencedor(char tab[3][3], char j);

int tabuleiro_cheio(char tab[3][3]);

#endif // FUNCTIONS_JOGO_DA_VELHA_H
