#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define branco 0
#define cinza 1
#define preto 2

typedef struct{
    int pred[MAX];
    int A[MAX][MAX];
    int d[MAX];
    int t[MAX];
    int cor[MAX];
}grafo;

void learquivo(FILE *,grafo *,int *);
void DFS(grafo *,int );
void visita(grafo *, int, int,int *);
#endif // GRAFOS_H_INCLUDED
