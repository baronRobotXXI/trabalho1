#include <stdio.h>
#include <stdlib.h>
#include "int_ord.h"

int main()
{
    Lista* lista;

    int opcao;
    int verif;
    int pos;
    int elemento;

    printf("Querido usuario, digite a opcao desejada:\n");
    printf("1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Verifica Lista Cheia\n4 - Inserir Elemento\n5 - Remover Elemento\n");
    printf("6 - Consulta elemento\n7 - Imprimir Lista\n8 - Liberar Lista\n");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 8){
        printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
        printf("1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Verifica Lista Cheia\n4 - Inserir Elemento\n5 - Remover Elemento\n");
        printf("6 - Consulta elemento\n7 - Imprimir Lista\n8 - Liberar Lista\n");
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

            verif = InsereOrdenado(lista, elemento);

            if (verif)
                printf("Elemento inserido com sucesso!\n");
            else
                printf("Nao foi possivel inserir o elemento!\n");
            break;

        case 5:
            printf("Digite o elemento a ser removido:\n");
            scanf("%d", &elemento);

            verif = RemoveOrdenado (lista, elemento);

            if (verif)
                printf("Elemento removido com sucesso!\n");
            else
                printf("Nao foi possivel remover o elemento!\n");
            break;

        case 6:
            printf("Digite a posicao do elemento a consultar:\n");
            scanf("%d", &pos);

            verif = ObtemValorElemento (lista, pos, &elemento);

            if (verif)
                printf("O elemento na posicao %d eh %d.\n", pos, elemento);
            else
                printf("Nao foi possivel encontrar o elemento!\n");
            break;

        case 7:
            ImprimeLista(lista);
            break;

        case 8:
            LiberaLista(&lista);
            break;

        }

        printf("Querido usuario, digite a opcao desejada:\n");
        printf("0 - Encerrar Programa\n1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Verifica Lista Cheia\n4 - Inserir Elemento\n5 - Remover Elemento\n");
        printf("6 - Consulta elemento\n7 - Imprimir Lista\n8 - Liberar Lista\n");
        scanf("%d", &opcao);

        while (opcao < 0 || opcao > 8){
            printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
            printf("0 - Encerrar Programa\n1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Verifica Lista Cheia\n4 - Inserir Elemento\n5 - Remover Elemento\n");
            printf("6 - Consulta elemento\n7 - Imprimir Lista\n8 - Liberar Lista\n");
            scanf("%d", &opcao);
        }

    }
    return 0;
}
