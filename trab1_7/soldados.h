#ifndef SOLDADOS_H_INCLUDED
#define SOLDADOS_H_INCLUDED

typedef struct no Lista;
typedef struct cab Soldados;

Soldados* CriaLista ();
int ListaVazia(Soldados* cab);
int InsereFinal (Soldados* cab, char* nome);
int Josephus (Lista* aux, Soldados** cab, int* qtde);
int ContaInicio (Soldados* cab, int* elemento);
int ContaAleatorio (Soldados* cab, int* elemento, char* nome);
int ContaNome (Soldados* cab, int* elemento, char* nome);
int ObtemElemento (Soldados* cab, int pos, char* nome);
int UltimoElemento (Soldados* cab, char* nome);
int VerificaNome (Soldados* cab, int* indice, char* nome);
void ImprimeLista (Soldados* lst, int elemento, int fim);
void LiberaLista (Soldados** cab);

#endif // SOLDADOS_H_INCLUDED
