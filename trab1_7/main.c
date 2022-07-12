#include <stdio.h>
#include <stdlib.h>
#include "soldados.h"

//subt elemento por qtde

int main()
{
    Soldados* cab;      //a lista é manipulada atraves do nó cab

    char nome[20];
    int opcao;
    int fim;
    int pos;
    int qtde;
    int verif;


    cab = CriaLista();

    do{
        fim = 0;
        printf("Querido usuario, digite o nome do soldado ou X para encerrar a insercao\n");
        setbuf(stdin, NULL);
        gets(nome);

        if (nome[1] != 0){
            if (InsereFinal(cab, nome)){
                printf("Soldado informado com sucesso!\n");
                fim++;
            }
            else
                printf("Falha ao inserir soldado!\n");

        }

    }while (nome[1] != '\0');

    printf("Digite a opcao de contagem:\n");
    printf("0 - Encerrar programa\n");
    printf("1 - A partir do primeiro\n");
    printf("2 - A partir de alguem aleatorio\n");
    printf("3 - Informar o nome do soldado para comecar\n");
    scanf("%d", &opcao);

    if (opcao == 0)
        return 0;           //encerra

    while (opcao < 0 || opcao > 3){
        printf("OPCAO INVALIDA!! Digite novamente a opcao:\n");
        printf("0 - Encerrar programa\n");
        printf("1 - A partir do primeiro\n");
        printf("2 - A partir de alguem aleatorio\n");
        printf("3 - Informar o nome do soldado para comecar\n");
        scanf("%d", &opcao);
    }

    printf("%d", opcao)
    while (opcao != 0){
        switch (opcao){

            ImprimeLista(cab, qtde, fim);

        case 1:
            if (!ContaInicio(cab, &qtde))
                printf("Erro na contagem!\n");

            break;

        case 2:
            if (!ContaAleatorio(cab, &qtde, nome))
                printf("Erro na contagem!\n");
            else
                printf("O soldado sorteado para comecar a contagem foi %s\n", nome);
            break;

        case 3:
            printf("Digite o nome do soldado para dar inicio:\n");
            setbuf(stdin, NULL);
            gets(nome);

            verif = VerificaNome(cab, &pos, nome);

            while (!verif){
                printf("%s nao esta na lista!\n", nome);
                printf("Digite novamente o nome do soldado:\n");
                setbuf(stdin, NULL);
                gets(nome);

                verif = VerificaNome(cab, &pos, nome);
            }

            if (!ContaNome(cab, &qtde, nome))
                printf("Erro na contagem!\n");

            break;
        }
    }

    ImprimeLista(cab, &qtde, fim);
    LiberaLista(&cab);

    return 0;
}
