#include "grafos.h"

int main()
{
   grafo g;
   int i;
   learquivo(&g);

   if(bellman(&g,0)){
        for(i=0;i<g.tam;i++){
            printf("No %d: ",i+1);
            printf("%d %d\n\n",g.dist[i],g.pred[i]+1);
        }

   }
   else printf("Grafo com pesos negativos");
   return 0;
}
