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

//função para contar o número de folhas
int contar_folhas(Node* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esquerdo == NULL && raiz->direito == NULL) {
        return 1;
    }
    return contar_folhas(raiz->esquerdo) + contar_folhas(raiz->direito);
}

//função principal
int main() {
    Node* raiz = NULL;

    //inserindo elementos na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    int folhas = contar_folhas(raiz);
    printf("O numero de folhas na arvore e: %d\n", folhas);

    return 0;
}
