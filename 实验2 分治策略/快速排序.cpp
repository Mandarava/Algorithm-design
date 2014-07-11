#include<stdio.h>
int Part(int Array[],int low,int high)
{
	int temp =Array[low];
	while(low<high)
	{
		while(low<high && Array[high]>=temp)
		{
			high--;
		}
			Array[low]=Array[high];		//�ҵ��ȷֽ���С�������ŵ���������
										//��ʱ��high�ұߵ������ȷֽ��
		while(low<high && Array[low]<=temp)
		{
		low++;
		}
		Array[high]=Array[low];
	}
	Array[low]=temp;
	return low;
}

void QuickSort(int Array[] , int low , int high)
{
	
	if (low<high)						//�������䳤�ȴ���1ʱ�������� 
	{
	int p=Part(Array,low,high);			//��Array[low,high]������ 
	QuickSort(Array,low,p-1);			//��������ݹ����� 
	QuickSort(Array,p+1,high);			//��������ݹ����� 
	}
}

int main()
{
	int a,i;
	int B[100]={0};
	printf("������Ҫ��������ֵĸ���\n");
	scanf("%d",&a); 
	printf("����������\n");
	for(i=1;i<=a;i++)
	{
		scanf("%d",&B[i-1]);
		
	}
	QuickSort(B,0,a-1);
	for(int i=0;i<=a-1;i++)
	printf("%d ",B[i]);
	printf("\n");
	return 0;
}


