#include<stdio.h>
void GreedySelector(int n,int B[],int E[],bool A[])//�Ի������̰��ѡ�� 
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


int main()
{	int n,i,j,y; 
	int C[100],B[100],E[100],F[100],num2[100];
	int location; 
	printf("�������ĸ���\n");
	scanf("%d", &n);
	printf("������ʼʱ��ͽ���ʱ��\n");
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
	for(i=0;i<n;i++)		///�����������E[]�е�Ԫ����ԭʼ�����е�λ�ã� 
							//ʹ������Ļ����ʱ����ԭʼ�Ŀ�ʼʱ����������Ӧ 
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
	printf("��������л��Ϣ������ʱ���������������:");////����Ϊ�������Ļ��Ϣ///
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
	printf("ѡ����"); 
	for(i=0;i<n;i++)
	{	if(A[i]==1)
		printf("%d",num2[i]+1);
		printf(" "); 
	}
	printf("\n");
	return 0;
}
