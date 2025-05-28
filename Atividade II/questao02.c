#include <stdio.h>
#include <stdlib.h>

//definição do nó da árvore binária
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;



//função para criar um novo nó
Node* criar_no(int valor) {
    Node* novo_no = (Node*) malloc(sizeof(Node));
    if (novo_no == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}



//função para imprimir a árvore (em pré-ordem)
void imprimir(Node* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}



//função para liberar a memória da árvore
void liberar(Node* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}


//função principal
int main() {
    //criação dos nós
    Node *raiz = criar_no(10);
    raiz->direita = criar_no(20);
    raiz->direita->esquerda = criar_no(15);

    //impressão da árvore
    printf("Percorrendo a arvore (pre-ordem): ");
    imprimir(raiz);
    printf("\n");

    //liberação da memória
    liberar(raiz);

    return 0;
}
