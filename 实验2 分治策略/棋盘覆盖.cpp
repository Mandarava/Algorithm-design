#include<stdio.h>
#include <math.h>
int tile=1;   
int board[20][20]={0};
void chessBoard(int tr,int tc,int dr,int dc,int size)
{
	
	int s;
	if(size==1)return;
	int t=tile++;
	s=size/2;
	
//�������Ͻ������� 
	if(dr<tr+s&&dc<tc+s)			
	 chessBoard(tr,tc,dr,dc,s);
	else{
		board[tr + s-1][tc + s-1]=t;
		chessBoard(tr,tc,tr+s-1,tc+s-1,s);
		}
//�������Ͻ������� 
	if(dr<tr+s&&dc>=tc+s)
	 chessBoard(tr,tc+s,dr,dc,s);
	else{
		 board[tr +s-1][tc + s]=t;
		 chessBoard(tr,tc+s,tr+s-1,tc+s,s);
		}
//�������½������� 	
	if(dr>=tr+s&&dc<tc+s)
	 chessBoard(tr + s,tc,dr,dc,s);
	 else
	 {
	 	board[tr+s][tc+s-1]=t;
		chessBoard(tr+s,tc,tr+s,tc+s-1,s);
	 }
//�������½������� 	 
	 if(dr>=tr+s&&dc>=tc+s)
	  chessBoard(tr+s,tc+s,dr,dc,s);
	 else 
	 {
	 	board[tr+s][tc+s]=t;
	 	chessBoard(tr+s,tc+s,tr+s,tc+s,s);
	 }
}
int main()
{ 	
	int k,x,y;
	printf("���������̵Ĺ�ģK��");
	scanf("%d",&k);
	printf("���������ⷽ����±�x,y��");
	scanf("%d %d",&x,&y);
	chessBoard(0,0,x,y,pow(2,k)); 
	for(int i=0; i<pow(2,k); i++)
	{
		for (int j=0; j<pow(2,k); j++)
		{
			printf("%-4d",board[i][j]);
		}
		printf("\n");
	}
	return 0;
	
	
}
