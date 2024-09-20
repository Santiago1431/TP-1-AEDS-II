#include <stdio.h>
#include "funcs.h"

void exibir_menu() {
    printf("Escolha um labirinto:\n");
    printf("1. Labirinto 1\n");
    printf("2. Labirinto 2\n");
    printf("3. Labirinto 3\n");
    printf("4. Labirinto 4\n");
    printf("5. Labirinto 5\n");
    printf("0. Sair\n");
}

const char* obter_nome_labirinto(int opcao) {
    switch (opcao) {
        case 1: return "labirinto1.txt";
        case 2: return "labirinto2.txt";
        case 3: return "labirinto3.txt";
        case 4: return "labirinto4.txt";
        case 5: return "labirinto5.txt";
        default: return NULL;
    }
}

int main() {
    char lab[10][10];
    int opcao;


    do {
        exibir_menu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 5) {
            const char* nome_labirinto = obter_nome_labirinto(opcao);
            completa_lab(lab, nome_labirinto);

            printf("Labirinto:\n");
            exibirlab(lab);

            int linha_e, coluna_e, linha_s, coluna_s;
            identifica(&linha_e, &coluna_e, &linha_s, &coluna_s, lab);

            printf("Entrada encontrada em: (%d, %d)\n", linha_e, coluna_e);
            printf("Saída encontrada em: (%d, %d)\n", linha_s, coluna_s);

            if (buscasaida(lab, linha_e, coluna_e, linha_s, coluna_s)) {
                printf("Saída encontrada!\n");
            } else {
                printf("Saída não encontrada.\n");
            }
        } else if (opcao != 0) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
