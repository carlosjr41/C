#include "grafos.h"

void learquivo(FILE *fp,grafo *g,int *n){
    int i,j;

    fp=fopen("grafos.txt","rt");
    if(fp==NULL) exit(1);

    fscanf(fp,"%d",&(*n));

    if ((*n)>MAX){
        printf("Numero de Vertices nao permitido\n");
        exit(1);
    }

    for(i=0;i<(*n);i++){
        for(j=0;j<(*n);j++){
            fscanf(fp,"%d",&g->A[i][j]);

        }
        g->cor[i]=branco;
        g->d[i]=0;
        g->t[i]=0;
        g->pred[i]=-1;
    }
    fclose(fp);
}

void DFS(grafo *g,int n){
    int i;
    int tempo=0;
    for (i=0;i<n;i++){
        if(g->cor[i]==branco) visita(g,n,i,&tempo);
    }

}

void visita(grafo *g,int n,int pos,int *tempo){
    int i,j;

    g->cor[pos]=cinza;
    (*tempo)++;
    g->d[pos]=(*tempo);

    for(i=0;i<n;i++){
        if(g->A[pos][i]!=0 && g->cor[i]==branco){
            g->pred[i]=pos+1;
            visita(g,n,i,&(*tempo));
        }
    }
    g->cor[pos]=preto;
    (*tempo)++;
    g->t[pos]=(*tempo);

}
