#ifndef INT_ORD_H_INCLUDED
#define INT_ORD_H_INCLUDED

typedef struct lista Lista;

Lista* CriaLista ();
int ListaVazia (Lista* lst);
int ListaCheia (Lista* lst);
int InsereOrdenado (Lista* lst, int elem);
int InsereElemento (Lista* lst, int elem);
int RemoveOrdenado (Lista* lst, int elem);
int RemoveImpares (Lista* lst);
int Menor (Lista* lst, int *elem);
int ObtemValorElemento (Lista* lst, int pos, int* elem);
int Tamanho (Lista* lst, int* tam);
int Concatena (Lista* lst1, Lista* lst2, Lista* lst3);
void ImprimeLista (Lista* lst);
void LiberaLista (Lista* lst);

#endif // INT_ORD_H_INCLUDED
