#include <stdio.h>


int fatorial_auxiliar(int n, int acumulador) {// função auxiliar para calcular o fatorial com recursão de cauda
    if (n == 0) {
        return acumulador; // retorna o valor acumulado
    }
    
    return fatorial_auxiliar(n - 1, n * acumulador);// chamada recursiva na posição de cauda
}


int fatorial(int n) {// função para chamar a função auxiliar
    return fatorial_auxiliar(n, 1); // inicializa o acumulador com 1
}

int main() {//função principal
    int num;
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Nao e possivel calcular o fatorial de numero negativo\n");
    } else {
        printf("Fatorial de %d e: %d\n", num, fatorial(num));
    }

    return 0;
}
