/**
 * @file ex02.c
 * @author Tarsila Paiva Pimentel
 * @brief Tente criar uma rotina para adicionar um elemento entre o primeiro e o
 * segundo elemento de uma lista ligada.
 * @version 0.1
 * @date 2026-04-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Psitacideo{
    char especie[32];
    int idadeAnos;
    struct Psitacideo *proximoNo; //Próximo nó, não sei ler se não tiver acentução jjjjjjjj
}Psitacideo; //Gosto de aves, psitacídeo = papagaio

void insereMeio(Psitacideo *primeiroNo, char *especieDoNovoPassaro, int idadeDoNovoPassaro){
    if (primeiroNo == NULL){
        printf("Lista não possui elementos suficientes.\n");
        return;
    }
    
    Psitacideo *novoNoPsitacideo = (Psitacideo *) malloc(sizeof(Psitacideo));

    strcpy(novoNoPsitacideo->especie, especieDoNovoPassaro);
    novoNoPsitacideo->idadeAnos = idadeDoNovoPassaro;
    novoNoPsitacideo->proximoNo = primeiroNo->proximoNo;

    primeiroNo->proximoNo = novoNoPsitacideo;
}

int main(){
    Psitacideo *primeiroNo = (Psitacideo *) malloc(sizeof(Psitacideo));
    Psitacideo *segundoNo = (Psitacideo *) malloc(sizeof(Psitacideo));

    strcpy(primeiroNo->especie, "Periquito-australiano");
    primeiroNo->idadeAnos = 5;

    strcpy(segundoNo->especie, "Arara-Canindé");
    segundoNo->idadeAnos = 15;

    primeiroNo->proximoNo = segundoNo;
    segundoNo->proximoNo = NULL;

    printf("Lista antes da inserção:\n");
    Psitacideo *noAtual = primeiroNo;
    while (noAtual != NULL){
        printf("| %-30s | %-2d anos |\n", noAtual->especie, noAtual->idadeAnos);
        noAtual = noAtual->proximoNo;
    }

    insereMeio(primeiroNo, "Papagaio-cinzento", 10);

    printf("Lista após inserção:\n");
    noAtual = primeiroNo;
    while (noAtual != NULL){
        printf("| %-30s | %-2d anos |\n", noAtual->especie, noAtual->idadeAnos);
        noAtual = noAtual->proximoNo;
    }

    return 0;
}
