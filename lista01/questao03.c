#include <stdio.h> 
#include <string.h> //biblioteca de strings
#include <ctype.h> // biblioteca para testar e manipular caracteres


int Palindromo(char str[], int inicio, int fim) { // Função recursiva para verificar se uma palavra é um palíndromo
    // anotação: se a posição inicial for maior ou igual à posição final, a palavra é um palíndromo
    if (inicio >= fim) {
        return 1;  // É um palíndromo
    }

    
    if (!isalnum(str[inicio])) { // função para Ignorar caracteres nulos como espaços e pontuação
        return Palindromo(str, inicio + 1, fim);  // função para pular caractere nulo
    }
    if (!isalnum(str[fim])) {
        return Palindromo(str, inicio, fim - 1);
    }

   
    if (tolower(str[inicio]) != tolower(str[fim])) {  // função para comparar os caracteres
        return 0;  // não é um palíndromo
    }

   
    return Palindromo(str, inicio + 1, fim - 1);  // chamada recursiva, comparando os caracteres internos
}

int main() { // função principal
    char str[100];

    printf("Digite uma palavra: "); // solicita ao usuário que digite a palavra ou expressão
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // remover o caractere de nova linha

    int comprimento = strlen(str);

    
    if (Palindromo(str, 0, comprimento - 1)) { // chama a função recursiva para verificar se a string é um palíndromo
        printf("A palavra e um palindromo.\n");
    } else {
        printf("A palavra nao e um palindromo.\n");
    }

    return 0;
}
