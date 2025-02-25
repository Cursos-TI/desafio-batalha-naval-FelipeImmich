#include <stdio.h>
#include <stdbool.h> // Para usar o tipo 'bool'

// Função para verificar se as coordenadas estão dentro dos limites do tabuleiro
int coordenadaValida(int x, int y) {
    return (x >= 0 && x < 10 && y >= 0 && y < 10);
}

// Função para verificar se há sobreposição de navios
int semSobreposicao(int tabuleiro[10][10], int x, int y) {
    return (tabuleiro[x][y] == 0); // Retorna true se a posição estiver livre (água)
}

void exibaTabuleiro(int tabuleiro[10][10]){
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios

    // Definindo as coordenadas dos navios
    int navio1[3][2] = {
        {2, 3},
        {2, 4},
        {2, 5}
    };

    int navio2[3][2] = {
        {5, 8},
        {6, 8},
        {7, 8}
    };

    // Inicializando o tabuleiro com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionando o navio1 no tabuleiro
    int navio1Valido = 1;
    for (int i = 0; i < 3; i++) {
        int x = navio1[i][0];
        int y = navio1[i][1];
        
        // Verifica se a coordenada é válida e se não há sobreposição
        if (!coordenadaValida(x, y) || !semSobreposicao(tabuleiro, x, y)) {
            navio1Valido = 0;
            break;
        }
    }

    if (navio1Valido) {
        for (int i = 0; i < 3; i++) {
            int x = navio1[i][0];
            int y = navio1[i][1];
            tabuleiro[x][y] = 3; // Marcando como navio
        }
        printf("Navio 1 posicionado com sucesso!\n");
    } else {
        printf("Erro: Navio 1 possui coordenadas inválidas ou sobreposição.\n");
    }

    // Posicionando o navio2 no tabuleiro
    int navio2Valido = 1;
    for (int i = 0; i < 3; i++) {
        int x = navio2[i][0];
        int y = navio2[i][1];

        // Verifica se a coordenada é válida e se não há sobreposição
        if (!coordenadaValida(x, y) || !semSobreposicao(tabuleiro, x, y)) {
            navio2Valido = 0;
            break;
        }
    }

    if (navio2Valido) {
        for (int i = 0; i < 3; i++) {
            int x = navio2[i][0];
            int y = navio2[i][1];
            tabuleiro[x][y] = 3; // Marcando como navio
        }
        printf("Navio 2 posicionado com sucesso!\n");
    } else {
        printf("Erro: Navio 2 possui coordenadas inválidas ou sobreposição.\n");
    }

    // Exibindo o tabuleiro
    exibaTabuleiro(tabuleiro);

    return 0;
}
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
