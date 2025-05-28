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
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }


    novo_no->valor = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}



//função principal
int main() {
    // Cria a raiz
    Node *raiz = criar_no(10);

    // Adiciona filho à direita
    raiz->direita = criar_no(20);

    // Adiciona filho à esquerda
    raiz->esquerda = criar_no(5);

    printf("Raiz: %d\n", raiz->valor);
    printf("Filho esquerdo: %d\n", raiz->esquerda->valor);
    printf("Filho direito: %d\n", raiz->direita->valor);

    // Libera a memória
    free(raiz->esquerda);
    free(raiz->direita);
    free(raiz);

    return 0;
}
