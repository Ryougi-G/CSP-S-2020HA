#include<bits/stdc++.h>
using namespace std;
long long Q,r;
long long AD=0;
long long y,m,d;
long long g=0;
long long syy()
{
	long long nn=0,a;
	a=r/146097;
	nn+=a*400;
	r%=146097;
	a=r/36524;
	nn+=a*100;
	r%=36524;
	a=r/1461;
	nn+=a*4;
	r%=1461;
	if(r<=366) 
	return nn;
	r-=366;
	nn++;
	while(r>365)
	{
		r-=365;
		nn++;
	}
	return nn;
}
long long sy()
{
    long long nn=0,a;
	a=r/1461;
	nn+=a*4;
	r%=1461;
	if(r<=366) 
	return nn;
	r-=366;
	nn++;
	while(r>365)
	{
		r-=365;
		nn++;
	}
	return nn;
}
bool pr(long long ni)
{
	if(AD==0) ni--;
	if(ni%4==0) return 1;
	else return 0;
}
bool ppr(long long ni)
{
	if(ni%100==0)
	{
		if(ni%400==0) return 1;
		else return 0;
	}
	else
	{
		if(ni%4==0) return 1;
		else return 0;
	}
}
long long sm()
{
	if(r<=31) return 1;
	r-=31;
	if(g==0)
	{
		if(pr(y))
		{
			if(r<=29) return 2;
			r-=29;
		}
		else
		{
			if(r<=28) return 2;
			r-=28;
		}
	}
	else
	{
		if(ppr(y))
		{
			if(r<=29) return 2;
			r-=29;
		}
		else
		{
			if(r<=28) return 2;
			r-=28;
		}
	}
	if(r<=31) return 3;
	r-=31;
	if(r<=30) return 4;
	r-=30;
	if(r<=31) return 5;
	r-=31;
	if(r<=30) return 6;
	r-=30;
	if(r<=31) return 7;
	r-=31;
	if(r<=31) return 8;
	r-=31;
	if(r<=30) return 9;
	r-=30;
	if(r<=31) return 10;
	r-=31;
	if(r<=30) return 11;
	r-=30;
	return 12;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>Q;
	for(long long q=1;q<=Q;q++)
	{
		scanf("%lld",&r);
		if(r<=2299160) 
		{
			r++;
			y=4713-sy();
			if(y<=0) AD=1,y*=-1,y++;
			m=sm();
			printf("%lld %lld %lld",r,m,y);
			if(AD==0) printf(" BC");
			printf("\n");
		}
		else
		{
			g=1;
			r-=2299160;
			r+=139810;
			y=1200+syy();
			m=sm();
			printf("%lld %lld %lld\n",r,m,y);
		}
	}
}
