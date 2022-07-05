#include <stdio.h>
#include <stdlib.h>
#include "int_est.h"
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

int InsereElemento (Lista* lst, int elem){      //insere no final

    if (lst == NULL || (ListaCheia(lst)))
        return 0;           //falha
    else{
        lst->info[lst->fim] = elem;
        lst->fim++;
        return 1;           //sucesso
    }
}

int RemoveElemento (Lista* lst, int elem){
    int i;
    int j;

    if (lst == NULL || ListaVazia(lst)){
        return 0;           //falha
    }
    else {
        for (j = 0; j < lst->fim && lst->info[j] != elem; j++);

        if (j == lst->fim)
            return 0;

        for (i = j+1; i < (lst->fim); i++)
            lst->info[i-1] = lst->info[i];

        lst->fim--;

        return 1;
    }

}

int RemoveImpares (Lista* lst){
    int i;
    int j;

    if(ListaVazia(lst)|| lst == NULL)
        return 0;

    for(i=0; i < lst->fim; i++){                        //percorre a lista
        if(lst->info[i] %2 == 1){                       //testa se o elemento em questao eh impar
            for (j = i+1; j < lst->fim; j++)            //caso seja, desloca
                lst->info[j-1] = lst->info[j];

            i--;
            lst->fim--;
        }
    }

    return 1;
}

int Menor (Lista* lst, int *elem){
    int menor;
    int i;

    if(lst == NULL || ListaVazia(lst))
        return 0;

    menor = lst->info[0];

    for (i = 0; i < lst->fim; i++){
        if (lst->info[i] < menor)
            menor = lst->info[i];
        }

    *elem = menor;

    return 1;
}

int OrdenaLista (Lista* lst){
    int aux;
    int i;
    int j;
    int n;

    if (ListaVazia(lst) || lst == NULL)
        return 0;

    n = lst->fim;       //apenas por preguica de digitar lst->fim td vez

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (lst->info[i] < lst->info[j]){

                aux = lst->info[j];
                lst->info[j] = lst->info[i];
                lst->info[i] = aux;
            }
        }
    }

    return 1;
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

int Tamanho (Lista* lst, int* tam){
    if (lst == NULL || (ListaVazia(lst)))
        return 0;

    else{
        *tam = lst->fim;
        return 1;
    }
}

int Concatena (Lista* lst1, Lista* lst2, Lista* lst3){
    int tam1;
    int tam2;
    int verif;
    int acumulaTam;
    int i;
    int j;

    verif = Tamanho(lst1, &tam1);

    acumulaTam = tam1;

    verif = Tamanho(lst2, &tam2);

    acumulaTam += tam2;

    if (acumulaTam > TAM)
        return 0;           //nao sera possivel criar uma nova lista de tamanho maior que o maximo
    else{
        for (i = 0; i < tam1; i++)
            verif = InsereElemento (lst3, lst1->info[i]);

        for (j = 0; i < acumulaTam; j++){
            verif = InsereElemento (lst3, lst2->info[j]);
            i++;
        }

    }

    return 1;

}

void ImprimeLista (Lista* lst){
    int i;
    int tam;
    int verif;

    verif = Tamanho(lst, &tam);

    for (i = 0; i < tam; i++)
        printf("%d\t", lst->info[i]);

    printf("\n");

}

void LiberaLista (Lista** lst){
    free(*lst);
}
