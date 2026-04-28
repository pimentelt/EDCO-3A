/**
 * @file ex03.c
 * @author Tarsila Paiva Pimentel
 * @brief Crie uma struct chamada Retangulo com os campos:
 * ● float largura
 * ● float altura
 * Implemente as seguintes funções:
 * ● float calcularArea(Retangulo *r): retorna a área do retângulo.
 * ● float calcularPerimetro(Retangulo *r): retorna o perímetro.
 * No main(), leia os valores do usuário, chame as funções e exiba os resultados.
 * @version 0.1
 * @date 2026-04-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float largura;
    float altura;
}Retangulo;

float calcularArea(Retangulo *retangulo){
    float area = (retangulo->largura) * (retangulo->altura);
    return area;
}

float calcularPerimetro(Retangulo *retangulo){
    float perimetro = (2*(retangulo->largura + retangulo->altura));
    return perimetro;
}

int main(){
    Retangulo retangulo;
    do{
        printf("Digite a altura do retângulo:\n");
        scanf("%f", &retangulo.altura);
        if (retangulo.altura <= 0) printf("A altura do retângulo deve ser maior que zero.\n");
    } while (retangulo.altura <= 0);
    
    do{
        printf("Digite a largura do retângulo:\n");
        scanf("%f", &retangulo.largura);
        if (retangulo.largura <= 0) printf("A largura do retângulo deve ser maior que zero.\n");
    } while (retangulo.largura <= 0);

    printf("-------------------------------------\n");
    printf("| Campo      | Valor                |\n");
    printf("-------------------------------------\n");
    printf("| Altura     | %.2f               |\n", retangulo.altura);
    printf("| Largura    | %.2f               |\n", retangulo.largura);
    printf("| Area       | %.2f               |\n", calcularArea(&retangulo));
    printf("| Perimetro  | %.2f               |\n", calcularPerimetro(&retangulo));
    printf("-------------------------------------\n");

    return 0;
}
