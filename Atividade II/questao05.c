#include <stdio.h>
#include <stdlib.h>

//definição do nó da árvore binária
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

// Função para criar um novo nó
Node* criar_no(int valor){
    Node* novo = malloc(sizeof(Node));
    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
    return novo;
}

//função para inserir na árvore binária
Node* inserir(Node* raiz, int valor){
    if(raiz == NULL){
        return criar_no(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if(valor > raiz->valor){
        raiz->direita = inserir(raiz->direita, valor);
    }
    //se o valor já existe, não faz nada
    return raiz;
}

//percurso em pré-ordem 
void pre_ordem(Node* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}


//função principal
int main(){
    Node *raiz = NULL;

    //inserindo nós
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 19);
    raiz = inserir(raiz, 17);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 41);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 31);

    //impressão em pré-ordem
    printf("Percurso em pre-ordem: ");
    pre_ordem(raiz);
    printf("\n");

    return 0;
}
