#include <stdio.h>

// Não inclui <stdlib.h> para tornar a solução do octaedro mais manual, sem a função abs().

int main() {
    
    // =========================================================================
    // NÍVEL NOVATO
    // =========================================================================
    printf("======================================\n");
    printf(" NIVEL NOVATO\n");
    printf("======================================\n\n");

    // Variáveis para os navios, inseridas manualmente no código.
    int navio_horizontal_x = 1;
    int navio_horizontal_y = 2;
    int navio_horizontal_tamanho = 3;

    int navio_vertical_x = 4;
    int navio_vertical_y = 0;
    int navio_vertical_tamanho = 4;

    printf("Posicionando navios...\n\n");

    // Imprime as coordenadas do navio horizontal usando printf
    printf("Coordenadas do Navio Horizontal (Tamanho %d):\n", navio_horizontal_tamanho);
    for (int i = 0; i < navio_horizontal_tamanho; i++) {
        printf("(%d, %d) ", navio_horizontal_x + i, navio_horizontal_y);
    }
    printf("\n\n");

    // Imprime as coordenadas do navio vertical
    printf("Coordenadas do Navio Vertical (Tamanho %d):\n", navio_vertical_tamanho);
    for (int i = 0; i < navio_vertical_tamanho; i++) {
        printf("(%d, %d) ", navio_vertical_x, navio_vertical_y + i);
    }
    printf("\n\n");


    // =========================================================================
    // NÍVEL AVENTUREIRO
    // =========================================================================
    printf("\n======================================\n");
    printf(" NIVEL AVENTUREIRO\n");
    printf("======================================\n\n");
    
    // Tabuleiro 10x10
    int tabuleiro[10][10];
    int i, j; // Variáveis de loop

    // Limpando o tabuleiro (preenchendo com 0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Posicionando 4 navios (horizontal, vertical, e dois diagonais)
    // Os valores são inseridos manualmente no código.
    
    // Navio 1: Horizontal (tamanho 4)
    int nav1_x = 1, nav1_y = 1, nav1_tam = 4;
    for(i = 0; i < nav1_tam; i++) {
        tabuleiro[nav1_y][nav1_x + i] = 3;
    }

    // Navio 2: Vertical (tamanho 5)
    int nav2_x = 8, nav2_y = 3, nav2_tam = 5;
    for(i = 0; i < nav2_tam; i++) {
        tabuleiro[nav2_y + i][nav2_x] = 3;
    }

    // Navio 3: Diagonal (tamanho 3)
    int nav3_x = 0, nav3_y = 5, nav3_tam = 3;
    for(i = 0; i < nav3_tam; i++) {
        tabuleiro[nav3_y + i][nav3_x + i] = 3;
    }
    
    // Navio 4: Diagonal Inversa (tamanho 4)
    int nav4_x = 4, nav4_y = 8, nav4_tam = 4;
     for(i = 0; i < nav4_tam; i++) {
        tabuleiro[nav4_y - i][nav4_x + i] = 3;
    }

    // Exibindo o tabuleiro completo
    printf("Exibindo o tabuleiro 10x10 completo (0 = Agua, 3 = Navio):\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Pula para a próxima linha
    }
    printf("\n");


    // =========================================================================
    // NÍVEL MESTRE
    // =========================================================================
    printf("\n======================================\n");
    printf(" NIVEL MESTRE\n");
    printf("======================================\n\n");

    int tabuleiro_habilidade[5][5];
    int centro = 2; // Centro de um tabuleiro 5x5 é a posição 2

    // --- HABILIDADE EM CONE ---
    printf("Habilidade em Cone (1 = Area atingida):\n\n");
    // Limpa o tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            tabuleiro_habilidade[i][j] = 0;
        }
    }
    
    // Desenha o padrão de cone usando loops aninhados
    for (i = 0; i <= centro; i++) {
        for (j = centro - i; j <= centro + i; j++) {
            tabuleiro_habilidade[i][j] = 1;
        }
    }

    // Imprime o tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", tabuleiro_habilidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // --- HABILIDADE EM CRUZ ---
    printf("Habilidade em Cruz (1 = Area atingida):\n\n");
    // Limpa o tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            tabuleiro_habilidade[i][j] = 0;
        }
    }

    // Desenha a linha horizontal
    for (j = 0; j < 5; j++) {
        tabuleiro_habilidade[centro][j] = 1;
    }
    // Desenha a linha vertical
    for (i = 0; i < 5; i++) {
        tabuleiro_habilidade[i][centro] = 1;
    }
    
    // Imprime o tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", tabuleiro_habilidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // --- HABILIDADE EM OCTAEDRO ---
    printf("Habilidade em Octaedro (1 = Area atingida):\n\n");
    // Limpa o tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            tabuleiro_habilidade[i][j] = 0;
        }
    }

    // Lógica mais "manual" para criar o diamante (octaedro)
    int largura_padrao;
    // Desenha a parte de cima, expandindo
    for (i = 0; i <= centro; i++) {
        largura_padrao = i;
        for (j = centro - largura_padrao; j <= centro + largura_padrao; j++) {
            tabuleiro_habilidade[i][j] = 1;
        }
    }
    // Desenha a parte de baixo, encolhendo
    for (i = centro + 1; i < 5; i++) {
        largura_padrao = (5 - 1) - i;
        for (j = centro - largura_padrao; j <= centro + largura_padrao; j++) {
            tabuleiro_habilidade[i][j] = 1;
        }
    }

    // Imprime o tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", tabuleiro_habilidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    printf("\n--- Desafio Concluido! ---\n");
    return 0;
}