#include "largura.h"

int main()
{
    grafo g;

    int i,n;

    learquivo(&g);
    visitabfs(&g);

    n=g.tam;

    for(i=0;i<n;i++){
        printf("No %d: ",i+1);
        printf("%d %d \n\n",g.dist[i],g.pred[i]);
    }

    return 0;
}
