#include <stdio.h>
#include <stdlib.h>
#include "circular_nord.h"

struct no {
    int info;
    struct no* prox;
};

Lista* CriaLista (){
    return NULL;
}

int ListaVazia (Lista* lst){
    if (lst == NULL){
        return 1;           //sucesso
    }
    else
        return 0;           //falha
}

int InsereFinal (Lista** lst, int elemento){
    Lista* novo;

    novo = (Lista*) malloc (sizeof(Lista));

    if (novo == NULL)
        return 0;
    else {
        novo->info = elemento;

        if (ListaVazia(*lst)){            //lista está vazia
            novo->prox = novo;
            (*lst) = novo;
        }
        else{                                   //lista tem elementos
            novo->prox = (*lst)->prox;
            (*lst)->prox = novo;
            *lst = novo;
        }
        return 1;
    }
}

int InsereInicio (Lista** lst, int elemento){
    Lista* novo;

    novo = (Lista*) malloc (sizeof(Lista));

    if (novo == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        exit(1);
    }
    else {
        novo->info = elemento;

        if (ListaVazia(*lst)){
            novo->prox = novo;
            (*lst) = novo;
        }
        else{
            novo->prox = (*lst)->prox;
            (*lst)->prox = novo;

        }
        return 1;
    }
}

int InserePosicao (Lista** lst, int pos, int elemento){
    Lista* local;
    Lista* novo;
    int i;

    novo = (Lista*) malloc (sizeof(Lista));

    if (novo == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        return 0;       //exit(1);
    }

    local = (*lst)->prox;      //pos0

    for (i = 0; i < pos-1; i++)
        local = local->prox;                //leva local até o elemento da posicao anterior a que será inserida

    novo->info = elemento;
    novo->prox = local->prox;
    local->prox = novo;

    return 1;           //sucesso
}

int RemoveInicio (Lista** lst, int* elemento){
    Lista* aux;

    if (ListaVazia(*lst))
        return 0;                       //falha

    aux = (*lst)->prox;
    *elemento = aux->info;

    if (*lst == (*lst)->prox){     //so existe um item
        *lst = NULL;
        return 1;
    }
    else{         //existe o dado a ser removid6
        (*lst)->prox = aux->prox;
        free(aux);
        return 1;
    }

}

int RemovePosicao(Lista** lst, int pos, int* elemento){
    Lista* aux;
    int i;

    if (ListaVazia(*lst))        //confere pos > tam na main
        return 0;
    else{
        aux = (*lst)->prox;     //pos0

        for (i = 0; i < pos-1; i++)
            aux->prox = aux->prox->prox;

        *elemento = aux->prox->info;
        aux->prox = aux->prox->prox;
        free(aux->prox);
    }

        return 1;

}

int ApenasImpares (Lista* lst1, Lista** lst2){
    int verif;
    Lista* aux;
    int i;

    aux = lst1;

    if (ListaVazia(lst1))
        return 0;

    i = 0;
    do{
        if (lst1->info % 2 == 1){
            verif = InsereInicio(lst2,lst1->info);

            if (!verif)
                return 0;
        }
        lst1 = lst1->prox;
        i++;
    }while(aux != lst1);

    return 1;
}

int ObtemValorElemento (Lista* lst, int pos, int* elemento){
    int i;
    Lista* local;

    if (ListaVazia(lst))
        return 0;       //falha

    local = lst->prox;

    for (i = 0; i < pos; i++)
        local = local->prox;

    *elemento = local->info;

    return 1;       //sucesso
}

int TamanhoLista (Lista* lst, int* tam){
    Lista* local;
    int i;

    local = lst->prox;      //pos0

    i = 0;
    do {
        local = local->prox;
        i++;
    }while(local != lst->prox);

    *tam = i;

    return 1;       //sucesso
}

int Maior (Lista* lst, int* elemento){
    int maior;
    Lista* local;

    if (ListaVazia(lst))
        return 0;               //falha

    local = lst->prox;
    maior = local->info;

    do {
        if (local->info > maior)
            maior = local->info;

        local = local->prox;
    }while(local != lst->prox);

    *elemento = maior;

    return 1;
}

void ImprimeLista (Lista* lst){
    Lista* local;

    local = lst->prox;

    do {
        printf("%d\t", local->info);
        local = local->prox;

    }while (local != lst->prox);

    printf("\n");
}

void LiberaLista (Lista** lst){

    while ((*lst)->prox != NULL) {
        (*lst) = (*lst)->prox;
        free(lst);
    }
    (*lst) = NULL;
}
