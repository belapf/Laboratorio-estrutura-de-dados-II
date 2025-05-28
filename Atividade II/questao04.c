#include <stdio.h>
#include <stdlib.h>

//definição do nó da árvore binária
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

//criar um novo nó
Node* criar_no(int valor){
    Node* novo = malloc(sizeof(Node));
    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
    return novo;
}

//inserir um valor na árvore
Node* inserir(Node* raiz, int valor){
    if(raiz == NULL){
        return criar_no(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor){
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

//função de busca
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

//função principal
int main(){
    Node *raiz = NULL;
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

    int chave = 19;
    Node* resultado = buscar(raiz, chave);

    if(resultado != NULL){
        printf("Valor %d encontrado na arvore.\n", resultado->valor);
    } else {
        printf("Valor %d não encontrado na arvore.\n", chave);
    }

    return 0;
}
