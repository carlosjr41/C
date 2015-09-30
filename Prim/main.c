#include "prim.h"

int main()
{
    Grafo g;
    int i,n;

    learquivo(&g);
    prim(&g,0);

    n=g.tam;

    for(i=0;i<n;i++){
        printf("No %d: ",i+1);
        if(g.pred[i]!=-1) printf("%d %d\n\n",g.pred[i]+1,g.dist[i]);
        else printf("0 0\n\n");
    }



    return 0;
}
