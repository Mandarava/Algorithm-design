#include<stdio.h>
int c; //�������� 
int n; //��Ʒ�� 
int weight[100]; //���n����Ʒ���������� 
int price[100]; //���n����Ʒ��ֵ������ 
int currentWeight=0; //��ǰ���� 
int currentPrice=0; //��ǰ��ֵ 
int bestPrice=0; //��ǰ����ֵ 
int bestAnswer[100]; //��ǰ���Ž� 
int bp=0;
int bA[100]; //��ǰ���Ž� 
void Print(); 
void Backtracking(int i) 
{
  
	if(i>n) 
	{ 
		Print();
		if(bestPrice>bp)
		{
			bp=bestPrice;
			for(int j=1;j<=n;j++)
               bA[j]=bestAnswer[j];
		}
		return; 
         } 
if(currentWeight+weight[i]<=c) 
	{ //����Ʒi���뱳�������������� 
		bestAnswer[i] = 1; 
		currentWeight += weight[i]; 
		bestPrice += price[i]; 
		Backtracking(i+1); //�������ĵݹ飬���ص���һ��㣬��Ʒi�����뱳����׼���ݹ������� 
		currentWeight -= weight[i]; 
		bestPrice -= price[i]; 
	} bestAnswer[i] = 0; 
	Backtracking(i+1); 
} 
void Print() 
{ 	int i; 
	printf("\n·��Ϊ  {"); 
	for(i=1;i<n;++i) 
		printf("%d,",bestAnswer[i]); 
	printf("%d}\t��ֵΪ%d\n",bestAnswer[i],bestPrice); 
} 
void main() 
{ 	int i; 
    printf("��������Ʒ������:\n");
    scanf("%d",&n);
    printf("�����뱳��������(�ܳ��ܵ�����):\n");
    scanf("%d",&c);
    printf("����������%d����Ʒ������:\n",n);

for(i=1;i<=n;i++)
        scanf("%d",&weight[i]);
    printf("����������%d����Ʒ�ļ�ֵ:\n",n);
 for(i=1;i<=n;i++)
        scanf("%d",&price[i]);
	printf("������������·��Ϊ��\n"); 
	Backtracking(1);
	printf("*******************************************************\n");
	printf("\nthe best answer is {"); 
	for(i=1;i<n;++i) 
		printf("%d,",bA[i]); 
	printf("%d}\tthe price is %d\n",bA[i],bp); 
 }

