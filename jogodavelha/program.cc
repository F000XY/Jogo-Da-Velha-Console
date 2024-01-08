#include <iostream>
#include <stdio.h>
using namespace std;

#define TAMANHO 3
// criando linha
int iniciarOtabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[j][i] = ' ';
        }
    }
    return 0;
}
// criando coluna
int imprimirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            cout << tabuleiro[j][i];
            if (j < TAMANHO - 1) {
                cout << " |";
                // coluna
            }
        }
        cout << endl;
        if (i < TAMANHO - 1) {
            printf("---------\n");
            // linha
        }
    }
    return 0;
}

bool verificarFimDeJogo(char tabuleiro[TAMANHO][TAMANHO]) {
    // Verificar linhas e colunas
    for (int i = 0; i < TAMANHO; i++) {
        if ((tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') ||
            (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')) {
            cout << endl;
            cout << "Jogador " << ((tabuleiro[i][1] == 'X') ? 1 : 2) << " venceu!\n";
            return true;  // Há um vencedor
        }
    }
    
      
   // Verificar diagonais
         if ((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') ||
         (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')) {
         cout << "Jogador " << ((tabuleiro[1][1] == 'X') ? 1 : 2) << " venceu!\n";
         return true;  // Há um vencedor 
}

    // Verificar empate
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ') {
                return false;  
            }
        }
    }

    cout << "Jogo empatado!\n";
    return true;  // em empate
}

int jogadasAlternadas() {
    int jogadorAtual = 1;
    char tabuleiro[TAMANHO][TAMANHO];
    iniciarOtabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);
    bool jogoAcabou = false;

    while (!jogoAcabou) {
        int linha, coluna;
        printf("\nJogador %d, indique o lugar (linha coluna): \n", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = (jogadorAtual == 1) ? 'X' : 'O';
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
            imprimirTabuleiro(tabuleiro);
            //lógica para verificar se o jogo acabou
            jogoAcabou = verificarFimDeJogo(tabuleiro);
        } else {
            printf("Coordenadas invalidas ou posicao ocupada. Tente novamente.\n");
        }
    }

    return 0;
}
int dados() {
    cout << "\nJOGADOR 1 voce sera o --> X";
    cout << "\nJOGADOR 2 voce sera o --> O";
    cout << endl;
    return 0;
}
int regras(){
    printf("Vamos ver algumas regras da posicao:\n");
    printf("1- Voce ira usar dois numeros, inserindo um por vez.\n");
    printf("2- Esses numeros correspondem a linha e coluna, veja o diagrama a baixo: \n");
    printf("00| 10 |20 \n");
    printf("-----------\n");
    printf("01| 11 |21 \n");
    printf("-----------\n");
    printf("02| 12 |22 \n");
    return 0 ;
}
int main() {
    cout << "XOXOXOXOXO--JOGO DA VELHA--OXOXOXOXOX\n";
    char tabuleiro[TAMANHO][TAMANHO];
    iniciarOtabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);
    dados();
    regras();
    cout << endl;
    printf("BORA JOGAR!\n");
    jogadasAlternadas();

    return 0;
}