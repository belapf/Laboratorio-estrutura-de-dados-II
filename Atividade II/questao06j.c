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

//função para calcular o nível de um nó
int nivel(Node* raiz, int valor, int nivel_atual) {
    if (raiz == NULL) {
        return -1;  //valor não encontrado
    }

    if (raiz->valor == valor) {
        return nivel_atual;
    }

    if (valor < raiz->valor) {
        return nivel(raiz->esquerdo, valor, nivel_atual + 1);
    } else {
        return nivel(raiz->direito, valor, nivel_atual + 1);
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

    int valor_procurado = 60;
    int resultado = nivel(raiz, valor_procurado, 0);

    if (resultado != -1) {
        printf("O nivel do valor %d na arvore e: %d\n", valor_procurado, resultado);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valor_procurado);
    }

    return 0;
}
