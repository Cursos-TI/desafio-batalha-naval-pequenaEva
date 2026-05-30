#include <stdio.h>
#include <stdlib.h>

int main() {
    // -------------------------------------------------------
    // TABULEIRO
    // Matriz 10x10 representando o campo de batalha naval
    // Valor 0 = água (célula vazia)
    // Valor 3 = navio
    // Valor 5 = área afetada por habilidade especial
    // -------------------------------------------------------
    int tabuleiro[10][10] = {0};

    // -------------------------------------------------------
    // MATRIZES DE HABILIDADE
    // Cada habilidade é uma matriz 3x5 separada
    // Valor 0 = área não afetada
    // Valor 1 = área afetada pela habilidade
    // -------------------------------------------------------
    int cone[3][5] = {0};
    int cruz[3][5] = {0};
    int octaedro[3][5] = {0};

    // -------------------------------------------------------
    // PONTOS DE ORIGEM DAS HABILIDADES
    // Define onde o centro de cada habilidade será
    // posicionado no tabuleiro principal
    // -------------------------------------------------------
    int origemLinhaCone = 6;
    int origemColunaCone = 7;

    int origemLinhaCruz = 3;
    int origemColunaCruz = 7;

    int origemLinhaOcta = 8;
    int origemColunaOcta = 7;

    // -------------------------------------------------------
    // NAVIOS
    // Cada navio é um vetor de tamanho 3
    // Todos os elementos valem 3, representando partes do navio
    // -------------------------------------------------------
    int tamanhoD1 = 3;
    int navioD1[tamanhoD1];
    
    int tamanhoD2 = 3;
    int navioD2[tamanhoD2];

    int tamanhoH = 3;
    int navioH[tamanhoH];

    int tamanhoV = 3;
    int navioV[tamanhoV];

    // -------------------------------------------------------
    // COORDENADAS INICIAIS DOS NAVIOS
    // Define a posição de início de cada navio no tabuleiro
    // -------------------------------------------------------
    int linhaH = 5, colunaH = 2; // horizontal: linha fixa, coluna avança
    int linhaV = 6, colunaV = 2; // vertical: coluna fixa, linha avança
    int linhaD1 = 1, colunaD1 = 1; // diagonal principal: linha e coluna avançam juntas
    int linhaD2 = 0, colunaD2 = 9; // diagonal secundária: linha avança, coluna recua


    // -------------------------------------------------------
    // PREENCHENDO OS VETORES DOS NAVIOS COM VALOR 3
    // O for percorre cada índice do vetor e atribui o valor 3
    // que representa uma parte do navio no tabuleiro
    // -------------------------------------------------------
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

    // -------------------------------------------------------
    // VALIDANDO E POSICIONANDO NAVIO HORIZONTAL
    // Valida se o navio cabe no tabuleiro verificando se
    // a coluna inicial + tamanho não ultrapassa o limite 10
    // Verifica sobreposição checando se as células estão livres (valor 0)
    // Posiciona copiando o valor 3 para cada célula da linha,
    // avançando a coluna com colunaH + i
    // -------------------------------------------------------
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

    // -------------------------------------------------------
    // VALIDANDO E POSICIONANDO NAVIO VERTICAL
    // Valida se a linha inicial + tamanho não ultrapassa 10
    // Verifica sobreposição nas células que o navio vai ocupar
    // Posiciona avançando a linha com linhaV + i
    // colunaV é fixa — navio vertical não muda de coluna
    // -------------------------------------------------------
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

    // -------------------------------------------------------
    // VALIDANDO E POSICIONANDO NAVIO DIAGONAL PRINCIPAL
    // Valida se linha + tamanho e coluna + tamanho não ultrapassam 10
    // Na diagonal principal linha e coluna avançam juntas com + i
    // -------------------------------------------------------
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

    // -------------------------------------------------------
    // VALIDANDO E POSICIONANDO NAVIO DIAGONAL SECUNDÁRIA
    // Valida se linha + tamanho não ultrapassa 10
    // Valida se coluna - (tamanho - 1) não fica negativo
    // tamanho - 1 representa o último índice acessado pelo loop
    // Na diagonal secundária linha avança com + i e coluna recua com - i
    // -------------------------------------------------------
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

    // -------------------------------------------------------
    // CONSTRUINDO O CONE
    // Forma geométrica que expande de cima para baixo
    // A cada linha (i), a área afetada cresce 1 célula para cada lado
    //
    // Centro da coluna = 2 (coluna do meio de 5 colunas: 0,1,2,3,4)
    // Limite esquerdo  = 2 - i (recua com i)
    // Limite direito   = 2 + i (avança com i)
    //
    // linha 0 (i=0): 2-0=2 até 2+0=2 → só o centro     → 0 0 1 0 0
    // linha 1 (i=1): 2-1=1 até 2+1=3 → expande 1 lado  → 0 1 1 1 0
    // linha 2 (i=2): 2-2=0 até 2+2=4 → expande 2 lados → 1 1 1 1 1
    // -------------------------------------------------------
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(j >= 2 - i && j <= 2 + i){
                cone[i][j] = 1;
            }

        }
    }

    // -------------------------------------------------------
    // CONSTRUINDO A CRUZ
    // Forma geométrica com linha e coluna centrais preenchidas
    //
    // Centro da linha  = 1 (linha do meio de 3 linhas: 0,1,2)
    // Centro da coluna = 2 (coluna do meio de 5 colunas: 0,1,2,3,4)
    //
    // i == 1 → preenche toda a linha do meio
    // j == 2 → preenche toda a coluna do meio
    // || garante que qualquer uma das condições marca a célula
    //
    // Resultado:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    // -------------------------------------------------------
    for(int i =0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(i == 1 || j == 2){
                cruz[i][j] = 1;
            }
        }
    }

    // -------------------------------------------------------
    // CONSTRUINDO O OCTAEDRO
    // Forma geométrica em losango — expande até o centro e contrai
    //
    // Centro da linha  = 1 (linha do meio de 3 linhas)
    // Centro da coluna = 2 (coluna do meio de 5 colunas)
    // Expansão máxima  = 1 (máximo de células para cada lado do centro)
    //
    // CÁLCULO DA EXPANSÃO:
    // abs(i - 1) = distância de cada linha até o centro (linha 1)
    //   linha 0: abs(0-1) = 1 → longe do centro
    //   linha 1: abs(1-1) = 0 → é o centro
    //   linha 2: abs(2-1) = 1 → longe do centro
    //
    // expansao = 1 - abs(i - 1)
    //   linha 0: 1 - 1 = 0 → não expande
    //   linha 1: 1 - 0 = 1 → expande 1 para cada lado
    //   linha 2: 1 - 1 = 0 → não expande
    //
    // Limite esquerdo = 2 - expansao
    // Limite direito  = 2 + expansao
    //
    // linha 0: 2-0=2 até 2+0=2 → só o centro     → 0 0 1 0 0
    // linha 1: 2-1=1 até 2+1=3 → expande 1 lado  → 0 1 1 1 0
    // linha 2: 2-0=2 até 2+0=2 → só o centro     → 0 0 1 0 0
    // -------------------------------------------------------
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            int expansao = 1 - abs(i - 1);
            if(j >= 2 - expansao && j <= 2 + expansao){
                octaedro[i][j] = 1;
            }
        }
    }   
    //-------------------------------------------------------
    // SOBREPONDO AS HABILIDADES AO TABULEIRO
    //
    // PROBLEMA: a habilidade tem coordenadas próprias [0..2][0..4]
    // mas o tabuleiro tem coordenadas [0..9][0..9]
    // Precisamos TRADUZIR as coordenadas da habilidade para o tabuleiro
    //
    // FÓRMULA:
    // linhaT  = origemLinha  + i - centroLinhaHabilidade
    // colunaT = origemColuna + j - centroColunaHabilidade
    //
    // centroLinhaHabilidade  = 1 (linha do meio de 3 linhas)
    // centroColunaHabilidade = 2 (coluna do meio de 5 colunas)
    //
    // POR QUE SUBTRAÍMOS O CENTRO?
    // Para que o centro da habilidade coincida com o ponto de origem.
    // Quando i=1 (centro da habilidade):
    //   linhaT = origemLinha + 1 - 1 = origemLinha -> centro na origem
    // Quando i=0 (acima do centro):
    //   linhaT = origemLinha + 0 - 1 = origemLinha - 1 -> uma linha acima
    // Quando i=2 (abaixo do centro):
    //   linhaT = origemLinha + 2 - 1 = origemLinha + 1 -> uma linha abaixo
    //
    // Só marcamos células onde a habilidade vale 1 — as que valem 0 não afetam o tabuleiro
    // -------------------------------------------------------

    // Sobrepor o cone ao tabuleiro
    int foraLimiteCone = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            int linhaT = origemLinhaCone + i - 1;
            int colunaT = origemColunaCone + j - 2;
            if (cone[i][j] == 1 && linhaT >= 0 && linhaT < 10 && colunaT >= 0 && colunaT < 10){ // só marca se a célula da habilidade é 1
                tabuleiro[linhaT][colunaT] = 5;
            } else if (cone[i][j] == 1) {
             foraLimiteCone = 1; // célula da habilidade ficou fora do tabuleiro
            }
        }
    }
    if (foraLimiteCone == 1) {
        printf("\n----------------------------------\n");
        printf("Cone: parte da habilidade fora dos limites!\n");
        printf("----------------------------------\n");
    }

    // Sobrepor a cruz ao tabuleiro
    int foraLimiteCruz = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            int linhaT = origemLinhaCruz + i - 1;
            int colunaT = origemColunaCruz + j - 2;
            if (cruz[i][j] == 1 && linhaT >= 0 && linhaT < 10 && colunaT >= 0 && colunaT < 10){
                tabuleiro[linhaT][colunaT] = 5;
            } else if (cruz[i][j] == 1) {
              foraLimiteCruz = 1; // célula da habilidade ficou fora do tabuleiro
            }
        }
    }

    if (foraLimiteCruz == 1) {
        printf("\n----------------------------------\n");
        printf("Cruz: parte da habilidade fora dos limites!\n");
        printf("----------------------------------\n");
    }

    // Sobrepor o octaedro ao tabuleiro
    int foraLimiteOctaedro = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            int linhaT = origemLinhaOcta + i - 1;
            int colunaT = origemColunaOcta + j - 2;
            if (octaedro[i][j] == 1 && linhaT >= 0 && linhaT < 10 && colunaT >= 0 && colunaT < 10){
                tabuleiro[linhaT][colunaT] = 5;
            } else if (octaedro[i][j] == 1) {
             foraLimiteOctaedro = 1; // célula da habilidade ficou fora do tabuleiro
            }
        }
    } 

    if (foraLimiteOctaedro == 1) {
        printf("\n----------------------------------\n");
        printf("Octaedro: parte da habilidade fora dos limites!\n");
        printf("----------------------------------\n");
    }

    // -------------------------------------------------------
    // EXIBINDO AS HABILIDADES SEPARADAMENTE
    // Mostra cada forma geométrica antes do tabuleiro
    // para facilitar a visualização e verificação
    // -------------------------------------------------------
    printf("\n");
    printf("Cruz\n"); 
     for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 5; j++)
        {
            printf(" %d ", cruz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Cone\n");
    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 5; j++)
        {
            printf(" %d ", cone[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Octaedro\n"); 
    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 5; j++)
        {
            printf(" %d ", octaedro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // -------------------------------------------------------
    // EXIBINDO O TABULEIRO PRINCIPAL
    // Mostra a matriz 10x10 com todos os elementos:
    // 0 = água, 3 = navio, 5 = área afetada por habilidade
    // Colunas identificadas por letras A-J
    // Linhas identificadas por números 0-9
    // -------------------------------------------------------

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