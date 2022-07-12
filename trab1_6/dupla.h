#ifndef DUPLA_H_INCLUDED
#define DUPLA_H_INCLUDED

typedef struct no Lista;

Lista* CriaLista();
int ListaVazia (Lista* lst);
int InsereOrdenado (Lista** lst, int elemento);
int RemoveOrdenado (Lista** lst, int elemento);
int Tamanho (Lista* lst);
float Media (Lista* lst);
int xor (int a, int b);
int ListasIguais (Lista* lst1, Lista* lst2);
int RemoveMultiplos (Lista** lst);
void ImprimeLista (Lista* lst);
void EsvaziaLista (Lista** lst);

#endif // DUPLA_H_INCLUDED
