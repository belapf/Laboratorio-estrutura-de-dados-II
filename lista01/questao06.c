#include <stdio.h>

int ackermann(int m, int n) { // função recursiva de Ackermann
    if (m == 0) 
        return n + 1;
    else if (m > 0 && n == 0) 
        return ackermann(m - 1, 1);
    else 
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main() { //função principal
    int m, n;

    printf("Digite os valores de m e n: "); // interação com o usuário
    scanf("%d %d", &m, &n);

    if (m < 0 || n < 0) { //função para verificar se os valores não são negativos
        printf("Os valores não devem ser negativos.\n");
        return 1;
    }

    
    int resultado = ackermann(m, n); //chamada da função de ackermann e exibição do resultado
    printf("Ackermann(%d, %d) = %d\n", m, n, resultado);

    return 0;
}
