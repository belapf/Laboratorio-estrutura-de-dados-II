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

//função para buscar um valor na árvore
Node* buscar(Node* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esquerdo, valor);
    } else {
        return buscar(raiz->direito, valor);
    }
}

//função para remover todos os nós 
void remover_arvore(Node* raiz) {
    if (raiz != NULL) {
        remover_arvore(raiz->esquerdo);
        remover_arvore(raiz->direito);
        free(raiz);
    }
}

//função para exibir a árvore 
void em_ordem(Node* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerdo);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direito);
    }
}

//função principal 
int main() {
    Node* raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("arvore em ordem: ");
    em_ordem(raiz);
    printf("\n");

    // busca
    int valor_buscado = 40;
    Node* resultado = buscar(raiz, valor_buscado);
    if (resultado != NULL) {
        printf("Valor %d encontrado na arvore.\n", valor_buscado);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valor_buscado);
    }

    //remoção de toda a árvore
    remover_arvore(raiz);
    printf("arvore removida.\n");

    return 0;
}
