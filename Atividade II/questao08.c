#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definição da estrutura do nó 
typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

//criar um novo nó 
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

//inserir aluno na árvore (baseado na matrícula)
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

//buscar aluno na árvore pela matrícula
Aluno* buscar(Aluno* raiz, int matricula) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->matricula == matricula) {
        return raiz;
    }
    if (matricula < raiz->matricula) {
        return buscar(raiz->esquerdo, matricula);
    } else {
        return buscar(raiz->direito, matricula);
    }
}

//exibir alunos em ordem de matrícula
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
    raiz = inserir(raiz, "Iara", 105, 8.2);
    raiz = inserir(raiz, "Ikaro", 103, 6.9);
    raiz = inserir(raiz, "Charles", 104, 9.0);

    //exibir alunos em ordem
    printf("Alunos em ordem de matricula:\n");
    ordem(raiz);

    // realizando uma busca
    int buscar_matricula;
    printf("\nDigite a matricula do aluno que deseja buscar: ");
    scanf("%d", &buscar_matricula);

    Aluno* resultado = buscar(raiz, buscar_matricula);
    if (resultado != NULL) {
        printf("Aluno encontrado:\n");
        printf("Nome: %s | Matricula: %d | Nota: %.2f\n", resultado->nome, resultado->matricula, resultado->nota);
    } else {
        printf("Aluno com matricula %d nao encontrado.\n", buscar_matricula);
    }

    return 0;
}
