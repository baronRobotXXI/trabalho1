#include <stdio.h>
#include <stdlib.h>
#include "int_ord.h"
#define TAM 20

struct lista {
    int info[TAM];
    int fim;
};

Lista* CriaLista (){
    Lista* lst;

    lst = (Lista*) malloc (sizeof(Lista));

    if (lst == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        exit(1);
    }
    else{
        lst->fim = 0;
        return lst;
    }
}

int ListaVazia (Lista* lst){
    if (lst->fim == 0)
        return 1;
    else
        return 0;
}

int ListaCheia (Lista* lst){
    if (lst->fim == TAM)
        return 1;
    else
        return 0;
}

int InsereOrdenado (Lista* lst, int elem){
    int i;
    int j;

    if (lst == NULL || lst->fim >= TAM)
        return 0;           //falha - testar lista cheia em vez disso?
    else{
        if (ListaVazia(lst) || elem >= lst->info[(lst->fim) - 1])
            lst->info[lst->fim] = elem;

        else{
            for (j = 0; elem >= lst->info[j]; j++);    //percorrimento

            for (i = lst->fim; i > j; i--)              //deslocamento
                lst->info[i] = lst->info[i-1];

            lst->info[j] = elem;
        }
            lst->fim++;
            return 1;
    }

}

int RemoveOrdenado (Lista* lst, int elem){
    int i;
    int j;

    if (lst == NULL || ListaVazia(lst) || elem < lst->info[0] || elem > lst->info[(lst->fim) - 1])
        return 0;               //falha
    else {
        for (j = 0; j < lst->fim && lst->info[j] < elem; j++);

        if (j == lst->fim || lst->info[j] > elem)       //elemento nao existe
            return 0;
        else
            for (i = j+1; i < (lst->fim)-1; i++)
                lst->info[i-1] = lst->info[i];

        lst->fim--;
        return 1;


    }
}

int ObtemValorElemento (Lista* lst, int pos, int* elem){
    int i;

    if (lst == NULL || (ListaVazia(lst)))
        return 0;
    else
        for (i = 0; i < pos; i++);

    *elem = lst->info[i];
    return 1;

}

void ImprimeLista (Lista* lst){
    int i;

    printf("Os elementos da lista sao:\n");
    for (i = 0; i <= (lst->fim)-1; i++)
        printf("%d\t", lst->info[i]);

    printf("\n");
}

void LiberaLista (Lista** lst){
    free(*lst);
}
