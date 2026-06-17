#include <stdio.h>
#include <assert.h>
#include "functions_jogo-da-velha.h"

void rodar_testes() {
    char t[3][3];
    
    inicializar_tabuleiro(t);
    assert(t[0][0] == ' ');
  
    assert(jogada_valida(t, 0, 0) == 1);
    assert(jogada_valida(t, 4, 0) == 0); // Fora do limite
    t[0][0] = 'X';
    assert(jogada_valida(t, 0, 0) == 0); // Casa ocupada

    inicializar_tabuleiro(t);
    t[0][0] = 'X'; t[0][1] = 'X'; t[0][2] = 'X';
    assert(verificar_vencedor(t, 'X') == 1);
    assert(verificar_vencedor(t, 'O') == 0);

    inicializar_tabuleiro(t);
    assert(tabuleiro_cheio(t) == 0);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++) t[i][j] = 'X';
    assert(tabuleiro_cheio(t) == 1);

    printf("Todos os testes passaram com sucesso!\n");
}

int main() {
    rodar_testes();
    printf("Criado por Miguel de Mello Gomes\n");
    return 0;
}
