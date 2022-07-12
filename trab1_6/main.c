#include <stdio.h>
#include <stdlib.h>
#include "dupla.h"

int main()
{
    Lista* lista;
    Lista* lista2;

    int opcao;
    int verif;
    int i;
    int elemento;
    int tam;
    float media;
    //int resulta;

    printf("Querido usuario, digite a opcao desejada:\n");
    printf("0 - Encerrar Programa:\n");
    printf("1 - Inicializar Lista\n");
    printf("2 - Verifica Lista Vazia\n");
    printf("3 - Inserir Elemento\n");
    printf("4 - Remover Elemento\n");
    printf("5 - Remove Ocorrencias do Elemento\n");
    printf("6 - Remove Multiplos de 3\n");
    printf("7 - Remove Maior\n");
    printf("8 - Tamanho da Lista\n");
    printf("9 - Media dos Elementos da Lista\n");
    printf("10 - Verifica se Duas Listas Sao Iguais\n");
    printf("11 - Imprime Lista\n");
    printf("12 - Limpa Lista\n");
    scanf("%d", &opcao);

    if (opcao == 0)
        return 0;       //encerra

    while (opcao < 0 || opcao > 12){
        printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
        printf("0 - Encerrar Programa:\n");
        printf("1 - Inicializar Lista\n");
        printf("2 - Verifica Lista Vazia\n");
        printf("3 - Inserir Elemento\n");
        printf("4 - Remover Elemento\n");
        printf("5 - Remove Ocorrencias do Elemento\n");
        printf("6 - Remove Multiplos de 3");
        printf("7 - Remove Maior\n");
        printf("8 - Tamanho da Lista\n");
        printf("9 - Media dos Elementos da Lista\n");
        printf("10 - Verifica se Duas Listas Sao Iguais\n");
        printf("11 - Imprime Lista\n");
        printf("12 - Limpa Lista\n");
        scanf("%d", &opcao);
    }

    while (opcao != 0){
        switch (opcao){

        case 1:
            lista = CriaLista();
            lista2 = CriaLista();

            break;

        case 2:
            verif = ListaVazia(lista);

            if (verif)
                printf("Lista vazia!!\n");
            else
                printf("Lista tem elementos!\n");
            break;

        case 3:
            printf("Digite o elemento a ser inserido: \n");
            scanf("%d", &elemento);

            verif = InsereOrdenado(&lista, elemento);

            if (verif)
                printf("Elemento inserido com sucesso!!\n");
            else
                printf("Falha ao inserir elemento!\n");
            break;

        case 4:
            printf("Digite o elemento a ser removido:\n");
            scanf("%d", &elemento);

            verif = RemoveOrdenado(&lista, elemento);

            if (verif)
                printf("Elemento removido com sucesso!!\n");
            else
                printf("Falha ao remover elemento!\n");

            break;

        case 5:
            printf("Digite o elemento a ser removido:\n");
            scanf("%d", &elemento);

            verif = RemoveRepetidos(&lista, elemento);

            if (verif)
                printf("Elemento removido com sucesso!!\n");
            else
                printf("Falha ao remover elemento!\n");
            break;

        case 6:
            verif = RemoveMultiplos(&lista);

            if (verif){
                printf("A lista sem os multiplos de 3 sera\n:");
                ImprimeLista(lista);
            }
            else
                printf("Erro ao remover!\n");

            break;

        case 7:
            verif = RemoveMaior(&lista, &elemento);

            if (verif)
                printf("O maior elemento da lista foi removido!\nValor: %d\n", elemento);
            else
                printf("Erro ao remover!\n");

            break;

        case 8:
            tam = Tamanho(lista);
            printf("A lista tem tamanho %d\n", tam);

            break;

        case 9:
            media = Media(lista);
            printf("A media dos elementos da lista eh %f:", media);

            break;

        case 10:
            printf("Digite os elementos da lista para intercalacao:\n");
                do {
                    scanf("%d", &elemento);
                    verif = InsereOrdenado(&lista2, elemento);

                    if (!verif)
                        return 1;

                    printf("Digite: \n0 - Encerrar insercao\n1 - Continuar insercao\n");
                    scanf("%d", &opcao);
                }while(opcao != 0);

                verif = ListasIguais(lista, lista2); //0 - diferentes, 1 - iguais

                if (verif)
                    printf("Listas iguais!\n");
                else
                    printf("Listas diferentes!\n");

                break;

        case 11:
            printf("Os elementos da lista sao:\n");
            ImprimeLista(lista);

            break;

        case 12:
            EsvaziaLista(&lista);

        }

        printf("Querido usuario, digite a opcao desejada:\n");
        printf("0 - Encerrar Programa:\n");
        printf("1 - Inicializar Lista\n");
        printf("2 - Verifica Lista Vazia\n");
        printf("3 - Inserir Elemento\n");
        printf("4 - Remover Elemento\n");
        printf("5 - Remove Ocorrencias do Elemento\n");
        printf("6 - Remove Multiplos de 3");
        printf("7 - Remove Maior\n");
        printf("8 - Tamanho da Lista\n");
        printf("9 - Media dos Elementos da Lista\n");
        printf("10 - Verifica se Duas Listas Sao Iguais\n");
        printf("11 - Imprime Lista\n");
        printf("12 - Limpa Lista\n");
        scanf("%d", &opcao);

        while (opcao < 0 || opcao > 12){
            printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
            printf("0 - Encerrar Programa:\n");
            printf("1 - Inicializar Lista\n");
            printf("2 - Verifica Lista Vazia\n");
            printf("3 - Inserir Elemento\n");
            printf("4 - Remover Elemento\n");
            printf("5 - Remove Ocorrencias do Elemento\n");
            printf("6 - Remove Multiplos de 3");
            printf("7 - Remove Maior\n");
            printf("8 - Tamanho da Lista\n");
            printf("9 - Media dos Elementos da Lista\n");
            printf("10 - Verifica se Duas Listas Sao Iguais\n");
            printf("11 - Imprime Lista\n");
            printf("12 - Limpa Lista\n");
            scanf("%d", &opcao);
        }

    }

    EsvaziaLista(&lista);
    EsvaziaLista(&lista2);

    return 0;
}
