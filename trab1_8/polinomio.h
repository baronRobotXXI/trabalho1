#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

typedef struct no Lista;

Lista* CriaLista();
int ListaVazia (Lista* lst);
int InsereElemento (Lista* lst, int potencia, int coeficiente);
int ObtemPosicao (Lista* lst, int pos, int* coeficiente, int* potencia);
int RemoveExpoente (Lista* lst, int pos);
int Somador (Lista* lst, int X, int* resultado);
void ImprimeLista (Lista* lst);
void LiberaLista (Lista** lst);
void EsvaziaLista (Lista** lst);

#endif // POLINOMIO_H_INCLUDED
