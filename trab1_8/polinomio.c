#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomio.h"

struct no {
    int pot;                    //no nó cabeçalho serve como tam
    int coef;
    struct no* prox;
};

Lista* CriaLista(){
    Lista* cab;

    cab = (Lista*) malloc (sizeof(Lista));

    if (cab == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        exit(1);
    }

    else{
        cab->prox = NULL;
        cab->pot = 0;
    }

    return cab;
}

int ListaVazia (Lista* lst){

    if (lst->prox == NULL)
        return 1;
    else
        return 0;
}

int InsereElemento (Lista* lst, int potencia, int coeficiente){
    Lista* novo;
    Lista* aux;

    novo = (Lista*) malloc (sizeof(Lista));

    if (novo == NULL){
        printf("Erro de alocacao!\n");
        system("pause");
        return 0;       //exit(1);
    }

    novo->pot = potencia;
    novo->coef = coeficiente;

    aux = lst;

    while (aux->prox != NULL && aux->prox->pot <= potencia){
        aux = aux->prox;

        if (aux->pot == potencia){
            aux->coef = coeficiente + aux->coef;
        }
    }

    novo->prox = aux->prox;
    aux->prox = novo;
    lst->pot++;                         //tam!

    return 1;
}

int ObtemPosicao (Lista* lst, int pos, int* coeficiente, int* potencia){
    Lista* aux;
    int i;

    if (ListaVazia(lst))
        return 0;

    for (i = 0; i <= pos; i++)
        aux = aux->prox;

    if (aux == NULL)
        return 0;

    *coeficiente = aux->coef;
    *potencia = aux->pot;
    return 1;

}

int RemoveExpoente (Lista* lst, int pos){
    Lista* aux;
    Lista* aux2;
    int i;

    if (ListaVazia(lst))
        return 0;
    else {
        for (i = 0; i < pos; i++)
            aux = aux->prox;

        aux2 = aux->prox;
        aux->prox = aux2->prox;
        free(aux2);
        lst->pot--;

        return 1;
    }
}

int Somador (Lista* lst, int X, int* resultado){
    Lista* aux;
    int i;
    int soma;
    int acumulaSoma;

    if(ListaVazia(lst) == 1)
        return 0;

    aux = lst;
    acumulaSoma = 0;

    for (i = 0; i < lst->pot; i++)
    {
        soma = pow(X, aux->prox->pot) * aux->prox->coef;
        acumulaSoma += soma;
        aux = aux->prox;
    }

    *resultado = acumulaSoma;
    return 1;
}

void ImprimeLista (Lista* lst){
    int i;
    int coeficiente;
    int potencia;

    if (ListaVazia(lst))
        printf("Lista vazia!!\n");
    else{
        for (i = 0; ObtemPosicao (lst, i, &coeficiente, &potencia) != 0; i++){

            if (potencia == 0){
                if (coeficiente > 0)
                    printf("+%dx ", coeficiente);
                else
                    printf("%dx ", coeficiente);


            }
            else {
                if (coeficiente > 0)
                    printf("+%dx^%d ", coeficiente, potencia);
                else
                    printf("%dx^%d ", coeficiente, potencia);
            }
        }
    }

}

void LiberaLista (Lista** lst) {
    *lst = NULL;                            //se o ponteiro inicial eh nulo, a lista esta vazia.
}

void EsvaziaLista (Lista** lst){
    Lista* busca;

    while (*lst != NULL){ //percorre e limpa todos os itens da lista, menos o primeiro
        busca = *lst;
        *lst = (*lst)->prox;
        free(busca);
    }
}
