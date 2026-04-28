/**
 * @file ex01.c
 * @author Tarsila Paiva Pimentel
 * @brief Defina o elemento pessoa contendo nome e idade.
 * Crie um array structs pessoa, pré-preenchida. 
 * Implemente uma função para contar quantas pessoas tem idade maior que 17 anos.
 * @version 0.1
 * @date 2026-04-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nome[52];
    int idade;
}Pessoa;


void preencheDados(Pessoa *pessoas, int contador){
    printf("Digite o nome do %d usuário\n", contador + 1);
    fgets(pessoas->nome, 52, stdin);
    pessoas->nome[strcspn(pessoas->nome, "\n")] = '\0';
    
    printf("Digite a idade do %d usuário\n", contador + 1);
    scanf("%d", &pessoas->idade);
    setbuf(stdin, NULL);
}

int contarMaiorIdade(Pessoa *pessoas, int tamanho){
    int contador = 0;
    for (int i = 0; i < tamanho; i++){
        if (pessoas[i].idade > 17) contador++;
    }
    return contador;
}

int main(){
    int numeroPessoas = 5;
    Pessoa pessoas[numeroPessoas];

    for (int i = 0; i < numeroPessoas; i++){
        preencheDados(&pessoas[i], i);
    }

    printf("Número de pessoas maiores de idade: %d\n", contarMaiorIdade(pessoas, numeroPessoas));
    return 0;
}
