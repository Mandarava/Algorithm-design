#include <stdio.h>

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
 
 MakeSet( int x)
 {  Parent[x]=x;
    Rank[x]=0;
 }
 
 int Find(int x)
 {  while(x!=Parent[x])
      x=Parent[x];
    return x;
 }
 
 Union(int x,int y)
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

  
main()
{ Graph G;
  Edge Gedge[100],Xedge[100];
  int n,i,j,edgek,temp,u,v,Xnum;
  
 //输入图 
  scanf("%d",&n);
  G.NodeNum=n;
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
  
   // for(i=1;i<edgek;i++)
      //printf("%d  %d   %d\n",Gedge[i].BeginNode,Gedge[i].EndNode,Gedge[i].weight);
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

}

