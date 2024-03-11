#include<stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

void bubbleSort(tipo_lista *list){
    int flag_troca, i, aux;

    do{
        flag_troca = 0;
        for (i = 0; i < list -> contador - 1; i++ ){
            if(list-> lista[i] > list->lista [i+1]){    
                aux = list -> lista[i];
                list -> lista [i]= list -> lista [i+1];
                list->lista[i+1]= aux;
                flag_troca ++;

            }

        }
    }while (flag_troca != 0);
    
}
   
void shellSorte(tipo_lista *list){
    int salto,i, flag_troca, aux;

    salto= (int) list -> contador/2;
    //etapa de comparação com saltos
    while (salto >1 )
    {
        for (i =0; (i+salto)< list -> contador; i++){
            if(list -> lista[i]> list ->lista [i+salto]){
                aux = list -> lista[i];
                list -> lista[i] = list -> lista[i+salto];
                list ->lista [i+salto]= aux; 
            }
        }
        salto = (int) salto/2;
    }
    
    do{
        flag_troca = 0;
        for (i = 0; i < list -> contador - 1; i++ ){
            if(list-> lista[i] > list->lista [i+salto]){    
                aux = list -> lista[i];
                list -> lista [i]= list -> lista [i+salto];
                list->lista[i+salto]= aux;
                flag_troca ++;

            }

        }
    }while (flag_troca !=0);
    
}

void insertSort_ver1(tipo_lista *list){
    int i, pos;

    tipo_lista list_ordenada;


    list_ordenada. contador = 0;

    //percorrer toda a lista de entrada para inserir cada va,or
    for(i = 0; i<list -> contador; i++){

        // aqui é possivel implmentar uma função de inserção ordenada
        // o que deixaria o código bem simples
        pos = list_ordenada.contador;
        if (pos == 0){
            insere_fim_lista(&list_ordenada, list -> lista [i]);

        }
        else{
            while ((pos > 0) && (list -> lista [i] < list_ordenada.lista[pos - 1]))
                pos--;
            
            insere_pos_lista(&list_ordenada, list -> lista [i], pos);
        }
    }

    for (i = 0; i < list-> contador; i++){
        list -> lista[i] = list_ordenada.lista [i];
    }

}

void merge_sort(tipo_lista *list){
    merge_div(list -> lista, list -> contador);
    
}

void merge_div(int vet[], int tamanho){
    int meio;
    if (tamanho > 1){
        meio = tamanho/2;
        merge_div(vet, meio);
        merge_div(& (vet[meio]) , (tamanho-meio));
        merge (vet, tamanho);
    }
}

void merge (int vet[], int tamanho){
    int *vet_aux, meio, i , j, idx_aux;

    vet_aux = (int*) malloc(sizeof(int)*tamanho);

    meio = tamanho/2;

    i = 0;
    j = meio;
    idx_aux =0;
    while ((i < meio) && (j < tamanho))
    {
        if (vet[i] < vet[j]){
            vet_aux[idx_aux++]= vet [i++];

        }else{ 
            vet_aux[idx_aux ++]= vet [j++];

        }
    }
    while (i < meio)
    {
        vet_aux[idx_aux++] = vet [i++];
    }
    while (j < tamanho)
    {
        vet_aux[idx_aux++] =vet [j++];
    }

    for (i = 0; i < tamanho; i++){
        vet [i] =  vet_aux[i];
    }
    
    free(vet_aux);
}

void quickSort(tipo_lista *list){
    if (list -> contador > 1){
        QuickDiv(list->lista, 0, list->contador - 1);
    }
    
}

void QuickDiv(int vet[], int inicio, int fim){
    int meio, i, j, pivo, aux;

    //calcula meio e define vlor do vetor
    meio = (inicio + fim) / 2;
    pivo = vet[meio];

    i = inicio;
    j = fim;
    //coloca o pivo no seu devido lugar
    while (i <= j)
    {
        while (vet[i] < pivo)
        {
            i++;
        }
        while (vet[j] > pivo)
        {
            j--;
        }
        if (i <= j)
        {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j)
    {
        QuickDiv(vet, inicio, j);
    }
    if (i < fim)
    {
        QuickDiv(vet, i, fim);
    }
}
