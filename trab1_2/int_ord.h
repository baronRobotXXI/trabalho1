#ifndef INT_ORD_H_INCLUDED
#define INT_ORD_H_INCLUDED

typedef struct lista Lista;

Lista* CriaLista ();
int ListaVazia (Lista* lst);
int ListaCheia (Lista* lst);
int InsereOrdenado (Lista* lst, int elem);
int RemoveOrdenado (Lista* lst, int elem);
void ImprimeLista (Lista* lst);
void LiberaLista (Lista** lst);

#endif // INT_ORD_H_INCLUDED
