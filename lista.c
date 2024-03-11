#include "lista.h"

/**
 * @brief Funcao que insere no inicio da lista.
 * 
 * @param tipo_lista *lista - Estrutura da lista
 * @param int valor - valor a ser inserido na lista
 * 
 * @return int - verdadeiro se insercao com sucesso, falso caso contrário
 */
int insere_inicio_lista(tipo_lista *lst, int valor) {
    /*
    int pos;
    if (lst->contador < N) {
        pos = lst->contador;
        while (pos > 0) {
            lst->lista[pos] = lst->lista[pos-1];
            pos--;
        }
        lst->lista[0] = valor;
        lst->contador++;
        return lst->contador;
    } else {
        return 0;
    }
    */
    return insere_pos_lista(lst, valor, 0);
}

/**
 * @brief FUncao que insere o novo valor no fim da lista.
 * 
 * @param tipo_lista *lst - Estrutura da Lista 
 * @param int valor - Valor a ser inserido
 * @return int - verdadeiro se insercao com sucesso, falso caso contrario
 */
int insere_fim_lista(tipo_lista *lst, int valor) {
    /*if (lst->contador < N) {
        lst->lista[lst->contador++] = valor;
        return 1;
    }
    return 0;*/
    return insere_pos_lista(lst, valor, lst->contador);
}

/**
 * @brief Funcao que insere em posicao especifica da lista.
 * 
 * @param tipo_lista *lst - Estrutura da lista 
 * @param int valor - valor a ser inserido
 * @param int pos - posicao onde o valor sera inserido
 * @return int - retorna verdadeiro se sucesso, ou falso caso contário
 */
int insere_pos_lista(tipo_lista *lst, int valor, int pos) {
    int i;
    if (lst->contador < N) {
        i = lst->contador;
        while (i > pos) {
            lst->lista[i] = lst->lista[i-1];
            i--;
        }
        lst->lista[pos] = valor;
        lst->contador++;
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Funcao que remove o elemento do inicio da lista.
 * 
 * @param tipo_lista *lst - Referencia para a estrutura da lista
 * @return int - retorna o valor removido, ou -1 em caso de erro
 */
int remove_inicio_lista(tipo_lista *lst) {
    return remove_pos_lista(lst, 0);
}

/**
 * @brief Funcao que remove o elemento do fim da lista.
 * 
 * @param tipo_lista *lst - Referencia para a estrutura da lista
 * @return int - retorna o valor removido, ou -1 em caso de erro
 */
int remove_fim_lista(tipo_lista *lst) {
    return remove_pos_lista(lst, lst->contador-1);
}

/**
 * @brief Funcao que remove um valor de uma posicao especifica.
 * 
 * @param tipo_lista *lst - Referencia para a estrutura da lista 
 * @param int pos - Posicao onde o valor sera removido
 * @return int - Retorna o valor removido, ou -1 no caso de erro. 
 */
int remove_pos_lista(tipo_lista *lst, int pos) {
    int valor, i;
    if ( (pos >= 0) && (pos < lst->contador) ) {
        valor = lst->lista[pos];
        for ( i = pos; i < lst->contador - 1; i++)
            lst->lista[i] = lst->lista[i+1];
        lst->contador--;
        return valor;
    } else {
        return -1;
    }
}

/**
 * @brief Funcao que remove um valor especifico, presente na lista
 * 
 * @param tipo_lista *lst - Referencia para a estrutura da lista
 * @param int valor - Valor a ser buscado e removido
 * @return int - retorna verdadeiro caso a remocao ocorra, ou falso caso contrario
 */
int remove_valor_lista(tipo_lista *lst, int valor) {
    int pos;
    pos = busca_valor_lista(*lst, valor);
    if (pos != -1)
        return remove_pos_lista(lst, pos);
    return -1;
}

/**
 * @brief Funcao que busca por um valor na lista
 * 
 * @param tipo_lista lst - Estrutura da lista. 
 * @param int valor - Valor a ser buscado
 * @return int - Retorna a posicao onde o valor foi encontrado, ou -1 caso não esteja presente
 */
int busca_valor_lista(tipo_lista lst, int valor) {
    int i;
    for (i = 0; i < lst.contador; i++) {
        if (lst.lista[i] == valor)
            return i;
    }
    return -1;
}

/**
 * @brief Funcao que busca o valor localizado na posicao especificada.
 * 
 * @param tipo_lista lst - Estrutura da lista. 
 * @param int pos - Posicao a ser verificada.
 * @return int - valor registrado na posicao, ou -1 caso posicao seja invalida
 */
int busca_pos_lista(tipo_lista lst, int pos) {
    if ( (pos >=0) && (pos < lst.contador) )
        return lst.lista[pos];
    return -1;
}

/**
 * @brief Funcao que encontra o maior valor presente na lista.
 * 
 * @param tipo_lista lst - Estrutura da Lista 
 * @return int - Maior valor encontrado, ou -1 caso a lista esteja vazia
 */
int busca_maior_lista(tipo_lista lst) {
    int i, maior;
    if (lst.contador > 0) {
        maior = lst.lista[0];
        for ( i = 1; i < lst.contador; i++) {
            if (lst.lista[i] > maior)
                maior = lst.lista[i];
        }
        return maior;
    } else {
        return -1;
    }
}

/**
 * @brief Funcao que encontra o menor valor presente na lista.
 * 
 * @param tipo_lista lst - Estrutura da Lista 
 * @return int - Menor valor encontrado, ou -1 caso a lista esteja vazia
 */
int busca_menor_lista(tipo_lista lst) {
    int i, menor;
    if (lst.contador > 0) {
        menor = lst.lista[0];
        for ( i = 1; i < lst.contador; i++) {
            if (lst.lista[i] < menor)
                menor = lst.lista[i];
        }
        return menor;
    } else {
        return -1;
    }
}

/**
 * @brief Procedimento que imprime a lista.
 * 
 * @param tipo_lista lst - Estrutura da lista.
 */
void imprime_lista(tipo_lista lst) {
    int i;
    printf("Lista: [ ");
    for (i=0; i<lst.contador; i++)
        printf("%d ", lst.lista[i]);
    printf("]\n\n");
}