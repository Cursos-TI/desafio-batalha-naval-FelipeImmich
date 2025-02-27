#include <stdio.h>
#define TAMANHO 10
#define TAMANHO_HAB 5

//Define o tabuleiro (global)
int tabuleiro[TAMANHO][TAMANHO];

//Funcao para imprimir o tabuleiro
void exibaTabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("% 2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se as coordenadas estão dentro dos limites do tabuleiro
int coordenadaValida(int x, int y)
{
    return (x >= 0 && x < 10 && y >= 0 && y < 10);
}

// Função para verificar se há sobreposição de navios
int semSobreposicao(int tabuleiro[TAMANHO][TAMANHO], int x, int y)
{
    return (tabuleiro[x][y] == 0); // Retorna true se a posição estiver livre (água)
}

void posicionarNavio(int navio[3][2])
{
    // Posicionando o navio1 no tabuleiro
    int navio1Valido = 1;
    for (int i = 0; i < 3; i++)
    {
        int x = navio[i][0];
        int y = navio[i][1];

        // Verifica se a coordenada é válida e se não há sobreposição
        if (!coordenadaValida(x, y) || !semSobreposicao(tabuleiro, x, y))
        {
            navio1Valido = 0;
            break;
        }
    }

    if (navio1Valido)
    {
        for (int i = 0; i < 3; i++)
        {
            int x = navio[i][0];
            int y = navio[i][1];
            tabuleiro[x][y] = 3; // Marcando como navio
        }
        printf("Navio posicionado com sucesso!\n");
    }
    else
    {
        printf("Erro: Navio possui coordenadas inválidas ou sobreposição.\n");
    }
}

// Função para sobrepor uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAMANHO_HAB][TAMANHO_HAB], int x, int y, int tipo) {
    for (int i = 0; i < TAMANHO_HAB; i++) {
        for (int j = 0; j < TAMANHO_HAB; j++) {
            int posX = x + i - TAMANHO_HAB / 2;
            int posY = y + j - TAMANHO_HAB / 2;
            if (posX >= 0 && posX < TAMANHO && posY >= 0 && posY < TAMANHO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[posX][posY] = tipo; // Usar o tipo para poder representar de forma diferente a area atingida
                }
            }
        }
    }
}

//Matrizes das habilidades
int cone[TAMANHO_HAB][TAMANHO_HAB] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int cruz[TAMANHO_HAB][TAMANHO_HAB] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

int octaedro[TAMANHO_HAB][TAMANHO_HAB] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

int main()
{
    //Iniciando o tabuleiro zerado
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    //Iniciando as coordenadas dos navios
    int navio1[3][2] = {
        {2, 3},
        {2, 4},
        {2, 5}};

    int navio2[3][2] = {
        {5, 8},
        {6, 8},
        {7, 8}};

    int navio3[3][2] = {
        {9, 0},
        {8, 1},
        {7, 2}};

    int navio4[3][2] = {
        {0, 0},
        {1, 1},
        {2, 2}};

        //Posicina os navios, verificando se a posicao é permitida
    posicionarNavio(navio1);
    posicionarNavio(navio2);
    posicionarNavio(navio3);
    posicionarNavio(navio4);

    // Exibindo o tabuleiro
    exibaTabuleiro(tabuleiro);


    // Aplica as habilidades no tabuleiro
    // Habilidade cone
    aplicarHabilidade(tabuleiro, cone, 2, 2, 4);      
    exibaTabuleiro(tabuleiro);
    // Habilidade cruz
    aplicarHabilidade(tabuleiro, cruz, 4, 4, 5);      
    exibaTabuleiro(tabuleiro);
    // Habilidade octaedro
    aplicarHabilidade(tabuleiro, octaedro, 6, 6, 6);  
    exibaTabuleiro(tabuleiro);

    return 0;
}