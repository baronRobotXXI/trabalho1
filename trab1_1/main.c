#include <stdio.h>
#include <stdlib.h>
#include "int_est.h"

int main()
{
    Lista* lista;
    Lista* lista2;
    Lista* lista3;
    int opcao;
    int verif;
    int pos;
    int elemento;

    printf("Querido usuario, digite a opcao desejada:\n");
    printf("1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Verifica Lista Cheia\n4 - Inserir Elemento\n5 - Remover Elemento\n");
    printf("6 - Remove Impares\n7 - Menor elemento da lista\n8 - Ordena a Lista\n9 - Tamanho da Lista\n10 - Concatena Listas\n");
    printf("11 - Consulta elemento\n12 - Imprimir Lista\n13 - Liberar Lista\n");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 13){
        printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
        printf("1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Verifica Lista Cheia\n4 - Inserir Elemento\n5 - Remover Elemento\n");
        printf("6 - Remove Impares\n7 - Menor elemento da lista\n8 - Ordena a Lista\n9 - Tamanho da Lista\n10 - Concatena Listas\n");
        printf("11 - Consulta elemento\n12 - Imprimir Lista\n13 - Liberar Lista\n");
        scanf("%d", &opcao);
    }

    while (opcao != 0){
        switch (opcao){

        case 1:
            lista = CriaLista();
            break;

        case 2:
            if (ListaVazia(lista))
                printf("Lista Vazia!\n");
            else
                printf("A lista nao esta vazia!\n");
            break;

        case 3:
            if (ListaCheia(lista))
                printf("Lista Cheia!\n");
            else
                printf("A lista nao esta cheia!\n");
            break;

        case 4:
            printf("Digite o elemento a ser inserido:\n");
            scanf("%d", &elemento);

            verif = InsereElemento(lista, elemento);

            if (verif)
                printf("Elemento inserido com sucesso!\n");
            else
                printf("Nao foi possivel inserir o elemento!\n");
            break;

        case 5:
            printf("Digite o elemento a ser removido:\n");
            scanf("%d", &elemento);

            verif = RemoveElemento (lista, elemento);

            if (verif)
                printf("Elemento removido com sucesso!\n");
            else
                printf("Nao foi possivel remover o elemento!\n");
            break;

        case 6:
            verif = RemoveImpares(lista);

            printf("A lista sem os impares eh: \n");
            ImprimeLista(lista);

            break;

        case 7:
            verif = Menor(lista, &elemento);
            printf("O menor elemento da lista eh: %d\n", elemento);

            break;

        case 8:
            verif = OrdenaLista(lista);

            printf("A lista ordenada eh: \n");
            ImprimeLista(lista);

            break;

        case 9:
            verif = Tamanho(lista, &elemento);

            printf("O tamanho da lista eh: %d\n", elemento);
            break;

        case 10:
            lista2 = CriaLista();
            lista3 = CriaLista();

            opcao = 1;

            printf("Digite os elementos da nova lista:\n");
            while (opcao != 0){
                scanf("%d", &elemento);
                verif = InsereElemento(lista2, elemento);

                printf("Continuar insercao?\n0 - nao 1 - sim\n");
                scanf("%d", &opcao);
            }

            verif = Concatena(lista, lista2, lista3);

            printf("A lista concatenada sera:\n");
            ImprimeLista(lista3);

            break;

        case 11:
            printf("Digite a posicao do elemento a consultar:\n");
            scanf("%d", &pos);

            verif = ObtemValorElemento (lista, pos, &elemento);

            if (verif)
                printf("O elemento na posicao %d eh %d.\n", pos, elemento);
            else
                printf("Nao foi possivel encontrar o elemento!\n");
            break;

        case 12:
            printf("A lista informada eh:\n");
            ImprimeLista(lista);
            break;

        case 13:
            LiberaLista(&lista);
            LiberaLista(&lista2);
            LiberaLista(&lista3);
            break;

        }

        printf("Querido usuario, digite a opcao desejada:\n");
        printf("0 - Encerrar Programa\n1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Verifica Lista Cheia\n4 - Inserir Elemento\n5 - Remover Elemento\n");
        printf("6 - Remove Impares\n7 - Menor elemento da lista\n8 - Ordena a Lista\n9 - Tamanho da Lista\n10 - Concatena Listas\n");
        printf("11 - Consulta elemento\n12 - Imprimir Lista\n13 - Liberar Lista\n");
        scanf("%d", &opcao);

        while (opcao < 0 || opcao > 13){
            printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
            printf("0 - Encerrar Programa\n1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Verifica Lista Cheia\n4 - Inserir Elemento\n5 - Remover Elemento\n");
            printf("6 - Remove Impares\n7 - Menor elemento da lista\n8 - Ordena a Lista\n9 - Tamanho da Lista\n10 - Concatena Listas\n");
            printf("11 - Consulta elemento\n12 - Imprimir Lista\n13 - Liberar Lista\n");
            scanf("%d", &opcao);
        }

    }
    return 0;
}
