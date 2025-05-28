#include <stdio.h>
#include <stdlib.h>

//definição da estrutura do nó
typedef struct Node {
    int valor;
    struct Node* esquerdo;
    struct Node* direito;
} Node;

//função para criar um nó
Node* criar_no(int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo) {
        novo->valor = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

//função para inserir na árvore
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else if (valor > raiz->valor) {
        raiz->direito = inserir(raiz->direito, valor);
    }
    return raiz;
}

//função para calcular a profundidade de um nó
int profundidade(Node* raiz, int valor) {
    if (raiz == NULL) {
        return -1; // nó não encontrado
    }
    if (raiz->valor == valor) {
        return 0; // raiz do próprio nó
    }
    if (valor < raiz->valor) {
        int prof = profundidade(raiz->esquerdo, valor);
        return (prof >= 0) ? prof + 1 : -1;
    } else {
        int prof = profundidade(raiz->direito, valor);
        return (prof >= 0) ? prof + 1 : -1;
    }
}

//função principal
int main() {
    Node* raiz = NULL;

    //inserindo valores na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    int valor = 60;
    int prof = profundidade(raiz, valor);

    if (prof != -1) {
        printf("Profundidade do no %d: %d\n", valor, prof);
    } else {
        printf("No %d não encontrado na arvore.\n", valor);
    }

    return 0;
}
