#include <bits/stdc++.h>
using namespace std;
int d1[15]={0,0,31,60,91,121,152,182,213,244,274,305,335},d2[15]={0,30,59,90,120,151,181,212,243,273,304,334,365};
int d3[15]={0,0,31,59,90,120,151,181,212,243,273,304,334},d4[15]={0,30,58,89,119,150,180,211,242,272,303,333,364};
void pout1(int year,int k)  //Èò 
{
	for(int i=1;i<=12;++i)
	{
		if(k>=d1[i]&&k<=d2[i])
		{
			printf("%d %d %d",1+k-d1[i],i,year);
			return ;
		}
	}
}
void pout2(int year,int k) 
{
	for(int i=1;i<=12;++i)
	{
		if(k>=d3[i]&&k<=d4[i])
		{
			printf("%d %d %d",1+k-d3[i],i,year);
			return ;
		}
	}
}
void sol1(long long r)
{
	int year=4713;
	int t=r/1461;
	year=year-4*t;
	int k=r%1461;
	if(k<366)
	  pout1(year,k);
	else
	  pout2(year-1-(k-366)/365,(k-366)%365);
}
void sol2(long long r)
{
	int year=1584;
	int t=r/1461;
	year=year+4*t;
	int k=r%1461;
	int x100=(year-1)/100-15,x400=(year-1)/400-3;
	k=k+x100-x400;
	while(k/1461>0)
	{
		year=year+4*(k/1461);
		k=k%1461;
		int y100=(year-1)/100-15,y400=(year-1-3)/400-3;
		k=k+(y100-x100)-(y400-x400);
		x100=y100;x400=y400;
	}
	if(k<366)
	  pout1(year,k);
	else
	  pout2(year+1+(k-366)/365,(k-366)%365);
}
void sol3(long long r)
{
	int year=4;
	int t=r/1461;
	year=year+4*t;
	int k=r%1461;
	if(k<366)
	  pout1(year,k);
	else
	  pout2(year+1+(k-366)/365,(k-366)%365);
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q=0;
	cin>>q;
	for(int l=1;l<=q;++l)
	{
		long long r=0;
		scanf("%lld",&r);
		if(r<1721424)
		{
			sol1(r);
			printf(" BC\n");
			continue;
		}
		else
		{
			r-=1721424;
			if(r<=1095)
			  pout2(1+r/365,r%365);
			else
			{
				if(r<=577460)
				{
					sol3(r-1095);
				}
				else
				{
					r+=10;
					if(r<=578190)
					  sol2(r-1095);
					else
					  sol2(r-1095);
				}
				//sol2(r-1095);
			}
			printf("\n");
			
		}
		if(r==1721424)
		{
			printf("1 1 1\n");
			continue;
		}
	}
}
