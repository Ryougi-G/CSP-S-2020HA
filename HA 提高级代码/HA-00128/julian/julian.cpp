#include<bits/stdc++.h>
using namespace std;
int q,r;
int rq[3][13],yrq[13];
void find(int x)
{
	int y, yy, nian;
	int nnian=x/365,yutian=x%365;
	int zreinian;
	if(x<=365)zreinian=nnian/4;
	else zreinian=max(nnian/4,1);
	int qiantian=zreinian-yutian;
	int qiannian=qiantian/365;
	if(qiantian<0) 
	{
	qiannian=0;
	}
	qiantian=qiantian%365;
	y=nnian-qiannian-4713;
//	if(y<0) y--;
	if(y<0)  yy=-y-1;
		else  yy=y;
	if((yy%4==0&&yy%100!=0)||(yy%400==0))  nian=2;
		else  nian=1;
	if(nian==1) x=365-qiantian;
	if(nian==2) x=366-qiantian;
	if(qiantian<0) 
	{
	x=-qiantian;
	}
	if(x<356)
	{
		for(int i=1;i<=12;i++)
		{
			if(nian==1) yrq[2]=28;
			else yrq[2]=29;
			if(rq[nian][i]-x>0)  
			{
				int rz=yrq[i]-rq[nian][i]+x+1;
				
				int yf=i;
				if(y>0) printf("%d %d %d\n",rz,yf,y);
				else printf("%d %d %d",rz,yf,-y),printf(" BC\n");
				return;
			}
		}
	}
	if(x==365) 
	{
		int rz=1,yf=1;
		if(y>0) printf("%d %d %d\n",rz,yf,y);
				else printf("%d %d %d",rz,yf,-y),printf(" BC\n");
				return;
	}
}	
	
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	yrq[1]=31,yrq[2]=28,yrq[3]=31,yrq[5]=31,yrq[7]=31,yrq[8]=31,yrq[10]=31,yrq[12]=31;
	yrq[4]=30,yrq[6]=30,yrq[9]=30,yrq[11]=30;	
	for(int j=1;j<=12;j++)
	{
		rq[1][j]+=rq[1][j-1]+yrq[j];
	}
	yrq[2]=29;
	for(int j=1;j<=12;j++)
	{
		rq[2][j]+=rq[2][j-1]+yrq[j];
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
	scanf("%d",&r);
		find(r);
	}	
	return 0;
}
