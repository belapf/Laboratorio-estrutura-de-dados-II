#include <stdio.h>
#include <stdlib.h>

//definição do nó da árvore
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

//função para contar o número de nós
int contar_nos(Node* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contar_nos(raiz->esquerdo) + contar_nos(raiz->direito);
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

    int total_nos = contar_nos(raiz);
    printf("O numero total de nos na arvore e: %d\n", total_nos);

    return 0;
}
