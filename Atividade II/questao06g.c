#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* esquerdo;
    struct Node* direito;
} Node;

int altura(Node* raiz) {
    if (raiz == NULL) return -1;
    int e = altura(raiz->esquerdo);
    int d = altura(raiz->direito);
    return (e > d ? e : d) + 1;
}

int main() {
    Node n1 = {20, NULL, NULL};
    Node n2 = {40, NULL, NULL};
    Node n3 = {30, &n1, &n2};
    Node n4 = {70, NULL, NULL};
    Node raiz = {50, &n3, &n4};

    printf("Altura da arvore: %d\n", altura(&raiz));

    return 0;
}
