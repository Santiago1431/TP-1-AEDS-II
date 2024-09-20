#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p);
int pilha_vazia(Pilha *p);
void empilha(Pilha *p, int valor);
int desempilha(Pilha *p);

#endif // PILHA_H
