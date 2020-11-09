#include<bits/stdc++.h>
using namespace std;
long long q,e;
int m[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31},m2[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
void s()
{
scanf("%lld",&e);
	e+=1;
	if(e<2299162)
	{
		long long y=e/1461,i=3,m1=1;
		long long y1=4*y,d=e-y*1461;
		if(d-366>0)
		{
			y1++;
			d-=366;
		}
		while(i)
		{
			if(d-365>0)
			{
				y1++;
				d-=365;
			}
			i--;
		}
		if(y1==4*y)
		{
			for(i=1; i<12; i++)
			{
				if(d>m2[i])
				{
					m1++;
					d-=m2[i];
				}
				else break;
			}
		}
		else
		{
			for(i=1; i<12; i++)
			{
				if(d>m[i])
				{
					m1++;
					d-=m[i];
				}
				else break;
			}
		}
		if(y1<4713)
			printf("%lld %lld %lld BC\n",d,m1,4713-y1);
		else
			printf("%lld %lld %lld\n",d,m1,y1-4712);
	}
	else
	{
		e-=1721426;
		long long ys=e/146097,i=4;
		long long y1=ys*400;
		long long d=e%146097;
		while(i)
		{
			if(d-36524>0)
			{
				y1+=100;
				d-=36524;
			}
			i--;
		}
		long long g=d/1461,m1=1,h;
		h=4*g;
		y1+=h;
		d=d-g*1461;
		i=4;
		while(i)
		{
			if(d-365>0)
			{
				y1++;
				d-=365;
			}
			i--;
		}
		if(y1%4==3)
		{
			for(i=1; i<12; i++)
			{
				if(d>m2[i])
				{
					m1++;
					d-=m2[i];
				}
				else break;
			}
		}
		else
		{
			for(i=1; i<12; i++)
			{
				if(d>m[i])
				{
					m1++;
					d-=m[i];
				}
				else break;
			}
		}
		printf("%lld %lld %lld\n",d,m1,y1+1);
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--)
		s();
	return 0;
}
