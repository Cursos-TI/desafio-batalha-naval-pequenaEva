#include <stdio.h>

int main() {

    // tabuleiro 10x10 zerado
    int tabuleiro[10][10] = {0};

    // navios com tamanho 3
    int tamanhoD1 = 3;
    int navioD1[tamanhoD1];
    
    int tamanhoD2 = 3;
    int navioD2[tamanhoD2];

    int tamanhoH = 3;
    int navioH[tamanhoH];

    int tamanhoV = 3;
    int navioV[tamanhoV];

    // coordenadas iniciais
    int linhaH = 5;
    int colunaH = 2;
    int linhaV = 6;
    int colunaV = 2;
    int linhaD1 = 1;
    int colunaD1 = 1;
    int linhaD2 = 1;
    int colunaD2 = 8;

    // preenchendo os navios com valor 3
    for (int i = 0; i < tamanhoH; i++) {
        navioH[i] = 3;
    }

    for (int i = 0; i < tamanhoV; i++) {
        navioV[i] = 3;
    }

    for (int i = 0; i < tamanhoD1; i++)
    {
        navioD1[i] = 3;
    }
    
    for (int i = 0; i < tamanhoD2; i++)
    {
        navioD2[i] = 3;
    }


    // validando e posicionando navioH
    if (colunaH + tamanhoH > 10) {
        printf("NavioH fora dos limites do tabuleiro!\n");
    } else { 
        int sobreposicao = 0; // variavel para indicar sobreposição
        for (int i = 0; i < tamanhoH; i++) {
            if (tabuleiro [linhaH][colunaH + i] != 0){
                sobreposicao = 1; // marca que houve sobreposição
            }
        }
            if (sobreposicao == 0) {
                // percorre cada posição do navio 
                for(int i = 0; i < tamanhoH; i++){
                    // copia o valor 3 do vetor navioH para a matriz
                    // linhaH é fixa pois o navio é horizontal
                    // colunaH + i avança a coluna a cada volta: colunaH+0, colunaH+1, colunaH+2
                    tabuleiro[linhaH][colunaH + i] = navioH[i];

                }
            } else {
                printf("\n");
                printf("----------------------------------\n");
                printf("NavioH: sobreposição detectada!\n");
                printf("----------------------------------\n");
            }
    }

    // validando e posicionando navioV
    if (linhaV + tamanhoV > 10) {
        printf("NavioV fora dos limites do tabuleiro!\n");
    } else {
            // percorre cada posição do navio
            int sobreposicao = 0; // variavel para indicar sobreposição
            for (int i = 0; i < tamanhoV; i++) {

                if(tabuleiro[linhaV + i][colunaV] != 0){
                    sobreposicao = 1; // marca que houve sobreposição
                }
            
            }

            if (sobreposicao == 0){
                for(int i = 0; i < tamanhoV; i++){
                    // copia o valor 3 do vetor navioV para a matriz
                    // linhaV + i avança a linha a cada volta do loop: linhaV+0, linhaV+1...
                    // colunaV é fixa pois o navio é vertical.
                    tabuleiro[linhaV + i][colunaV] = navioV[i];
                }
            } else {
                printf("\n");
                printf("----------------------------------\n");
                printf("NavioV: sobreposição detectada!\n");
                printf("----------------------------------\n");
            }

        }

    


    // validando e posicionando navioD1
    if(linhaD1 + tamanhoD1 > 10 || colunaD1 + tamanhoD1 > 10){

        printf("NavioD1 fora dos limites do tabuleiro! \n");
    } else {
        // variavel para indicar sobreposição
        int sobreposicao = 0;
        // percorre cada posição do navio
        for (int i = 0; i < tamanhoD1; i++)
        {
         // Se os valores nos indices forem diferentes de 0, marca que houve sobreposição.
         if(tabuleiro[linhaD1 + i][colunaD1 + i] != 0){
            sobreposicao = 1;
         } 
           
        }

        if(sobreposicao == 0){
            for (int i = 0; i < tamanhoD1; i++){
                    // copia o valor 3 do vetor navioD1 para a matriz
                    // linhaD1 + i avança a linha a cada volta do loop
                    // colunaD1 também avança a coluna a cada volta do loop.
                tabuleiro[linhaD1 + i][colunaD1 + i] = navioD1[i];
            }
            
        }  else {
            printf("\n");
            printf("----------------------------------\n");
            printf("NavioD1: sobreposição detectada!\n");
            printf("----------------------------------\n");
        }
        
        
    }

    // validando e posicionando navioD2
    if (linhaD2 + tamanhoD2 > 10 || colunaD2 - (tamanhoD2 - 1) < 0) {

        printf("NavioD2 fora dos limites do tabuleiro! \n");
    } else {
        // variavel para indicar sobreposição
        int sobreposicao = 0;
        // percorre cada posição do navio
        for (int i = 0; i < tamanhoD2; i++)
        {  
            // Se os valores nos indices forem diferentes de 0, marca que houve sobreposição.
            if(tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
            sobreposicao = 1;
        }

        if(sobreposicao == 0){
            for(int i = 0; i < tamanhoD2; i++){
                    // copia o valor 3 do vetor navioD2 para a matriz
                    // linhaD2 + i avança a linha a cada volta do loop
                    // colunaD2 regride a coluna a cada volta do loop.
                tabuleiro[linhaD2 + i][colunaD2 - i] = navioD2[i];
            }
            
        } else {
            printf("\n");
            printf("----------------------------------\n");
            printf("NavioD2: sobreposição detectada!\n");
            printf("----------------------------------\n");
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