#include<stdio.h>
int main()  
{
	int m[5]={50,20,10,5,1};//5种零钱,1元以下的零钱暂且忽略 ,零钱数量足够 
	int number[5]={0,0,0,0,0};//每种零钱的个数
	int n,i;
	printf("输入应找的金额"); 
	scanf("%d",&n);
	 for(int i=0;i<5;i++)
    {
          number[i]=n/m[i];
          n=n%m[i];
     }
	for(i=0;i<5;i++)
	if(number[i]!=0)
		printf("%d个%d元\n",number[i],m[i]);	
} 
