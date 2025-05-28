#include <stdio.h>
#include <stdlib.h>

//definição da estrutura do nó
typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
} Node;

//função para criar um nó
Node* criar_no(int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo) {
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

//função para inserir na árvore
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

//função para buscar um valor na árvore
Node* buscar(Node* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

//função para remover todos os nós 
void remover_arvore(Node* raiz) {
    if (raiz != NULL) {
        remover_arvore(raiz->esquerda);
        remover_arvore(raiz->direita);
        free(raiz);
    }
}

//função para exibir a árvore em ordem - in-ordem
void em_ordem(Node* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

//função principal 
int main() {
    Node* raiz = NULL;

    //inserção de valores na árvore
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 16);
    raiz = inserir(raiz, 32);
    raiz = inserir(raiz, 64);

    //exibir a árvore em ordem
    printf("arvore em ordem: ");
    em_ordem(raiz);
    printf("\n");

    //buscar um valor na árvore
    int valor_buscado = 4;
    Node* resultado = buscar(raiz, valor_buscado);
    if (resultado != NULL) {
        printf("Valor %d encontrado na arvore.\n", valor_buscado);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valor_buscado);
    }

    //remover toda a árvore
    remover_arvore(raiz);
    printf("arvore removida.\n");

    return 0;
}
