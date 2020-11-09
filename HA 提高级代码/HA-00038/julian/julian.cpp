#include<bits/stdc++.h>
using namespace std;
int Q,m=1,y=4713;
long long r,yuan,ans=0;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void work1()
{
	y=y-(r/1461)*4;
	r=r%1461;
	y=y-r/365;
	r=r%365;
	for(int k=1;k<=12;k++)
	{
		r=r-mon[k];
		if(r<0)
		{
			m=k;
			r=mon[k]+r;
			break;
		}
	}
	if(yuan<1721424)	printf("%lld %d %d BC\n",r,m,y);
	else	printf("%lld %d %d\n",r,m,1-y);
}
void work2()
{
	y=1582,m=10;
	r=r+10-2299526;
	y=y+r/365;
	for(int i=1582;i<=y;i++)
	{
		if((i%400==0)||((i%4==0)&&(i%100!=0)))	ans+=366;
		else	ans+=365;
		if(ans>=r)	y=i-1;
	}
	r=ans+365-r;
	for(int k=1;k<=12;k++)
	{
		r=r-mon[k];
		if(r<0)
		{
			m=k;
			r=mon[k]+r;
			break;
		}
	}
	printf("%lld %d %d\n",r,m,y);
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		m=1,y=4713;
		scanf("%d",&r);
		yuan=r;
		if(r<31)	printf("%lld 1 4713 BC\n",r+1);
		else	if(r<2299526)	work1();
		else	work2();
	}
	return 0;
}
