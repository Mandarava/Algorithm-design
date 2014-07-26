#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
void main1();//��������� 
void main2();//��Ǯ�һ����� 
void main3();//Kruskal 
void main4();//��Դ����·�� 
int main()
{	system("cls");
	int a;
	printf("\t\t���������������������������������� \n");
	printf("\t\t��        ̰�Ĳ���ʵ��          ��\n");
	printf("\t\t��      1�����������         ��\n");
	printf("\t\t��      2����Ǯ�һ�����         ��\n");
	printf("\t\t��      3��Kruskal              �� \n");
	printf("\t\t��      4����Դ����·��         ��\n");
	printf("\t\t��      5���˳�                 ��\n");
	printf("\t\t����������������������������������\n");
	printf("\t\t��ѡ��:");
	while((status=scanf("%d",&a))!=1||(a>5||a<1))
	{
		if(status!=1)				//判断是否为字符 
			scanf("%*s");			//跳至下一个空白符 
			printf("请输入1-5的数字\n");
	}
	switch(a)
	{
		case 1:main1();    //����� 
				break;
		case 2:main2();    //��Ǯ�һ� 
				break;
		case 3:main3();    //Kruskal 
				break;
		case 4:main4();    //��Դ����·�� 
				break;
		case 5:exit(0);    //�˳� 
		default:main();    //�������˵� 
		return 0;
	}
}
//**********************����Ϊ�����***********************// 
void GreedySelector(int n,int B[],int E[],bool A[])//�Ի�������̰��ѡ�� 
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
int Part(int Array[], int low, int high)      /////���������㷨////////// 
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
	printf("��������ĸ���\n");
	scanf("%d", &n);
	printf("�������ʼʱ���ͽ���ʱ��\n");
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&B[i],&E[i] );
	}
	for(i=0;i<n;i++)
	{
		F[i]=E[i];							//F[]���ڸ���E[]�е����� 
	}
	int num[100];		          			//numΪ�ڼ���� 
	for (int i = 0; i < n; i++)
	{
		num[i] = i;
	}
	QuickSort(E,0,n-1);	     ////��E[]�е�Ԫ�ذ��Ǽ������� 
	for(i=0;i<n;i++)		///������������E[]�е�Ԫ����ԭʼ�����е�λ�ã� 
							//ʹ�������Ļ����ʱ����ԭʼ�Ŀ�ʼʱ�������������Ӧ 
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
	printf("���������л��Ϣ������ʱ����������������:");////����Ϊ���������Ļ��Ϣ///
	printf("\n�i  ");
	printf("  ");
	for (int i = 0; i < n; i++)
	{
		printf("%4d", num2[i]+1);

	}
	printf("\n��ʼʱ�� ");
	for (int i = 0; i < n; i++)
	{
		printf("%4d", C[i]);
	}
	printf("\n����ʱ��");
	printf(" ");
	for (int i = 0; i < n; i++)
	{
		printf("%4d", E[i]);

	}
	printf("\n");		//////////////////////////////////////////////////////// 
	bool A[100];
	GreedySelector(n, C, E, A);//����̰��ѡ��	
	for (int i = 0; i < n; i++)
	{
		printf("%2d",A[i]);
	}
	printf("\n");
	printf("ѡ�����"); 
	for(i=0;i<n;i++)
	{	if(A[i]==1)
		printf("%d",num2[i]+1);
		printf(" "); 
	}
	printf("\n");
	system("pause");
	main();
	
}
//**********************����Ϊ�����********************************// 

//**********************����Ϊ����Ǯ**********************************// 
void main2()  
{	system("cls");
	int m[5]={50,20,10,5,1};//5����Ǯ,1Ԫ���µ���Ǯ���Һ��� ,��Ǯ�����㹻 ��
							//����Ǯ���Ӵ���С��˳���洢���Ա��ڴ���������Ǯ��ʼ�� 
	int number[5]={0,0,0,0,0};//ÿ����Ǯ�ĸ���
	int n,i;
	printf("����Ӧ�ҵĽ���"); 
	scanf("%d",&n);
	 for(int i=0;i<5;i++)
    {
          number[i]=n/m[i];
          n=n%m[i];
     }
	for(i=0;i<5;i++)
	if(number[i]!=0)
		printf("%d��%dԪ\n",number[i],m[i]);
	system("pause");
	main();	
} 
//**********************����Ϊ����Ǯ*********************************//
 
//**********************����ΪDijkstra*******************************//
//����ͼ 
typedef struct graph
{
	int c[10][10];
	int n;
}graph;
graph g;
void Path(int s[],int dist[],int p[] )			//����·�� 
{	int i=0;
	printf("\npath:");
	for(i=1;i<5;i++)
		printf("p[%d]=%d ",i,p[i]);				//����ǰ���ڵ� 
	printf("\n");
	for(i=0;i<5;i++)
		if (s[i]==1)	//s[i]=1 ��ʾ����i�Ѿ����뼯��S�����򶥵�i���ڼ���V-S 
		{
			if(i!=0)
			{
				printf("����·������dist[%d]:%d\n",i,dist[i]);//��������·������ 
			}
		}

}
void Dijkstra(graph g)
{	
	int dist[10],p[10]; 			//dist[] ��¼��Դ�㵽��������������·������ p[]��¼����·�� 
	int s[10];						//s[i]=1 ��ʾ����i�Ѿ����뼯��S�����򶥵�i���ڼ���V-S 
	int i,j;
	int u=-1;
	for(i=0;i<5;i++)				//��ʼ�� 
	{
		dist[i]=g.c[0][i];			//Ĭ�ϴӶ���0��ʼ ,��ǰ������·�� 
		s[i]=0;
		p[i]=0;
	}
	//ѡ��Сdist

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
		if((dist[j]>dist[u]+g.c[u][j])&&(s[j]==0))//����ѡ�����̵ķ��� 
			{
				dist[j]=dist[u]+g.c[u][j];		//����dist[j] 
				p[j]=u;							//ǰ���ڵ�Ϊu 
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
	printf("����ͼG���ڽӾ���:\n");
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
//***************************����ΪDijkstra**********************// 

//***************************����Ϊkruskal**********************//
//�����߽ṹ 
typedef struct Edge
  {  int BeginNode;
     int EndNode;
     int weight;
  } Edge;
  
//����ͼ 
  typedef struct Graph
  {  int C[100][100];
     int NodeNum;
  } Graph;
 
 int Parent[100];
 int Rank[100];
 
void MakeSet( int x)//�γ�һ��������x�ļ���
 {  Parent[x]=x;
    Rank[x]=0;
 }
 
 int Find(int x)    //Ѱ��X�����ĸ�����
 {  while(x!=Parent[x])
      x=Parent[x];
    return x;
 }
 
void Union(int x,int y)//�ϲ�����x��y�ļ��ϡ�

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
  
 //����ͼ 
  	printf("�����붥������");
  	scanf("%d",&n);
	G.NodeNum=n;
 	printf("��������ͼ���ڽӾ������粻�ɵ���������һ�����ڵ���1000�����֣�\n");
	for(i=1;i<=n;i++)
    	for(j=1;j<=n;j++)
      		scanf("%d",&G.C[i][j]);
      
  //ͳ�Ʊ� 
  edgek=0;
  for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
      if (G.C[i][j]<1000&&G.C[i][j]>0)
	  { edgek++;
	    Gedge[edgek].BeginNode=i;
        Gedge[edgek].EndNode=j;
        Gedge[edgek].weight=G.C[i][j];
      }
  //������
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



