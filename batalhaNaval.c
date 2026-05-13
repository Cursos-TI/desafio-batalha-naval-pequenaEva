#include <stdio.h>

int main() {

    // tabuleiro 10x10 zerado
    int tabuleiro[10][10] = {0};

    // navios com tamanho 3
    int tamanhoH = 3;
    int navioH[tamanhoH];

    int tamanhoV = 3;
    int navioV[tamanhoV];

    // coordenadas iniciais
    int linhaH = 2;
    int colunaH = 7;
    int linhaV = 3;
    int colunaV = 4;

    // preenchendo os navios com valor 3
    for (int i = 0; i < tamanhoH; i++) {
        navioH[i] = 3;
    }

    for (int i = 0; i < tamanhoV; i++) {
        navioV[i] = 3;
    }

    // validando e posicionando navioH
    if (colunaH + tamanhoH > 10) {
        printf("NavioH fora dos limites do tabuleiro!\n");
    } else {
    // percorre cada posição do navio    
        for (int i = 0; i < tamanhoH; i++) {
            // copia o valor 3 do vetor navioH para a matriz
            // linhaH é fixa pois o navio é horizontal
            // colunaH + i avança a coluna a cada volta: colunaH+0, colunaH+1, colunaH+2
            tabuleiro[linhaH][colunaH + i] = navioH[i];
        }
    }

    // validando e posicionando navioV
    if (linhaV + tamanhoV > 10) {
        printf("NavioV fora dos limites do tabuleiro!\n");
    } else {
    // percorre cada posição do navio
        for (int i = 0; i < tamanhoV; i++) {
            // copia o valor 3 do vetor navioV para a matriz
            // linhaV + i avança a linha a cada volta do loop: linhaV+0, linhaV+1...
            // colunaV é fixa pois o navio é vertical.
            tabuleiro[linhaV + i][colunaV] = navioV[i];
        }
    }

    // exibe o título do jogo
    printf("\n");
    printf("\n");
    printf("      TABULEIRO BATALHA NAVAL\n"); 
    printf("\n");

    // acrescentar espaço para que fique alinhado às letras das colunas
    printf("    "); 
    // Exibir o índice de cada coluna usando letras do alfabeto
    // letra A é representada pelo número 65 na tabela ASCII, por isso i inicia em 65
    for ( int i = 65; i <= 74; i++) 
    {
        printf(" %c ", i);
       
    }
    
    // Pular linha após exibir os índices das colunas
    printf("\n");


    // Exibindo o tabuleiro
    for (int i = 0; i < 10; i++)
    {   
        // A cada iteração é impresso o valor de i para numerar as linhas do tabuleiro
        printf(" %d  ", i );
        for (int j = 0; j < 10; j++)
        {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}