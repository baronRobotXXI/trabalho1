#include <stdio.h>
#include <stdlib.h>
#include "int_ord_cab.h"

struct no {
    int info;
    struct no* prox;
};

Lista* CriaLista (){
    Lista* cab;
    cab = (Lista*) malloc (sizeof(Lista));

    if (cab != NULL){
        cab->prox = NULL;
        cab->info = 0;
    }
    return cab;
}

int ListaVazia (Lista* lst){
    if (lst->prox == NULL)
        return 1;       //sucesso
    else
        return 0;       //falha
}

int InsereElemento (Lista* lst, int elemento){
    Lista* novo;

    novo = (Lista*) malloc (sizeof(Lista));

    if (novo == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        exit(1);
    }

    novo->info = elemento;
    novo->prox = lst->prox;         //insere no inicio
    lst->prox = novo;
    lst->info++;

    return 1;       //sucesso
}

int InsereOrdenado (Lista* lst, int elemento){
    Lista* novo;
    Lista* busca;

    novo = (Lista*) malloc(sizeof(Lista));

    if (novo == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        exit(1);
    }

    else
        novo->info = elemento;

    busca = lst;

    while (busca->prox != NULL && busca->prox->info < elemento)
        busca = busca->prox;

    novo->prox = busca->prox;
    busca->prox = novo;
    lst->info++;
    return 1;

}

int RemoveOrdenado (Lista* lst, int elemento){
    Lista* aux;
    Lista* aux2;

    if (ListaVazia(lst))
        return 0;

    aux = lst;

    while (aux->prox != NULL && aux->prox->info < elemento)
        aux = aux->prox;

    if (aux->prox == NULL || aux->prox->info > elemento)
        return 0;

    aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    lst->info--;
    return 1;

}

int ObtemValorElemento (Lista* lst, int pos, int* elemento){
    int i;

    if (pos >= lst->info)        //posicao maior que o tamanho
        return 0;

    for (i = 0; i < pos; i++){
        lst->prox = lst->prox->prox;
    }

    *elemento = lst->prox->info;
    return 1;
}

int Media (Lista* lst, float* media){
    int acumulador;
    int tam;

    tam = lst->info;

    if (ListaVazia(lst))
        return 0;               //falha

    acumulador = 0;
    while (lst->prox != NULL){
        acumulador += lst->prox->info;
        lst = lst->prox;
    }

    (*media) = (float) acumulador / tam;
    return 1;                   //sucesso
}

int ListasIguais (Lista* lst1, Lista* lst2){
    int verif;

    verif = 1;

    if (ListaVazia(lst1) || ListaVazia(lst2))
        return 0;           //falha, se uma lista tem elementos e a outra nao tem, elas sao diferentes

    if (lst1->info != lst2->info)
        return 0;                       //listas de tamanhos diferentes sao necessariamente diferentes
    else {
        while (lst1 != NULL){               //se as listas tem o msm tamanho, qd uma chegar a NULL a outra tbm chegara
            if (lst1->info != lst2->info)
                verif = 0;

        lst1 = lst1->prox;
        lst2 = lst2->prox;
        }
    }


    return verif;       //1 -> listas iguais, 0 -> listas diferentes
}

void IntercalaListas (Lista* lst1, Lista* lst2, Lista* lst3){
    Lista* aux1;
    Lista* aux2;

    aux1 = lst1->prox;
    aux2 = lst2->prox;


    while (aux1 != NULL){
        InsereOrdenado(lst3, aux1->info);
        aux1 = aux1->prox;
    }

    while (aux2 != NULL){
        InsereOrdenado(lst3, aux2->info);
        aux2 = aux2->prox;
    }
}

int InverteLista (Lista* lst1, Lista* lst2){
    int i;
    int temp;

    if (ListaVazia(lst1))
        return 0;

    for (i = 0; i < lst1->info; i++){                       //lst->info = tam
        ObtemValorElemento(lst1, i, &temp);
        InsereElemento(lst2, temp);
        lst2->info++;
    }

    return 1;
}

int ApenasImpares (Lista* lst1, Lista* lst2){
    int i;
    int verif;

    if (ListaVazia(lst1))
        return 0;

    for (i = 0; lst1->prox != NULL; i++){
        if (lst1->prox->info % 2 == 1){
            verif = InsereOrdenado(lst2, lst1->prox->info);

            if (!verif)
                return 0;       //insercao falhou
        }
        lst1->prox = lst1->prox->prox;
    }

    return 1;
}

int TamanhoLista (Lista* lst){          //precisa pq nem o .c nem a main conseguem acessar os campos da struct
   return lst->info;
}

void ImprimeLista (Lista* lst){

    while (lst->prox != NULL){
        printf("%d\t", lst->prox->info);
        lst = lst->prox;
    }
    printf("\n");
}

void EsvaziaLista (Lista** pLst) {
    *pLst = NULL;                            //se o ponteiro inicial eh nulo, a lista esta vazia.
}

void LiberaLista (Lista** pLst){
    Lista* busca;

    while (*pLst != NULL){ //percorre e limpa todos os itens da lista, menos o primeiro
        busca = *pLst;
        *pLst = (*pLst)->prox;
        free(busca);
    }
}
