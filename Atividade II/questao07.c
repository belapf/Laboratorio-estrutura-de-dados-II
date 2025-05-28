#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo a estrutura do nó da árvore
typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

//função para criar um novo aluno - nó
Aluno* criar_aluno(char nome[], int matricula, float nota) {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo) {
        strcpy(novo->nome, nome);
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

//função para inserir um aluno na árvore
Aluno* inserir(Aluno* raiz, char nome[], int matricula, float nota) {
    if (raiz == NULL) {
        return criar_aluno(nome, matricula, nota);
    }
    if (matricula < raiz->matricula) {
        raiz->esquerdo = inserir(raiz->esquerdo, nome, matricula, nota);
    } else if (matricula > raiz->matricula) {
        raiz->direito = inserir(raiz->direito, nome, matricula, nota);
    }
    return raiz;
}

//função para exibir os alunos em ordem (ordenado pela matrícula)
void ordem(Aluno* raiz) {
    if (raiz != NULL) {
        ordem(raiz->esquerdo);
        printf("Nome: %s | Matricula: %d | Nota: %.2f\n", raiz->nome, raiz->matricula, raiz->nota);
        ordem(raiz->direito);
    }
}


//função principal
int main() {
    Aluno* raiz = NULL;

    //inserindo valores
    raiz = inserir(raiz, "Isabel", 102, 9.5);
    raiz = inserir(raiz, "Itallo", 101, 7.8);
    raiz = inserir(raiz, "Charles", 105, 8.2);
    raiz = inserir(raiz, "Iara", 103, 6.9);
    raiz = inserir(raiz, "Ikaro", 104, 9.0);

    //exibir os alunos em ordem crescente de matrícula
    printf("Alunos em ordem de matricula:\n");
    ordem(raiz);

    return 0;
}
