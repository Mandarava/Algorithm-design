#include<stdio.h>
int Visited[7];
int c[7][7];
void Dfsk(int k)
{
	Visited[k]=1;
	for(int j=0;j<7;j++)
	{
		if(c[k][j]==1 && Visited[j]==0)
		{
			printf("%d %d \n",k+1,j+1);
			Dfsk(j);
		}
	}
}
void Dfs()
{
	for(int i=0;i<7;i++)
	{
		if(Visited[i]==0)
		{
			Dfsk(i);
		}
	}
}
void initGraph()
{
	printf("     1-------2      \n");
	printf("     | \\    | \\    \n");
	printf("     |   \\  |  5   \n");
	printf("     |     \\| /    \n");
	printf("     3-------4      \n");
	printf("\n");
	printf("     6-------7\n\n");	
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			c[i][j] = 0;
		}
	}

	c[0][0] = c[0][1] = c[0][2] = c[0][3] = 1;
	c[1][0] = c[1][1] = c[1][3] = c[1][4] = 1;
	c[2][0] = c[2][2] = c[2][3] = 1;
	c[3][0] = c[3][1] = c[3][2] = c[3][3] = c[3][4] = 1;
	c[4][1] = c[4][3] = c[4][4] = 1;
	c[5][5] = c[5][6] = 1;
	c[6][5] = c[6][6] = 1;
	for (int i = 0; i < 7; i++)
	{	
		Visited[i] = 0;
	}
}
int main()
{	printf("实验的无向图如图所示\n");
	initGraph();
	printf("DFS算法如下:\n\n");
	Dfs();
	return 0;
}
