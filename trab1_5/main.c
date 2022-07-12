#include <stdio.h>
#include <stdlib.h>
#include "circular_nord.h"

int main()
{
    Lista* lista;
    Lista* lista2;

    int opcao;
    int verif;
    int pos;
    int elemento;
    int tam;

    printf("Querido usuario, digite a opcao desejada:\n");
    printf("1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Inserir Elemento no Final\n4 - Inserir Elemento no Inicio\n");
    printf("5 - Inserir Elemento na Posicao Desejada\n6 - Consulta Elemento\n7 - Remover Elemento no Inicio\n8 - Remover Elemento na Posicao Desejada\n");
    printf("9 - Tamanho Lista\n10 - Apenas os impares da lista informada\n11 - Maior Elemento da Lista\n12 - Imprimir Lista\n13 - Liberar Lista\n");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 13){
        printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
        printf("1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Inserir Elemento no Final\n4 - Inserir Elemento no Inicio\n");
        printf("5 - Inserir Elemento na Posicao Desejada\n6 - Consulta Elemento\n7 - Remover Elemento no Inicio\n8 - Remover Elemento na Posicao Desejada\n");
        printf("9 - Tamanho Lista\n10 - Apenas os impares da lista informada\n11 - Maior Elemento da Lista\n12 - Imprimir Lista\n13 - Liberar Lista\n");
        scanf("%d", &opcao);
    }

    while (opcao != 0){
        switch (opcao){

        case 1:
            lista = CriaLista();
            lista2 = CriaLista();

            break;

        case 2:
            if (ListaVazia(lista))
                printf("Lista Vazia!\n");
            else
                printf("A lista nao esta vazia!\n");
            break;

        case 3:
            printf("Digite o elemento a ser inserido (final):\n");
            scanf("%d", &elemento);

            verif = InsereFinal(&lista, elemento);

            if (verif)
                printf("Elemento inserido com sucesso!\n");
            else
                printf("Nao foi possivel inserir o elemento!\n");
            break;

        case 4:
            printf("Digite o elemento a ser inserido (inicio):\n");
            scanf("%d", &elemento);

            verif = InsereInicio(&lista, elemento);

            if (verif)
                printf("Elemento inserido com sucesso!\n");


            else
                printf("Nao foi possivel inserir o elemento!\n");
            break;

        case 5:
            verif = TamanhoLista(lista, &tam);

            printf("Digite a posicao onde o elemento sera inserido:\n");
            scanf("%d", &pos);

            while (pos < 0 || pos > tam){
                printf("Posicao invalida!! Digite a posicao em que o elemento sera inserido:\n");
                scanf("%d", &pos);
            }

            printf("Digite o elemento a ser inserido:\n");
            scanf("%d", &elemento);

            verif = InserePosicao(&lista, pos, elemento);

            if (verif)
                printf("Elemento inserido com sucesso!\n");
            else
                printf("Nao foi possivel inserir o elemento!\n");
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
            verif = RemoveInicio (&lista, &elemento);

            if (verif)
                printf("Elemento removido com sucesso!\nO elemento removido foi: %d\n", elemento);
            else
                printf("Nao foi possivel remover o elemento!\n");
            break;

        case 8:
            printf("Digite a posicao onde o elemento sera removido:\n");
            scanf("%d", &pos);

            TamanhoLista(lista, &tam);

            while (pos < 0 || pos > tam){
                printf("Posicao invalida!! Digite a posicao em que o elemento sera removido:\n");
                scanf("%d", &pos);
            }

            verif = RemovePosicao(&lista, pos, &elemento);

            if (verif)
                printf("Elemento removido com sucesso!\nO elemento removido foi: %d\n", elemento);
            else
                printf("Nao foi possivel remover o elemento!\n");

            break;

        case 9:
            verif = TamanhoLista(lista, &tam);
            printf("O tamanho da lista eh: %d\n", tam);

            break;

        case 10:
            verif = ApenasImpares (lista, &lista2);

            printf("A nova lista apenas com os impares eh:\n");
            ImprimeLista(lista2);

            break;

        case 11:
            verif = Maior (lista, &elemento);
            printf("O maior elemento da lista eh: %d\n", elemento);

            break;

        case 12:
            printf("\nOs elementos da lista sao:\n");
            ImprimeLista(lista);
            break;

        case 13:
            LiberaLista(&lista);
            break;

        }//fim do switch

        printf("Querido usuario, digite a opcao desejada:\n");
        printf("0 - Encerrar Programa\n1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Inserir Elemento no Final\n4 - Inserir Elemento no Inicio\n");
        printf("5 - Inserir Elemento na Posicao Desejada\n6 - Consulta Elemento\n7 - Remover Elemento no Inicio\n8 - Remover Elemento na Posicao Desejada\n");
        printf("9 - Tamanho Lista\n10 - Apenas os impares da lista informada\n11 - Maior Elemento da Lista\n12 - Imprimir Lista\n13 - Liberar Lista\n");
        scanf("%d", &opcao);

        while (opcao < 0 || opcao > 13){
            printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
            printf("0 - Encerrar Programa\n1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Inserir Elemento no Final\n4 - Inserir Elemento no Inicio\n");
            printf("5 - Inserir Elemento na Posicao Desejada\n6 - Consulta Elemento\n7 - Remover Elemento no Inicio\n8 - Remover Elemento na Posicao Desejada\n");
            printf("9 - Tamanho Lista\n10 - Apenas os impares da lista informada\n11 - Maior Elemento da Lista\n12 - Imprimir Lista\n13 - Liberar Lista\n");
            scanf("%d", &opcao);
        }

    }//fim while

    return 0;
}//fim main
