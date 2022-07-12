#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

int main()
{
    Lista* lista;

    int opcao;
    int verif;
    int i;
    int potencia;
    int coeficiente;
    int x;
    int resulta;

    printf("Querido usuario, digite a opcao desejada:\n");
    printf("0 - Encerrar Programa:\n");
    printf("1 - Inicializar Lista\n");
    printf("2 - Verifica Lista Vazia\n");
    printf("3 - Inserir Termo\n");
    printf("4 - Remover Termo\n");
    printf("5 - Calcular Polinomio para o x Informado\n");
    printf("6 - Imprimir Polinomio\n");
    printf("7 - Limpar\n");
    scanf("%d", &opcao);

    if (opcao == 0)
        return 0;       //encerra

    while (opcao < 0 || opcao > 7){
        printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
        printf("0 - Encerrar Programa:\n");
        printf("1 - Inicializar Lista\n");
        printf("2 - Verifica Lista Vazia\n");
        printf("3 - Inserir Termo\n");
        printf("4 - Remover Termo\n");
        printf("5 - Calcular Polinomio para o x Informado\n");
        printf("6 - Imprimir Polinomio\n");
        printf("7 - Limpar\n");
        scanf("%d", &opcao);
    }

    while (opcao != 0){
        switch (opcao){

        case 1:
            lista = CriaLista();

            break;

        case 2:
            verif = ListaVazia(lista);

            if (verif)
                printf("Lista vazia!!\n");
            else
                printf("Lista tem elementos!\n");
            break;

        case 3:
            printf("Digite o expoente: \n");
            scanf("%d", &potencia);         //aô potencia

            printf("Digite tambem o coeficiente:\n");
            scanf("%d", &coeficiente);

            verif = InsereElemento(lista, potencia, coeficiente);

            if (verif)
                printf("Elemento inserido com sucesso!!\n");
            else
                printf("Falha ao inserir elemento!\n");
            break;

        case 4:
            printf("Digite o expoente do elemento a ser removido:\n");
            scanf("%d", &potencia);

            verif = RemoveExpoente(lista, potencia);

            if (verif)
                printf("Elemento removido com sucesso!!\n");
            else
                printf("Falha ao remover elemento!\n");

            break;

        case 5:
            printf("Digite o valor inteiro de x para se calcular o polinomio:\n");
            scanf("%d", &x);

            Somador(lista, x, &resulta);

            printf("O valor do polinomio para %d é %d.", x, resulta);
            break;

        case 6:
            ImprimeLista(lista);

            break;

        case 7:
            EsvaziaLista(&lista);
            printf("Lista esvaziada!\n");

            break;

        }

        printf("Querido usuario, digite a opcao desejada:\n");
        printf("0 - Encerrar Programa:\n");
        printf("1 - Inicializar Lista\n");
        printf("2 - Verifica Lista Vazia\n");
        printf("3 - Inserir Termo\n");
        printf("4 - Remover Termo\n");
        printf("5 - Calcular Polinomio para o x Informado\n");
        printf("6 - Imprimir Polinomio\n");
        printf("7 - Limpar\n");
        scanf("%d", &opcao);

        while (opcao < 0 || opcao > 7){
            printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
            printf("0 - Encerrar Programa:\n");
            printf("1 - Inicializar Lista\n");
            printf("2 - Verifica Lista Vazia\n");
            printf("3 - Inserir Termo\n");
            printf("4 - Remover Termo\n");
            printf("5 - Calcular Polinomio para o x Informado\n");
            printf("6 - Imprimir Polinomio\n");
            printf("7 - Limpar\n");
            scanf("%d", &opcao);
        }

    }

    LiberaLista(&lista);
    return 0;
}
