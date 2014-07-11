#include<stdio.h>
int binarySearch(int A[],int n,int x)
{
	int low=0,high =n-1,middle;
	while(low<=high)
	{		
	middle =(low+high)/2; 
	if (x==A[middle])
	return middle;
	else if (x<A[middle])
	high =middle - 1;
	else 
	low =middle+1;
	}
return -1;
}

int main()
{
	int i,x,y,n,location;
	int A[100]={0};
	int middle;
	printf("请输入数字个数\n");
	scanf("%d",&n);
	printf("请按从小到大的顺序输入数字\n");
	for(i=1;i<=n;i++)
	{
	scanf("%d",&A[i-1]);
	}
	printf("请输入你要查找的数：\n"); 
	scanf("%d",&y); 
	location=binarySearch(A,n,y);
	printf("你要查找的数的数组下标为 %d \n",location);
}


