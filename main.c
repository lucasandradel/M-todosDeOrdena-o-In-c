/**
 
Universidade Federal de Mato Grosso
Bacharelado em Ciencia da Computacao
@file main.c
@author Prof. Ivairton
@brief Arquivo para testes.
@version 0.1
@date 2023-12-12
@copyright Copyright (c) 2023
*/

#include<stdio.h>
#include<stdlib.h>

#include "lista.h"
#include "ordenacao.h"

int main(int argc, char *argv[]) {

    tipo_lista minha_lista;
    minha_lista.contador = 0;

    insere_fim_lista(&minha_lista, 4);
    insere_fim_lista(&minha_lista, 5);
    insere_fim_lista(&minha_lista, 6);
    insere_fim_lista(&minha_lista, 4);
    insere_fim_lista(&minha_lista, 8);
    insere_fim_lista(&minha_lista, 2);
    insere_fim_lista(&minha_lista, 9);
    insere_fim_lista(&minha_lista, 10);
    insere_fim_lista(&minha_lista, 11);
    insere_fim_lista(&minha_lista, 4);
    insere_fim_lista(&minha_lista, 5);
    insere_fim_lista(&minha_lista, 6);

    printf("Lista DESORDENADA:\n");
    imprime_lista(minha_lista);
    

    //ordenacao da lista

    bubbleSort(&minha_lista);
    printf("--> Lista ordenada pelo BOBBLE SORT:\n");
    imprime_lista(minha_lista);

   

    shellSorte(&minha_lista);
    printf("--> Lista ordenada pelo SHELL SORT:\n");
    imprime_lista(minha_lista);

    quickSort (&minha_lista);
    printf("--> Lista ordenada pelo QUICK SORT:\n");
    imprime_lista(minha_lista);
    
    merge_sort(&minha_lista);
    printf("--> Lista ordenada pelo MERGE SORT:\n");
    imprime_lista(minha_lista);

    insertSort_ver1 (&minha_lista);
    printf("Lista ordenada pelo pelo insert sorte :\n");
    imprime_lista(minha_lista);

    return EXIT_SUCCESS;
}