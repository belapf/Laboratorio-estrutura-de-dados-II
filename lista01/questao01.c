#include <stdio.h>

float soma_serie(int n) { // função recursiva para somar os primeiros n termos da série com sinais alternados
    if (n == 1) {
        return 1; // para o caso do valor ser positivo
    } else {
        float termo = 1 / n;
        if (n % 2 == 0) {
            termo = -termo; // para o caso do valor ser negativo
        }
        return termo + soma_serie(n - 1);
    }
}

int main() { //função principal
    int n;
    printf("Digite um valor para n: "); // interação com o usuário
    scanf("%d", &n);
   
    float resultado = soma_serie(n);  // chamando a função para somar a série
    printf("A soma dos valores da sequencia e: %.2f\n", resultado);

    return 0;
}
