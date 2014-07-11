#include<stdio.h>
void GreedySelector(int n,int B[],int E[],bool A[])
{
	int i,j;
	A[1]=true;
	j=1;i=2;
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
int main()
{	printf("会议i     1  2  3  4  5  6  7  8  9  10  11\n");
	printf("开始时间  1  3  0  5  3  5  6  8  8  2   12\n"); 
	printf("结束时间  4  5  6  7  8  9  10 11 12 13  14\n\n"); 
	int i,j;
	bool A[11];
	int B[11]={1,3,0,5,3,5,6,8,8,2,12};			//开始时间 
	int E[11]={4,5,6,7,8,9,10,11,12,13,14};		//结束时间 
	for(i=0;i<11;i++)
	{
		A[i]=0;	
	}
	GreedySelector(11,B,E,A);
	for (int i = 0; i < 11;i++)
	{
		if (A[i] == true)
		{
			printf("1"); 
		}
		else
		printf("0");
	}
	printf("\n");	
	return 0;	
}

