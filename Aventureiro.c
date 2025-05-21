#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char Nome1[60];
    int Idade1, Nascimento1;
    char Tutorial[20];

    // Quantidade de casas para movimentação
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;
    const int casasCavaloBaixo = 2;
    const int casasCavaloEsquerda = 1;

    printf("\n    ===== XADREZ - NÍVEL NOVATO =====\n");

    printf("Olá novo jogador. Qual é o seu nome? ");
    if (scanf(" %[^\n]", Nome1) != 1) return 1;

    printf("Nome bonito o seu! Qual é a sua idade? ");
    if (scanf("%d", &Idade1) != 1) return 1;

    printf("Quando você nasceu? (Digite apenas o ano, ex: 2013) ");
    if (scanf("%d", &Nascimento1) != 1) return 1;

    while (getchar() != '\n'); // Limpa o buffer do teclado

    printf("Deseja receber o tutorial? (Sim ou Não) ");
    if (scanf(" %[^\n]", Tutorial) != 1) return 1;

    if (strcmp(Tutorial, "Sim") == 0) {
        printf("\n===== TUTORIAL =====\n");
        printf("Neste programa, vamos simular os movimentos de quatro peças de xadrez: Torre, Bispo, Rainha e Cavalo.\n");
        printf("Cada peça se move de forma diferente, e vamos representar isso usando estruturas de repetição.\n");
        printf("- A Torre se move em linha reta na horizontal ou vertical. Vamos simular %d casas para a Direita.\n", casasTorre);
        printf("- O Bispo se move na diagonal. Vamos simular %d casas na Diagonal para Cima e Direita.\n", casasBispo);
        printf("- A Rainha se move em todas as direções. Vamos simular %d casas para a Esquerda.\n", casasRainha);
        printf("- O Cavalo se move em L. Vamos simular 2 casas para Baixo e 1 para a Esquerda.\n");
    } else {
        printf("Ok! Vamos prosseguir então.\n\n");
    }

    if (Idade1 >= 18)
        printf("\nBem-vindo(a), %s! Prepare-se para usar sua lógica e estratégia.\n\n", Nome1);
    else
        printf("\nOi %s! Vamos nos divertir aprendendo juntos com o xadrez!\n\n", Nome1);

    // Exibição do tabuleiro 8x8
    printf("===== TABULEIRO DE XADREZ (8x8) =====\n");
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            printf("[%d,%d] ", linha, coluna);
        }
        printf("\n");
    }

    const char *Pecas[] = {"Torre", "Bispo", "Rainha", "Cavalo"};
    int escolha;

    printf("\nAs Peças disponíveis são:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d - %s\n", i + 1, Pecas[i]);
    }

    printf("\n%s, escolha sua peça (1 a 4): ", Nome1);
    if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > 4) {
        printf("Escolha inválida.\n");
        return 1;
    }

    escolha--; // Ajusta para índice do vetor
    printf("\n=====  %s =====\n", Pecas[escolha]);

    switch (escolha) {
        case 0: // Torre
            printf("Movimento: para a Direita \n");
            for (int i = 1; i <= casasTorre; i++) {
                printf("Casa %d à Direita\n", i);
            }
            break;

        case 1: // Bispo
            printf("Movimento: Diagonal para Cima e Direita \n");
            {
                int j = 1;
                while (j <= casasBispo) {
                    printf("Diagonal %d para Cima e Direita\n", j);
                    j++;
                }
            }
            break;

        case 2: // Rainha
            printf("Movimento: para a Esquerda \n");
            {
                int k = 1;
                do {
                    printf("Casa %d à Esquerda\n", k);
                    k++;
                } while (k <= casasRainha);
            }
            break;

        case 3: // Cavalo
            printf("Movimento: Duas casas para Baixo e uma para Esquerda\n");
            for (int passo = 1; passo <= casasCavaloBaixo; passo++) {
                printf("Passo %d para Baixo\n", passo);
                if (passo == casasCavaloBaixo) {
                    int esquerda = 1;
                    while (esquerda <= casasCavaloEsquerda) {
                        printf("Passo %d para Esquerda\n", esquerda);
                        esquerda++;
                    }
                }
            }
            break;
    }

    printf("\nObrigada por jogar! Em breve, novas fases com desafios mais avançados!\n");
    return 0;
}
