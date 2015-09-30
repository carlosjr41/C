#ifndef PRIM_H_INCLUDED
#define PRIM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int pred[MAX];
    int A[MAX][MAX];
    int dist[MAX];
    int tam;
}Grafo;

typedef struct no{
    int n,d;//numero do no e a distância da origem
    struct no*prox;
    struct no *ant;
}No;

typedef struct{
    No *ini, *fim;
}Fila;



void learquivo(Grafo *g); //le Grafo de um Arquivo texto

Fila *cria(); //cria uma Fila duplamente Encadeada

void insere(Fila *f,int num,int dist); //insere no Fim da Fila

void retiramenor(Fila *f,int *num); //retira o menor elemento

int vazia(Fila *f); //Verifica se uma fila esta vazia

void libera(Fila *);//libera uma Fila

void altera(Fila *f,int num,int dist); //Funcao que altera valores na Fila

int contem(Fila *f,int i);//verifica se um No esta na lista

int retornapeso(Grafo *g,int u, int v);//retorna o peso entre 2 Nos

void prim(Grafo *g,int origem);//Executa o Algoritmo de Prim
#endif // PRIM_H_INCLUDED
