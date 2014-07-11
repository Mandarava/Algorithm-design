#include<stdio.h>
int c=0; 
void move(char x,int n,char z)
{ 
printf("第%i步: 将%i号盘从%c移到%c\n",++c,n,x,z);
}
void hanoi(int n,char x,char y,char z)
{ 
	if(n==1)
	move(x,1,z);
	else
	{
	hanoi(n-1,x,z,y); 	//将x上编号为1至n-1的圆盘移到y，z作辅助塔
	move(x,n,z); 		//将编号为n的圆盘从x移到z
	hanoi(n-1,y,x,z); 	//将y上编号为1至n-1的圆盘移到z，x作辅助塔
	}
}
void main()
{
int n;
printf("3个塔座为a、b、c，圆盘最初在a，借助b移到c。请输入问题规模n：");
scanf("%d",&n);
hanoi(n,'a','b','c');
}
