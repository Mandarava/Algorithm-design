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
	printf("���������ָ���\n");
	scanf("%d",&n);
	printf("�밴��С�����˳����������\n");
	for(i=1;i<=n;i++)
	{
	scanf("%d",&A[i-1]);
	}
	printf("��������Ҫ���ҵ�����\n"); 
	scanf("%d",&y); 
	location=binarySearch(A,n,y);
	printf("��Ҫ���ҵ����������±�Ϊ %d \n",location);
}


