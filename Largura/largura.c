#include "largura.h"

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
        g->cor[i]=branco;
        g->dist[i]=100000;
        g->pred[i]=NULL;
    }
    fclose(fp);
}

void bfs(grafo *g,int s,Fila *f){
    int u,i;
    g->cor[s]=cinza;
    g->dist[s]=0;
    esvazia(f);
    insere(f,s);

    while(!vazia(f)){
       u=retira(f);
       for(i=0;i<g->tam;i++){
            if(g->A[u][i]!=0 && g->cor[i]==branco){
                g->cor[i]=cinza;
                g->dist[i]=g->dist[u]+1;
                g->pred[i]=u;
                insere(f,i);
            }
       }

       g->cor[u]=preto;

    }

}

void visitabfs(grafo *g){
    int i,tempo;
    Fila *f=cria(g->tam);

    for(i=0;i<g->tam;i++){
        if(g->cor[i]==branco) bfs(g,i,f);
    }
    libera(f);
}

Fila *cria(int t){
    Fila *f=(Fila *)malloc(sizeof(Fila));
    if (f==NULL) exit(1);
    f->ini=f->fim=0;
    f->tam=t;
    return f;
}

void insere(Fila *f,int v){
    if(cheia(f)) exit(1);
    f->vet[f->fim]=v;
    f->fim++;
}

int retira(Fila *f){
    int aux;
    if (vazia(f)) exit(1);

    aux=f->vet[f->ini];
    f->ini++;
    return aux;

}

void esvazia(Fila *f){
    f->ini=f->fim=0;
}

int vazia(Fila *f){
    return f->fim==f->ini;
}

int cheia(Fila *f){
    return f->fim==f->tam;
}

void libera (Fila* f){
    free(f);
}
