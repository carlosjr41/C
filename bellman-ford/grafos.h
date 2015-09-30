#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int pred[MAX];
    int A[MAX][MAX];
    int dist[MAX];

    int tam;
}grafo;

void learquivo(grafo *g);

void inicializaOrigemUnica(grafo *g,int ini);

int retornapeso(grafo *g,int v1, int v2);

void relaxamento(grafo *g,int u, int v);

int bellman(grafo *g,int ini);

#endif // GRAFOS_H_INCLUDED
