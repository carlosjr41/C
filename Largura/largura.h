#ifndef LARGURA_H_INCLUDED
#define LARGURA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define branco 0
#define cinza 1
#define preto 2

typedef struct{
    int pred[MAX];
    int A[MAX][MAX];
    int dist[MAX];
    int cor[MAX];
    int tam;
}grafo;


typedef struct{
    int ini,fim;
    int vet[MAX];
    int tam;
}Fila;

void learquivo(grafo *); //funcao que le a matriz de adjacencia do arquivo texto

void bfs(grafo *,int ,Fila *); //funcao auxiliar da busca em largura

void visitabfs(grafo *); //funcao que dispara a busca em largura

Fila *cria(int ); //funcao que cria a fila

void insere(Fila *,int ); //funcao que insere na fila

int retira(Fila *);//funcao que retira da fila

void esvazia(Fila *); //funcao que esvazia a fila

int vazia(Fila *); //funcao que verifica se uma fila esta vazia

int cheia(Fila *); //funcao que verifica se uma fila esta cheia

void libera(Fila *); //funcao que desaloca a fila




#endif // LARGURA_H_INCLUDED
