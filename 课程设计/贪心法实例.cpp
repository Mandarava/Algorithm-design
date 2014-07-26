#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
void main1();//活动安排问题 
void main2();//零钱兑换问题 
void main3();//Kruskal 
void main4();//单源最短路径 
int main()
{	system("cls");
	int a,status;
	printf("\t\t┌───────────────┐ \n");
	printf("\t\t│        贪心策略实例          │\n");
	printf("\t\t│      1、活动安排问题         │\n");
	printf("\t\t│      2、零钱兑换问题         │\n");
	printf("\t\t│      3、Kruskal              │ \n");
	printf("\t\t│      4、单源最短路径         │\n");
	printf("\t\t│      5、退出                 │\n");
	printf("\t\t└───────────────┘\n");
	printf("\t\t请选择:");
	while((status=scanf("%d",&a))!=1||(a>5||a<1))
	{
		if(status!=1)				//判断是否为字符 
			scanf("%*s");			//跳至下一个空白符 
			printf("请输入1-5的数字\n");
	}
	switch(a)
	{
		case 1:main1();    //活动安排 
				break;
		case 2:main2();    //零钱兑换 
				break;
		case 3:main3();    //Kruskal 
				break;
		case 4:main4();    //单源最短路径 
				break;
		case 5:exit(0);    //退出 
		default:main();    //返回主菜单 
		return 0;
	}
}
//**********************以下为活动安排***********************// 
void GreedySelector(int n,int B[],int E[],bool A[])//对会议进行贪心选择 
{
	int i,j;
	A[0]=true;
	j=0;i=1;
	while(i<=n)
	{	if(B[i]>=E[j])
		{
			A[i]=true;
			j=i;
		}
		else 
		{
		A[i]=false;
		}
		i++;	
	}
}
int Part(int Array[], int low, int high)      /////快速排序算法////////// 
{
	int temp = Array[low];
	while (low<high)
	{
		while (low<high && Array[high] >= temp)
		{
			high--;
		}
		Array[low] = Array[high];

		while (low<high && Array[low] <= temp)
		{
			low++;
		}
		Array[high] = Array[low];
	}
	Array[low] = temp;
	return low;
}

void QuickSort(int Array[], int low, int high)
{

	if (low<high)
	{
		int p = Part(Array, low, high);
		QuickSort(Array, low, p - 1);
		QuickSort(Array, p + 1, high);
	}
}


void main1()
{	system("cls");
	int n,i,j,y; 
	int C[100],B[100],E[100],F[100],num2[100];
	int location; 
	printf("请输入活动的个数\n");
	scanf("%d", &n);
	printf("输入活动开始时间和结束时间\n");
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&B[i],&E[i] );
	}
	for(i=0;i<n;i++)
	{
		F[i]=E[i];							//F[]用于复制E[]中的数据 
	}
	int num[100];		          			//num为第几个活动 
	for (int i = 0; i < n; i++)
	{
		num[i] = i;
	}
	QuickSort(E,0,n-1);	     ////对E[]中的元素按非减序排列 
	for(i=0;i<n;i++)		///查找排序完的E[]中的元素在原始数组中的位置， 
							//使排序过的活动结束时间与原始的开始时间与活动序号相对应 
	{
		for(j=0;j<n;j++)
		{
			if(E[i]==F[j])
			{	C[i]=j;	
				C[i]=B[j];
				num2[i]=num[j];				
			}
					
		}
	}
	printf("输入的所有活动信息按结束时间的升序排列如下:");////以下为输出输入的活动信息///
	printf("\n活动i  ");
	printf("  ");
	for (int i = 0; i < n; i++)
	{
		printf("%4d", num2[i]+1);

	}
	printf("\n开始时间 ");
	for (int i = 0; i < n; i++)
	{
		printf("%4d", C[i]);
	}
	printf("\n结束时间");
	printf(" ");
	for (int i = 0; i < n; i++)
	{
		printf("%4d", E[i]);

	}
	printf("\n");		//////////////////////////////////////////////////////// 
	bool A[100];
	GreedySelector(n, C, E, A);//进行贪心选择	
	for (int i = 0; i < n; i++)
	{
		printf("%2d",A[i]);
	}
	printf("\n");
	printf("选择活动："); 
	for(i=0;i<n;i++)
	{	if(A[i]==1)
		printf("%d",num2[i]+1);
		printf(" "); 
	}
	printf("\n");
	system("pause");
	main();
	
}
//**********************以上为活动安排********************************// 

//**********************以下为找零钱**********************************// 
void main2()  
{	system("cls");
	int m[5]={50,20,10,5,1};//5种零钱,1元以下的零钱暂且忽略 ,零钱数量足够 ，
							//且零钱按从大到小的顺序存储，以便于从最大的零钱开始找 
	int number[5]={0,0,0,0,0};//每种零钱的个数
	int n,i;
	printf("输入应找的金额"); 
	scanf("%d",&n);
	 for(int i=0;i<5;i++)
    {
          number[i]=n/m[i];
          n=n%m[i];
     }
	for(i=0;i<5;i++)
	if(number[i]!=0)
		printf("%d个%d元\n",number[i],m[i]);
	system("pause");
	main();	
} 
//**********************以上为找零钱*********************************//
 
