#include <stdio.h>

int main() { //função principal
    int n, i;
    int t1 = 0, t2 = 1, proximo_termo;

    printf("Quantos termos da sequencia Fibonacci voce deseja exibir? ");// Solicita ao usuário o número de termos da sequência Fibonacci
    scanf("%d", &n);

    printf("Sequencia Fibonacci: "); // Exibe os primeiros dois termos da sequência ou seja 0 e 1 
    
    if (n <= 0) {
        printf("Por favor, insira um numero maior que 0.");
    } else if (n == 1) {
        printf("%d", t1);
    } else {
        printf("%d, %d", t1, t2);
        
        
        for (i = 3; i <= n; ++i) {// função para calcular e exibir os próximos termos
            proximo_termo = t1 + t2;
            printf(", %d", proximo_termo);
            t1 = t2;
            t2 = proximo_termo;
        }
    }
    
    printf("\n");

    return 0;
}
