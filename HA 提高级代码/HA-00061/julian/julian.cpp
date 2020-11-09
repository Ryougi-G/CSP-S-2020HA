#include<bits/stdc++.h>
#define ll long long
using namespace std;
int q;
int month[15]={0,31,59,90,120,151,181,212,243,273,304,334,365};//平常一年
int smonth[15]={0,31,60,91,121,152,182,213,244,274,305,335,366};
bool run(int x)
{
	if(x%400==0) return true;
	else if(x%100==0) return false;
	else if(x%4==0) return true;
	return false; 
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--)
	{
		ll x;
		ll y,m,d;
		scanf("%lld",&x);
		if(x<=1721423)
		{
			y=4713,m=1,d=1;
			int w=x/1461;//包含多少个四年 
			x=x-w*1461;
			y=y-w*4;
			while(x>=366)
			{
				if((y-1)%4==0&&x==365) break;
				if((y-1)%4==0) 
				{
					x=x-366;
					y--;
				}
				else 
				{
					x=x-365;
					y--;
				}
			}
			if((y-1)%4==0)
		  {
			for(int i=1;i<=12;i++)
			{
				if(x<smonth[i]) {m=i,d=x-smonth[i-1]+1;break;}
			}
		  }
		  else
		  {
		  	for(int i=1;i<=12;i++)
			{
				if(x<month[i]) {m=i,d=x-month[i-1]+1;break;}
			}
		  }
		  printf("%lld %lld %lld BC\n",d,m,y);
		  continue;
		}
		x=x-1721424;
		if(x<=577737)
		{
			y=1,d=1,m=1;
			int w=x/1461;//包含多少个四年 
			x=x-w*1461;
			y=y+w*4;
			while(x>=366)
			{
				if(y%4==0&&x==365) break;
				if(y%4==0) 
				{
					x=x-366;
					y++;
				}
				else 
				{
					x=x-365;
					y++;
				}
			}
			if(y%4==0)
		  {
			for(int i=1;i<=12;i++)
			{
				if(x<smonth[i]) {m=i,d=x-smonth[i-1]+1;break;}
			}
		  }
		  else
		  {
		  	for(int i=1;i<=12;i++)
			{
				if(x<month[i]) {m=i,d=x-month[i-1]+1;break;}
			}
		  }
		  printf("%lld %lld %lld\n",d,m,y);
		  continue;
		}
		x=x-577737;
		x=x+10;
		if(x<78)
		{
			if(x<17)
			{
				printf("%lld %lld %lld\n",x+15,10,1582);
				continue;
			}
			if(x<47)
			{
				printf("%lld %lld %lld\n",x-17+1,11,1582);
				continue;
			}
			printf("%lld %lld %lld\n",x-47+1,12,1582);
			continue;
		}
		d=1,y=1583,m=1;
		int w=x/146097;//包含多少个400年 
		x=x-w*146097;
		x=x-88;
		y=y+w*400;
			while(x>=366)
			{
				if(run(y)&&x==365) break;
				if(run(y)) 
				{
					x=x-366;
					y++;
				}
				else 
				{
					x=x-365;
					y++;
				}
			}
			if(run(y))
		  {
			for(int i=1;i<=12;i++)
			{
				if(x<smonth[i]) {m=i,d=x-smonth[i-1]+1;break;}
			}
		  }
		  else
		  {
		  	for(int i=1;i<=12;i++)
			{
				if(x<month[i]) {m=i,d=x-month[i-1]+1;break;}
			}
		  }
		  printf("%lld %lld %lld\n",d,m,y);
	}
	return 0;
}
