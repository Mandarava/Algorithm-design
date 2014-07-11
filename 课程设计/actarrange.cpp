#include<stdio.h>
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


int main()
{	int n,i,j,y; 
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
	return 0;
}
