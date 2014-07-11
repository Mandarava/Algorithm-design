#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=0;a<=100;a++)
 		for(b=0;b<=100;b++)
 			for(c=0;c<=100;c++)
			if(c%3==0)
 			if(5*a+3*b+c/3==100&&a+b+c==100)
 			printf("%d %d %d\n",a,b,c);
}
