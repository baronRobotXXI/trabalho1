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

    if (lst == NULL || ListaCheia(lst))         //anteriormente lst->fim >= TAM, só pra usar o ListaCheia
        return 0;           //falha
    else{
        if (ListaVazia(lst) || elem >= lst->info[(lst->fim) - 1])           //lista vazia ou elemento maior que o ultimo - insere no final
            lst->info[lst->fim] = elem;

        else{
            for (j = 0; elem >= lst->info[j]; j++);    //percorrimento

            for (i = lst->fim; i > j; i--)              //deslocamento
                lst->info[i] = lst->info[i-1];

            lst->info[j] = elem;                    //inserção
        }
            lst->fim++;
            return 1;
    }

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

    for(i = 0; i < lst->fim; i++){                        //percorre a lista
        if(lst->info[i] %2 == 1){                       //testa se o elemento em questao eh impar
            for (j = i+1; j < lst->fim; j++)            //caso seja, desloca
                lst->info[j-1] = lst->info[j];

            i--;
            lst->fim--;
        }
    }

    return 1;
}

int Menor (Lista* lst, int* elemento){

    if (ListaVazia(lst) || lst == NULL)
        return 0;
    else{
        *elemento = lst->info[0];        //numa lista ordenada o menor elemento eh sempre o primeiro
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

int Tamanho (Lista* lst, int* tam){
    if (lst == NULL)
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
            verif = InsereElemento (lst3, lst2->info[j]);       //admitindo que aqui se
            i++;
        }

    }

    return 1;
}

void ImprimeLista (Lista* lst){
    int i;

    printf("Os elementos da lista sao:\n");
    for (i = 0; i <= (lst->fim)-1; i++)
        printf("%d\t", lst->info[i]);

    printf("\n");
}

void LiberaLista (Lista* lst){
    if (lst != NULL)
        lst->fim = 0;

        free (&lst);
}
