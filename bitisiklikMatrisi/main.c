#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0};
int min,mincost=0,cost[10][10];
int main() {
	printf("Dugum sayýsýný giriniz: ");
	scanf("%d ",&n);
	printf(	"\n Bitiþiklik matrisini giriniz :");
	for(i=0;i<n;i++){
		for(j=1;j<=n;j++){
			scanf("%d ",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=900;
		}
	}
	visited[1]=1;
	printf("\n");
	while(ne<n){
	for(i=1,min=900;i<=n;i++){
		for(j=1;j<=n;j++){
			if(visited[i]==0){
				min=cost[i][j];
				a=u=i;
				b=v=j;
			}
			if(visited[u]==0||visited[v]==0){
				printf("\n kenar %d: (%d %d ) maliyet %d ",ne++,a,b,min);
				mincost+=min;
				visited[b]=1;
			}
			cost[0][b]=cost[b][0]=900;
		}
	}
	}
	printf("\n minimum maliyet =%d",mincost);
	return 0;
}
