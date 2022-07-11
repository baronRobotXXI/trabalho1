#include <stdio.h>
#include <stdlib.h>
#include "int_ord_cab.h"

int main()
{
    Lista* lista;
    Lista* lista2;
    Lista* lista3;

    int opcao;
    int verif;
    int pos;
    int elemento;
    int tam;
    float media;

    printf("Querido usuario, digite a opcao desejada:\n");
    printf("1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Inserir Elemento\n4 - Remover Elemento\n");
    printf("5 - Consulta elemento\n6 - Media dos elementos da lista\n7 - Verificar se 2 listas sao iguais\n8 - Intercala listas\n");
    printf("9 - Inverte lista\n10 - Apenas os impares da lista informada\n11 - Tamanho Lista\n12 - Imprimir Lista\n13 - Liberar Lista\n");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 14){
        printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
        printf("1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Inserir Elemento\n4 - Remover Elemento\n");
        printf("5 - Consulta elemento\n6 - Media dos elementos da lista\n7 - Verificar se 2 listas sao iguais\n8 - Intercala listas\n");
        printf("9 - Inverte lista\n10 - Apenas os impares da lista informada\n11 - Tamanho Lista\n12 - Imprimir Lista\n13 - Liberar Lista\n");
        scanf("%d", &opcao);
    }

    while (opcao != 0){
        switch (opcao){

        case 1:
            lista = CriaLista();
            lista2 = CriaLista();
            lista3 = CriaLista();

            break;

        case 2:
            if (ListaVazia(lista))
                printf("Lista Vazia!\n");
            else
                printf("A lista nao esta vazia!\n");
            break;

        case 3:
            printf("Digite o elemento a ser inserido:\n");
            scanf("%d", &elemento);

            verif = InsereOrdenado(lista, elemento);

            if (verif)
                printf("Elemento inserido com sucesso!\n");
            else
                printf("Nao foi possivel inserir o elemento!\n");
            break;

        case 4:
            printf("Digite o elemento a ser removido:\n");
            scanf("%d", &elemento);

            verif = RemoveOrdenado (lista, elemento);

            if (verif)
                printf("Elemento removido com sucesso!\n");
            else
                printf("Nao foi possivel remover o elemento!\n");
            break;

        case 5:
            printf("Digite a posicao do elemento a consultar:\n");
            scanf("%d", &pos);

            verif = ObtemValorElemento (lista, pos, &elemento);

            if (verif)
                printf("O elemento na posicao %d eh %d.\n", pos, elemento);
            else
                printf("Nao foi possivel encontrar o elemento!\n");
            break;

        case 6:
            verif = Media(lista, &media);

            if (verif)
                printf("A media dos elementos da lista eh: %.4f\n", media);
            else
                printf("Nao foi possivel calcular a media dos elementos da lista!\n");

            break;

        case 7:
            printf("Digite os elementos da lista de comparacao:\n");
            do {
                scanf("%d", &elemento);
                verif = InsereOrdenado(lista2, elemento);

                printf("Digite:\n0 - Encerrar insercao\n1- Continuar insercao\n");
                scanf("%d", &opcao);
            }while (opcao != 0);

            ImprimeLista(lista);
            ImprimeLista(lista2);

            verif = ListasIguais(lista,lista2);

            if (verif)
                printf("\nListas iguais!\n");
            else
                printf("\nLista diferentes!\n");
            break;

        case 8:
            printf("As listas ja estao criadas?\n1 - sim\t0 - nao\n");
            scanf("%d", &verif);

            if (verif)
                IntercalaListas(lista, lista2, lista3);

            else{
                printf("Digite os elementos da lista para intercalacao:\n");
                do {
                    scanf("%d", &elemento);
                    verif = InsereOrdenado(lista2, elemento);

                    printf("Elementos lista 2:\n");
                    ImprimeLista(lista2);

                    printf("Digite: \n0 - Encerrar insercao\n1 - Continuar insercao\n");
                    scanf("%d", &opcao);
                }while(opcao != 0);



                IntercalaListas(lista, lista2, lista3);

            }

                printf("A nova lista intercalada sera: \n");
                ImprimeLista (lista3);

                break;

        case 9:
            verif = InverteLista(lista, &lista3);

            printf("A lista invertida sera: \n");
            ImprimeLista(lista3);

            break;

        case 10:
            verif = ApenasImpares (lista, lista3);

            printf("A nova lista apenas com os impares da lista anterior eh:\n");
            ImprimeLista(lista3);

            break;

        case 11:
            tam = TamanhoLista(lista);
            printf("O tamanho da lista eh: %d\n", tam);
            break;

        case 12:
            printf("\nOs elementos da lista sao:\n");
            ImprimeLista(lista);
            break;

        case 13:
            EsvaziaLista(&lista);
            LiberaLista(&lista);
            break;

        }

        printf("Querido usuario, digite a opcao desejada:\n");
        printf("0 - Encerrar Programa\n1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Inserir Elemento\n4 - Remover Elemento\n");
        printf("5 - Consulta elemento\n6 - Media dos elementos da lista\n7 - Verificar se 2 listas sao iguais\n8 - Intercala listas\n");
        printf("9 - Inverte lista\n10 - Apenas os impares da lista informada\n11 - Tamanho Lista\n12 - Imprimir Lista\n13 - Liberar Lista\n");
        scanf("%d", &opcao);

        while (opcao < 0 || opcao > 13){
            printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
            printf("0 - Encerrar Programa\n1 - Inicializar Lista\n2 - Verifica Lista Vazia\n3 - Inserir Elemento\n4 - Remover Elemento\n");
            printf("5 - Consulta elemento\n6 - Media dos elementos da lista\n7 - Verificar se 2 listas sao iguais\n8 - Intercala listas\n");
            printf("9 - Inverte lista\n10 - Apenas os impares da lista informada\n11 - Tamanho Lista\n12 - Imprimir Lista\n13 - Liberar Lista\n");
            scanf("%d", &opcao);
    }

    }
    EsvaziaLista(&lista2);
    EsvaziaLista(&lista3);
    LiberaLista(&lista2);
    LiberaLista(&lista3);

    return 0;
}
