#include<stdio.h>
int main()  
{
	int m[5]={50,20,10,5,1};//5����Ǯ,1Ԫ���µ���Ǯ���Һ��� ,��Ǯ�����㹻 
	int number[5]={0,0,0,0,0};//ÿ����Ǯ�ĸ���
	int n,i;
	printf("����Ӧ�ҵĽ��"); 
	scanf("%d",&n);
	 for(int i=0;i<5;i++)
    {
          number[i]=n/m[i];
          n=n%m[i];
     }
	for(i=0;i<5;i++)
	if(number[i]!=0)
		printf("%d��%dԪ\n",number[i],m[i]);	
} 
