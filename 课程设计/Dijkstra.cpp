#include<stdio.h>
typedef struct graph
{
	int c[10][10];
	int n;
}graph;
graph g;
void Path(int s[],int dist[],int p[] )
{	int i=0;
	printf("\npath:");
	for(i=1;i<5;i++)
		printf("p[%d]=%d ",i,p[i]);
	printf("\n");
	for(i=0;i<5;i++)
		if (s[i]==1)
		{
			if(i!=0)
			{
				printf("最短路径长度dist[%d]:%d\n",i,dist[i]);
			}
		}

}
void Dijkstra(graph g)
{	
	int dist[10],p[10];
	int s[10];
	int i,j;
	int u=-1;
	for(i=0;i<5;i++)
	{
		dist[i]=g.c[0][i];
		s[i]=0;
		p[i]=0;
	}
	//选最小dist

	for(i=0;i<5;i++)
	{
		int temp=1000;
		for(j=1;j<=5;j++)
		if((dist[j]<temp)&&(s[j]==0))
		{
			temp=dist[j];
			u=j;
		}
		s[u]=1;
		for(j=1;j<=5;j++)
		if((dist[j]>dist[u]+g.c[u][j])&&(s[j]==0))
			{
				dist[j]=dist[u]+g.c[u][j];
				p[j]=u;
			}
	}
	Path(s,dist,p);
}


void main4()
{
	int i,j=0;
	graph g;
	int A[10][10];
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			A[i][j]=1000;
		}
	}
	A[0][0]=0; A[1][1]=0;
	A[2][2]=0;A[3][3]=0;A[4][4]=0;
	A[0][1] = 8; A[0][2] = 32;
	A[1][0] = 12; A[1][2] = 16; A[1][3] = 15;
	A[2][1] = 29; A[2][4] = 13;
	A[3][1] = 21; A[3][4] = 7;
	A[4][2] = 27; A[4][3] = 19;
	printf("有向图G的邻接矩阵:\n");
	for( i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			{				
				printf("%d ",A[i][j]);
				if(j == 4)
   				printf("\n");
			}
	
	}	
	for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				g.c[i][j]=A[i][j];
			}
		}
	Dijkstra(g);
	printf("\n");
}
