#include <stdio.h>
#include "pilha.h"

void inicializa(Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

void empilha(Pilha *p, int valor) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = valor;
    }
}

int desempilha(Pilha *p) {
    if (!pilha_vazia(p)) {
        return p->itens[(p->topo)--];
    }
    return -1; // Retorna -1 se a pilha estiver vazia
}
