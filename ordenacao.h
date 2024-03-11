

#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include<stdio.h>
#include<stdlib.h>

//Inclui bib que manipula lista com alocacao estatica
#include "lista.h"

//Prototipo dos metodos de ordenacao
void bubbleSort(tipo_lista *);
void shellSorte(tipo_lista *);
void insertSort_ver1(tipo_lista *);
void merge_sort(tipo_lista *);
void merge_div(int*, int);
void merge(int*, int);
void quickSort (tipo_lista *);
void QuickDiv (int*, int, int);


//int particiona(int *, int, int);
//void quickSort(int*, int, int);

#endif //FIM __ORDENACAO_H__