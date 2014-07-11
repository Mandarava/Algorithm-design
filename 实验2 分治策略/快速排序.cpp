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
			Array[low]=Array[high];		//找到比分界数小的数，放到数组的左边
										//此时，high右边的数均比分界大
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
	
	if (low<high)						//仅当区间长度大于1时才须排序 
	{
	int p=Part(Array,low,high);			//对Array[low,high]做划分 
	QuickSort(Array,low,p-1);			//对左区间递归排序 
	QuickSort(Array,p+1,high);			//对右区间递归排序 
	}
}

int main()
{
	int a,i;
	int B[100]={0};
	printf("请输入要输入的数字的个数\n");
	scanf("%d",&a); 
	printf("请输入数字\n");
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


