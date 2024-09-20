#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "pilha.h"


void completa_lab(char lab[10][10], const char *labirinto) {
    FILE *arq = fopen(labirinto, "rt");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    char c;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            c = fgetc(arq);
            lab[i][j] = c;
        }
        fgetc(arq); // Para pular o caractere de nova linha
    }
    fclose(arq);
}

void identifica(int *linha_e, int *coluna_e, int *linha_s, int *coluna_s, char lab[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (lab[i][j] == 'E') {
                *linha_e = i;
                *coluna_e = j;
            }
            if (lab[i][j] == 'S') {
                *linha_s = i;
                *coluna_s = j;
            }
        }
    }
}

void exibirlab(char lab[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c  ", lab[i][j]);
        }
        printf("\n");
    }
}

void exibesaida(Pilha *p_linhas, Pilha *p_colunas) {
    // Cria pilhas auxiliares para armazenar os elementos na ordem correta
    Pilha p_linhas_aux, p_colunas_aux;
    inicializa(&p_linhas_aux);
    inicializa(&p_colunas_aux);

    // Desempilha e armazena na pilha auxiliar
    while (!pilha_vazia(p_linhas) && !pilha_vazia(p_colunas)) {
        int linha = desempilha(p_linhas);
        int coluna = desempilha(p_colunas);
        empilha(&p_linhas_aux, linha);
        empilha(&p_colunas_aux, coluna);
    }

    // Exibe na ordem correta
    printf("Caminho percorrido (Linha, Coluna):\n");
    while (!pilha_vazia(&p_linhas_aux) && !pilha_vazia(&p_colunas_aux)) {
        int linha = desempilha(&p_linhas_aux);
        int coluna = desempilha(&p_colunas_aux);
        printf("(%d, %d)\n", linha, coluna);
    }
}


int buscasaida(char lab[10][10], int linha_e, int coluna_e, int linha_s, int coluna_s) {
    Pilha p_colunas, p_linhas;
    inicializa(&p_colunas);
    inicializa(&p_linhas);


    while (lab[linha_e][coluna_e] != 'S') {
        // Marca a posição atual como visitada
        if (lab[linha_e][coluna_e] != 'E')
        {
             lab[linha_e][coluna_e] = 'v'; 
        }
        

        // Tenta mover para a direita
        if (coluna_e + 1 < 10 && (lab[linha_e][coluna_e + 1] == '0' || lab[linha_e][coluna_e + 1] == 'S')) {
            empilha(&p_colunas, coluna_e);
            empilha(&p_linhas, linha_e);
            coluna_e++;
        } 
        // Tenta mover para baixo
        else if (linha_e + 1 < 10 && (lab[linha_e + 1][coluna_e] == '0' || lab[linha_e + 1][coluna_e] == 'S')) {
            empilha(&p_colunas, coluna_e);
            empilha(&p_linhas, linha_e);
            linha_e++;
        } 
        // Tenta mover para a esquerda
        else if (coluna_e - 1 >= 0 && (lab[linha_e][coluna_e - 1] == '0' || lab[linha_e][coluna_e - 1] == 'S')) {
            empilha(&p_colunas, coluna_e);
            empilha(&p_linhas, linha_e);
            coluna_e--;
        } 
        // Tenta mover para cima
        else if (linha_e - 1 >= 0 && (lab[linha_e - 1][coluna_e] == '0' || lab[linha_e - 1][coluna_e] == 'S')) {
            empilha(&p_colunas, coluna_e);
            empilha(&p_linhas, linha_e);
            linha_e--;
        } 
        // Se não há para onde ir, desempilha
        else {
            if (pilha_vazia(&p_colunas) && pilha_vazia(&p_linhas)) {
                return 0; // Não encontrou saída
            } else {
                lab[linha_e][coluna_e] = 'x'; // Marca como um caminho sem saída
                coluna_e = desempilha(&p_colunas);
                linha_e = desempilha(&p_linhas);
                continue; // Retorna ao início do loop
            }
        }

        // Verifica se encontrou a saída
        if (lab[linha_e][coluna_e] == 'S') {
            system("pause");
            system("clear");
            exibirlab(lab);
            lab[linha_e][coluna_e] = 'v';
            empilha(&p_colunas, coluna_e);
            empilha(&p_linhas, linha_e);
            exibesaida(&p_linhas, &p_colunas);
            return 1; // Encontrou saída
        }  

        system("pause");
        system("clear");
        exibirlab(lab);
    }

    return 0; // Saída não encontrada
}



