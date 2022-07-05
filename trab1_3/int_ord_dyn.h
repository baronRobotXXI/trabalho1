#ifndef INT_ORD_DYN_H_INCLUDED
#define INT_ORD_DYN_H_INCLUDED

typedef struct no Lista;

Lista* CriaLista();
int ListaVazia (Lista* lst);
int InsereElemento (Lista** lst, int elemento);
int InsereOrdenado (Lista** lst, int elemento);
int RemoveOrdenado (Lista** lst, int elemento);
int TamanhoLista (Lista* lst, int* tam);
int ObtemValorElemento (Lista* lst, int pos, int* elemento);
int Media (Lista* lst, float* media);
int xor (int a, int b);
int ListasIguais (Lista* lst1, Lista* lst2);
void IntercalaListas (Lista* lst1, Lista* lst2, Lista** lst3);
int InverteLista (Lista* lst1, Lista** lst2);
void ImprimeLista (Lista* lst);
int ApenasImpares (Lista* lst1, Lista** lst2);
void LiberaLista (Lista** lst);

#endif // INT_ORD_DYN_H_INCLUDED
