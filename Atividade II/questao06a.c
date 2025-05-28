#include <stdio.h>
#include <stdlib.h>

//definição da estrutura do nó da árvore binária de busca
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;
