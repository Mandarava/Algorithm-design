#include<stdio.h>
void Merge(int *num,int start,int middle,int end)
{

	int n1=middle-start+1; 
	int n2=end-middle;
	int *L=new int[n1+1];
	int *R=new int[n2+1];
	int i,j=0,k;
	for (i=0; i<n1; i++)
    {
		*(L+i)=*(num+start+i);
	}
    *(L+n1)=1000000;
	for (i=0; i<n2; i++)
    {
		*(R+i)=*(num+middle+i+1);
	}
	*(R+n2)=1000000;
	i=0;
	for (k=start; k<=end; k++)
    {
		if(L[i]<=R[j])
        {
			num[k]=L[i];
			i++;
		}
		else
        {
			num[k]=R[j];
			j++;
		}
	}
	delete [] L;
	delete [] R;
	} 


void MergeSort(int A[],int low,int high)
{
	int middle;
	if(low<high)
	{
		middle=(low+high)/2;
		MergeSort(A,low,middle);
		MergeSort(A,middle+1,high);
		Merge(A,low,middle,high);
	}
}
int main()
{
	int a,i;
	int A[100]={0};
	printf("请输入要输入的数字的个数\n");
	scanf("%d",&a); 
	printf("请输入数字\n");
	for(i=1;i<=a;i++)
	{
		scanf("%d",&A[i-1]);
		
	}
 	MergeSort(A,0,a-1);
	for(int i=0;i<=a-1;i++)
	printf("%d ",A[i]);
	printf("\n");
	return 0;
}


