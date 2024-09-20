#ifndef FUNCS_H
#define FUNCS_H
#include "pilha.h"

typedef struct {
    int linha;
    int coluna;
} Coordenada;

void completa_lab(char lab[10][10], const char *labirinto);
void identifica(int *linha_e, int *coluna_e, int *linha_s, int *coluna_s, char lab[10][10]);
void exibirlab(char lab[10][10]);
int buscasaida(char lab[10][10], int linha_e, int coluna_e, int linha_s, int coluna_s);
void exibesaida(Pilha *p_linhas, Pilha *p_colunas);


#endif // FUNCS_H
