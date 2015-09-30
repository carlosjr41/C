#include "prim.h"

void learquivo(Grafo *g){
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

Fila *cria(){
    Fila *f;

    f=(Fila *)malloc(sizeof(Fila));
    if (f==NULL) exit(1);

    f->ini=f->fim=NULL;
    return f;
}

void insere(Fila *f,int num,int dist){
    No* aux=(No *)malloc(sizeof(No));
    if (aux==NULL) exit(1);

    aux->n=num;
    aux->d=dist;
    aux->ant=aux->prox=NULL;

    if(f->fim!=NULL){
        f->fim->prox=aux;
        aux->ant=f->fim;
    }
    f->fim=aux;

    if(f->ini==NULL) f->ini=f->fim;

}

void retiramenor(Fila *f,int *num){
    No *aux, *menor;


    menor=f->ini;

    for(aux=menor->prox; aux!=NULL; aux=aux->prox){
        if(aux->d<menor->d) menor=aux;
    }

    (*num)=menor->n;


    if(menor->ant==NULL && menor->prox==NULL){

        f->ini=f->fim==NULL;
        free(menor);

    }

    else if(menor->ant==NULL){

        f->ini=menor->prox;
        f->ini->ant=NULL;
        free(menor);
    }

    else if(menor->prox==NULL){

        f->fim=menor->ant;
        f->fim->prox=NULL;
        free(menor);
    }

    else{

        menor->ant->prox=menor->prox;
        menor->prox->ant=menor->ant;
        free(menor);
    }

}

void altera(Fila *f,int num,int dist){
    No *aux;
    if(!vazia(f)){
        for(aux=f->ini;aux!=NULL;aux=aux->prox){
            if(aux->n==num){
                aux->d=dist;
                break;
            }
        }
    }
}

int vazia(Fila *f){
    return f->ini==NULL;
}

void libera (Fila* f){
    No * q;
    No * t;
    q = f->ini;
    while (q!=NULL) {
        t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

int contem(Fila *f,int i){
    No *aux;
    if(vazia(f)) return 0;
    for (aux=f->ini;aux!=NULL;aux=aux->prox){
        if(aux->n==i) return 1;
    }
    return 0;
}

int retornapeso(Grafo *g,int u, int v){
    return g->A[u][v];
}



void prim(Grafo *g,int origem){
    int i,u;
    Fila *f=cria();
    for (i=0;i<g->tam;i++){
        if (i!=origem){
            g->dist[i]=100000;
            g->pred[i]=-1;
        }
    }
    g->dist[origem]=0;
    g->pred[origem]=-1;

    for(i=0;i<g->tam;i++){ //inserindo no Nos grafos
        insere(f,i,g->dist[i]);
    }

    while(!vazia(f)){
        retiramenor(f,&u);

        for(i=0;i<g->tam;i++){
            if(g->A[u][i]!=0 && contem(f,i)){
                if(retornapeso(g,u,i)<g->dist[i]){
                    g->pred[i]=u;
                    g->dist[i]=retornapeso(g,u,i);
                    altera(f,i,g->dist[i]);

                }

            }
        }


    }

}
