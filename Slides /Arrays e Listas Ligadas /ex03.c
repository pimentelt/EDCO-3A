/**
 * @file ex03.c
 * @author Tarsila Paiva Pimentel
 * @brief Crie 5 estruturas do tipo pessoa e ligue uma à outra. 
 * @version 0.1
 * @date 2026-04-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUANTIDADE_PESSOAS 5

typedef struct Pessoa{
    char nome[12];
    int idade;
    struct Pessoa *proximoNo;
}Pessoa;

int main(){
    Pessoa *cabeca = NULL;
    Pessoa *atual = NULL;
    Pessoa *anterior = NULL;
    
    char nomes[QUANTIDADE_PESSOAS][32] = {"Ana", "Bruno", "Carla", "Daniel", "Eva"};
    int idades[QUANTIDADE_PESSOAS] = {20, 22, 19, 25, 30};
    for (int i = 0; i < QUANTIDADE_PESSOAS; i++){
        Pessoa *novoNo = (Pessoa*) malloc(sizeof(Pessoa));
        
        strcpy(novoNo->nome, nomes[i]);
        novoNo->idade = idades[i];
        novoNo->proximoNo = NULL;
    
        if (cabeca == NULL){
            cabeca = novoNo;
        } else {
            anterior->proximoNo = novoNo;
        }
        anterior = novoNo;
    }
    
    atual = cabeca;
    printf("Lista de pessoas:\n");
    while (atual != NULL) {
        printf("| %-10s | %2d anos |\n", atual->nome, atual->idade);
        atual = atual->proximoNo;
    }

    return 0;
}