//**********************以下为Dijkstra*******************************//
//定义图 
typedef struct graph
{
	int c[10][10];
	int n;
}graph;
graph g;
void Path(int s[],int dist[],int p[] )			//输出路径 
{	int i=0;
	printf("\npath:");
	for(i=1;i<5;i++)
		printf("p[%d]=%d ",i,p[i]);				//输出前驱节点 
	printf("\n");
	for(i=0;i<5;i++)
		if (s[i]==1)	//s[i]=1 表示顶点i已经加入集合S；否则顶点i属于集合V-S 
		{
			if(i!=0)
			{
				printf("最短路径长度dist[%d]:%d\n",i,dist[i]);//输出最短路径长度 
			}
		}

}
void Dijkstra(graph g)
{	
	int dist[10],p[10]; 			//dist[] 记录从源点到其他顶点的最短路径长度 p[]记录最短路径 
	int s[10];						//s[i]=1 表示顶点i已经加入集合S；否则顶点i属于集合V-S 
	int i,j;
	int u=-1;
	for(i=0;i<5;i++)				//初始化 
	{
		dist[i]=g.c[0][i];			//默认从顶点0开始 ,当前的最短路径 
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
		if((dist[j]>dist[u]+g.c[u][j])&&(s[j]==0))//进行选择最短的方案 
			{
				dist[j]=dist[u]+g.c[u][j];		//更新dist[j] 
				p[j]=u;							//前驱节点为u 
			}
	}
	Path(s,dist,p);
}


void main4()
{	system("cls");
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
	system("pause");
	main();
}
//***************************以上为Dijkstra**********************// 

//***************************以下为kruskal**********************//
//定义边结构 
typedef struct Edge
  {  int BeginNode;
     int EndNode;
     int weight;
  } Edge;
  
//定义图 
  typedef struct Graph
  {  int C[100][100];
     int NodeNum;
  } Graph;
 
 int Parent[100];
 int Rank[100];
 
void MakeSet( int x)//形成一个仅仅含x的集合
 {  Parent[x]=x;
    Rank[x]=0;
 }
 
 int Find(int x)    //寻找X属于哪个集合
 {  while(x!=Parent[x])
      x=Parent[x];
    return x;
 }
 
void Union(int x,int y)//合并包含x和y的集合。

 {  int rootx,rooty;
    rootx=Find(x);
    rooty=Find(y);
    if (Rank[rootx] > Rank[rooty])
        Parent[rooty]=rootx;
	else
       Parent[rootx]=rooty;
    if (Rank[rootx]==Rank[rooty])
      Rank[rooty]++;
 }

  
void main3()
{ 
	system("cls");
	Graph G;
  	Edge Gedge[100],Xedge[100];
  	int n,i,j,edgek,temp,u,v,Xnum;
  
 //输入图 
  	printf("请输入顶点个数");
  	scanf("%d",&n);
	G.NodeNum=n;
 	printf("请输入该图的邻接矩阵（如不可到达请输入一个大于等于1000的数字）\n");
	for(i=1;i<=n;i++)
    	for(j=1;j<=n;j++)
      		scanf("%d",&G.C[i][j]);
      
  //统计边 
  edgek=0;
  for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
      if (G.C[i][j]<1000&&G.C[i][j]>0)
	  { edgek++;
	    Gedge[edgek].BeginNode=i;
        Gedge[edgek].EndNode=j;
        Gedge[edgek].weight=G.C[i][j];
      }
  //边排序
   for(i=1;i<edgek;i++)
    for(j=1;j<=edgek-i;j++)
      if(Gedge[j].weight>Gedge[j+1].weight)
	   { temp=Gedge[j].BeginNode;
	     Gedge[j].BeginNode=Gedge[j+1].BeginNode;
         Gedge[j+1].BeginNode=temp;
         
         temp=Gedge[j].EndNode;
	     Gedge[j].EndNode=Gedge[j+1].EndNode;
         Gedge[j+1].EndNode=temp;
         
         temp=Gedge[j].weight;
	     Gedge[j].weight=Gedge[j+1].weight;
         Gedge[j+1].weight=temp;
       }
  

  Xnum=0;
  
  for(i=1;i<=G.NodeNum;i++)
    MakeSet(i);
  
  for(i=1;i<=edgek;i++)
  {  u=Gedge[i].BeginNode;
     v=Gedge[i].EndNode;
     if(Find(u)!=Find(v))
      { Xnum++;
        Xedge[Xnum].BeginNode=u;
        Xedge[Xnum].EndNode=v;
        Xedge[Xnum].weight=Gedge[i].weight;
        Union(u,v);
      }
  }
for(i=1;i<=Xnum;i++)
  printf("%d  %d   %d\n",Xedge[i].BeginNode,Xedge[i].EndNode,Xedge[i].weight);
  system("pause");
  main();

}


