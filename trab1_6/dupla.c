#include <stdio.h>
#include <stdlib.h>
#include "dupla.h"

struct no {
    int info;
    struct no* prox;
    struct no* ant;
};

Lista* CriaLista(){
    return NULL;
}

int ListaVazia (Lista* lst){

    if (lst == NULL)
        return 1;
    else
        return 0;
}

int InsereOrdenado (Lista** lst, int elemento){
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

    if (ListaVazia(*lst) || elemento <= (*lst)->info){ //insere no inicio
        novo->ant = NULL;
        novo->prox = *lst;                                                                              //elemento > maior
        (*lst) = novo;                                                  //novo->prox = busca->prox(null); novo->ant = busca; busca->prox = novo;
        return 1;
    }
    else{
        busca = *lst;

        while (busca->prox != NULL && busca->info < elemento)
            busca = busca->prox;

        novo->ant = busca->ant;
        novo->prox = busca;
        busca->ant->prox = novo;
        busca->ant = novo;

        return 1;
    }

}

int RemoveOrdenado (Lista** lst, int elemento){
    Lista* aux;

    if (ListaVazia(*lst) || elemento < (*lst)->info)
        return 0;

    aux = *lst;

    if (elemento == (*lst)->info){
        aux->prox->ant = NULL;
        *lst = aux->prox;
        free(aux);
        return 1;
    }
    else {
        while (aux->prox != NULL && aux->prox->info < elemento)
            aux = aux->prox;

        if (aux->prox == NULL || aux->prox->info > elemento)            //elemento nao esta na lista
            return 0;

        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        free(aux);
        return 1;
    }
}

int RemoveRepetidos (Lista** lst, int elemento){
    Lista* aux;

    if (ListaVazia(*lst) || elemento < (*lst)->info)
        return 0;

    aux = *lst;

    if (elemento == (*lst)->info){
        aux->prox->ant = NULL;
        *lst = aux->prox;
        free(aux);
        return 1;
    }
    else {
        while (aux->prox != NULL && aux->prox->info < elemento){
            aux = aux->prox;

            if (aux->prox == NULL || aux->prox->info > elemento)            //elemento nao esta na lista
                return 0;

            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
            free(aux);
        }

        return 1;
    }
}

int RemoveMaior (Lista** lst, int* elemento){
    Lista* aux;

    if (ListaVazia(*lst))
        return 0;

    aux = *lst;


    while (aux->prox != NULL)
        aux = aux->prox;

    *elemento = aux->info;
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;
    free(aux);
    return 1;

}

int Tamanho (Lista* lst){           //nao tem erro pra dar
    int i;

    for (i = 0; lst != NULL; i++)
        lst = lst->prox;

    return i;
}

float Media (Lista* lst){         //nao tem erro pra dar
    int acumula;
    int tam;
    int i;

    tam = Tamanho(lst);

    if (!tam)
        exit(1);

    acumula = 0;
    for (i = 0; lst->prox != NULL; i++)
        acumula += lst->info;

    return (float) acumula / tam;
}

int xor (int a, int b){
    return (a || b) && !(a && b);
}

int ListasIguais (Lista* lst1, Lista* lst2){
    int verif;
	int tam1;
	int tam2;

    verif = xor ((ListaVazia(lst1)), (ListaVazia(lst2)));       //se uma das listas for vazia e a outra nao, elas sao diferentes

    if (!verif){
        return 0;           //falha
    }


	tam1 = Tamanho(lst1);
	tam2 = Tamanho(lst2);

	if (tam1 != tam2)
		return 0;			//listas de tamanhos diferentes sao necessariamente diferentes

    verif = 1;
    while (lst1 != NULL){		//se as listas tem o msm tamanho, qd uma chegar em NULL a outra tbm chegara
        if (lst1->info != lst2->info)
            verif = 0;

        lst1 = lst1->prox;
        lst2 = lst2->prox;
    }

    return verif;       //1 -> listas iguais, 0 -> listas diferentes
}

int RemoveMultiplos (Lista** lst){
    Lista* aux;

    if (ListaVazia(*lst))
        return 0;

    aux = *lst;

    while (aux->prox != NULL){
        if (aux->info % 3 == 0){
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
            free(aux);
        }
        aux = aux->prox;
    }
    return 1;
}

void ImprimeLista (Lista* lst){

    while (lst != NULL){
        printf("%d\t", lst->info);
        lst = lst->prox;
    }
    printf("\n");
}

void EsvaziaLista (Lista** lst){
    Lista* busca;

    while (*lst != NULL){ //percorre e limpa todos os itens da lista, menos o primeiro
        busca = *lst;
        *lst = (*lst)->prox;
        free(busca);
    }

    *lst = NULL;
}
