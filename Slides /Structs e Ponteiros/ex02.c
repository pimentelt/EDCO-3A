/**
 * @file ex02.c
 * @author Tarsila Paiva Pimentel
 * @brief Crie uma struct chamada Produto com os campos:
 * ● char nome[50]
 * ● float preco
 * ● int estoque
 * No main(), declare três produtos, preencha seus dados manualmente e imprima as informações na tela.
 * Faça uma função void atualizarEstoque(Produto *p, int quantidade) para atualizar o estoque usando
 * ponteiros.
 * @version 0.1
 * @date 2026-04-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define quantidadeProdutos 3

typedef struct{
    char nome[52];
    float preco;
    int estoque;
}Produto;

void atualizarEstoque(Produto *produtos, int quantidade){
    produtos->estoque += quantidade;
}

int main(){
    int quantidade, indice;
    Produto produtos[quantidadeProdutos]={
        {"Arroz", 10.50, 20},
        {"Feijão", 8.90, 15},
        {"Macarrão", 5.30, 30},
    };

    printf("Escolha o produto (1 a %d):\n", quantidadeProdutos);
    scanf("%d", &indice);
    indice = indice - 1;
    
    printf("Digite a quantidade (negativo para venda, positivo para reposicao): ");
    scanf("%d", &quantidade);

    atualizarEstoque(&produtos[indice], quantidade);
    for (int i = 0; i < quantidadeProdutos; i++){
        printf("=====================================\n");
        printf("Produto: %s\n", produtos[i].nome);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Estoque: %d unidades\n", produtos[i].estoque);
        printf("=====================================\n\n");
    }
    
    return 0;
}
