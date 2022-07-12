#ifndef CIRCULAR_NORD_H_INCLUDED
#define CIRCULAR_NORD_H_INCLUDED

typedef struct no Lista;

Lista* CriaLista ();
int ListaVazia (Lista* lst);
int InsereFinal (Lista** lst, int elemento);
int InsereInicio (Lista** lst, int elemento);
int InserePosicao (Lista** lst, int pos, int elemento);
int RemoveInicio (Lista** lst, int* elemento);
int RemovePosicao(Lista** lst, int pos, int* elemento);
int ApenasImpares (Lista* lst1, Lista** lst2);
int ObtemValorElemento (Lista* lst, int pos, int* elemento);
int TamanhoLista (Lista* lst, int* tam);
int Maior (Lista* lst, int* elemento);
void ImprimeLista (Lista* lst);
void LiberaLista (Lista** lst);
void EsvaziaLista (Lista** lst);

#endif // CIRCULAR_NORD_H_INCLUDED
