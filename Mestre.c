#include <stdio.h>      // Biblioteca padrão para entrada e saída de dados
#include <stdlib.h>     // Biblioteca para funções como rand() e srand()
#include <string.h>     // Biblioteca para manipular strings
#include <time.h>       // Biblioteca para trabalhar com o tempo (usada no sorteio aleatório)

#define TAM 8           // Definimos o tamanho do tabuleiro (8x8)

int pontosJogador1 = 0; // Variável para contar os pontos do Jogador 1
int pontosJogador2 = 0; // Variável para contar os pontos do Jogador 2

// Função para imprimir o tabuleiro na tela
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n    A B C D E F G H\n");
    printf("   -----------------\n");
    for (int i = 0; i < TAM; i++) {
        printf(" %d |", i + 1);  // Mostra o número da linha
        for (int j = 0; j < TAM; j++) {
            printf(" %c", tabuleiro[i][j]);  // Mostra o conteúdo de cada casa
        }
        printf("\n");
    }
    printf("\n");
}

// Função recursiva que simula os movimentos da Torre
void moverTorreRecursiva(int passos, int direcao) {
    if (passos == 0) return; // Caso base: quando não há mais passos, para a recursão
    // Mostra a direção escolhida
    if (direcao == 0) printf("Cima\n");
    else if (direcao == 1) printf("Baixo\n");
    else if (direcao == 2) printf("Esquerda\n");
    else printf("Direita\n");
    // Chama a função novamente diminuindo os passos
    moverTorreRecursiva(passos - 1, direcao);
}

// Função recursiva que usa a Torre para simular os movimentos da Rainha
void moverRainhaRecursiva(int passos, int direcao) {
    if (passos == 0) return;
    printf("Movimento da Rainha: ");
    moverTorreRecursiva(1, direcao); // Rainha anda como a Torre
    moverRainhaRecursiva(passos - 1, direcao);
}

// Função recursiva para simular o movimento do Bispo
void moverBispoRecursivo(int linha, int coluna, int passos) {
    if (passos == 0) return;
    for (int i = 0; i < passos; i++) {
        for (int j = 0; j < passos; j++) {
            printf("Diagonal Direita-Baixo\n"); // Movimento do Bispo
        }
    }
    moverBispoRecursivo(linha + 1, coluna + 1, passos - 1); // Move para frente
}

// Função que simula o movimento do Cavalo
void moverCavalo() {
    for (int i = 0; i < 3; i++) {
        if (i < 2) printf("Cima\n");  // Primeiro sobe 2 casas
        else {
            for (int j = 0; j < 2; j++) {
                if (j == 1) {
                    printf("Direita\n"); // Depois anda 1 casa para a direita
                    break;
                }
            }
        }
    }
}

// Função que cuida da escolha da peça e movimentação de cada jogador
void escolherJogada(int jogador, char nome[], char tabuleiro[TAM][TAM]) {
    int escolha, direcao;
    char peca = '.';

    // Se o jogador for o computador, ele escolhe aleatoriamente
    if (strcmp(nome, "COMPUTADOR") == 0) {
        escolha = rand() % 4 + 1;
        direcao = rand() % 4;
        printf("%s escolheu a opção %d.\n", nome, escolha);
    } else {
        // Senão, o jogador escolhe sua peça
        printf("%s, escolha sua peça:\n", nome);
        printf("1. Torre\n2. Rainha\n3. Bispo\n4. Cavalo\nOpção: ");
        scanf("%d", &escolha);
    }

    // Executa o movimento conforme a escolha do jogador
    switch (escolha) {
        case 1:
            peca = 'T';
            if (strcmp(nome, "COMPUTADOR") != 0) {
                printf("Direções: 0 - Cima | 1 - Baixo | 2 - Esquerda | 3 - Direita\n");
                printf("Escolha a direção: ");
                scanf("%d", &direcao);
            }
            moverTorreRecursiva(3, direcao);
            if (jogador == 1) pontosJogador1 += 10;
            else pontosJogador2 += 10;
            break;
        case 2:
            peca = 'R';
            if (strcmp(nome, "COMPUTADOR") != 0) {
                printf("Direções: 0 - Cima | 1 - Baixo | 2 - Esquerda | 3 - Direita\n");
                printf("Escolha a direção: ");
                scanf("%d", &direcao);
            }
            moverRainhaRecursiva(3, direcao);
            if (jogador == 1) pontosJogador1 += 20;
            else pontosJogador2 += 20;
            break;
        case 3:
            peca = 'B';
            moverBispoRecursivo(0, 0, 3);
            if (jogador == 1) pontosJogador1 += 15;
            else pontosJogador2 += 15;
            break;
        case 4:
            peca = 'C';
            moverCavalo();
            if (jogador == 1) pontosJogador1 += 15;
            else pontosJogador2 += 15;
            break;
        default:
            printf("Opção inválida! Perde a vez.\n");
            return;
    }

    // Coloca a peça no tabuleiro (posição fictícia para visualização)
    if (jogador == 1) tabuleiro[0][jogador + escolha] = peca;
    else tabuleiro[7][jogador + escolha] = peca;
}

int main() {
    char tabuleiro[TAM][TAM];  // Matriz que representa o tabuleiro
    char nome1[50], nome2[50]; // Nomes dos jogadores
    int modo;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Introdução do jogo estilo "Super Trunfo"
    printf("===================================\n");
    printf("                XADREZ             \n");
    printf("===================================\n\n");
    printf("Bem-vinda(o) à arena da mente!\n");
    printf("Aqui você escolherá entre jogar contra um(a) amigo(a) ou desafiar o computador.\n\n");
    printf("Escolha o modo de jogo:\n");
    printf("1. Jogador vs Jogador\n");
    printf("2. Jogador vs Computador\n");
    printf("Opção: ");
    scanf("%d", &modo);
    getchar(); // Limpa o ENTER do teclado

    // Entrada dos nomes
    printf("\nDigite o nome do Jogador 1: ");
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = 0; // Remove o ENTER do final do nome

    if (modo == 1) {
        printf("Digite o nome do Jogador 2: ");
        fgets(nome2, sizeof(nome2), stdin);
        nome2[strcspn(nome2, "\n")] = 0;
    } else {
        strcpy(nome2, "COMPUTADOR");
    }

    // Mostra os competidores
    printf("\n%s vs %s\n", nome1, nome2);
    printf("Que comecem os duelos!\n");

    // Inicializa o tabuleiro com pontos vazios ('.')
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    // Jogo com 3 rodadas
    int rodada = 1;
    while (rodada <= 3) {
        printf("\n=== Rodada %d ===\n", rodada);

        // Vez do jogador 1
        printf("\n%s, É a sua vez:\n", nome1);
        escolherJogada(1, nome1, tabuleiro);

        // Vez do jogador 2 ou computador
        printf("\n%s,   É a sua vez:\n", nome2);
        escolherJogada(2, nome2, tabuleiro);

        // Mostra o tabuleiro atualizado
        imprimirTabuleiro(tabuleiro);
        rodada++;
    }

    // Mostra os pontos finais
    printf("\n=== Pontuação Final ===\n");
    printf("%s: %d pontos\n", nome1, pontosJogador1);
    printf("%s: %d pontos\n", nome2, pontosJogador2);

    // Verifica quem venceu
    if (pontosJogador1 > pontosJogador2)
        printf("Parabéns, %s! Você venceu!\n", nome1);
    else if (pontosJogador2 > pontosJogador1)
        printf("Parabéns, %s! Você venceu!\n", nome2);
    else
        printf("Empate! Ambos foram brilhantes!\n");

    return 0;
}
