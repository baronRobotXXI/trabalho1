#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Soldados.h"

/*
    A estrutura de representação da lista de soldados é representada por:

    Nó cabeçalho que armazena a quantidade de soldados (SIZE),
    (A quantidade de elementos é importante para saber a range ideal de valores
    para gerar o número aleatório o qual indicará qual soldado excluir).

    e o endereço do último no (ULT) de uma lista circular,
    ( facilitando o percorrimento circular da lista, a inserção no final,
    e acesso direto ao último elemento)
*/

struct no {
    char info[20];
    struct no* prox;
};

struct cab {
    int tam;
    struct no* ultimo;
};

Soldados* CriaLista (){
	Soldados* cab;

	cab = (Soldados*) malloc (sizeof(Soldados));

	if (cab != NULL){
		cab->tam = 0;
		cab->ultimo = NULL;
	}
	return cab;

}

int ListaVazia(Soldados* cab){
    if (cab->tam == 0)
        return 1;
    else
        return 0;
}

int InsereFinal (Soldados* cab, char* nome){
	Lista* novo;

	if (cab == NULL)
		return 0;

	else{
		novo = (Lista*) malloc (sizeof(Lista));

		if (novo == NULL){
			printf("Erro de alocacao!\n");
			system("pause");
			return 0;       //exit(1);
		}

		strcpy(novo->info, nome);

		if (ListaVazia(cab))
			novo->prox = novo;		//lista circular

		else {
			novo->prox = cab->ultimo->prox;
			cab->ultimo->prox = novo;
		}

		cab->ultimo = novo;
		cab->tam++;

		return 1;

	}
}

/*
    Considerando o valor mínimo de pessoas igual a 2
    &&
    Considerando o valor mínimo de N igual a 2, e o máximo de N igual ao número de pessoas -> N = qtde
*/

int Josephus (Lista* aux, Soldados** cab, int* qtde){
	Soldados* cab2;
	Soldados* cab3;
	int i;
	int j;
	Lista* local;

	if (cab == NULL || ListaVazia(*cab) || (*cab)->tam < 2)		//nao ha escolha a ser feita caso haja menos de 2 soldados
		return 0;

	srand(time(NULL));
	*qtde = rand() % ((*cab)->tam-1);

	cab2 = CriaLista();		//main?

	if (cab2 == NULL){
		printf("Erro de alocacao!\n");
		system("pause");
		return 0;       //exit(1);
	}

	for (i = 0; i < (*cab)->tam; i++){
		for (j = 0; j < *qtde; j++)
			aux = aux->prox;

		local = aux->prox;

		if (!(InsereFinal (cab2, local->info)))		//se a insercao do soldado sorteado for malsucedida
			return 0;

		aux->prox = local->prox;
		aux = local->prox;                      //remove o elemento desejado
		free(local);

	}

	cab3 = cab2;
	(*cab)->ultimo = cab3->ultimo;
	free(cab3);
	*qtde += 2;

	return 1;

}

int ContaInicio (Soldados* cab, int* elemento){
	return Josephus(cab->ultimo->prox, &cab, elemento);
}

int ContaAleatorio (Soldados* cab, int* elemento, char* nome){
	int indice;
	Lista* inicio;
	int i;

	srand(time(NULL));

	inicio = cab->ultimo->prox;
	indice = rand() % cab->tam;

	for (i = 0; i < indice; i++)
		inicio = inicio->prox;

	strcpy(nome, inicio->info);

	return Josephus(inicio, &cab, elemento);
}

int ContaNome (Soldados* cab, int* elemento, char* nome){
	int indice;
	Lista* inicio;
	int i;

	if (!(VerificaNome(cab, &indice, nome)))
		return 0;

	inicio = cab->ultimo->prox;

	for (i = 0; i < indice; i++)
		inicio = inicio->prox;

	return Josephus(inicio, &cab, elemento);
}

int ObtemElemento (Soldados* cab, int pos, char* nome){
	int i;
	Lista* aux;

	if (ListaVazia(cab) || pos < 0 || pos >= cab->tam)
		return 0;

	aux = cab->ultimo->prox;

	for (i = 0; i < pos; i++)
		aux = aux->prox;

	strcpy (nome, aux->info);
	return 1;
}

int UltimoElemento (Soldados* cab, char* nome){

    if(cab == NULL || ListaVazia(cab))
        return 0;

    strcpy(nome, cab->ultimo->info);
    return 1;
}

int VerificaNome (Soldados* cab, int* indice, char* nome){
	int i;
	Lista* aux;

    if(cab == NULL)
        return 0;

    aux = cab->ultimo->prox;

    for(i = 0; strcmp(nome,aux->info); i++){
        aux = aux->prox;

        if(aux == cab->ultimo->prox)
            return 0;
    }

    *indice = i;
    return 1;
}

void ImprimeLista (Soldados* lst, int elemento, int fim){
    int i;
    char nome[20];

    printf("O numero sorteado foi %d\n", elemento);
    printf("Soldados mortos: ");

    for (i = 0; i < fim-1; i++){
        ObtemElemento(lst, i, nome);
        printf("%s ", nome);
    }

    ObtemElemento(lst, fim, nome);                                                  //na intencao de chamar o último
    printf("O soldade sobrevivente foi %s\n", nome);
}

void LiberaLista (Soldados** cab){
    Lista* aux;
    Lista* aux2;

    aux = (*cab)->ultimo->prox;

    while(1){                                   //refazer cond de parada. Onde a lista começa? Pegar o ->ultimo

        if(aux == (*cab)->ultimo){
            free(aux);
            break;
        }

        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*cab);
}
