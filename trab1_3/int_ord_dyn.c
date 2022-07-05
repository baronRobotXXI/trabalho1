#include <stdio.h>
#include <stdlib.h>
#include "int_ord_dyn.h"

struct no {
    int info;
    struct no* prox;
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

int InsereElemento (Lista** lst, int elemento){     //insere no inicio
    Lista* novo;

    novo = (Lista*) malloc (sizeof(Lista));

    if (novo == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        return 0;       //exit(1);
    }

    novo->info = elemento;
    novo->prox = *lst;
    *lst = novo;

    return 1;       //sucesso
}

int InsereOrdenado (Lista** lst, int elemento){
    Lista* novo;
    Lista* busca;

    novo = (Lista*) malloc(sizeof(Lista));
    novo->prox = NULL;

    if (novo == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        exit(1);
    }

    else
        novo->info = elemento;

    if (ListaVazia(*lst) || elemento <= (*lst)->info){ //insere no inicio

        novo->prox = *lst;
        (*lst) = novo;
        return 1;
    }
    else{
        busca = *lst;

        while (busca->prox != NULL && busca->prox->info < elemento)
            busca = busca->prox;

        novo->prox = busca->prox;
        busca->prox = novo;
        return 1;
    }

}

int RemoveOrdenado (Lista** lst, int elemento){
    Lista* aux;
    Lista* aux2;

    if (ListaVazia(*lst) || elemento < (*lst)->info)
        return 0;

    aux = *lst;

    if (elemento == (*lst)->info){
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    while (aux->prox != NULL && aux->prox->info < elemento)
        aux = aux->prox;

    if (aux->prox == NULL || aux->prox->info > elemento)
        return 0;

    aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;

}

int ObtemValorElemento (Lista* lst, int pos, int* elemento){
    int i;
    int tam;
    int verif;

    verif = TamanhoLista(lst, &tam);

    if (!(verif) || pos > tam)
        return 0;

    for (i = 0; i < pos; i++){
        lst = lst->prox;
    }

    *elemento = lst->info;
    return 1;
}

int TamanhoLista (Lista* lst, int* tam){
    int i;

    if (ListaVazia(lst))
        return 0;
    else
        for (i = 0; lst != NULL; i++)
            lst = lst->prox;

    (*tam) = i;
        return 1;
}

int Media (Lista* lst, float* media){
    int acumulador;
    int i;

    if (ListaVazia(lst))
        return 0;               //falha

    acumulador = 0;
    for (i = 0; lst != NULL; ++i){
        acumulador += lst->info;
        lst = lst->prox;
    }

    (*media) = (float) acumulador / i;
    return 1;                   //sucesso
}

int xor (int a, int b){
    return (a || b) && !(a && b);
}

int ListasIguais (Lista* lst1, Lista* lst2){
    int verif;
	int tam1;
	int tam2;

    verif = xor ((ListaVazia(lst1)), (ListaVazia(lst2)));       //se uma das listas for vazia e a outra nao, elas sao diferentes

    if (!verif)
        return 0;           //falha

	verif = TamanhoLista(lst1, &tam1);
	verif = TamanhoLista(lst2, &tam2);

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

void IntercalaListas (Lista* lst1, Lista* lst2, Lista** lst3){
	int tam;
	int tam1;
	int tam2;
	int i;
	int verif;

    verif = (TamanhoLista(lst1, &tam1));
    tam = tam1;

    verif = (TamanhoLista(lst2, &tam2));
    tam += tam2;

    (*lst3) = NULL;

    for (i = 0; i < tam1 ; i++){
        verif = InsereOrdenado(&(*lst3), lst1->info);
        lst1 = lst1->prox;
    }

    for (; i < tam; i++){
        verif = InsereOrdenado(&(*lst3), lst2->info);
        lst2 = lst2->prox;
    }
}

int InverteLista (Lista* lst1, Lista** lst2){
    int i;
    int tam;
    int verif;
    int temp;

    verif = TamanhoLista(lst1, &tam);

    if (ListaVazia(lst1))
        return 0;

    for (i = 0; i < tam; i++){
        verif = ObtemValorElemento(lst1, i, &temp);
        verif = InsereElemento(&(*lst2), temp);
    }

    return 1;
}

int ApenasImpares (Lista* lst1, Lista** lst2){
    int tam;
    int i;
    int verif;

    if (ListaVazia(lst1))
        return 0;

    for (i = 0; lst1 != NULL; i++){
        if (lst1->info % 2 == 1){
            verif = InsereElemento(lst2, lst1->info);

            if (!verif)
                return 0;


        }
        lst1 = lst1->prox;
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

void LiberaLista (Lista** pLst) {
    *pLst = NULL;                            //se o ponteiro inicial eh nulo, a lista esta vazia.
}

void EsvaziaLista (Lista** pLst){
    Lista* busca;

    while (*pLst != NULL){ //percorre e limpa todos os itens da lista, menos o primeiro
        busca = *pLst;
        *pLst = (*pLst)->prox;
        free(busca);
    }
}
