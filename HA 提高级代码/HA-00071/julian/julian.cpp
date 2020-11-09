#include<bits/stdc++.h>
using namespace std;
const int N=2298766;
long long year,month,day;
int mp[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int mr[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
long long absccf(long long a)
{
	if(a<0)
	{
		return -a;
	}
	if(a==0)
	{
		return 0;
	}
	if(a>0)
	{
		return a;
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q;
	scanf("%d",&Q);
	long long r;
	long long a,b,c,d;
	for(int qq=0;qq<Q;++qq)
	{
		year=0,month=0,day=0;
		a=0,b=0,c=0,d=0;
		scanf("%lld",&r);
		year=r/365;
		a=r/(365*1460);
		year-=a;
		b=year;
		year=absccf(4713-year);
		day=r-b*365+b/4;
		if(day<0)
		{
			day+=365;
		}
		day++;
		for(int i=1;i<=12;++i)
		{
			day-=mr[i];
			if(day<0)
			{
				day+=mr[i];
				printf("%lld %d %lld BC\n",day,i,year);
				break;
			}
		}
	}
	return 0;
}
