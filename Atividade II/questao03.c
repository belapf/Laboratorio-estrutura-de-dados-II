#include <stdio.h>
#include <stdlib.h>

// definição do nó da árvore binária
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

// função para criar o nó
Node* criar_no(int valor){
    Node* novo = malloc(sizeof(Node));
    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
    return novo;
}

// função para remover o nó (com impressão)
void remover_arvore(Node* T) {
    if (T != NULL) {
        remover_arvore(T->esquerda);
        remover_arvore(T->direita);
        printf("Removendo no com valor: %d\n", T->valor);
        free(T);
    }
}

// função principal
int main(){
    Node *raiz = criar_no(10);
    raiz->direita = criar_no(20);
    raiz->direita->esquerda = criar_no(15);

    // libera memória e imprime os nós removidos
    remover_arvore(raiz);
    

    return 0;
}

