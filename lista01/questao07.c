#include <stdio.h>
#include <math.h> // biblioteca para funções matemáticas


double aproximacao_sen(double rad) {// função para aproximação de seno para ângulos menores que 1 (em radianos)
    return rad; // para os ângulos pequenos, sen(x) ≈ x
}


double deg_to_rad(double deg) {// função para conversão de graus para radianos
    // fórmula de conversão: rad = graus * π / 180
    return deg * M_PI / 180;
}


double recursiva_sen(double deg) {// função recursiva para calcular o seno usando a fórmula de seno duplo
    double rad = deg_to_rad(deg);// converção do ângulo de graus para radianos

    
    if (deg < 1.0) {// para ângulos menores que 1, utiliza-se a aproximação direta
        return aproximacao_sen(rad);
    }

    double divide_angulo = deg / 2.0; // função para dividir o ângulo pela metade para a recursão
    
    double meio_angulo = recursiva_sen(divide_angulo);// chamada recursiva para calcular o seno do meio do ângulo

    
    double cos_half = sqrt(1.0 - meio_angulo * meio_angulo);// cálculo do cosseno usando a identidade trigonométrica: cos²(x) = 1 - sen²(x)

    return 2.0 * meio_angulo * cos_half;// usando a fórmula do seno duplo: sen(2x) = 2 * sen(x) * cos(x)
}


int main() {// função principal
    double angulo; // variável para armazenar o ângulo informado pelo usuário

    
    printf("Digite o angulo em graus: ");//interação com o usuário
    scanf("%lf", &angulo);

    double resultado = recursiva_sen(angulo); // cálculo do seno do ângulo informado

    printf("O valor aproximado do sen(%.2f) e: %.6f\n", angulo, resultado);

    return 0;
}
