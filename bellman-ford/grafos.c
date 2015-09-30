#include "grafos.h"

void learquivo(grafo *g){
    int i,j;
    FILE *fp=fopen("grafos.txt","rt");
    if (fp==NULL){
        printf("erro ao ler arquivo");
        exit(1);
    }

    fscanf(fp,"%d",&g->tam);

    if (g->tam>MAX){
        printf("Numero de Vertices nao permitido\n");
        exit(1);
    }

    for(i=0;i<g->tam;i++){
        for(j=0;j<g->tam;j++){
            fscanf(fp,"%d",&g->A[i][j]);

        }

    }
    fclose(fp);
}

void inicializaOrigemUnica(grafo *g,int ini){
    int i;
    for(i=0;i<g->tam;i++){
        if (i!=ini){
            g->dist[i]=100000;
            g->pred[i]=NULL;
        }
    }
    g->dist[ini]=0;
    g->pred[ini]=-1;
}

int retornapeso(grafo *g,int v1, int v2){
    return g->A[v1][v2];
}

void relaxamento(grafo *g,int u, int v){

    if(g->dist[v]>(g->dist[u]+retornapeso(g,u,v))){
       g->dist[v]=g->dist[u]+retornapeso(g,u,v);
       g->pred[v]=u;
    }
}

int bellman(grafo *g,int ini){
    int i,j;
    inicializaOrigemUnica(g,ini);
    for(i=0;i<g->tam;i++){
        for(j=0;j<g->tam;j++){
            if(retornapeso(g,i,j)!=0){
                relaxamento(g,i,j);
            }
        }

    }

    for(i=0;i<g->tam;i++){
        for(j=0;j<g->tam;j++){
            if(retornapeso(g,i,j)!=0){
                if(g->dist[j]>g->dist[i]+retornapeso(g,i,j)) return 0;
            }
        }
    }

    return 1;
}
