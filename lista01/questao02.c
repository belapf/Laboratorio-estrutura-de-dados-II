#include <stdio.h>

float soma_serie(int n) {// função recursiva para somar os primeiros n termos da série com sinais alternados
    if (n == 1) {
        return 1;
    } else {
        float termo = 1 / n;
        if (n % 2 == 0) {
            termo = -termo;
        }
        return termo + soma_serie(n - 1);
    }
}


void cubos(int n) {// função recursiva para imprimir os cubos dos números de 1 a n
    if (n == 0) {
        return;
    }
    cubos(n - 1);
    printf("%d ", n * n * n);
}

int main() { //função principal
    int n;
    printf("Digite um valor para n: "); //interação com o usuário
    scanf("%d", &n);
    
    float resultado = soma_serie(n); // função para somar a série
    printf("A soma dos valores da serie de cubos e: %.2f\n", resultado);

    printf("Cubos dos numeros de 1 a %d: ", n); // função recursiva para imprimir os cubos
    cubos(n);
    printf("\n");

    return 0;
}
