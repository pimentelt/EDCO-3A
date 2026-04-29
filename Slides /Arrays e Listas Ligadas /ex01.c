/**
 * @file ex01.c
 * @author Tarsila Paiva Pimentel
 * @brief Tente criar uma função para remover um elemento no meio do array.
 * @version 0.1
 * @date 2026-04-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE_PESSOAS 5

typedef struct{
    char nome[12];
    int idade;
}Pessoa;

void removerItem(Pessoa *pessoas, int *quantidadeItens, int posicao){
    if (posicao < 0 || posicao >= *quantidadeItens){
        printf("Posição inválida.\n");
        return;
    }
    
    for (int i = posicao; i < *quantidadeItens - 1; i++){
        pessoas[i] =  pessoas[i + 1];
    }
    
    (*quantidadeItens)--;
}

int main(){
    Pessoa pessoas[QUANTIDADE_PESSOAS] = {
        {"Ana", 20},
        {"Maria", 15},
        {"Clara", 25},
        {"Eduarda", 30},
        {"Isabela", 20},
    };

    int quantidadeItens = QUANTIDADE_PESSOAS;

    printf("Antes da remoção:\n");
    for (int i = 0; i < quantidadeItens; i++){
        printf("%-10s - %-2d\n", pessoas[i].nome, pessoas[i].idade);
    }

    removerItem(pessoas, &quantidadeItens, 1);

    printf("\nDepois da remoção:\n");
    for (int i = 0; i < quantidadeItens; i++){
        printf("%-10s - %-2d\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}
