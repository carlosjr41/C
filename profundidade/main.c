#include "grafos.h"



int main()
{
    int i,n;
    FILE *fp;
    grafo g;
    learquivo(fp,&g,&n);
    DFS(&g,n);

    for(i=0;i<n;i++){
        printf("No %d: ",i+1);
        printf("%d %d/%d\n\n",g.pred[i],g.d[i],g.t[i]);
    }

    return 0;
}
