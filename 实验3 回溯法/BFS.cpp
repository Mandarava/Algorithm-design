#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct
{
	ElemType data[7];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue *&q)
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=0;
}

bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{
	if((q->rear+1)%7==q->front)
		return 0;
		q->rear=(q->rear+1)%7;
		q->data[q->rear]=e;
		return 1;
}
bool deQueue(SqQueue *&q,ElemType &e)
{
	if(q->front==q->rear)
	return 0;
	q->front=(q->front+1)%7;
	e=q->data[q->front];
	return 1;
}

int Visited[7];
int c[7][7];
void BFSSearch(int k)
{   ElemType e;
	SqQueue *q;
	int w;
		printf(" %d",k+1);
	Visited[k] = 1;
	InitQueue(q);
	enQueue(q, k);
	while (!QueueEmpty(q))
	{
		deQueue(q, e);
		for (int i = 0; i < 7; i++)
		{
			if (c[e][i] != 0)
			{
				w = i;
			}
			if (c[e][i]==1 && Visited[w]==0)
			{
					printf(" %d",w+1);;
				Visited[w] = 1;
				enQueue(q, w);
			}
		}
	}
}
void BFSGuide()
{
	for(int i=0;i<7;i++)
	{
		if(Visited[i]==0)
		{
			BFSSearch(i);
		}
	}
}
void initGraph()
{
	printf("【1】----【2】        \n");
	printf("     \\     | \\      \n") ;
	printf("       \\   |  【5】  \n");
	printf("         \\ | /       \n");
	printf("【3】----【4】        \n");
	printf("           |          \n");
	printf("【6】----【7】        \n");
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			c[i][j] = 0;
		}
	}
	//连通顶点标记
	c[0][0] = c[0][1] = c[0][3] = 1;
	c[1][0] = c[1][1] = c[1][3] = c[1][4] = 1;
	c[2][2] = c[2][3] = 1;
	c[3][2] = c[3][3] = c[3][4] = c[3][6] = 1;
	c[4][1] = c[4][3] = c[4][4] = 1;
	c[5][5] = c[5][6] = 1;
	c[6][3] = c[6][5] = c[6][6] = 1;
	//顶点标志位初始化
	for (int i = 0; i < 7; i++)
	{
		Visited[i] = 0;
	}
}
int main()
{	printf("实验的无向图如图所示\n");
	initGraph();
	printf("BFS算法如下:\n\n");
	BFSGuide();
	return 0;
}


